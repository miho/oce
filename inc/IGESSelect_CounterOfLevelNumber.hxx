// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESSelect_CounterOfLevelNumber_HeaderFile
#define _IGESSelect_CounterOfLevelNumber_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESSelect_CounterOfLevelNumber.hxx>

#include <Standard_Integer.hxx>
#include <Handle_TColStd_HArray1OfInteger.hxx>
#include <IFSelect_SignCounter.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Handle_Interface_InterfaceModel.hxx>
#include <Handle_TColStd_HSequenceOfInteger.hxx>
#include <Handle_TCollection_HAsciiString.hxx>
#include <Handle_Message_Messenger.hxx>
class TColStd_HArray1OfInteger;
class Standard_Transient;
class Interface_InterfaceModel;
class TColStd_HSequenceOfInteger;
class TCollection_HAsciiString;
class Message_Messenger;


//! This class gives information about Level Number. It counts
//! entities according level number, considering also the
//! multiple level (see the class LevelList) for which an entity
//! is attached to each of the listed levels.
//!
//! Data are available, as level number, or as their alphanumeric
//! counterparts ("LEVEL nnnnnnn", " NO LEVEL", " LEVEL LIST")
class IGESSelect_CounterOfLevelNumber : public IFSelect_SignCounter
{

public:

  
  //! Creates a CounterOfLevelNumber, clear, ready to work
  //! <withmap> and <withlist> are transmitted to SignCounter
  Standard_EXPORT IGESSelect_CounterOfLevelNumber(const Standard_Boolean withmap = Standard_True, const Standard_Boolean withlist = Standard_False);
  
  //! Resets already memorized informations : also numeric data
  Standard_EXPORT virtual   void Clear() ;
  
  //! Adds an entity by considering its lrvrl number(s)
  //! A level is added both in numeric and alphanumeric form,
  //! i.e. LevelList gives "LEVEL LIST", others (no level or
  //! positive level) displays level number on 7 digits (C : %7d)
  //! Remark : an entity attached to a Level List is added for
  //! " LEVEL LIST", and for each of its constituant levels
  Standard_EXPORT virtual   void AddSign (const Handle(Standard_Transient)& ent, const Handle(Interface_InterfaceModel)& model) ;
  
  //! The internal action to record a new level number, positive,
  //! null (no level) or negative (level list)
  Standard_EXPORT   void AddLevel (const Handle(Standard_Transient)& ent, const Standard_Integer level) ;
  
  //! Returns the highest value found for a level number
  Standard_EXPORT   Standard_Integer HighestLevel()  const;
  
  //! Returns the number of times a level is used,
  //! 0 if it has not been recorded at all
  //! <level> = 0 counts entities attached to no level
  //! <level> < 0 counts entities attached to a LevelList
  Standard_EXPORT   Standard_Integer NbTimesLevel (const Standard_Integer level)  const;
  
  //! Returns the ordered list of used positive Level numbers
  Standard_EXPORT   Handle(TColStd_HSequenceOfInteger) Levels()  const;
  
  //! Determines and returns the value of the signature for an
  //! entity as an HAsciiString. Redefined, gives the same result
  //! as AddSign, see this method ("LEVEL LIST" or "nnnnnnn")
  Standard_EXPORT virtual   Handle(TCollection_HAsciiString) Sign (const Handle(Standard_Transient)& ent, const Handle(Interface_InterfaceModel)& model)  const;
  
  //! Prints the counts of items (not the list) then the Highest
  //! Level Number recorded
  Standard_EXPORT virtual   void PrintCount (const Handle(Message_Messenger)& S)  const;




  DEFINE_STANDARD_RTTI(IGESSelect_CounterOfLevelNumber)

protected:




private: 


  Standard_Integer thehigh;
  Standard_Integer thenblists;
  Handle(TColStd_HArray1OfInteger) thelevels;


};







#endif // _IGESSelect_CounterOfLevelNumber_HeaderFile
