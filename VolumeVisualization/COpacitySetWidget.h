#ifndef COPACITYSETWIDGET_H
#define COPACITYSETWIDGET_H

#include <QFrame>

class QSpinBox;
class QPushButton;
class COpacityPresetDlg;
struct VolumePropertyInfo;

class COpacitySetWidget : public QFrame
{
	Q_OBJECT

public:
	COpacitySetWidget( QWidget *parent = 0 );
	~COpacitySetWidget();

signals:
	void sigOpacityChanged( const VolumePropertyInfo& stProperty );

protected slots:
	void slotBtnOpacity();

private:
	void InitWidget();

private:
	QPushButton* m_pBtnOpacity;
	COpacityPresetDlg* m_pOpacityPresetDlg;

	QSpinBox* m_pSpbPixelValueMin;
	QSpinBox* m_pSpbPixelValueLower;
	QSpinBox* m_pSpbPixelValueMedium;
	QSpinBox* m_pSpbPixelValueUpper;
	QSpinBox* m_pSpbPixelValueMax;

	QPushButton* m_pBtnMin;
	QPushButton* m_pBtnLower;
	QPushButton* m_pBtnMedium;
	QPushButton* m_pBtnUpper;
	QPushButton* m_pBtnMax;
};

#endif // COPACITYSETWIDGET_H
