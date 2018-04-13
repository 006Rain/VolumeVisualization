#ifndef CROTATEINFOWIDGET_H
#define CROTATEINFOWIDGET_H

#include <QFrame>

class QSpinBox;
class QRadioButton;

class CRotateSetWidget : public QFrame
{
	Q_OBJECT

public:
	CRotateSetWidget( QWidget *parent = 0 );
	~CRotateSetWidget();

signals:
	void sigRotateX( int nX, bool bRotateByVolume );
	void sigRotateY( int nY, bool bRotateByVolume );
	void sigRotateZ( int nZ, bool bRotateByVolume );
	void sigResetPosition();

protected slots:
	void slotBtnX();
	void slotBtnY();
	void slotBtnZ();

private:
	void InitWidget();

private:
	QRadioButton* m_pRadioBtnVolume;
	QRadioButton* m_pRadioBtnCamera;

	QSpinBox* m_pSpbRotateX;
	QSpinBox* m_pSpbRotateY;
	QSpinBox* m_pSpbRotateZ;
};

#endif // CROTATEINFOWIDGET_H
