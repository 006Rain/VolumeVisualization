#include "CVolumeOpacitySetDlg.h"

#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSpinBox>

CVolumeOpacitySetDlg::CVolumeOpacitySetDlg( QWidget *parent )
	: QDialog( parent )
{
	setWindowIcon( QIcon( "./Images/logo.jpg" ) );
	setWindowTitle( tr( "Set Opacity" ) );
	setFixedSize( 500, 280 );

	InitWidget();
}

CVolumeOpacitySetDlg::~CVolumeOpacitySetDlg()
{

}

void CVolumeOpacitySetDlg::InitWidget()
{
	//R
	QSlider* pSliderR = new QSlider( Qt::Horizontal );
	pSliderR->setRange( 0, 255 );
	pSliderR->setSingleStep( 1 );
	pSliderR->setFixedHeight( 25 );

	QSpinBox* pSpbR = new QSpinBox;
	pSpbR->setRange( 0, 255 );
	pSpbR->setSingleStep( 1 );
	pSpbR->setFixedHeight( 25 );

	//G
	QSlider* pSliderG = new QSlider( Qt::Horizontal );
	pSliderG->setRange( 0, 255 );
	pSliderG->setSingleStep( 1 );
	pSliderG->setFixedHeight( 25 );

	QSpinBox* pSpbG = new QSpinBox;
	pSpbG->setRange( 0, 255 );
	pSpbG->setSingleStep( 1 );
	pSpbG->setFixedHeight( 25 );

	//B
	QSlider* pSliderB = new QSlider( Qt::Horizontal );
	pSliderB->setRange( 0, 255 );
	pSliderB->setSingleStep( 1 );
	pSliderB->setFixedHeight( 25 );

	QSpinBox* pSpbB = new QSpinBox;
	pSpbB->setRange( 0, 255 );
	pSpbB->setSingleStep( 1 );
	pSpbB->setFixedHeight( 25 );

	//A
	QSlider* pSliderA = new QSlider( Qt::Horizontal );
	pSliderA->setRange( 0, 255 );
	pSliderA->setSingleStep( 1 );
	pSliderA->setFixedHeight( 25 );

	QSpinBox* pSpbA = new QSpinBox;
	pSpbA->setRange( 0, 255 );
	pSpbA->setSingleStep( 1 );
	pSpbA->setFixedHeight( 25 );

	//Main Layout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( new QLabel( tr( "R:" ) ), 0, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderR, 0, 1 );
	pMainLayout->addWidget( pSpbR, 0, 2 );
	pMainLayout->addWidget( new QLabel( tr( "G:" ) ), 1, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderG, 1, 1 );
	pMainLayout->addWidget( pSpbG, 1, 2 );
	pMainLayout->addWidget( new QLabel( tr( "B:" ) ), 2, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderB, 2, 1 );
	pMainLayout->addWidget( pSpbB, 2, 2 );
	pMainLayout->addWidget( new QLabel( tr( "A:" ) ), 3, 0, Qt::AlignRight );
	pMainLayout->addWidget( pSliderA, 3, 1 );
	pMainLayout->addWidget( pSpbA, 3, 2 );

	pMainLayout->setSpacing( 15 );
	setLayout( pMainLayout );

	//connects
	connect( pSliderR, SIGNAL( valueChanged( int ) ), pSpbR, SLOT( setValue( int ) ) );
	connect( pSliderG, SIGNAL( valueChanged( int ) ), pSpbG, SLOT( setValue( int ) ) );
	connect( pSliderB, SIGNAL( valueChanged( int ) ), pSpbB, SLOT( setValue( int ) ) );
	connect( pSliderA, SIGNAL( valueChanged( int ) ), pSpbA, SLOT( setValue( int ) ) );
	connect( pSpbR, SIGNAL( valueChanged( int ) ), pSliderR, SLOT( setValue( int ) ) );
	connect( pSpbG, SIGNAL( valueChanged( int ) ), pSliderG, SLOT( setValue( int ) ) );
	connect( pSpbB, SIGNAL( valueChanged( int ) ), pSliderB, SLOT( setValue( int ) ) );
	connect( pSpbA, SIGNAL( valueChanged( int ) ), pSliderA, SLOT( setValue( int ) ) );
}