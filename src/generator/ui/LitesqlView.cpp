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

#include "ui.h"
#include "VisualLitesqlApp.h"
#include "LitesqlView.h"
#include "GenerateView.h"

#include "LitesqlDocument.h"

#include "LitesqlModelTreePanel.h"

IMPLEMENT_DYNAMIC_CLASS(LitesqlView, wxView)

BEGIN_EVENT_TABLE(LitesqlView, wxView)
  EVT_MENU(VisualLitesqlApp::ID_GENERATE, LitesqlView::OnGenerate)
  
  EVT_MENU(VisualLitesqlApp::ID_ADD_OBJECT,     LitesqlView::OnAddObject)
  EVT_MENU(VisualLitesqlApp::ID_REMOVE_OBJECT,  LitesqlView::OnRemoveObject)

  EVT_MENU(VisualLitesqlApp::ID_ADD_FIELD,     LitesqlView::OnAddField)
  EVT_MENU(VisualLitesqlApp::ID_REMOVE_FIELD,  LitesqlView::OnRemoveField)

  EVT_MENU(VisualLitesqlApp::ID_ADD_METHOD,     LitesqlView::OnAddMethod)
  EVT_MENU(VisualLitesqlApp::ID_REMOVE_METHOD,  LitesqlView::OnRemoveMethod)

  EVT_MENU(VisualLitesqlApp::ID_ADD_RELATED,    LitesqlView::OnAddRelated)
  EVT_MENU(VisualLitesqlApp::ID_REMOVE_RELATED, LitesqlView::OnRemoveRelated)

  EVT_MENU(VisualLitesqlApp::ID_ADD_RELATION,   LitesqlView::OnAddRelation)
  EVT_MENU(VisualLitesqlApp::ID_REMOVE_RELATION,LitesqlView::OnRemoveRelation)

  EVT_CONTEXT_MENU(LitesqlView::OnContextMenu)
  
END_EVENT_TABLE()

using namespace xml;
using namespace litesql;
using namespace ui;

LitesqlView::LitesqlView() 
  : frame((wxMDIChildFrame *) NULL),m_ctxMenu(NULL)
{}

LitesqlView::~LitesqlView()
{
  if (m_ctxMenu)
  {
    delete m_ctxMenu;
  }
}

wxMenu* LitesqlView::GetContextMenu()
{
  if (!m_ctxMenu) 
  {
    m_ctxMenu = new wxMenu;
    m_ctxMenu->Append(VisualLitesqlApp::ID_ADD_OBJECT,_("Add Object ..."));
    m_ctxMenu->Append(VisualLitesqlApp::ID_REMOVE_OBJECT,_("Remove Object ..."));
    m_ctxMenu->AppendSeparator();
    m_ctxMenu->Append(VisualLitesqlApp::ID_ADD_FIELD,_("Add Field..."));
    m_ctxMenu->Append(VisualLitesqlApp::ID_REMOVE_FIELD,_("Remove Field ..."));
    m_ctxMenu->AppendSeparator();
    m_ctxMenu->Append(VisualLitesqlApp::ID_ADD_METHOD,_("Add Method ..."));
    m_ctxMenu->Append(VisualLitesqlApp::ID_REMOVE_METHOD,_("Remove Method..."));
    m_ctxMenu->AppendSeparator();
    m_ctxMenu->Append(VisualLitesqlApp::ID_ADD_RELATED,_("Add Related..."));
    m_ctxMenu->Append(VisualLitesqlApp::ID_REMOVE_RELATED,_("Remove Related ..."));
    m_ctxMenu->AppendSeparator();
    m_ctxMenu->Append(VisualLitesqlApp::ID_ADD_RELATION,_("Add Relation..."));
    m_ctxMenu->Append(VisualLitesqlApp::ID_REMOVE_RELATION,_("Remove Relation ..."));
    m_ctxMenu->AppendSeparator();
    m_ctxMenu->Append(VisualLitesqlApp::ID_GENERATE,_("Generate..."));
  }

  // \TODO change menu on selected item
  return m_ctxMenu;
}

