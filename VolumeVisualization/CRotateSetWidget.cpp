#include "CRotateSetWidget.h"

#include <QLabel>
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
	QLabel* pLbTip = new QLabel( tr( "Rotate:" ) );

	//X¡¢Y¡¢Z
	m_pSpbRotateX = new QSpinBox;
	m_pSpbRotateX->setRange( 0, 360 );
	m_pSpbRotateX->setSingleStep( 1 );
	m_pSpbRotateX->setValue( 0 );
	m_pSpbRotateX->setAlignment( Qt::AlignCenter );
	m_pSpbRotateX->setFixedSize( 70, 28 );

	m_pSpbRotateY = new QSpinBox;
	m_pSpbRotateY->setFixedSize( 70, 28 );
	m_pSpbRotateY->setRange( 0, 360 );
	m_pSpbRotateY->setSingleStep( 1 );
	m_pSpbRotateY->setValue( 0 );
	m_pSpbRotateY->setAlignment( Qt::AlignCenter );
	m_pSpbRotateY->setFixedSize( 70, 28 );

	m_pSpbRotateZ = new QSpinBox;
	m_pSpbRotateZ->setFixedSize( 70, 28 );
	m_pSpbRotateZ->setRange( 0, 360 );
	m_pSpbRotateZ->setSingleStep( 1 );
	m_pSpbRotateZ->setValue( 0 );
	m_pSpbRotateZ->setAlignment( Qt::AlignCenter );
	m_pSpbRotateZ->setFixedSize( 70, 28 );

	//Buttons
	QPushButton* pBtnApply = new QPushButton( tr( "Apply" ) );
	pBtnApply->setFixedSize( 70, 28 );

	QPushButton* pBtnReset = new QPushButton( tr( "Reset" ) );
	pBtnReset->setFixedSize( 70, 28 );

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( pLbTip, 0, 0, 1, 2 );
	pMainLayout->addWidget( new QLabel( tr( "X:" ) ), 1, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbRotateX, 1, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Y:" ) ), 1, 2, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbRotateY, 1, 3 );
	pMainLayout->addWidget( new QLabel( tr( "Z:" ) ), 2, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbRotateZ, 2, 1 );
	pMainLayout->addWidget( pBtnApply, 2, 3 );
	pMainLayout->addWidget( pBtnReset, 3, 1 );
	pMainLayout->setSpacing( 15 );
	pMainLayout->setRowStretch( 3, 1 );
	setLayout( pMainLayout );

	//connects
	connect( pBtnApply, SIGNAL( clicked() ), this, SLOT( slotBtnApply() ) );
	connect( pBtnReset, SIGNAL( clicked() ), this, SIGNAL( sigResetPosition() ) );
}

void CRotateSetWidget::slotBtnApply()
{
	int nX = m_pSpbRotateX->value();
	int nY = m_pSpbRotateY->value();
	int nZ = m_pSpbRotateZ->value();
	emit sigRotateXYZ( nX, nY, nZ );
}