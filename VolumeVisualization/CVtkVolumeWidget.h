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
	VolumePropertyInfo GetVolumeProperty();

	void Reset();
	void RemoveImage();
	void RotateXYZ( int nX, int nY, int nZ );

	void GetMaxMinPixelValue( float& fMax, float& fMin );

private:
	vtkSmartPointer<vtkRenderer> m_pRenderer;
	vtkSmartPointer<vtkRenderWindow> m_pRenderWindow;
	vtkSmartPointer<vtkVolume> m_pVolume;
	vtkSmartPointer<vtkVolumeProperty> m_pVolumeProperty;

	ImageParams m_stImageParam;
	VolumePropertyInfo m_stPropertyInfo;

	float m_fPixelMax;
	float m_fPixelMin;
};

#endif // CVOLUMEWIDGET_H
