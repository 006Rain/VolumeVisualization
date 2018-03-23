#include "volumevisualization.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>

#include "CLoadImageDlg.h"
#include "CVtkVolumeWidget.h"

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

	//Btn Load
	QPushButton* pBtnLoad = new QPushButton( tr( "Load" ) );
	pBtnLoad->setFixedSize( 80, 30 );
	
	QHBoxLayout* pBtnLayout = new QHBoxLayout;
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( pBtnLoad );
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
	stVolumeProperty.mapOpacity[ 0 ] = 0.0;
	stVolumeProperty.mapOpacity[ 36.05 ] = 0.0;
	stVolumeProperty.mapOpacity[ 218.302 ] = 0.171429;
	stVolumeProperty.mapOpacity[ 412.406 ] = 1;
	stVolumeProperty.mapOpacity[ 641 ] = 1;
	
	RGBA stRgba;
	stRgba.m_r = 0;
	stRgba.m_g = 0;
	stRgba.m_b = 0;
	stRgba.m_a = 255;

	stVolumeProperty.mapColor[ 0 ] = stRgba;
	stRgba.m_r = 244;
	stRgba.m_g = 214;
	stRgba.m_b = 49;
	stVolumeProperty.mapColor[ 98.7223 ] = stRgba;

	stRgba.m_r = 0;
	stRgba.m_g = 151;
	stRgba.m_b = 206;
	stVolumeProperty.mapColor[ 412.406 ] = stRgba;

	stRgba.m_r = 255;
	stRgba.m_g = 255;
	stRgba.m_b = 255;
	stVolumeProperty.mapColor[ 641 ] = stRgba;

	stVolumeProperty.bShade = true;
	stVolumeProperty.dAmbient = 0.3;
	stVolumeProperty.dDiffuse = 0.6;
	stVolumeProperty.dSpecular = 0.5;
	stVolumeProperty.fMax = 641;
	stVolumeProperty.fMin = 0;

	m_pVolumeWidget->UpdateVolumeProperty( stVolumeProperty );

	return;
}