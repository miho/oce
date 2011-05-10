// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic2d_Buffer_HeaderFile
#define _Graphic2d_Buffer_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Graphic2d_Buffer_HeaderFile
#include <Handle_Graphic2d_Buffer.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Aspect_WindowDriver_HeaderFile
#include <Handle_Aspect_WindowDriver.hxx>
#endif
#ifndef _Standard_ShortReal_HeaderFile
#include <Standard_ShortReal.hxx>
#endif
#ifndef _Aspect_TypeOfDrawMode_HeaderFile
#include <Aspect_TypeOfDrawMode.hxx>
#endif
#ifndef _Graphic2d_ViewPtr_HeaderFile
#include <Graphic2d_ViewPtr.hxx>
#endif
#ifndef _Graphic2d_SequenceOfPrimitives_HeaderFile
#include <Graphic2d_SequenceOfPrimitives.hxx>
#endif
#ifndef _Graphic2d_SequenceOfGraphicObject_HeaderFile
#include <Graphic2d_SequenceOfGraphicObject.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_Graphic2d_View_HeaderFile
#include <Handle_Graphic2d_View.hxx>
#endif
#ifndef _Quantity_Length_HeaderFile
#include <Quantity_Length.hxx>
#endif
#ifndef _Handle_Graphic2d_GraphicObject_HeaderFile
#include <Handle_Graphic2d_GraphicObject.hxx>
#endif
#ifndef _Handle_Graphic2d_Primitive_HeaderFile
#include <Handle_Graphic2d_Primitive.hxx>
#endif
#ifndef _Quantity_PlaneAngle_HeaderFile
#include <Quantity_PlaneAngle.hxx>
#endif
#ifndef _Quantity_Factor_HeaderFile
#include <Quantity_Factor.hxx>
#endif
#ifndef _Handle_Graphic2d_ViewMapping_HeaderFile
#include <Handle_Graphic2d_ViewMapping.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class Aspect_WindowDriver;
class Graphic2d_View;
class Graphic2d_GraphicObject;
class Graphic2d_Primitive;
class Graphic2d_ViewMapping;


//! This class constructs a 2D graphic buffer in a view.   It <br>
//! manages a set of graphic objects and/or primitives. <br>
//! To draw the buffer, the following elements are required: <br>
//! -   the override color <br>
//! -   the font <br>
//! -   a solid line type <br>
//! -   thickness of 1 pixel. <br>
//! With this category , the user can drag the geometry <br>
//! stored in the buffer without changing the fixed <br>
//! background.   This mechanism is reserved for the <br>
//! special driver Aspect_WindowDriver:   if no other <br>
//! driver has been defined, nothing will be drawn.   Both <br>
//! this driver and view mapping are used to draw the buffer. <br>
//! Warning <br>
//! -   This class manages dragging only.   It does not <br>
//!   manage "sketching" or "rubberbanding".   For example: <br>
//!   -   There is no empty constructor for this <br>
//!    primitive.   Therefore we must create a primitive <br>
//!    in a dummy object simply to add this primitive to the buffer. <br>
//!   -   There is no Buffer->Add (anArrayOfPoints) <br>
//!    method.   Therefor it is not possible to add <br>
//!    shapes to the buffer. <br>
//!   -   There are no Polyline->ChangeApoint () nor <br>
//!    Circle->ChangeRadius () methods.   Therefore <br>
//!    we must call the primitive's destructor to modify <br>
//!    the definition of one primitive in a buffer. <br>
//! -   The Graphic2d_Image class is a primitive.   For <br>
//!   this class, we replace the definition of the image <br>
//!   with a rectangle with the same size and the same position. <br>
//! -   You can add or remove primitives to the buffer <br>
//!   after creating and displaying it again. <br>
class Graphic2d_Buffer : public MMgt_TShared {

public:

