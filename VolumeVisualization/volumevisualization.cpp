#include "volumevisualization.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>

#include "CLoadImageDlg.h"
#include "CVtkVolumeWidget.h"

#include "CRotateSetWidget.h"
#include "COpacitySetWidget.h"

VolumeVisualization::VolumeVisualization( QWidget *parent )
	:QWidget( parent )
{
	ui.setupUi( this );
	setWindowIcon( QIcon( "./Images/logo.jpg" ) );
	setWindowTitle( tr( "Volume Visualization" ) );
	setFixedSize( 1000, 600 );

	InitWidget();
}

VolumeVisualization::~VolumeVisualization()
{
	
}

void VolumeVisualization::InitWidget()
{
	//Volume Widget
	m_pVolumeWidget = new CVtkVolumeWidget;

	/*Left Property Set Widget*/
	QWidget* pLeftWidget = new QWidget;

	//Rotate
	CRotateSetWidget* pRotateWidget = new CRotateSetWidget;
	pRotateWidget->setFixedSize( 250, 150 );

	//Opacity
	COpacitySetWidget* pOpacityWidget = new COpacitySetWidget;
//	pRotateWidget->setFixedSize( 250, 120 );

	//Left Layout
	QGridLayout* pLeftLayout = new QGridLayout;
	pLeftLayout->addWidget( pRotateWidget, 0, 0 );
	pLeftLayout->addWidget( pOpacityWidget, 1, 0 );

	/*Buttons*/
	//Load Image
	QPushButton* pBtnLoad = new QPushButton( tr( "Load" ) );
	pBtnLoad->setFixedSize( 80, 30 );

	//Remove
	m_pBtnRemove = new QPushButton( tr( "Remove" ) );
	m_pBtnRemove->setFixedSize( 80, 30 );
	m_pBtnRemove->setEnabled( false );

	QHBoxLayout* pBtnLayout = new QHBoxLayout;
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( pBtnLoad );
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( m_pBtnRemove );
	pBtnLayout->addStretch();

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addLayout( pLeftLayout, 0, 0 );
	pMainLayout->addWidget( m_pVolumeWidget, 0, 1 );
	pMainLayout->addLayout( pBtnLayout, 1, 1 );
	pMainLayout->setContentsMargins( 15, 15, 15, 15 );
	pMainLayout->setSpacing( 15 );
	setLayout( pMainLayout );
	
	//connects sigOpacityInfo
	connect( pBtnLoad, SIGNAL( clicked() ), this, SLOT( slotBtnLoad() ) );
	connect( m_pBtnRemove, SIGNAL( clicked() ), this, SLOT( slotBtnRemove() ) );
	connect( pOpacityWidget, SIGNAL( sigOpacityChanged( const VolumePropertyInfo& ) ), this, SLOT( slotOpacityInfoChanged( const VolumePropertyInfo& ) ) );
	connect( pRotateWidget, SIGNAL( sigRotateXYZ( int, int, int ) ), this, SLOT( slotRotateXYZ( int, int, int ) ) );
	connect( pRotateWidget, SIGNAL( sigResetPosition() ), this, SLOT( slotResetPosition() ) );
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

	m_pBtnRemove->setEnabled( true );
	return;
}

void VolumeVisualization::slotBtnRemove()
{
	if( m_pVolumeWidget )
		m_pVolumeWidget->RemoveImage();
}

void VolumeVisualization::slotResetPosition()
{
	if( m_pVolumeWidget )
		m_pVolumeWidget->Reset();
}

void VolumeVisualization::slotOpacityInfoChanged( const VolumePropertyInfo& stPropertyInfo )
{
	if( m_pVolumeWidget )
		m_pVolumeWidget->UpdateVolumeProperty( stPropertyInfo );
}

void VolumeVisualization::slotRotateXYZ( int nX, int nY, int nZ )
{
	if( m_pVolumeWidget )
		m_pVolumeWidget->RotateXYZ( nX, nY, nZ );
}
