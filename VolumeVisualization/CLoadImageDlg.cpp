#include "CLoadImageDlg.h"

#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>

CLoadImageDlg::CLoadImageDlg( QWidget *parent )
	: QDialog( parent )
{
	setWindowIcon( QIcon( "./Images/logo.jpg" ) );
	setWindowTitle( tr( "Load Image" ) );
	setWindowFlags( Qt::WindowCloseButtonHint );
	setFixedSize( 500, 280 );

	InitWidget();
}

CLoadImageDlg::~CLoadImageDlg()
{

}

void CLoadImageDlg::InitWidget()
{
	//Dimens
	m_pEdtDimX = new QLineEdit( "256" );
	m_pEdtDimX->setValidator( new QIntValidator( 1, 4096 ) );
	m_pEdtDimX->setFixedHeight( 25 );
	m_pEdtDimY = new QLineEdit( "256" );
	m_pEdtDimY->setValidator( new QIntValidator( 1, 4096 ) );
	m_pEdtDimY->setFixedHeight( 25 );
	m_pEdtDimZ = new QLineEdit( "256" );
	m_pEdtDimZ->setValidator( new QIntValidator( 1, 4096 ) );
	m_pEdtDimZ->setFixedHeight( 25 );

	//Pixel Size
	m_pSpbPixelX = new QDoubleSpinBox;
	m_pSpbPixelX->setValue( 0.49 );
	m_pSpbPixelX->setRange( 0.05, 5 );
	m_pSpbPixelX->setDecimals( 5 );
	m_pSpbPixelX->setSingleStep( 0.05 );
	m_pSpbPixelX->setFixedHeight( 25 );
	
	m_pSpbPixelY = new QDoubleSpinBox;
	m_pSpbPixelY->setValue( 0.49 );
	m_pSpbPixelY->setRange( 0.05, 5 );
	m_pSpbPixelY->setDecimals( 5 );
	m_pSpbPixelY->setSingleStep( 0.05 );
	m_pSpbPixelY->setFixedHeight( 25 );
	
	m_pSpbPixelZ = new QDoubleSpinBox;
	m_pSpbPixelZ->setValue( 0.49 );
	m_pSpbPixelZ->setRange( 0.05, 5 );
	m_pSpbPixelZ->setDecimals( 5 );
	m_pSpbPixelZ->setSingleStep( 0.05 );
	m_pSpbPixelZ->setFixedHeight( 25 );
	
	//Offset
	m_pEdtOffset = new QLineEdit( "0" );
	m_pEdtOffset->setValidator( new QIntValidator( 0, 8192 ) );
	m_pEdtOffset->setFixedHeight( 25 );
	
	//Image Data Type
	m_pCmbDataType = new QComboBox;
	m_pCmbDataType->addItem( "Char" );
	m_pCmbDataType->addItem( "Short" );
	m_pCmbDataType->addItem( "Float" );
	//m_pCmbDataType->setCurrentIndex( 1 );
	m_pCmbDataType->setFixedHeight( 25 );

	//File Path
	m_pEdtFilePath = new QLineEdit;
	m_pEdtFilePath->isReadOnly();
	QPushButton* pBtnBroswer = new QPushButton( tr( "Broswer..." ) );
	pBtnBroswer->setFixedHeight( 25 );

	//Btn
	QPushButton* pBtnOk = new QPushButton( tr( "Ok" ) );
	pBtnOk->setFixedSize( 80, 30 );
	QPushButton* pBtnCancel = new QPushButton( tr( "Cancel" ) );
	pBtnCancel->setFixedSize( 80, 30 );

	QHBoxLayout* pBtnLayout = new QHBoxLayout;
	pBtnLayout->addStretch( 10 );
	pBtnLayout->addWidget( pBtnOk );
	pBtnLayout->addWidget( pBtnCancel );
	pBtnLayout->addStretch( 1 );
	pBtnLayout->setContentsMargins( 0, 0, 0, 0 );

	//MainLayout
	QGridLayout* pMainLayout = new QGridLayout;
	pMainLayout->addWidget( new QLabel( tr( "DimX" ) ), 0, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pEdtDimX, 0, 1 );
	pMainLayout->addWidget( new QLabel( tr( "PixelX" ) ), 0, 2, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelX, 0, 3 );
	pMainLayout->addWidget( new QLabel( "mm" ), 0, 4 );

	pMainLayout->addWidget( new QLabel( tr( "DimY" ) ), 1, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pEdtDimY, 1, 1 );
	pMainLayout->addWidget( new QLabel( tr( "PixelY" ) ), 1, 2, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelY, 1, 3 );
	pMainLayout->addWidget( new QLabel( "mm" ), 1, 4 );

	pMainLayout->addWidget( new QLabel( tr( "DimZ" ) ), 2, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pEdtDimZ, 2, 1 );
	pMainLayout->addWidget( new QLabel( tr( "PixelZ" ) ), 2, 2, Qt::AlignRight );
	pMainLayout->addWidget( m_pSpbPixelZ, 2, 3 );
	pMainLayout->addWidget( new QLabel( "mm" ), 2, 4 );
	
	pMainLayout->addWidget( new QLabel( tr( "Offset" ) ), 3, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pEdtOffset, 3, 1 );
	pMainLayout->addWidget( new QLabel( tr( "Data Type" ) ), 3, 2, Qt::AlignRight );
	pMainLayout->addWidget( m_pCmbDataType, 3, 3 );

	pMainLayout->addWidget( new QLabel( tr( "File Path:" ) ), 4, 0, Qt::AlignRight );
	pMainLayout->addWidget( m_pEdtFilePath, 4, 1, 1, 2 );
	pMainLayout->addWidget( pBtnBroswer, 4, 3 );

	pMainLayout->addLayout( pBtnLayout, 5, 0, 1, 5 );

	pMainLayout->setColumnStretch( 1, 1 );
	pMainLayout->setColumnStretch( 3, 1 );
	setLayout( pMainLayout );

	//connects
	connect( pBtnBroswer, SIGNAL( clicked() ), this, SLOT( slotBtnBroswer() ) );
	connect( pBtnOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
	connect( pBtnCancel, SIGNAL( clicked() ), this, SLOT( close() ) );
}

void CLoadImageDlg::GetImageParam( ImageParams& stImgParam )
{
	stImgParam.nDimX = m_pEdtDimX->text().toInt();
	stImgParam.nDimY = m_pEdtDimY->text().toInt();
	stImgParam.nDimZ = m_pEdtDimZ->text().toInt();

	stImgParam.dPixelX = m_pSpbPixelX->value();
	stImgParam.dPixelY = m_pSpbPixelY->value();
	stImgParam.dPixelZ = m_pSpbPixelZ->value();

	stImgParam.nOffset = m_pEdtOffset->text().toInt();
	stImgParam.eDataType = (DataType)m_pCmbDataType->currentIndex();
	
	stImgParam.strFilePath = m_pEdtFilePath->text();

	return;
}

void CLoadImageDlg::slotBtnBroswer()
{
	bool bOk = false;
	QString strFilePath = QFileDialog::getOpenFileName( 0, tr( "Image File" ), "" );

	m_pEdtFilePath->setText( strFilePath );
}

void CLoadImageDlg::accept()
{
	QDialog::accept();
}