
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !wxUSE_DOC_VIEW_ARCHITECTURE
#error You must set wxUSE_DOC_VIEW_ARCHITECTURE to 1 in setup.h!
#endif

#if wxUSE_STD_IOSTREAM
    #include "wx/ioswrap.h"
#else
    #include "wx/txtstrm.h"
#endif

#include "LitesqlDocument.h"

#include "litesql-gen-xml.hpp"

IMPLEMENT_DYNAMIC_CLASS(LitesqlDocument, wxDocument)

using namespace std;
using namespace litesql;

LitesqlDocument::LitesqlDocument(void)
{
  m_pModel = new ObjectModel();
}

LitesqlDocument::~LitesqlDocument(void)
{
  if (m_pModel) {
    delete m_pModel;
  }
}

ObjectModel* LitesqlDocument::GetModel()
{
  return m_pModel;
}

void LitesqlDocument::RemoveField(xml::Field::counted_ptr pField)
{
  if ( (m_pModel!=NULL) && (pField.get()!=NULL) ) 
  {
    if (m_pModel->remove(pField))  
    {
      Modify(true);
      UpdateAllViews();
    }
  }
}

#if wxUSE_STD_IOSTREAM
wxSTD ostream& LitesqlDocument::SaveObject(wxSTD ostream& stream)
#else
wxOutputStream& LitesqlDocument::SaveObject(wxOutputStream& stream)
#endif
{
  XmlGenerator xml_generator;
  
  string fname (GetFilename().mb_str());
  xml_generator.setOutputFilename(fname);

  xml_generator.generateCode(m_pModel);
  
  return stream;
}

#if wxUSE_STD_IOSTREAM
wxSTD istream& LitesqlDocument::LoadObject(wxSTD istream& stream)
#else
wxInputStream& LitesqlDocument::LoadObject(wxInputStream& stream)
#endif
{
  string fname (GetFilename().mb_str());
  m_pModel->loadFromFile(fname);
  return stream;
}
