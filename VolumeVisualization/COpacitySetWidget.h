#ifndef COPACITYSETWIDGET_H
#define COPACITYSETWIDGET_H

#include <QFrame>

class QSlider;
class QDoubleSpinBox;
class QPushButton;
class COpacityPresetDlg;
struct OpacityParam;
struct VolumePropertyInfo;

class COpacitySetWidget : public QFrame
{
	Q_OBJECT

public:
	COpacitySetWidget( QWidget *parent = 0 );
	~COpacitySetWidget();

	void SetPixelValueRange( const float& fMin, const float& fMax );

signals:
	void sigOpacityChanged( const VolumePropertyInfo& stProperty );

protected slots:
	void slotBtnOpacity();
	void slotOpacityChanged();

	void slotBtnMin();
	void slotBtnLower();
	void slotBtnMedium();
	void slotBtnUpper();
	void slotBtnMax();

private:
	void InitWidget();

private:
	QPushButton* m_pBtnOpacity;
	COpacityPresetDlg* m_pOpacityPresetDlg;

	QDoubleSpinBox* m_pSpbPixelValueMin;
	QDoubleSpinBox* m_pSpbPixelValueLower;
	QDoubleSpinBox* m_pSpbPixelValueMedium;
	QDoubleSpinBox* m_pSpbPixelValueUpper;
	QDoubleSpinBox* m_pSpbPixelValueMax;

	QPushButton* m_pBtnMin;
	QPushButton* m_pBtnLower;
	QPushButton* m_pBtnMedium;
	QPushButton* m_pBtnUpper;
	QPushButton* m_pBtnMax;

	QSlider*	m_pSliderMin;
	QSlider*	m_pSliderLower;
	QSlider*	m_pSliderMedium;
	QSlider*	m_pSliderUpper;
	QSlider*	m_pSliderMax;
};

#endif // COPACITYSETWIDGET_H
