/*
@Author Aige
¹¦ÄÜ£ºÍ¼Ïñ×¢ÊÍÀà
*/
#pragma once
#define vtkInteractionWidgets_EXPORTS

#include "vtkInteractionWidgetsModule.h" // For export macro
#include "vtkCornerAnnotation.h"
 
class  VTKINTERACTIONWIDGETS_EXPORT vtkCornerAnnotation2 : public vtkCornerAnnotation
{
public:
	// Description:
	// Instantiate this class.
	static vtkCornerAnnotation2 *New();

	// Description:
	// Standard methods for a VTK class.
	vtkTypeMacro(vtkCornerAnnotation2, vtkCornerAnnotation);
	void PrintSelf(ostream& os, vtkIndent indent);

	enum TextPosition
	{
		LowerLeft = 0, ///< Uses the lower left corner.
		LowerRight,    ///< Uses the lower right corner.
		UpperLeft,     ///< Uses the upper left corner.
		UpperRight,     ///< Uses the upper right corner.
		LowerEdge,
		UpperEdge,
		LeftEdge,
		RightEdge
	};

	// Description:
	// Set/Get the text to be displayed for each corner
	// \sa TextPosition
	void SetText(int i, const char *text);
	int RenderOverlay(vtkViewport* viewport);
	int RenderOpaqueGeometry(vtkViewport* viewport);
	virtual void ReleaseGraphicsResources(vtkWindow *);
	virtual void TextReplace(
		vtkImageActor *ia, vtkImageMapToWindowLevelColors *wl);

	// Description:
	// Set text actor positions given a viewport size and justification
	virtual void SetTextActorsPosition(int vsize[2]);
	virtual void SetTextActorsJustification();
protected:
	vtkCornerAnnotation2();
	~vtkCornerAnnotation2();
	
	char *CornerText[8];
	vtkActor2D    *TextActor[8]; 
	vtkTextMapper *TextMapper[8];

private:
	vtkCornerAnnotation2(const vtkCornerAnnotation2&);  //Not implemented
	void operator=(const vtkCornerAnnotation2&);  //Not implemented
};