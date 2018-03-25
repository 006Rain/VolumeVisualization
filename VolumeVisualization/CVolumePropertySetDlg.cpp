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
	QPushButton* pBtnCT_AAA = new QPushButton( "CT-AAA" );
	pBtnCT_AAA->setFixedHeight( 30 );
	connect( pBtnCT_AAA, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnCT_AAA, "CT-AAA" );

	QPushButton* pBtnCT_Bone = new QPushButton( "CT-Bone" );
	pBtnCT_Bone->setFixedHeight( 30 );
	connect( pBtnCT_Bone, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnCT_Bone, "CT-Bone" );
	
	QPushButton* pBtnCT_Muscle = new QPushButton( "CT-Muscle" );
	pBtnCT_Muscle->setFixedHeight( 30 );
	connect( pBtnCT_Muscle, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnCT_Muscle, "CT-Muscle" );
	
	QPushButton* pBtnMR_MIP = new QPushButton( "MR-MIP" );
	pBtnMR_MIP->setFixedHeight( 30 );
	connect( pBtnMR_MIP, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnMR_MIP, "MR-MIP" );

	QPushButton* pBtnMR_T2_Brain = new QPushButton( "MR-T2-Brain" );
	pBtnMR_T2_Brain->setFixedHeight( 30 );
	connect( pBtnMR_T2_Brain, SIGNAL( clicked() ), pSignalMapper, SLOT( map() ) );
	pSignalMapper->setMapping( pBtnMR_T2_Brain, "MR-T2-Brain" );

	//Main Layout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( pBtnCT_AAA, 0, 0 );
	pMainLayout->addWidget( pBtnCT_Bone, 0, 1 );
	pMainLayout->addWidget( pBtnCT_Muscle, 1, 0 );
	pMainLayout->addWidget( pBtnMR_MIP, 1, 1 );
	pMainLayout->addWidget( pBtnMR_T2_Brain, 2, 0 );
	setLayout( pMainLayout );
}

