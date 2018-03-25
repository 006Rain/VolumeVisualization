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
	void slotBtnOpacity();
	void slotOpacityInfoChanged( const VolumePropertyInfo& stRGBA );

private:
	void InitWidget();

private:
	Ui::VolumeVisualizationClass ui;

	CVtkVolumeWidget* m_pVolumeWidget;

	QPushButton* m_pBtnOpacity;
	CVolumePropertySetDlg* m_pOpacityDlg;
};

#endif // VOLUMEVISUALIZATION_H
