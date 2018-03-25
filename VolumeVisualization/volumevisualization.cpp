#include "volumevisualization.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>

#include "CLoadImageDlg.h"
#include "CVtkVolumeWidget.h"
#include "CVolumePropertySetDlg.h"

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
	if( m_pOpacityDlg )
		m_pOpacityDlg->close();
}

void VolumeVisualization::InitWidget()
{
	//Volume Widget
	m_pVolumeWidget = new CVtkVolumeWidget;

	//Btn
	QPushButton* pBtnLoad = new QPushButton( tr( "Load" ) );
	pBtnLoad->setFixedSize( 80, 30 );

	m_pBtnOpacity = new QPushButton( tr( "Property" ) );
	m_pBtnOpacity->setFixedSize( 80, 30 );
	m_pBtnOpacity->setEnabled( false );
	
	QHBoxLayout* pBtnLayout = new QHBoxLayout;
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( pBtnLoad );
	pBtnLayout->addStretch();
	pBtnLayout->addWidget( m_pBtnOpacity );
	pBtnLayout->addStretch();

	//Opacity Dlg
	m_pOpacityDlg = new CVolumePropertySetDlg;

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( m_pVolumeWidget, 0, 0 );
	pMainLayout->addLayout( pBtnLayout, 1, 0 );
	pMainLayout->setContentsMargins( 15, 15, 15, 15 );
	pMainLayout->setSpacing( 15 );
	setLayout( pMainLayout );
	
	//connects sigOpacityInfo
	connect( pBtnLoad, SIGNAL( clicked() ), this, SLOT( slotBtnLoad() ) );
	connect( m_pBtnOpacity, SIGNAL( clicked() ), this, SLOT( slotBtnOpacity() ) );
	connect( m_pOpacityDlg, SIGNAL( sigPropertyChanged( const VolumePropertyInfo& ) ), this, SLOT( slotOpacityInfoChanged( const VolumePropertyInfo& ) ) );
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

	m_pBtnOpacity->setEnabled( true );
	return;
}

void VolumeVisualization::slotBtnOpacity()
{
	m_pOpacityDlg->show();
}

void VolumeVisualization::slotOpacityInfoChanged( const VolumePropertyInfo& stPropertyInfo )
{
	m_pVolumeWidget->UpdateVolumeProperty( stPropertyInfo );
}