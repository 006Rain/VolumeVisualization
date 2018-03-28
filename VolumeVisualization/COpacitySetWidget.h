#ifndef COPACITYSETWIDGET_H
#define COPACITYSETWIDGET_H

#include <QFrame>

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
};

#endif // COPACITYSETWIDGET_H
