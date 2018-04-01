#include "COpacitySetWidget.h"

#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QColorDialog>

#include "COpacityPresetDlg.h"
#include "CommonDef.h"

COpacitySetWidget::COpacitySetWidget( QWidget *parent )
	: QFrame( parent )
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
	m_pSpbPixelValueMin = new QDoubleSpinBox();
	m_pSpbPixelValueMin->setSingleStep( 0.5 );
	m_pSpbPixelValueMin->setRange( -65535, 65535 );
	m_pSpbPixelValueMin->setFixedHeight( 25 );
	m_pBtnMin = new QPushButton;
	m_pBtnMin->setFixedSize( 45, 25 );

	m_pSliderMin = new QSlider( Qt::Horizontal );
	m_pSliderMin->setSingleStep( 1 );
	m_pSliderMin->setRange( 0, 255 );
	m_pSliderMin->setValue( 255 );
	m_pSliderMin->setFixedWidth( 80 );
	QSpinBox* pSpbAlphaMin = new QSpinBox;
	pSpbAlphaMin->setRange( 0, 255 );
	pSpbAlphaMin->setSingleStep( 1 );
	pSpbAlphaMin->setValue( 255 );

	//Lower
	m_pSpbPixelValueLower = new QDoubleSpinBox();
	m_pSpbPixelValueLower->setSingleStep( 0.5 );
	m_pSpbPixelValueLower->setRange( -65535, 65535 );
	m_pSpbPixelValueLower->setFixedHeight( 25 );
	m_pBtnLower = new QPushButton;
	m_pBtnLower->setFixedSize( 45, 25 );

	m_pSliderLower = new QSlider( Qt::Horizontal );
	m_pSliderLower->setSingleStep( 1 );
	m_pSliderLower->setRange( 0, 255 );
	m_pSliderLower->setValue( 255 );
	m_pSliderLower->setFixedWidth( 80 );
	QSpinBox* pSpbAlphaLower = new QSpinBox;
	pSpbAlphaLower->setRange( 0, 255 );
	pSpbAlphaLower->setSingleStep( 1 );
	pSpbAlphaLower->setValue( 255 );

	//Medium
	m_pSpbPixelValueMedium = new QDoubleSpinBox();
	m_pSpbPixelValueMedium->setSingleStep( 0.5 );
	m_pSpbPixelValueMedium->setRange( -65535, 65535 );
	m_pSpbPixelValueMedium->setFixedHeight( 25 );
	m_pBtnMedium = new QPushButton;
	m_pBtnMedium->setFixedSize( 45, 25 );
	
	m_pSliderMedium = new QSlider( Qt::Horizontal );
	m_pSliderMedium->setSingleStep( 1 );
	m_pSliderMedium->setRange( 0, 255 );
	m_pSliderMedium->setValue( 255 );
	m_pSliderMedium->setFixedWidth( 80 );
	QSpinBox* pSpbAlphaMedium = new QSpinBox;
	pSpbAlphaMedium->setRange( 0, 255 );
	pSpbAlphaMedium->setSingleStep( 1 );
	pSpbAlphaMedium->setValue( 255 );

	//Upper
	m_pSpbPixelValueUpper = new QDoubleSpinBox();
	m_pSpbPixelValueUpper->setSingleStep( 0.5 );
	m_pSpbPixelValueUpper->setRange( -65535, 65535 );
	m_pSpbPixelValueUpper->setFixedHeight( 25 );
	m_pBtnUpper = new QPushButton;
	m_pBtnUpper->setFixedSize( 45, 25 );
	
	m_pSliderUpper = new QSlider( Qt::Horizontal );
	m_pSliderUpper->setSingleStep( 1 );
	m_pSliderUpper->setRange( 0, 255 );
	m_pSliderUpper->setValue( 255 );
	m_pSliderUpper->setFixedWidth( 80 );
	QSpinBox* pSpbAlphaUpper = new QSpinBox;
	pSpbAlphaUpper->setRange( 0, 255 );
	pSpbAlphaUpper->setSingleStep( 1 );
	pSpbAlphaUpper->setValue( 255 );

	//Max
	m_pSpbPixelValueMax = new QDoubleSpinBox();
	m_pSpbPixelValueMax->setSingleStep( 0.5 );
	m_pSpbPixelValueMax->setRange( -65535, 65535 );
	m_pSpbPixelValueMax->setFixedHeight( 25 );
	m_pBtnMax = new QPushButton;
	m_pBtnMax->setFixedSize( 45, 25 );
	
	m_pSliderMax = new QSlider( Qt::Horizontal );
	m_pSliderMax->setSingleStep( 1 );
	m_pSliderMax->setRange( 0, 255 );
	m_pSliderMax->setValue( 255 );
	m_pSliderMax->setFixedWidth( 80 );
	QSpinBox* pSpbAlphaMax = new QSpinBox;
	pSpbAlphaMax->setRange( 0, 255 );
	pSpbAlphaMax->setSingleStep( 1 );
	pSpbAlphaMax->setValue( 255 );

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
	pMainLayout->addWidget( m_pSliderMin, 2, 1 );
	pMainLayout->addWidget( pSpbAlphaMin, 2, 2 );

	pMainLayout->addWidget( new QLabel( tr( "Lower:" ) ), 3, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueLower, 3, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 3, 2 );
	pMainLayout->addWidget( m_pBtnLower, 3, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 4, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSliderLower, 4, 1 );
	pMainLayout->addWidget( pSpbAlphaLower, 4, 2 );

	pMainLayout->addWidget( new QLabel( tr( "Medium:" ) ), 5, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueMedium, 5, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 5, 2 );
	pMainLayout->addWidget( m_pBtnMedium, 5, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 6, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSliderMedium, 6, 1 );
	pMainLayout->addWidget( pSpbAlphaMedium, 6, 2 );

	pMainLayout->addWidget( new QLabel( tr( "Upper:" ) ), 7, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueUpper, 7, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 7, 2 );
	pMainLayout->addWidget( m_pBtnUpper, 7, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 8, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSliderUpper, 8, 1 );
	pMainLayout->addWidget( pSpbAlphaUpper, 8, 2 );

	pMainLayout->addWidget( new QLabel( tr( "Max:" ) ), 9, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelValueMax, 9, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Color:" ) ), 9, 2 );
	pMainLayout->addWidget( m_pBtnMax, 9, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Alpha:" ) ), 10, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSliderMax, 10, 1 );
	pMainLayout->addWidget( pSpbAlphaMax, 10, 2 );

	pMainLayout->addWidget( m_pBtnOpacity, 11, 1 );
	pMainLayout->setSpacing( 15 );
	pMainLayout->setRowStretch( 12, 1 );
	setLayout( pMainLayout );

	//connects
	connect( m_pBtnOpacity, SIGNAL( clicked() ), this, SLOT( slotBtnOpacity() ) );
	connect( m_pOpacityPresetDlg, SIGNAL( sigOpacityChanged( const VolumePropertyInfo& ) ), this, SIGNAL( sigOpacityChanged( const VolumePropertyInfo& ) ) );

	connect( m_pBtnMin, SIGNAL( clicked() ), this, SLOT( slotBtnMin() ) );
	connect( m_pBtnLower, SIGNAL( clicked() ), this, SLOT( slotBtnLower() ) );
	connect( m_pBtnMedium, SIGNAL( clicked() ), this, SLOT( slotBtnMedium() ) );
	connect( m_pBtnUpper, SIGNAL( clicked() ), this, SLOT( slotBtnUpper() ) );
	connect( m_pBtnMax, SIGNAL( clicked() ), this, SLOT( slotBtnMax() ) );

	connect( m_pSpbPixelValueMin, SIGNAL( valueChanged( double ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderMin, SIGNAL( valueChanged( int ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderMin, SIGNAL( valueChanged( int ) ), pSpbAlphaMin, SLOT( setValue( int ) ) );
	connect( pSpbAlphaMin, SIGNAL( valueChanged( int ) ), m_pSliderMin, SLOT( setValue( int ) ) );
	
	connect( m_pSpbPixelValueLower, SIGNAL( valueChanged( double ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderLower, SIGNAL( valueChanged( int ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderLower, SIGNAL( valueChanged( int ) ), pSpbAlphaLower, SLOT( setValue( int ) ) );
	connect( pSpbAlphaLower, SIGNAL( valueChanged( int ) ), m_pSliderLower, SLOT( setValue( int ) ) );

	connect( m_pSpbPixelValueMedium, SIGNAL( valueChanged( double ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderMedium, SIGNAL( valueChanged( int ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderMedium, SIGNAL( valueChanged( int ) ), pSpbAlphaMedium, SLOT( setValue( int ) ) );
	connect( pSpbAlphaMedium, SIGNAL( valueChanged( int ) ), m_pSliderMedium, SLOT( setValue( int ) ) );

	connect( m_pSpbPixelValueUpper, SIGNAL( valueChanged( double ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderUpper, SIGNAL( valueChanged( int ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderUpper, SIGNAL( valueChanged( int ) ), pSpbAlphaUpper, SLOT( setValue( int ) ) );
	connect( pSpbAlphaUpper, SIGNAL( valueChanged( int ) ), m_pSliderUpper, SLOT( setValue( int ) ) );

	connect( m_pSpbPixelValueMax, SIGNAL( valueChanged( double ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderMax, SIGNAL( valueChanged( int ) ), this, SLOT( slotOpacityChanged() ) );
	connect( m_pSliderMax, SIGNAL( valueChanged( int ) ), pSpbAlphaMax, SLOT( setValue( int ) ) );
	connect( pSpbAlphaMax, SIGNAL( valueChanged( int ) ), m_pSliderMax, SLOT( setValue( int ) ) );
}

void COpacitySetWidget::SetPixelValueRange( const float& fMin, const float& fMax )
{
	float fLower = fMin + ( fMax - fMin ) * 0.25;
	float fMedium = fMin + (fMax - fMin) * 0.5;
	float fUpper = fMin + (fMax - fMin) * 0.75;

	m_pSpbPixelValueMin->setValue( fMin );
	m_pSpbPixelValueLower->setValue( fLower );
	m_pSpbPixelValueMedium->setValue( fMedium );
	m_pSpbPixelValueUpper->setValue( fUpper );
	m_pSpbPixelValueMax->setValue( fMax );

	QPalette palleteMin = m_pBtnMin->palette();
	m_pBtnMin->setAutoFillBackground( true );
	palleteMin.setBrush( QPalette::Button, QBrush( Qt::yellow ) );
	m_pBtnMin->setPalette( palleteMin );
	m_pBtnMin->setFlat( true );

	QPalette palleteLower = m_pBtnLower->palette();
	m_pBtnLower->setAutoFillBackground( true );
	palleteLower.setColor( QPalette::Button, Qt::red );
	m_pBtnLower->setPalette( palleteLower );
	m_pBtnLower->setFlat( true );

	QPalette palleteMedium = m_pBtnMedium->palette();
	m_pBtnMedium->setAutoFillBackground( true );
	palleteMedium.setColor( QPalette::Button, Qt::green );
	m_pBtnMedium->setPalette( palleteMedium );
	m_pBtnMedium->setFlat( true );

	QPalette palleteUpper = m_pBtnUpper->palette();
	m_pBtnUpper->setAutoFillBackground( true );
	palleteUpper.setColor( QPalette::Button, Qt::blue );
	m_pBtnUpper->setPalette( palleteUpper );
	m_pBtnUpper->setFlat( true );

	QPalette palleteMax = m_pBtnMax->palette();
	m_pBtnMax->setAutoFillBackground( true );
	palleteMax.setColor( QPalette::Button, Qt::black );
	m_pBtnMax->setPalette( palleteMax );
	m_pBtnMax->setFlat( true );
}

void COpacitySetWidget::slotBtnOpacity()
{
	if( m_pOpacityPresetDlg )
		m_pOpacityPresetDlg->show();
}

void COpacitySetWidget::slotOpacityChanged()
{
	VolumePropertyInfo stInfo;
	
	float fValueMin = m_pSpbPixelValueMin->value();
	float fValueLower = m_pSpbPixelValueLower->value();
	float fValueMedium = m_pSpbPixelValueMedium->value();
	float fValueUpper = m_pSpbPixelValueUpper->value();
	float fValueMax = m_pSpbPixelValueMax->value();

	QColor colorMin = m_pBtnMin->palette().color( QPalette::Button );
	QColor colorLower = m_pBtnLower->palette().color( QPalette::Button );
	QColor colorMedium = m_pBtnMedium->palette().color( QPalette::Button );
	QColor colorUpper = m_pBtnUpper->palette().color( QPalette::Button );
	QColor colorMax = m_pBtnMax->palette().color( QPalette::Button );

	//test begin
	int nRed = colorMin.red();
	int nGreen = colorMin.red();
	int nBlue = colorMin.red();
	//test end

	float fAlphaMin = m_pSliderMin->value() / 255.0;
	float fAlphaLower = m_pSliderLower->value() / 255.0;
	float fAlphaMedium = m_pSliderMedium->value() / 255.0;
	float fAlphaUpper = m_pSliderUpper->value() / 255.0;
	float fAlphaMax = m_pSliderMax->value() / 255.0;

	stInfo.fMin = fValueMin;
	stInfo.fMax = fValueMax;

	stInfo.mapColor[ fValueMin ] = RGBA( colorMin.red(), colorMin.green(), colorMin.blue(), 255 );
	stInfo.mapColor[ fValueLower ] = RGBA( colorLower.red(), colorLower.green(), colorLower.blue(), 255 );
	stInfo.mapColor[ fValueMedium ] = RGBA( colorMedium.red(), colorMedium.green(), colorMedium.blue(), 255 );
	stInfo.mapColor[ fValueUpper ] = RGBA( colorUpper.red(), colorUpper.green(), colorUpper.blue(), 255 );
	stInfo.mapColor[ fValueMax ] = RGBA( colorMax.red(), colorMax.green(), colorMax.blue(), 255 );

	stInfo.mapOpacity[ fValueMin ] = fAlphaMin;
	stInfo.mapOpacity[ fValueLower ] = fAlphaLower;
	stInfo.mapOpacity[ fValueMedium ] = fAlphaMedium;
	stInfo.mapOpacity[ fValueUpper ] = fAlphaUpper;
	stInfo.mapOpacity[ fValueMax ] = fAlphaMax;

	emit sigOpacityChanged( stInfo );
}

void COpacitySetWidget::slotBtnMin()
{
	QColor color = QColorDialog::getColor();
	QPalette paletteBtn = m_pBtnMin->palette();
	paletteBtn.setColor( QPalette::Button, QColor( color ) );
	m_pBtnMin->setPalette( paletteBtn );

	slotOpacityChanged();
}

void COpacitySetWidget::slotBtnLower()
{
	QColor color = QColorDialog::getColor();
	QPalette paletteBtn = m_pBtnLower->palette();
	paletteBtn.setColor( QPalette::Button, QColor( color ) );
	m_pBtnLower->setPalette( paletteBtn );

	slotOpacityChanged();
}

void COpacitySetWidget::slotBtnMedium()
{
	QColor color = QColorDialog::getColor();
	QPalette paletteBtn = m_pBtnMedium->palette();
	paletteBtn.setColor( QPalette::Button, QColor( color ) );
	m_pBtnMedium->setPalette( paletteBtn );

	slotOpacityChanged();
}

void COpacitySetWidget::slotBtnUpper()
{
	QColor color = QColorDialog::getColor();
	QPalette paletteBtn = m_pBtnUpper->palette();
	paletteBtn.setColor( QPalette::Button, QColor( color ) );
	m_pBtnUpper->setPalette( paletteBtn );

	slotOpacityChanged();
}

void COpacitySetWidget::slotBtnMax()
{
	QColor color = QColorDialog::getColor();
	QPalette paletteBtn = m_pBtnMax->palette();
	paletteBtn.setColor( QPalette::Button, QColor( color ) );
	m_pBtnMax->setPalette( paletteBtn );

	slotOpacityChanged();
}