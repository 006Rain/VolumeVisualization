#include <vtkAutoInit.h> 
VTK_MODULE_INIT( vtkRenderingOpenGL );
VTK_MODULE_INIT( vtkInteractionStyle );
#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)  

#include "CVtkVolumeWidget.h"

#include <QFile>

#include "vtkImageData.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkVolume.h"
#include "vtkVolumeProperty.h"
#include "vtkPiecewiseFunction.h"
#include "vtkGPUVolumeRayCastMapper.h"
#include "vtkColorTransferFunction.h"

#include "CommonDef.h"

CVtkVolumeWidget::CVtkVolumeWidget( QWidget *parent )
	: QVTKWidget( parent )
{
	//Init RenderWindow
	m_pRenderer = vtkSmartPointer<vtkRenderer>::New();
	m_pRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	m_pVolume = vtkSmartPointer<vtkVolume>::New();

	m_pRenderWindow->AddRenderer( m_pRenderer );
	this->SetRenderWindow( m_pRenderWindow );
	//m_pRenderWindow->GetInteractor()->SetInteractorStyle( 0 );

	/*Init Property Info*/
	m_pVolumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();

	m_stPropertyInfo.bClamping = true;
	m_stPropertyInfo.bShade = true;
	m_stPropertyInfo.dAmbient = 0.2;
	m_stPropertyInfo.dDiffuse = 0.6;
	m_stPropertyInfo.dSpecular = 1;
	m_stPropertyInfo.mapOpacity[ -3024 ] = 0.0;
	m_stPropertyInfo.mapOpacity[ -16.4458 ] = 0.0;
	m_stPropertyInfo.mapOpacity[ 641.385 ] = 0.715686;
	m_stPropertyInfo.mapOpacity[ 3071 ] = 0.705882;

	RGBA stRgba;
	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	stRgba.m_nA = 255;

	m_stPropertyInfo.mapColor[ -3024 ] = stRgba;
	stRgba.m_nR = 186;
	stRgba.m_nG = 65;
	stRgba.m_nB = 77;
	m_stPropertyInfo.mapColor[ -16.4458 ] = stRgba;

	stRgba.m_nR = 230;
	stRgba.m_nG = 208;
	stRgba.m_nB = 141;
	m_stPropertyInfo.mapColor[ 641.385 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stPropertyInfo.mapColor[ 3071 ] = stRgba;

	m_stPropertyInfo.fMax = 3071;
	m_stPropertyInfo.fMin = -3024;
}

CVtkVolumeWidget::~CVtkVolumeWidget()
{

}


void CVtkVolumeWidget::SetImageParam( const ImageParams& stParam )
{
	m_stImageParam = stParam;
}

void CVtkVolumeWidget::UpdateImage()
{
	//Create Image Data
	int nDims[ 3 ] = { 1 };
	nDims[ 0 ] = m_stImageParam.nDimX;
	nDims[ 1 ] = m_stImageParam.nDimY;
	nDims[ 2 ] = m_stImageParam.nDimZ;

	double dSpacing[ 3 ] = { 0.1 };
	dSpacing[ 0 ] = m_stImageParam.dPixelX;
	dSpacing[ 1 ] = m_stImageParam.dPixelY;
	dSpacing[ 2 ] = m_stImageParam.dPixelZ;

	double dOrigin[ 3 ] = { 0.0 };

	vtkSmartPointer<vtkImageData> pImageData = vtkSmartPointer<vtkImageData>::New();
	pImageData->SetSpacing( dSpacing );
	pImageData->SetDimensions( nDims );
	pImageData->SetOrigin( dOrigin );

	//
	QFile file( m_stImageParam.strFilePath );
	if( !file.open( QIODevice::ReadOnly ) )
		return;
	file.seek( m_stImageParam.nOffset );

	switch( m_stImageParam.eDataType )
	{
	case Char:
	{
		long lLength = nDims[ 0 ] * nDims[ 1 ] * nDims[ 2 ];
		char* pRawData = new char[ lLength ];
		long lRead = 0;
		while( lRead < lLength )
			lRead += file.read( pRawData, lLength );

		pImageData->AllocateScalars( VTK_SIGNED_CHAR, 1 );
		char* pScalarPointer = (char*)pImageData->GetScalarPointer();
		memcpy( pScalarPointer, pRawData, lLength );
	}
		break;
	case Short:
	{
		long lLength = nDims[ 0 ] * nDims[ 1 ] * nDims[ 2 ] * 2;
		char* pRawData = new char[ lLength ];
		long lRead = 0;
		while( lRead < lLength )
			lRead += file.read( pRawData, lLength );

		pImageData->AllocateScalars( VTK_SHORT, 1 );
		short* pScalarPointer = (short*)pImageData->GetScalarPointer();
		short* pData = (short*)pRawData;
		memcpy( pScalarPointer, pData, lLength );
	}
		break;
	case Float:
	{
		long lLength = nDims[ 0 ] * nDims[ 1 ] * nDims[ 2 ] * 4;
		char* pRawData = new char[ lLength ];
		long lRead = 0;
		while( lRead < lLength )
			lRead += file.read( pRawData, lLength );

		pImageData->AllocateScalars( VTK_FLOAT, 1 );
		float* pScalarPointer = (float*)pImageData->GetScalarPointer();
		float* pData = (float*)pRawData;
		memcpy( pScalarPointer, pData, lLength );
	}
		break;
	}
	file.close();

	//Volume
	vtkSmartPointer<vtkGPUVolumeRayCastMapper> volumeMapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
	volumeMapper->SetInputData( pImageData );

	vtkSmartPointer<vtkVolume> pVolume = vtkSmartPointer<vtkVolume>::New();
	pVolume->SetMapper( volumeMapper );
	pVolume->SetProperty( m_pVolumeProperty );

	//Render Window
	m_pRenderer->AddVolume( pVolume );
	m_pRenderer->ResetCamera();
	m_pRenderWindow->Modified();
	m_pRenderWindow->Render();

	UpdateVolumeProperty( m_stPropertyInfo );
}

void CVtkVolumeWidget::UpdateVolumeProperty( const VolumePropertyInfo& volPresetInfo )
{
	m_stPropertyInfo = volPresetInfo;

	//1.设置Color（颜色传输函数）
	vtkSmartPointer<vtkColorTransferFunction> pColorTransferFunction = vtkSmartPointer<vtkColorTransferFunction>::New();

	const QMap<float, RGBA>& mapColor = volPresetInfo.mapColor;
	QMap<float, RGBA>::const_iterator iter = mapColor.constBegin();
	while( iter != mapColor.constEnd() )
	{
		const RGBA rgb = iter.value();
		pColorTransferFunction->AddRGBPoint( iter.key(), rgb.m_nR / 255.0, rgb.m_nG / 255.0, rgb.m_nB / 255.0 );
		++iter;
	}

	pColorTransferFunction->SetScaleToLinear();
	m_pVolumeProperty->SetColor( pColorTransferFunction );

	//2.设置Opacity（不透明度传输函数）
	vtkSmartPointer<vtkPiecewiseFunction> pOpacityTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New();
	pOpacityTransferFunction->SetClamping( volPresetInfo.bClamping );
	const QMap<float, float>& mapOpacity = volPresetInfo.mapOpacity;

	QMap<float, float>::const_iterator c_iter = mapOpacity.constBegin();
	while( c_iter != mapOpacity.constEnd() )
	{
		pOpacityTransferFunction->AddPoint( c_iter.key(), c_iter.value() );
		++c_iter;
	}
	m_pVolumeProperty->SetScalarOpacity( pOpacityTransferFunction );

	//3.设置插值模式为线性插值
	m_pVolumeProperty->SetInterpolationTypeToLinear();
	m_pVolumeProperty->ShadeOn();//阴影
	m_pVolumeProperty->SetAmbient( volPresetInfo.dAmbient );//环境光因子
	m_pVolumeProperty->SetDiffuse( volPresetInfo.dDiffuse );//散射光因子
	m_pVolumeProperty->SetSpecular( volPresetInfo.dSpecular );//反射光因子

	//4.Set Modified，引发重新计算并刷新
	m_pVolumeProperty->Modified();
	m_pVolume->Modified();
	m_pRenderWindow->Modified();
	m_pRenderWindow->Render();
}

VolumePropertyInfo CVtkVolumeWidget::GetVolumeProperty()
{
	return m_stPropertyInfo;
}