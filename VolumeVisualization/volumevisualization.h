#ifndef VOLUMEVISUALIZATION_H
#define VOLUMEVISUALIZATION_H

#include "QVTKWidget.h"
#include "ui_volumevisualization.h"

class CVtkVolumeWidget;

class VolumeVisualization : public QWidget
{
	Q_OBJECT

public:
	VolumeVisualization( QWidget *parent = 0 );
	~VolumeVisualization();

protected slots:
	void slotBtnLoad();
	void slotBtnOpacity();

private:
	void InitWidget();

private:
	Ui::VolumeVisualizationClass ui;

	CVtkVolumeWidget* m_pVolumeWidget;
};

#endif // VOLUMEVISUALIZATION_H
