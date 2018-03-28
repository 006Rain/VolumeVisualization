#ifndef VOLUMEVISUALIZATION_H
#define VOLUMEVISUALIZATION_H

#include "QVTKWidget.h"
#include "ui_volumevisualization.h"

class QPushButton;
class CVtkVolumeWidget;

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
	void slotResetPosition();
	void slotOpacityInfoChanged( const VolumePropertyInfo& stRGBA );

	void slotRotateXYZ( int, int, int );

private:
	void InitWidget();

private:
	Ui::VolumeVisualizationClass ui;

	CVtkVolumeWidget* m_pVolumeWidget;

	//Buttons
	QPushButton* m_pBtnRemove;
};

#endif // VOLUMEVISUALIZATION_H
