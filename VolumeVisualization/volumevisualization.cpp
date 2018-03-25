#include "volumevisualization.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>

#include "CLoadImageDlg.h"
#include "CVtkVolumeWidget.h"
#include "CVolumeOpacitySetDlg.h"

VolumeVisualization::VolumeVisualization( QWidget *parent )
	:QWidget( parent )
{
	ui.setupUi( this );
	setWindowIcon( QIcon( "./Images/logo.jpg" ) );
	setWindowTitle( tr( "Volume Visualization" ) );
	setFixedSize( 800, 600 );

	InitWidget();
}

VolumeVisualization::~VolumeVisualization()
{

}

void VolumeVisualization::InitWidget()
{
	//Volume Widget
	m_pVolumeWidget = new CVtkVolumeWidget;

	//Btn
	QPushButton* pBtnLoad = new QPushButton( tr( "Load" ) );
	pBtnLoad->setFixedSize( 80, 30 );

	QPushButton* pBtnOpacity = new QPushButton( tr( "Opacity" ) );
	pBtnOpacity->setFixedSize( 80, 30 );
	
	QHBoxLayout* pBtnLayout = new QHBoxLayout;
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( pBtnLoad );
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( pBtnOpacity );
	pBtnLayout->addStretch();

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( m_pVolumeWidget, 0, 0 );
	pMainLayout->addLayout( pBtnLayout, 1, 0 );
	pMainLayout->setContentsMargins( 15, 15, 15, 15 );
	pMainLayout->setSpacing( 15 );
	setLayout( pMainLayout );
	
	//connects
	connect( pBtnLoad, SIGNAL( clicked() ), this, SLOT( slotBtnLoad() ) );
	connect( pBtnOpacity, SIGNAL( clicked() ), this, SLOT( slotBtnOpacity() ) );
}

void VolumeVisualization::slotBtnLoad()
{
	CLoadImageDlg dlgLoadImage;
	if( QDialog::Accepted != dlgLoadImage.exec() )
		return;

	ImageParams stParam;
	dlgLoadImage.GetImageParam( stParam );

	if( !m_pVolumeWidget )
		m_pVolumeWidget = new CVtkVolumeWidget;

	m_pVolumeWidget->SetImageParam( stParam );
	m_pVolumeWidget->UpdateImage();

	VolumePropertyInfo stVolumeProperty;
	stVolumeProperty.mapOpacity[ -3024] = 0.0;
	stVolumeProperty.mapOpacity[ -16.4458 ] = 0.0;
	stVolumeProperty.mapOpacity[ 641.385 ] = 0.715686;
	stVolumeProperty.mapOpacity[ 3071 ] = 0.705882;
	
	RGBA stRgba;
	stRgba.m_r = 0;
	stRgba.m_g = 0;
	stRgba.m_b = 0;
	stRgba.m_a = 255;

	stVolumeProperty.mapColor[ -3024 ] = stRgba;
	stRgba.m_r = 186;
	stRgba.m_g = 65;
	stRgba.m_b = 77;
	stVolumeProperty.mapColor[ -16.4458 ] = stRgba;

	stRgba.m_r = 230;
	stRgba.m_g = 208;
	stRgba.m_b = 141;
	stVolumeProperty.mapColor[ 641.385 ] = stRgba;

	stRgba.m_r = 255;
	stRgba.m_g = 255;
	stRgba.m_b = 255;
	stVolumeProperty.mapColor[ 3071 ] = stRgba;

	stVolumeProperty.bShade = true;
	stVolumeProperty.bUseAbsolute = true;
	stVolumeProperty.dAmbient = 0.1;
	stVolumeProperty.dDiffuse = 0.9;
	stVolumeProperty.dSpecular = 0.2;
	stVolumeProperty.fMax = 3071;
	stVolumeProperty.fMin = -3024;

	m_pVolumeWidget->UpdateVolumeProperty( stVolumeProperty );

	return;
}

void VolumeVisualization::slotBtnOpacity()
{
	CVolumeOpacitySetDlg dlgOpacity;
	dlgOpacity.exec();
}