void CVolumePropertySetDlg::InitPropertyInfo()
{
	RGBA stRgba;
	//m_stProperty_CT_AAA
	m_stProperty_CT_AAA.dAmbient = 0.1;
	m_stProperty_CT_AAA.dDiffuse = 0.9;
	m_stProperty_CT_AAA.dSpecular = 0.2;
	m_stProperty_CT_AAA.fMin = -3024;
	m_stProperty_CT_AAA.fMax = 3071;
	m_stProperty_CT_AAA.mapOpacity.clear();
	m_stProperty_CT_AAA.mapOpacity[ -3024 ] = 0;
	m_stProperty_CT_AAA.mapOpacity[ 143.556 ] = 0;
	m_stProperty_CT_AAA.mapOpacity[ 166.222 ] = 0.686275;
	m_stProperty_CT_AAA.mapOpacity[ 214.389 ] = 0.696078;
	m_stProperty_CT_AAA.mapOpacity[ 419.736 ] = 0.833333;
	m_stProperty_CT_AAA.mapOpacity[ 3071 ] = 0.803922;

	m_stProperty_CT_AAA.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	m_stProperty_CT_AAA.mapColor[ -3024 ] = stRgba;

	stRgba.m_nR = 157;
	stRgba.m_nG = 91;
	stRgba.m_nB = 47;
	m_stProperty_CT_AAA.mapColor[ 143.556 ] = stRgba;

	stRgba.m_nR = 225;
	stRgba.m_nG = 154;
	stRgba.m_nB = 74;
	m_stProperty_CT_AAA.mapColor[ 166.222 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_CT_AAA.mapColor[ 214.389 ] = stRgba;

	stRgba.m_nR = 239;
	stRgba.m_nG = 243;
	stRgba.m_nB = 255;
	m_stProperty_CT_AAA.mapColor[ 419.736 ] = stRgba;

	stRgba.m_nR = 211;
	stRgba.m_nG = 168;
	stRgba.m_nB = 255;
	m_stProperty_CT_AAA.mapColor[ 3071 ] = stRgba;

	//m_stProperty_CT_Bone
	m_stProperty_CT_Bone.dAmbient = 0.1;
	m_stProperty_CT_Bone.dDiffuse = 0.9;
	m_stProperty_CT_Bone.dSpecular = 0.2;
	m_stProperty_CT_Bone.fMin = -3024;
	m_stProperty_CT_Bone.fMax = 3071;
	m_stProperty_CT_Bone.mapOpacity.clear();
	m_stProperty_CT_Bone.mapOpacity[ -3024 ] = 0;
	m_stProperty_CT_Bone.mapOpacity[ - 16.4458 ] = 0;
	m_stProperty_CT_Bone.mapOpacity[ 641.385 ] = 0.715686;
	m_stProperty_CT_Bone.mapOpacity[ 3071 ] = 0.705882;

	m_stProperty_CT_Bone.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	m_stProperty_CT_Bone.mapColor[ -3024 ] = stRgba;

	stRgba.m_nR = 186;
	stRgba.m_nG = 65;
	stRgba.m_nB = 77;
	m_stProperty_CT_Bone.mapColor[ -16.4458 ] = stRgba;

	stRgba.m_nR = 230;
	stRgba.m_nG = 208;
	stRgba.m_nB = 141;
	m_stProperty_CT_Bone.mapColor[ 641.385 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_CT_Bone.mapColor[ 3071 ] = stRgba;
	
	//m_stProperty_CT_Muscle
	m_stProperty_CT_Muscle.dAmbient = 0.1;
	m_stProperty_CT_Muscle.dDiffuse = 0.9;
	m_stProperty_CT_Muscle.dSpecular = 0.2;
	m_stProperty_CT_Muscle.fMin = -3024;
	m_stProperty_CT_Muscle.fMax = 3071;
	m_stProperty_CT_Muscle.mapOpacity.clear();
	m_stProperty_CT_Muscle.mapOpacity[ -3024 ] = 0;
	m_stProperty_CT_Muscle.mapOpacity[ -155.407 ] = 0;
	m_stProperty_CT_Muscle.mapOpacity[ 217.641 ] = 0.676471;
	m_stProperty_CT_Muscle.mapOpacity[ 419.736 ] = 0.833333;
	m_stProperty_CT_Muscle.mapOpacity[ 3071 ] = 0.803922;

	m_stProperty_CT_Muscle.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	m_stProperty_CT_Muscle.mapColor[ -3024 ] = stRgba;

	stRgba.m_nR = 140;
	stRgba.m_nG = 64;
	stRgba.m_nB = 38;
	m_stProperty_CT_Muscle.mapColor[ -155.407 ] = stRgba;

	stRgba.m_nR = 225;
	stRgba.m_nG = 154;
	stRgba.m_nB = 74;
	m_stProperty_CT_Muscle.mapColor[ 217.641 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 239;
	stRgba.m_nB = 243;
	m_stProperty_CT_Muscle.mapColor[ 419.736 ] = stRgba;

	stRgba.m_nR = 211;
	stRgba.m_nG = 168;
	stRgba.m_nB = 255;
	m_stProperty_CT_Muscle.mapColor[ 3071 ] = stRgba;
	
	//m_stProperty_MR_MIP
	m_stProperty_MR_MIP.bShade = false;
	m_stProperty_MR_MIP.dAmbient = 0.2;
	m_stProperty_MR_MIP.dDiffuse = 1;
	m_stProperty_MR_MIP.dSpecular = 0;
	m_stProperty_MR_MIP.fMin = 0;
	m_stProperty_MR_MIP.fMax = 2800;
	m_stProperty_MR_MIP.mapOpacity.clear();
	m_stProperty_MR_MIP.mapOpacity[ 0 ] = 0;
	m_stProperty_MR_MIP.mapOpacity[ 98.3725 ] = 0;
	m_stProperty_MR_MIP.mapOpacity[ 416.637 ] = 1;
	m_stProperty_MR_MIP.mapOpacity[ 2800 ] = 1;

	m_stProperty_MR_MIP.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_MR_MIP.mapColor[ 0 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_MR_MIP.mapColor[ 98.3725 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_MR_MIP.mapColor[ 416.637 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_MR_MIP.mapColor[ 2800 ] = stRgba;
	
	//m_stProperty_MR_T2_Brain
	m_stProperty_MR_T2_Brain.bShade = true;
	m_stProperty_MR_T2_Brain.dAmbient = 0.3;
	m_stProperty_MR_T2_Brain.dDiffuse = 6;
	m_stProperty_MR_T2_Brain.dSpecular = 0.5;
	m_stProperty_MR_T2_Brain.fMin = 0;
	m_stProperty_MR_T2_Brain.fMax = 641;
	m_stProperty_MR_T2_Brain.mapOpacity.clear();
	m_stProperty_MR_T2_Brain.mapOpacity[ 0 ] = 0;
	m_stProperty_MR_T2_Brain.mapOpacity[ 36.05 ] = 0;
	m_stProperty_MR_T2_Brain.mapOpacity[ 218.302 ] = 1;
	m_stProperty_MR_T2_Brain.mapOpacity[ 641 ] = 1;

	m_stProperty_MR_T2_Brain.mapColor.clear();
	stRgba.m_nA = 255;
	stRgba.m_nR = 0;
	stRgba.m_nG = 0;
	stRgba.m_nB = 0;
	m_stProperty_MR_T2_Brain.mapColor[ 0 ] = stRgba;

	stRgba.m_nR = 244;
	stRgba.m_nG = 214;
	stRgba.m_nB = 49;
	m_stProperty_MR_T2_Brain.mapColor[ 98.7223 ] = stRgba;

	stRgba.m_nR = 0;
	stRgba.m_nG = 151;
	stRgba.m_nB = 206;
	m_stProperty_MR_T2_Brain.mapColor[ 412.406 ] = stRgba;

	stRgba.m_nR = 255;
	stRgba.m_nG = 255;
	stRgba.m_nB = 255;
	m_stProperty_MR_T2_Brain.mapColor[ 641 ] = stRgba;
}

void CVolumePropertySetDlg::slotPropertyChanged( const QString& strPropertyName )
{
	if( "CT-AAA" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_CT_AAA );
	else if( "CT-Bone" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_CT_Bone );
	else if( "CT-Muscle" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_CT_Muscle );
	else if( "MR-MIP" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_MR_MIP );
	else if( "MR-T2-Brain" == strPropertyName )
		emit sigPropertyChanged( m_stProperty_MR_T2_Brain );
}