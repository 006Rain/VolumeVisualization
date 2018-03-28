#ifndef VOLUMEVISUALIZATION_H
#define VOLUMEVISUALIZATION_H

#include "QVTKWidget.h"
#include "ui_volumevisualization.h"

class QPushButton;
class CVtkVolumeWidget;
class CVolumePropertySetDlg;

struct VolumePropertyInfo;

class VolumeVisualization : public QWidget
{
	Q_OBJECT

public:
	VolumeVisualization( QWidget *parent = 0 );
	~VolumeVisualization();

protected slots:
	void slotBtnLoad();
	void slotBtnRemove();
	void slotBtnOpacity();
	void slotBtnReset();
	void slotOpacityInfoChanged( const VolumePropertyInfo& stRGBA );

protected:
	virtual void closeEvent( QCloseEvent * );

private:
	void InitWidget();

private:
	Ui::VolumeVisualizationClass ui;

	CVtkVolumeWidget* m_pVolumeWidget;

	//Buttons
	QPushButton* m_pBtnRemove;
	QPushButton* m_pBtnOpacity;
	QPushButton* m_pBtnReset;

	CVolumePropertySetDlg* m_pOpacityDlg;
};

#endif // VOLUMEVISUALIZATION_H