  //!	Creates an empty graphic buffer in the view <aView>. <br>
//!		A graphic buffer manages a set of graphic objects <br>
//!		and/or primitives. <br>
//!		A buffer color and font index can be defined, <br>
//!		in place of the default overrideColor or systemFont. <br>
//!		When the drawmode is REPLACE the buffer is drawn with <br>
//!		the right color and background drawing is used for <br>
//!		restoring it at Erase() time. <br>
//!		When the drawmode is XOR the buffer is drawn or erase <br>
//!		with an optimal color depending of the background color <br>
//!		but some side effects can appears depending of <br>
//!		background drawing pixels values. <br>
  Standard_EXPORT   Graphic2d_Buffer(const Handle(Graphic2d_View)& aView,const Quantity_Length aPivotX,const Quantity_Length aPivotY,const Standard_Integer aWidthIndex = 0,const Standard_Integer aColorIndex = 0,const Standard_Integer aFontIndex = 0,const Aspect_TypeOfDrawMode aDrawMode = Aspect_TODM_REPLACE);
  //!	Deletes the graphic buffer <me>. <br>
  Standard_EXPORT     void Destroy() ;
~Graphic2d_Buffer()
{
  Destroy();
}
  //!	Adds the graphic object <anObject> in the graphic <br>
//!		buffer <me>. <br>
  Standard_EXPORT     void Add(const Handle(Graphic2d_GraphicObject)& anObject) ;
  //!	Adds the primitive <aPrimitive> in the graphic <br>
//!		buffer <me>. <br>
  Standard_EXPORT     void Add(const Handle(Graphic2d_Primitive)& aPrimitive) ;
  //!     Removes the object <anObject> from the graphic <br>
//!              buffer <me>. <br>
  Standard_EXPORT     void Remove(const Handle(Graphic2d_GraphicObject)& anObject) ;
  //!     Removes the primitive <aPrimitive> from the graphic <br>
//!              buffer <me>. <br>
  Standard_EXPORT     void Remove(const Handle(Graphic2d_Primitive)& aPrimitive) ;
  //!	Clears the graphic buffer <me>. <br>
//!		Removes all the primitives from the graphic buffer <me>. <br>
  Standard_EXPORT     void Clear() ;
  //!	Updates the default buffer color with a new <br>
//!		color index defines in the user ColorMap. <br>
//!         	Update the default buffer font with a new <br>
//!		font index defines in the user FontMap. <br>
//!		Update the default buffer drawmode with <br>
//!		REPLACE or XOR . <br>
//!		You can specify the width index <br>
//!		- -1 draw all lines with the largest width <br>
//!		  defined in the buffer <me> <br>
//!		- 0 draw all lines with the default width <br>
//!		  defined in the driver (1 pixel) <br>
//!		- draw all lines with the specified width <br>
//!		  <aWidthIndex> <br>
//!		You can specify the color index <br>
//!		- -1 draw all primitives with the color of <br>
//!		  the first primitive color defined in the buffer. <br>
//!		- 0 draw all primitives with the default color. <br>
//!		You can specify the font index <br>
//!		- -1 draw all text primitives with the font of <br>
//!		  the first primitive text defined in the buffer. <br>
//!		- 0 draw all text primitives with the default font. <br>
//!  Warning:	The buffer is redisplayed again if it was posted. <br>
  Standard_EXPORT     void SetAttrib(const Standard_Integer aWidthIndex,const Standard_Integer aColorIndex,const Standard_Integer aFontIndex,const Aspect_TypeOfDrawMode aDrawMode) ;
  //!	Updates the buffer pivot position. <br>
//!  Warning:	The buffer is redisplayed again if it was posted. <br>
  Standard_EXPORT     void SetPivot(const Quantity_Length aPivotX,const Quantity_Length aPivotY) ;
  //!	Updates the buffer pivot position with the actual position. <br>
  Standard_EXPORT     void SetPivot() ;
  //!	Moves the graphic buffer <me> at the specified <br>
//!		position. The new position of the buffer is : <br>
//!		(<aPivotX> + <aDeltaX>, <aPivotY> + <aDeltaY>) <br>
  Standard_EXPORT     void Move(const Quantity_Length aDeltaX,const Quantity_Length aDeltaY) ;
  //!	Rotates the graphic buffer <me> with the specified <br>
//!		absolute counter clockwise angle from the pivot X axis. <br>
  Standard_EXPORT     void Rotate(const Quantity_PlaneAngle anAngle) ;
  //!	Scales the graphic buffer <me> with the specified <br>
//!		absolute scale factor from the pivot point. <br>
  Standard_EXPORT     void Scale(const Quantity_Factor aFactor) ;
  //!	Returns the view which manages the graphic buffer <me>. <br>
  Standard_EXPORT     Handle_Graphic2d_View View() const;
  //!	Returns Standard_True if the graphic buffer <me> <br>
//!		is empty, Standard_False if not. <br>
  Standard_EXPORT     Standard_Boolean IsEmpty() const;
  //!	Returns Standard_True if the primitive <aPrimitive> <br>
//!		is in the graphic buffer <me>, Standard_False if not. <br>
  Standard_EXPORT     Standard_Boolean IsIn(const Handle(Graphic2d_Primitive)& aPrimitive) const;
  //!	Returns Standard_True if the graphic object <anObject> <br>
//!		is in the graphic buffer <me>, Standard_False if not. <br>
  Standard_EXPORT     Standard_Boolean IsIn(const Handle(Graphic2d_GraphicObject)& anObject) const;
  //!	Post the graphic buffer in the current View driver <br>
//! and display it. <br>
//!  Warning: The view driver must be defined and of type WindowDriver <br>
//! or nothing is drawn . <br>
  Standard_EXPORT     void Post() ;
  //!	Post the graphic buffer in a View driver and display it. <br>
  Standard_EXPORT     void Post(const Handle(Aspect_WindowDriver)& aDriver,const Handle(Graphic2d_ViewMapping)& aViewMapping,const Standard_Real aXPosition,const Standard_Real aYPosition,const Standard_Real aScale) ;
  //!	Unpost the graphic buffer from the view and erase it. <br>
  Standard_EXPORT     void UnPost() ;
  //!	Returns Standard_True if the graphic buffer <me> <br>
//!		is posted in the view, Standard_False if not. <br>
  Standard_EXPORT     Standard_Boolean IsPosted() const;
  //!	Returns the value of the rotation angle of the <br>
//!		graphic buffer <me>. <br>
  Standard_EXPORT     Quantity_PlaneAngle Angle() const;
  //!	Returns the value of the scale factor of the <br>
//!		graphic buffer <me>. <br>
  Standard_EXPORT     Quantity_Factor Scale() const;
  //!	Returns the actual value of the X pivot point. <br>
//!		of the graphic buffer <me>. <br>
  Standard_EXPORT     Quantity_Length Xpivot() const;
  //!	Returns the actual value of the Y pivot point. <br>
//!		of the graphic buffer <me>. <br>
  Standard_EXPORT     Quantity_Length Ypivot() const;

friend class Graphic2d_View;


