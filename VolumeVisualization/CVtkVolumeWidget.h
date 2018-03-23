#ifndef CVOLUMEWIDGET_H
#define CVOLUMEWIDGET_H

#include "QVTKWidget.h"
#include "vtkSmartPointer.h"

#include "CommonDef.h"

class vtkRenderer;
class vtkRenderWindow;
class vtkVolume;
class vtkVolumeProperty;

class CVtkVolumeWidget : public QVTKWidget
{
	Q_OBJECT

public:
	CVtkVolumeWidget( QWidget *parent = 0 );
	~CVtkVolumeWidget();

	void SetImageParam( const ImageParams& stParam );
	void UpdateImage();
	void UpdateVolumeProperty( const VolumePropertyInfo& stOpacityColors );

private:
	vtkSmartPointer<vtkRenderer> m_pRenderer;
	vtkSmartPointer<vtkRenderWindow> m_pRenderWindow;
	vtkSmartPointer<vtkVolume> m_pVolume;
	vtkSmartPointer<vtkVolumeProperty> m_pVolumeProperty;

	ImageParams m_stImageParam;
};

#endif // CVOLUMEWIDGET_H
