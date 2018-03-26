#include "CVolumePropertySetDlg.h"

#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

#include "CommonDef.h"

CVolumePropertySetDlg::CVolumePropertySetDlg( QWidget *parent )
	: QDialog( parent )
{
	setWindowIcon( QIcon( "./Images/logo.jpg" ) );
	setWindowTitle( tr( "Set Property" ) );
	setFixedSize( 500, 280 );

	InitWidget();
	InitPropertyInfo();
}

CVolumePropertySetDlg::~CVolumePropertySetDlg()
{

}

void CVolumePropertySetDlg::InitWidget()
{
	QSignalMapper* pSignalMapper = new QSignalMapper();
	connect( pSignalMapper, SIGNAL( mapped( const QString& ) ), this, SLOT( slotPropertyChanged( const QString& ) ) );

	//Buttons
	QPushButton* pBtnCT_Default = new QPushButton( "CT_Default" );
	pBtnCT_Default->setFixedHeight( 30 );
	connect( pBtnCT_Default, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnCT_Default, "CT_Default" );

	QPushButton* pBtnCT_Bone1 = new QPushButton( "CT_Bone1" );
	pBtnCT_Bone1->setFixedHeight( 30 );
	connect( pBtnCT_Bone1, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnCT_Bone1, "CT_Bone1" );

	QPushButton* pBtnCT_Bone2 = new QPushButton( "CT_Bone2" );
	pBtnCT_Bone2->setFixedHeight( 30 );
	connect( pBtnCT_Bone2, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnCT_Bone2, "CT_Bone2" );

	//Main Layout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( pBtnCT_Default, 0, 0 );
	pMainLayout->addWidget( pBtnCT_Bone1, 0, 1 );
	pMainLayout->addWidget( pBtnCT_Bone2, 1, 0 );
	setLayout( pMainLayout );
}

void CVolumePropertySetDlg::InitPropertyInfo()
{
	RGBA stRgba;
	//m_stProperty_CT_Default
	m_stProperty_CT_Default.bClamping = true;
	m_stProperty_CT_Default.bShade = true;
	m_stProperty_CT_Default.dAmbient = 0.2;
	m_stProperty_CT_Default.dDiffuse = 0.6;
	m_stProperty_CT_Default.dSpecular = 1;
	m_stProperty_CT_Default.mapOpacity[ -3024 ] = 0.0;
	m_stProperty_CT_Default.mapOpacity[ -16.4458 ] = 0.0;
	m_stProperty_CT_Default.mapOpacity[ 641.385 ] = 0.715686;
	m_stProperty_CT_Default.mapOpacity[ 3071 ] = 0.705882;

	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	stRgba.m_nA = 255;

	m_stProperty_CT_Default.mapColor[ -3024 ] = stRgba;
	stRgba.m_nR = 186;
	stRgba.m_nG = 65;
	stRgba.m_nB = 77;
	m_stProperty_CT_Default.mapColor[ -16.4458 ] = stRgba;

	stRgba.m_nR = 230;
	stRgba.m_nG = 208;
	stRgba.m_nB = 141;
	m_stProperty_CT_Default.mapColor[ 641.385 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_CT_Default.mapColor[ 3071 ] = stRgba;

	m_stProperty_CT_Default.fMax = 3071;
	m_stProperty_CT_Default.fMin = -3024;

	//m_stProperty_CT_Bone1
	m_stProperty_CT_Bone1.bShade = true;
	m_stProperty_CT_Bone1.dAmbient = 0.4;
	m_stProperty_CT_Bone1.dDiffuse = 0.6;
	m_stProperty_CT_Bone1.dSpecular = 0.2;
	m_stProperty_CT_Bone1.fMin = -15591;
	m_stProperty_CT_Bone1.fMax = 32767;
	m_stProperty_CT_Bone1.mapOpacity.clear();
	m_stProperty_CT_Bone1.mapOpacity[ -15591 ] = 0;
	m_stProperty_CT_Bone1.mapOpacity[ 571.1527 ] = 0;
	m_stProperty_CT_Bone1.mapOpacity[ 7190.2893 ] = 0.994444;
	m_stProperty_CT_Bone1.mapOpacity[ 14644.8037 ] = 0;
	m_stProperty_CT_Bone1.mapOpacity[ 32767 ] = 0;

	m_stProperty_CT_Bone1.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 255;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone1.mapColor[ -15591 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone1.mapColor[ 571.1527 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 255;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone1.mapColor[ 7190.2893 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_CT_Bone1.mapColor[ 14644.8037 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 255;
	m_stProperty_CT_Bone1.mapColor[ 32767 ] = stRgba;
	
	//m_stProperty_CT_Bone2
	m_stProperty_CT_Bone2.bShade = true;
	m_stProperty_CT_Bone2.dAmbient = 0.4;
	m_stProperty_CT_Bone2.dDiffuse = 0.6;
	m_stProperty_CT_Bone2.dSpecular = 0.2;
	m_stProperty_CT_Bone2.fMin = -15591;
	m_stProperty_CT_Bone2.fMax = 32767;
	m_stProperty_CT_Bone2.mapOpacity.clear();
	m_stProperty_CT_Bone2.mapOpacity[ -15591 ] = 0;
	m_stProperty_CT_Bone2.mapOpacity[ 4876.7858 ] = 0;
	m_stProperty_CT_Bone2.mapOpacity[ 7961.4381 ] = 1;
	m_stProperty_CT_Bone2.mapOpacity[ 11110.3194 ] = 0;
	m_stProperty_CT_Bone2.mapOpacity[ 32767 ] = 0;

	m_stProperty_CT_Bone2.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 255;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone2.mapColor[ -15591 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone2.mapColor[ 4876.7858 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 255;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone2.mapColor[ 7961.4381 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_CT_Bone2.mapColor[ 11110.3194 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 255;
	m_stProperty_CT_Bone2.mapColor[ 32767 ] = stRgba;
}

void CVolumePropertySetDlg::slotPropertyChanged( const QString& strPropertyName )
{
	if( "CT_Default" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_CT_Default );
	else if( "CT_Bone1" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_CT_Bone1 );
	else if( "CT_Bone2" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_CT_Bone2 );
}