// What to do when a view is created. Creates actual
// windows for displaying the view.
bool LitesqlView::OnCreate(wxDocument *doc, long WXUNUSED(flags) )
{
	frame = wxGetApp().CreateChildFrame(doc, this);
	frame->SetTitle(_T("LitesqlView"));

#ifdef __X__
	// X seems to require a forced resize
	int x, y;
	frame->GetSize(&x, &y);
	frame->SetSize(wxDefaultCoord, wxDefaultCoord, x, y);
#endif

	panel = new LitesqlModelTreePanel(frame);
/*
	panel->GetTreeCtrl()->DeleteAllItems();
	wxTreeItemId rootId = panel->GetTreeCtrl()->AddRoot(_("root"));
	wxModelItem::RefreshTree(panel->GetTreeCtrl(),rootId,new wxLitesqlModel(((LitesqlDocument*) doc)->GetModel()));
*/
	panel->Layout();
	frame->Show(true);
	Activate(true);

	return true;
}

void LitesqlView::OnUpdate(wxView *sender, wxObject *hint) 
{
	panel->setObjectModel(((LitesqlDocument*) GetDocument())->GetModel());
  panel->Layout();
}

// Sneakily gets used for default print/preview
// as well as drawing on the screen.
void LitesqlView::OnDraw(wxDC *dc)
{
  dc->SetFont(*wxNORMAL_FONT);
  dc->SetPen(*wxBLACK_PEN);
}

// Clean up windows used for displaying the view.
bool LitesqlView::OnClose(bool deleteWindow)
{
  if (!GetDocument()->Close())
    return false;
  wxApp::GetInstance();

  wxString s(wxTheApp->GetAppName());
  if (frame)
    frame->SetTitle(s);

  SetFrame((wxFrame*)NULL);

  Activate(false);

  if (deleteWindow)
  {
    delete frame;
    return true;
  }
  return true;
}



void LitesqlView::OnContextMenu(wxContextMenuEvent& event)
{
  if (frame)
  {
    frame->PopupMenu(GetContextMenu(),frame->ScreenToClient(event.GetPosition()));
  }
}


void LitesqlView::OnAddObject(wxCommandEvent& WXUNUSED(event) )
{
  panel->AddObject(new Object("newObject",""));
  GetDocument()->Modify(true);
  GetDocument()->UpdateAllViews(this,NULL);
}

void LitesqlView::OnRemoveObject(wxCommandEvent& WXUNUSED(event) )
{
  wxMessageBox(_("OnRemoveObject"));
  GetDocument()->Modify(true);
  GetDocument()->UpdateAllViews(this,NULL);
}

void LitesqlView::OnAddField(wxCommandEvent& WXUNUSED(event) )
{
/*
wxWindow *pPage = m_treebook->GetCurrentPage();
  if (!pPage) 
  {
  
  }
  else if (pPage->IsKindOf(CLASSINFO(LitesqlObjectPanel)))
  {
    xml::Field* newField = new xml::Field("newField",AU_field_type,"",AU_field_indexed,AU_field_unique);
    ((LitesqlObjectPanel*)pPage)->GetObject()->fields.push_back(newField);
    m_treebook->InsertSubPage(  m_treebook->GetSelection(),
                                new LitesqlFieldPanel(m_treebook, newField),_("newField(Field)"),
                                true);
      GetDocument()->Modify(true);
      GetDocument()->UpdateAllViews(this,NULL);
  }
  else
  {
  
  }
*/
}

void LitesqlView::OnRemoveField(wxCommandEvent& WXUNUSED(event) )
{
/*
wxWindow *pPage = m_treebook->GetCurrentPage();
  if (!pPage) 
  {
  
  }
  else if (pPage->IsKindOf(CLASSINFO(LitesqlFieldPanel)))
  {
    ((LitesqlDocument*) GetDocument())->RemoveField(((LitesqlFieldPanel*)pPage)->GetField());
  }
  else
  {
  
  }
*/

}

void LitesqlView::OnAddMethod(wxCommandEvent& WXUNUSED(event) )
{
	
}

void LitesqlView::OnRemoveMethod(wxCommandEvent& WXUNUSED(event) )
{}

void LitesqlView::OnAddRelated(wxCommandEvent& WXUNUSED(event) )
{}

void LitesqlView::OnRemoveRelated(wxCommandEvent& WXUNUSED(event) )
{}

void LitesqlView::OnAddRelation(wxCommandEvent& WXUNUSED(event) )
{}

void LitesqlView::OnRemoveRelation(wxCommandEvent& WXUNUSED(event) )
{}

void LitesqlView::OnGenerate(wxCommandEvent& WXUNUSED(event) )
{
  wxGetApp().m_pGenerateViewTemplate->CreateView(GetDocument());
}

