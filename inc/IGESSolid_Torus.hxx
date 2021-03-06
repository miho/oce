// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESSolid_Torus_HeaderFile
#define _IGESSolid_Torus_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESSolid_Torus.hxx>

#include <Standard_Real.hxx>
#include <gp_XYZ.hxx>
#include <IGESData_IGESEntity.hxx>
class gp_XYZ;
class gp_Pnt;
class gp_Dir;


//! defines Torus, Type <160> Form Number <0>
//! in package IGESSolid
//! A Torus is a solid formed by revolving a circular disc
//! about a specified coplanar axis.
class IGESSolid_Torus : public IGESData_IGESEntity
{

public:

  
  Standard_EXPORT IGESSolid_Torus();
  
  //! This method is used to set the fields of the class Torus
  //! - R1     : distance from center of torus to center
  //! of circular disc to be revolved
  //! - R2     : radius of circular disc
  //! - aPoint : center point coordinates (default (0,0,0))
  //! - anAxis : unit vector in axis direction (default (0,0,1))
  Standard_EXPORT   void Init (const Standard_Real R1, const Standard_Real R2, const gp_XYZ& aPoint, const gp_XYZ& anAxisdir) ;
  
  //! returns the distance from the center of torus to the center of
  //! the disc to be revolved
  Standard_EXPORT   Standard_Real MajorRadius()  const;
  
  //! returns the radius of the disc to be revolved
  Standard_EXPORT   Standard_Real DiscRadius()  const;
  
  //! returns the center of torus
  Standard_EXPORT   gp_Pnt AxisPoint()  const;
  
  //! returns the center of torus after applying TransformationMatrix
  Standard_EXPORT   gp_Pnt TransformedAxisPoint()  const;
  
  //! returns direction of the axis
  Standard_EXPORT   gp_Dir Axis()  const;
  
  //! returns direction of the axis after applying TransformationMatrix
  Standard_EXPORT   gp_Dir TransformedAxis()  const;




  DEFINE_STANDARD_RTTI(IGESSolid_Torus)

protected:




private: 


  Standard_Real theR1;
  Standard_Real theR2;
  gp_XYZ thePoint;
  gp_XYZ theAxis;


};







#endif // _IGESSolid_Torus_HeaderFile
