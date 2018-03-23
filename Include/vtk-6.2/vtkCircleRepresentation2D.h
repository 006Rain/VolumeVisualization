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

#ifndef vtkCircleRepresentation2D_h
#define vtkCircleRepresentation2D_h

#define vtkInteractionWidgets_EXPORTS
#include "vtkInteractionWidgetsModule.h" // For export macro
#include "vtkCircleRepresentation.h"
 
class vtkActor2D;
class vtkProperty2D;

class VTKINTERACTIONWIDGETS_EXPORT vtkCircleRepresentation2D : public vtkCircleRepresentation
//class  vtkCircleRepresentation2D : public vtkCircleRepresentation
{
public:
  // Description:
  // Instantiate class.
	static vtkCircleRepresentation2D *New();

  // Description:
  // Standard VTK methods.
	vtkTypeMacro( vtkCircleRepresentation2D , vtkCircleRepresentation );
  void PrintSelf(ostream& os, vtkIndent indent);
   
  vtkActor2D* GetCircleActor();
  vtkProperty2D  *GetAxisProperty();

 
  // Description:
  // Method to satisfy superclasses' API.
  virtual void BuildRepresentation();
  virtual int ComputeInteractionState(int X, int Y, int modify = 0);
  // Description:
  // Methods required by vtkProp superclass.
  virtual void ReleaseGraphicsResources(vtkWindow *w);
  virtual int RenderOverlay(vtkViewport *viewport);
  virtual int RenderOpaqueGeometry(vtkViewport *viewport);


  //control 4 points
  double* GetPoint1WorldPosition( );
  double* GetPoint2WorldPosition( );
  void GetPoint1WorldPosition( double pos[ 3 ] );
  void GetPoint2WorldPosition( double pos[ 3 ] );
  void SetPoint1WorldPosition( double pos[ 3 ] );
  void SetPoint2WorldPosition( double pos[ 3 ] );

  void SetPoint1DisplayPosition( double pos[ 3 ] );
  void SetPoint2DisplayPosition( double pos[ 3 ] );
  void GetPoint1DisplayPosition( double pos[ 3 ] );
  void GetPoint2DisplayPosition( double pos[ 3 ] );

  double* GetPoint3WorldPosition( );
  double* GetPoint4WorldPosition( );
  void GetPoint3WorldPosition( double pos[ 3 ] );
  void GetPoint4WorldPosition( double pos[ 3 ] );
  void SetPoint3WorldPosition( double pos[ 3 ] );
  void SetPoint4WorldPosition( double pos[ 3 ] );

  void SetPoint3DisplayPosition( double pos[ 3 ] );
  void SetPoint4DisplayPosition( double pos[ 3 ] );
  void GetPoint3DisplayPosition( double pos[ 3 ] );
  void GetPoint4DisplayPosition( double pos[ 3 ] );

  void SetLineWorldPosition( double pos[ 3 ] );
  void GetLineWorldPosition( double pos[ 3 ] );
  void SetLineDisplayPosition( double pos[ 3 ] );
  void GetLineDisplayPosition( double pos[ 3 ] );

  void EnableRotateActor( bool bRotate );
protected:
	vtkCircleRepresentation2D();
	~vtkCircleRepresentation2D();
	  
	vtkActor2D *AxisActor1;
	vtkProperty2D  *AxisProperty;
	vtkActor2D *RotateActor;
private:
	vtkCircleRepresentation2D(const vtkCircleRepresentation2D&);  //Not implemented
	void operator=(const vtkCircleRepresentation2D&);  //Not implemented
};

#endif 

