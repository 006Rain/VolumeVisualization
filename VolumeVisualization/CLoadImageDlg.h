#ifndef CLOADIMAGEWIDEGT_H
#define CLOADIMAGEWIDEGT_H

#include <QDialog>
#include "CommonDef.h"

class QLineEdit;
class QComboBox;
class QDoubleSpinBox;

class CLoadImageDlg : public QDialog
{
	Q_OBJECT

public:
	CLoadImageDlg( QWidget *parent = 0 );
	~CLoadImageDlg();

	void GetImageParam( ImageParams& stImgParam );

protected slots:
	virtual void accept();
	void slotBtnBroswer();

private:
	void InitWidget();

private:
	QLineEdit* m_pEdtDimX;
	QLineEdit* m_pEdtDimY;
	QLineEdit* m_pEdtDimZ;

	QDoubleSpinBox* m_pSpbPixelX;
	QDoubleSpinBox* m_pSpbPixelY;
	QDoubleSpinBox* m_pSpbPixelZ;

	QLineEdit* m_pEdtOffset;
	QComboBox* m_pCmbDataType;

	QLineEdit* m_pEdtFilePath;

	ImageParams m_stImageParams;
};

#endif // CLOADIMAGEWIDEGT_H
