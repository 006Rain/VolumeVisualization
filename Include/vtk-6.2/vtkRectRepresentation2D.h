/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkDistanceRepresentation2D.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkDistanceRepresentation2D - represent the vtkDistanceWidget
// .SECTION Description
// The vtkDistanceRepresentation2D is a representation for the
// vtkDistanceWidget. This representation consists of a measuring line (axis)
// and two vtkHandleWidgets to place the end points of the line. Note that
// this particular widget draws its representation in the overlay plane, and
// the handles also operate in the 2D overlay plane. (If you desire to use
// the distance widget for 3D measurements, use the
// vtkDistanceRepresentation3D.)

// .SECTION See Also
// vtkDistanceWidget vtkDistanceRepresentation vtkDistanceRepresentation3D
#ifndef vtkRectRepresentation2D_h
#define vtkRectRepresentation2D_h


#define vtkInteractionWidgets_EXPORTS
#include "vtkInteractionWidgetsModule.h" // For export macro
#include "vtkRectRepresentation.h"

class vtkActor2D;
class vtkProperty2D;


class VTKINTERACTIONWIDGETS_EXPORT vtkRectRepresentation2D : public vtkRectRepresentation
//class  vtkRectRepresentation2D : public vtkRectRepresentation
{
public:
  // Description:
  // Instantiate class.
	static vtkRectRepresentation2D *New();

  // Description:
  // Standard VTK methods.
	vtkTypeMacro(vtkRectRepresentation2D, vtkRectRepresentation);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Satisfy the superclasses API.
  virtual double GetDistance()
    {return this->Distance;}

  // Description:
  // Methods to Set/Get the coordinates of the two points defining
  // this representation. Note that methods are available for both
  // display and world coordinates.
  double* GetPoint1WorldPosition();
  double* GetPoint2WorldPosition();
  void GetPoint1WorldPosition(double pos[3]);
  void GetPoint2WorldPosition(double pos[3]);
  void SetPoint1WorldPosition(double pos[3]);
  void SetPoint2WorldPosition(double pos[3]);

  void SetPoint1DisplayPosition(double pos[3]);
  void SetPoint2DisplayPosition(double pos[3]);
  void GetPoint1DisplayPosition(double pos[3]);
  void GetPoint2DisplayPosition(double pos[3]);

  double* GetPoint3WorldPosition();
  double* GetPoint4WorldPosition();
  void GetPoint3WorldPosition(double pos[3]);
  void GetPoint4WorldPosition(double pos[3]);
  void SetPoint3WorldPosition(double pos[3]);
  void SetPoint4WorldPosition(double pos[3]);

  void SetPoint3DisplayPosition(double pos[3]);
  void SetPoint4DisplayPosition(double pos[3]);
  void GetPoint3DisplayPosition(double pos[3]);
  void GetPoint4DisplayPosition(double pos[3]);

  void SetLineWorldPosition(double pos[3]);
  void GetLineWorldPosition(double pos[3]);
  void SetLineDisplayPosition(double pos[3]);
  void GetLineDisplayPosition(double pos[3]);
  // Description:
  // Retrieve the vtkAxisActor2D used to draw the measurement axis. With this
  // properties can be set and so on. There is also a convenience method to
  // get the axis property.
  vtkActor2D *GetAxis1();
  vtkActor2D *GetAxis2();
  vtkActor2D *GetAxis3();
  vtkActor2D *GetAxis4();
  vtkProperty2D  *GetAxisProperty();

  void EnableRotateActor( bool bEnable );

  // Description:
  // Method to satisfy superclasses' API.
  virtual void BuildRepresentation();

  // Description:
  // Methods required by vtkProp superclass.
  virtual void ReleaseGraphicsResources(vtkWindow *w);
  virtual int RenderOverlay(vtkViewport *viewport);
  virtual int RenderOpaqueGeometry(vtkViewport *viewport);

protected:
	vtkRectRepresentation2D();
	~vtkRectRepresentation2D();

  // Add a line to the mix
  vtkActor2D *AxisActor1;
  vtkProperty2D  *AxisProperty;

  vtkActor2D *AxisActor2;
  vtkActor2D *AxisActor3;
  vtkActor2D *AxisActor4;
  vtkActor2D *RotateActor;
   // The distance between the two points
  double Distance;

private:
	vtkRectRepresentation2D(const vtkRectRepresentation2D&);  //Not implemented
	void operator=(const vtkRectRepresentation2D&);  //Not implemented
};

#endif