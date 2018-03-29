#include "COpacitySetWidget.h"

#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>

#include "COpacityPresetDlg.h"

COpacitySetWidget::COpacitySetWidget(QWidget *parent)
	: QFrame(parent)
{
	setFrameShape( QFrame::Box );

	m_pOpacityPresetDlg = NULL;

	InitWidget();
}

COpacitySetWidget::~COpacitySetWidget()
{

}

void COpacitySetWidget::InitWidget()
{
	//Tip
	QLabel* pLbTip = new QLabel( tr( "Opacity:" ) );

	/*Set Opacity*/
	//Min
	m_pSpbPixelValueMin = new QSpinBox();
	m_pSpbPixelValueMin->setSingleStep( 1 );
	m_pSpbPixelValueMin->setFixedHeight( 25 );
	m_pBtnMin = new QPushButton;
	m_pBtnMin->setFixedSize( 45, 25 );
	QSlider* pSliderMin = new QSlider( Qt::Horizontal );
	pSliderMin->setSingleStep( 1 );
	pSliderMin->setRange( 0, 255 );
	pSliderMin->setValue( 255 );
	pSliderMin->setFixedWidth( 80 );

	//Lower
	m_pSpbPixelValueLower = new QSpinBox();
	m_pSpbPixelValueLower->setSingleStep( 1 );
	m_pSpbPixelValueLower->setFixedHeight( 25 );
	m_pBtnLower = new QPushButton;
	m_pBtnLower->setFixedSize( 45, 25 );

	QSlider* pSliderLower = new QSlider( Qt::Horizontal );
	pSliderLower->setSingleStep( 1 );
	pSliderLower->setRange( 0, 255 );
	pSliderLower->setValue( 255 );
	pSliderLower->setFixedWidth( 80 );

	//Medium
	m_pSpbPixelValueMedium = new QSpinBox();
	m_pSpbPixelValueMedium->setSingleStep( 1 );
	m_pSpbPixelValueMedium->setFixedHeight( 25 );
	m_pBtnMedium = new QPushButton;
	m_pBtnMedium->setFixedSize( 45, 25 );
	QSlider* pSliderMedium = new QSlider( Qt::Horizontal );
	pSliderMedium->setSingleStep( 1 );
	pSliderMedium->setRange( 0, 255 );
	pSliderMedium->setValue( 255 );
	pSliderMedium->setFixedWidth( 80 );

	//Upper
	m_pSpbPixelValueUpper = new QSpinBox();
	m_pSpbPixelValueUpper->setSingleStep( 1 );
	m_pSpbPixelValueUpper->setFixedHeight( 25 );
	m_pBtnUpper = new QPushButton;
	m_pBtnUpper->setFixedSize( 45, 25 );
	QSlider* pSliderUpper = new QSlider( Qt::Horizontal );
	pSliderUpper->setSingleStep( 1 );
	pSliderUpper->setRange( 0, 255 );
	pSliderUpper->setValue( 255 );
	pSliderUpper->setFixedWidth( 80 );

	//Max
	m_pSpbPixelValueMax = new QSpinBox();
	m_pSpbPixelValueMax->setSingleStep( 1 );
	m_pSpbPixelValueMax->setFixedHeight( 25 );
	m_pBtnMax = new QPushButton;
	m_pBtnMax->setFixedSize( 45, 25 );
	QSlider* pSliderMax = new QSlider( Qt::Horizontal );
	pSliderMax->setSingleStep( 1 );
	pSliderMax->setRange( 0, 255 );
	pSliderMax->setValue( 255 );
	pSliderMax->setFixedWidth( 80 );

	//Preset
	m_pBtnOpacity = new QPushButton( tr( "Preset" ) );
	m_pBtnOpacity->setFixedSize( 80, 30 );

	m_pOpacityPresetDlg = new COpacityPresetDlg;

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( pLbTip, 0, 0 );
	
	pMainLayout->addWidget( new QLabel( tr( "Min:" ) ), 1, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueMin, 1, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 1, 2 );
	pMainLayout->addWidget( m_pBtnMin, 1, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 2, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderMin, 2, 1 );

	pMainLayout->addWidget( new QLabel( tr( "Lower:" ) ), 3, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueLower, 3, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 3, 2 );
	pMainLayout->addWidget( m_pBtnLower, 3, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 4, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderLower, 4, 1 );

	pMainLayout->addWidget( new QLabel( tr( "Medium:" ) ), 5, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueMedium, 5, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 5, 2 );
	pMainLayout->addWidget( m_pBtnMedium, 5, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 6, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderMedium, 6, 1 );

	pMainLayout->addWidget( new QLabel( tr( "Upper:" ) ), 7, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueUpper, 7, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 7, 2 );
	pMainLayout->addWidget( m_pBtnUpper, 7, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 8, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderUpper, 8, 1 );

	pMainLayout->addWidget( new QLabel( tr( "Max:" ) ), 9, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueMax, 9, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 9, 2 );
	pMainLayout->addWidget( m_pBtnMax, 9, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 10, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderMax, 10, 1 );

	pMainLayout->addWidget( m_pBtnOpacity, 11, 1 );
	pMainLayout->setSpacing( 15 );
	pMainLayout->setRowStretch( 12, 1 );
	setLayout( pMainLayout );

	//connects
	connect( m_pBtnOpacity, SIGNAL( clicked() ), this, SLOT( slotBtnOpacity() ) );
	connect( m_pOpacityPresetDlg, SIGNAL( sigOpacityChanged( const VolumePropertyInfo& ) ), this, SIGNAL( sigOpacityChanged( const VolumePropertyInfo& ) ) );
}

void COpacitySetWidget::slotBtnOpacity()
{
	if( m_pOpacityPresetDlg )
		m_pOpacityPresetDlg->show();
}