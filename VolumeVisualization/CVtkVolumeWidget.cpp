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
	m_pRenderer = vtkSmartPointer<vtkRenderer>::New();
	m_pRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	m_pVolume = vtkSmartPointer<vtkVolume>::New();
	m_pVolumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();

	m_pRenderWindow->AddRenderer( m_pRenderer );
	this->SetRenderWindow( m_pRenderWindow );
	//m_pRenderWindow->GetInteractor()->SetInteractorStyle( 0 );
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

	/*Volume*/
	//Default Volume Property
	m_pVolumeProperty->SetInterpolationTypeToLinear();
	m_pVolumeProperty->ShadeOn();
	m_pVolumeProperty->SetAmbient( 0.2 );
	m_pVolumeProperty->SetDiffuse( 0.6 );
	m_pVolumeProperty->SetSpecular( 1 );

	//opacity func
	vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	compositeOpacity->AddPoint( 0, 0.0 );
	compositeOpacity->AddPoint( 20, 0.0 );
	compositeOpacity->AddPoint( 40, 0.15 );
	compositeOpacity->AddPoint( 120, 0.3 );
	compositeOpacity->AddPoint( 1220, 0.375 );
	compositeOpacity->AddPoint( 1024, 0.5 );
	m_pVolumeProperty->SetScalarOpacity( compositeOpacity );

	//color transfer func
	vtkSmartPointer<vtkColorTransferFunction> colorTransFunc = vtkSmartPointer<vtkColorTransferFunction>::New();
	colorTransFunc->AddRGBPoint( 0, 0, 0, 0 );
	colorTransFunc->AddRGBPoint( 20, 0.168627, 0, 0 );
	colorTransFunc->AddRGBPoint( 40, 0.403922, 0.145098, 0.0784314 );
	colorTransFunc->AddRGBPoint( 120, 0.780392, 0.607843, 0.380392 );
	colorTransFunc->AddRGBPoint( 220, 0.847059, 0.835294, 0.788235 );
	colorTransFunc->AddRGBPoint( 1024, 1, 1, 1 );
	m_pVolumeProperty->SetColor( colorTransFunc );

	vtkSmartPointer<vtkGPUVolumeRayCastMapper> volumeMapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
	volumeMapper->SetInputData( pImageData );

	vtkSmartPointer<vtkVolume> pVolume = vtkSmartPointer<vtkVolume>::New();
	pVolume->SetMapper( volumeMapper );
	pVolume->SetProperty( m_pVolumeProperty );
	pVolume->RotateX( 90 );
	pVolume->RotateZ( 180 );

	//Render Window
	m_pRenderer->AddVolume( pVolume );
	m_pRenderer->ResetCamera();
	m_pRenderWindow->Modified();
	m_pRenderWindow->Render();
}

void CVtkVolumeWidget::UpdateVolumeProperty( const VolumePropertyInfo& volPresetInfo )
{
	//1.设置Color（颜色传输函数）
	vtkSmartPointer<vtkColorTransferFunction> pColorTransferFunction = vtkSmartPointer<vtkColorTransferFunction>::New();

	const QMap<float, RGBA>& mapColor = volPresetInfo.mapColor;
	float fMax = volPresetInfo.fMax;
	float fMin = volPresetInfo.fMin;
	QMap<float, RGBA>::const_iterator iter = mapColor.constBegin();
	while( iter != mapColor.constEnd() )
	{
		const RGBA rgb = iter.value();
		if( !volPresetInfo.bUseAbsolute )
			pColorTransferFunction->AddRGBPoint( fMin + iter.key()*(fMax - fMin), rgb.m_r / 255.0, rgb.m_g / 255.0, rgb.m_b / 255.0 );
		else
			pColorTransferFunction->AddRGBPoint( iter.key(), rgb.m_r / 255.0, rgb.m_g / 255.0, rgb.m_b / 255.0 );
		++iter;
	}

	// 	pColorTransferFunction->SetScaleToLinear();
	m_pVolumeProperty->SetColor( pColorTransferFunction );

	//2.设置Opacity（不透明度传输函数）
	vtkSmartPointer<vtkPiecewiseFunction> pOpacityTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New();
	pOpacityTransferFunction->SetClamping( volPresetInfo.bClamping );
	const QMap<float, float>& mapOpacity = volPresetInfo.mapOpacity;

	QMap<float, float>::const_iterator c_iter = mapOpacity.constBegin();
	while( c_iter != mapOpacity.constEnd() )
	{
		if( !volPresetInfo.bUseAbsolute )
			pOpacityTransferFunction->AddPoint( fMin + c_iter.key()*(fMax - fMin), c_iter.value() );
		else
			pOpacityTransferFunction->AddPoint( c_iter.key(), c_iter.value() );
		++c_iter;
	}


	m_pVolumeProperty->SetScalarOpacity( pOpacityTransferFunction );

	//3.设置插值模式为线性插值
	m_pVolumeProperty->SetInterpolationTypeToLinear();

	if( volPresetInfo.bShade )
	{
		m_pVolumeProperty->ShadeOn();//阴影
		m_pVolumeProperty->SetAmbient( volPresetInfo.dAmbient );//环境光因子
		m_pVolumeProperty->SetDiffuse( volPresetInfo.dDiffuse );//散射光因子
		m_pVolumeProperty->SetSpecular( volPresetInfo.dSpecular );//反射光因子
	}
	else
	{
		m_pVolumeProperty->ShadeOff();
		m_pVolumeProperty->SetAmbient( 1.0 );//环境光因子
		m_pVolumeProperty->SetDiffuse( 0 );//散射光因子
		m_pVolumeProperty->SetSpecular( 0 );//反射光因子

	}

	//4.Set Modified，引发重新计算并刷新
	m_pVolumeProperty->Modified();
	m_pVolume->Modified();
}