  DEFINE_STANDARD_RTTI(Graphic2d_Buffer)

protected:




private: 

  //!	Returns Standard_True if the graphic buffer <me> <br>
//!		is posted in the view with the driver <aDriver>, <br>
//!		Standard_False if not. <br>
  Standard_EXPORT     Standard_Boolean IsPosted(const Handle(Aspect_WindowDriver)& aDriver) const;
  //!	Update the internal buffer with new primitives <br>
//!		if any and draw it at screen. <br>
  Standard_EXPORT     void Draw() ;
  //!	Erase the internal buffer from the screen. <br>
  Standard_EXPORT     void Erase() ;
  //!	Erase and Reload the internal graphic buffer before <br>
//!		drawing to the current drawer. <br>
//!		Keep the actual position if <ResetPosition> is FALSE. <br>
  Standard_EXPORT     void ReLoad(const Standard_Boolean ResetPosition = Standard_True) ;
  //!	Returns Standard_True if the buffer contains <br>
//!		lines and the maximum width of the lines in the <br>
//!		buffer <me> <br>
  Standard_EXPORT     Standard_Boolean MaxWidth(Quantity_Length& theWidth,Standard_Integer& theIndex) const;

Standard_Integer myBufferId;
Standard_Boolean myBufferIsPosted;
Handle_Aspect_WindowDriver myDriver;
Standard_ShortReal myPivotX;
Standard_ShortReal myPivotY;
Standard_Integer myWidthIndex;
Standard_Integer myColorIndex;
Standard_Integer myFontIndex;
Aspect_TypeOfDrawMode myDrawMode;
Graphic2d_ViewPtr myPView;
Graphic2d_SequenceOfPrimitives myPrimitives;
Graphic2d_SequenceOfGraphicObject myObjects;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif