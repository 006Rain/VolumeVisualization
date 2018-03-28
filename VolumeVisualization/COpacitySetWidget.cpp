#include "COpacitySetWidget.h"

#include <QLabel>
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

	//Preset
	m_pBtnOpacity = new QPushButton( tr( "Preset" ) );
	m_pBtnOpacity->setFixedSize( 80, 30 );

	m_pOpacityPresetDlg = new COpacityPresetDlg;

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( pLbTip, 0, 0 );
	//pMainLayout->addWidget( new QLabel( tr( "X:" ) ), 1, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pBtnOpacity, 1, 0 );
	pMainLayout->setSpacing( 15 );
	pMainLayout->setRowStretch( 3, 1 );
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