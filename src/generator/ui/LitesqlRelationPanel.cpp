#include "LitesqlRelationPanel.h"

#include "objectmodel.hpp"
#include "ddx.h"

using namespace xml;

LitesqlRelationPanel::LitesqlRelationPanel( wxWindow* parent, vector<xml::Object*> baseClasses, Relation* pRelation )
: ui::RelationPanel( parent ),
  m_pRelation(pRelation)
{
  m_textCtrlName->SetValidator(StdStringValidator(wxFILTER_ALPHANUMERIC,&m_pRelation->name));

  for (vector<Object*>::const_iterator it = baseClasses.begin();
      it != baseClasses.end();
      it++)
  {
    m_choiceObject1->Append(wxString::FromUTF8((*it)->name.c_str()));
    m_choiceObject2->Append(wxString::FromUTF8((*it)->name.c_str()));
  }

  m_choiceObject1->SetValidator(RelateTypeValidator(m_pRelation->related[0]));
  m_choiceObject2->SetValidator(RelateTypeValidator(m_pRelation->related[1]));
}



/* RelateTypeValidator Implementation */
IMPLEMENT_DYNAMIC_CLASS(RelateTypeValidator,wxGenericValidator)

RelateTypeValidator::RelateTypeValidator (xml::Relate *val)
: m_pRelate(val),
  wxGenericValidator(&value)
{
}

RelateTypeValidator::RelateTypeValidator (const RelateTypeValidator& val)
: wxGenericValidator(val)
{
  m_pRelate = val.m_pRelate;
  value = val.value;
  Copy(val);
  m_pString = &value;
}

wxObject *RelateTypeValidator::Clone() const
{ return new RelateTypeValidator(*this); }
    
  // Called to transfer data to the window
bool RelateTypeValidator::TransferToWindow() 
{
  value = wxString::FromUTF8(m_pRelate->objectName.c_str());
  return wxGenericValidator::TransferToWindow();
}

    // Called to transfer data from the window
bool RelateTypeValidator::TransferFromWindow()
{
  bool rval = wxGenericValidator::TransferFromWindow();
  m_pRelate->objectName = value.ToUTF8();
  return rval;
}

