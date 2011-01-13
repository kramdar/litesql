#include "LitesqlObjectPanel.h"
#include "objectmodel.hpp"

#include "ddx.h"

using namespace xml;

IMPLEMENT_DYNAMIC_CLASS(LitesqlObjectPanel,ui::ObjectPanel)


LitesqlObjectPanel::LitesqlObjectPanel( wxWindow* parent, ObjectPtr& pObject  )
:
ui::ObjectPanel( parent ),
m_pObject(pObject)
{
    // setBaseClasses(<#const std *baseClasses#>);
  
  m_choiceInheritsFrom->SetValidator(ObjectTypeValidator(m_pObject));

  m_textCtrlName->SetValidator(StdStringValidator(wxFILTER_ALPHANUMERIC,&m_pObject->name));
}

void LitesqlObjectPanel::setBaseClasses(const ObjectSequence& baseClasses)
{
  m_choiceInheritsFrom->Clear();
  m_choiceInheritsFrom->Append(wxString::FromUTF8(Object::DEFAULT_BASE->name.c_str()));
  for (ObjectSequence::const_iterator it = baseClasses.begin();
       it != baseClasses.end();
       it++)
  {
    if ((*it)->name!=m_pObject->name) 
    {
      m_choiceInheritsFrom->Append(wxString::FromUTF8((*it)->name.c_str()));
    }
  }
  m_choiceInheritsFrom->SetStringSelection(wxString::FromUTF8(m_pObject->inherits.c_str()));
}


xml::ObjectPtr& LitesqlObjectPanel::GetObject()
{
  return m_pObject;
}

/* ObjectTypeValidator Implementation */
IMPLEMENT_DYNAMIC_CLASS(ObjectTypeValidator,wxGenericValidator)

ObjectTypeValidator::ObjectTypeValidator (xml::ObjectPtr val)
: m_pObject(val),
  wxGenericValidator(&value)
{
}

ObjectTypeValidator::ObjectTypeValidator (const ObjectTypeValidator& val)
: wxGenericValidator(val)
{
  m_pObject= val.m_pObject;
  value = val.value;
  Copy(val);
  m_pString = &value;
}

wxObject *ObjectTypeValidator::Clone() const
{ return new ObjectTypeValidator(*this); }
    
  // Called to transfer data to the window
bool ObjectTypeValidator::TransferToWindow() 
{
  value = wxString::FromUTF8(m_pObject->inherits.c_str());
  return wxGenericValidator::TransferToWindow();
}

    // Called to transfer data from the window
bool ObjectTypeValidator::TransferFromWindow()
{
  bool rval = wxGenericValidator::TransferFromWindow();
  m_pObject->inherits = value.ToUTF8();
  return rval;
}
