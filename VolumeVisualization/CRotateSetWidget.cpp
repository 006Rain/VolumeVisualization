#include "CRotateSetWidget.h"

#include <QLabel>
#include <QRadioButton>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>

CRotateSetWidget::CRotateSetWidget( QWidget *parent )
	: QFrame( parent )
{
	setFrameShape( QFrame::Box );

	InitWidget();
}

CRotateSetWidget::~CRotateSetWidget()
{

}

void CRotateSetWidget::InitWidget()
{
	//Tip
	QLabel* pLbTip = new QLabel( tr( "Rotate By:" ) );

	//
	m_pRadioBtnVolume = new QRadioButton( "Volume" );
	m_pRadioBtnVolume->setChecked( true );
	m_pRadioBtnCamera = new QRadioButton( "Camera" );

	//X¡¢Y¡¢Z
	m_pSpbRotateX = new QSpinBox;
	m_pSpbRotateX->setRange( 0, 360 );
	m_pSpbRotateX->setSingleStep( 1 );
	m_pSpbRotateX->setValue( 0 );
	m_pSpbRotateX->setAlignment( Qt::AlignCenter );
	m_pSpbRotateX->setFixedSize( 70, 28 );
	QPushButton* pBtnX = new QPushButton( "Apply" );

	m_pSpbRotateY = new QSpinBox;
	m_pSpbRotateY->setFixedSize( 70, 28 );
	m_pSpbRotateY->setRange( 0, 360 );
	m_pSpbRotateY->setSingleStep( 1 );
	m_pSpbRotateY->setValue( 0 );
	m_pSpbRotateY->setAlignment( Qt::AlignCenter );
	m_pSpbRotateY->setFixedSize( 70, 28 );
	QPushButton* pBtnY = new QPushButton( "Apply" );

	m_pSpbRotateZ = new QSpinBox;
	m_pSpbRotateZ->setFixedSize( 70, 28 );
	m_pSpbRotateZ->setRange( 0, 360 );
	m_pSpbRotateZ->setSingleStep( 1 );
	m_pSpbRotateZ->setValue( 0 );
	m_pSpbRotateZ->setAlignment( Qt::AlignCenter );
	m_pSpbRotateZ->setFixedSize( 70, 28 );
	QPushButton* pBtnZ = new QPushButton( "Apply" );

	//Buttons
	QPushButton* pBtnApply = new QPushButton( tr( "Apply" ) );
	pBtnApply->setFixedSize( 70, 28 );

	QPushButton* pBtnReset = new QPushButton( tr( "Reset" ) );
	pBtnReset->setFixedSize( 70, 28 );

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( pLbTip, 0, 0 );
	pMainLayout->addWidget( m_pRadioBtnVolume, 0, 1 );
	pMainLayout->addWidget( m_pRadioBtnCamera, 0, 2 );
	pMainLayout->addWidget( new QLabel( tr( "X:" ) ), 1, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbRotateX, 1, 1 );
	pMainLayout->addWidget( pBtnX, 1, 2 );
	pMainLayout->addWidget( new QLabel( tr( "Y:" ) ), 2, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbRotateY, 2, 1 );
	pMainLayout->addWidget( pBtnY, 2, 2 );
	pMainLayout->addWidget( new QLabel( tr( "Z:" ) ), 3, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbRotateZ, 3, 1 );
	pMainLayout->addWidget( pBtnZ, 3, 2 );
	//pMainLayout->addWidget( pBtnApply, 2, 3 );
	//pMainLayout->addWidget( pBtnReset, 3, 1 );
	pMainLayout->setSpacing( 15 );
	pMainLayout->setColumnStretch( 5, 1 );
	pMainLayout->setRowStretch( 5, 1 );
	setLayout( pMainLayout );

	//connects
	connect( pBtnX, SIGNAL( clicked() ), this, SLOT( slotBtnX() ) );
	connect( pBtnY, SIGNAL( clicked() ), this, SLOT( slotBtnY() ) );
	connect( pBtnZ, SIGNAL( clicked() ), this, SLOT( slotBtnZ() ) );
	connect( pBtnReset, SIGNAL( clicked() ), this, SIGNAL( sigResetPosition() ) );
}

void CRotateSetWidget::slotBtnX()
{
	int nX = m_pSpbRotateX->value();
	bool bRotateByVolume = m_pRadioBtnVolume->isChecked();

	emit sigRotateX( nX, bRotateByVolume );
}

void CRotateSetWidget::slotBtnY()
{
	int nY = m_pSpbRotateY->value();
	bool bRotateByVolume = m_pRadioBtnVolume->isChecked();

	emit sigRotateY( nY, bRotateByVolume );
}

void CRotateSetWidget::slotBtnZ()
{
	int nZ = m_pSpbRotateZ->value();
	bool bRotateByVolume = m_pRadioBtnVolume->isChecked();
	
	emit sigRotateZ( nZ, bRotateByVolume );
}