#ifndef CROTATEINFOWIDGET_H
#define CROTATEINFOWIDGET_H

#include <QFrame>

class QSpinBox;

class CRotateSetWidget : public QFrame
{
	Q_OBJECT

public:
	CRotateSetWidget( QWidget *parent = 0 );
	~CRotateSetWidget();

signals:
	void sigRotateXYZ( int, int, int );
	void sigResetPosition();

protected slots:
	void slotBtnApply();

private:
	void InitWidget();

private:
	QSpinBox* m_pSpbRotateX;
	QSpinBox* m_pSpbRotateY;
	QSpinBox* m_pSpbRotateZ;
};

#endif // CROTATEINFOWIDGET_H
