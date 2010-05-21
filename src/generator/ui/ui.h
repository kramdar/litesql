///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ui__
#define __ui__

#include <wx/cshelp.h>
#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/checklst.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////

namespace ui
{
	///////////////////////////////////////////////////////////////////////////////
	/// Class ObjectPanel
	///////////////////////////////////////////////////////////////////////////////
	class ObjectPanel : public wxPanel 
	{
		private:
		
		protected:
			wxStaticText* lblName;
			wxTextCtrl* m_textCtrlName;
			wxStaticText* lblInherits;
			wxChoice* m_choiceInheritsFrom;
		
		public:
			ObjectPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,80 ), long style = wxTAB_TRAVERSAL );
			~ObjectPanel();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class FieldPanel
	///////////////////////////////////////////////////////////////////////////////
	class FieldPanel : public wxPanel 
	{
		private:
		
		protected:
		
		public:
			FieldPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,120 ), long style = wxTAB_TRAVERSAL );
			~FieldPanel();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class RelationPanel
	///////////////////////////////////////////////////////////////////////////////
	class RelationPanel : public wxPanel 
	{
		private:
		
		protected:
			wxStaticText* m_staticText2;
			wxTextCtrl* m_textCtrl2;
		
		public:
			RelationPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,120 ), long style = wxTAB_TRAVERSAL );
			~RelationPanel();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class AboutDialog
	///////////////////////////////////////////////////////////////////////////////
	class AboutDialog : public wxDialog 
	{
		private:
		
		protected:
			wxStaticText* m_staticText4;
			wxStaticText* m_staticText5;
			wxButton* m_btnClose;
		
		public:
			AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 345,320 ), long style = wxDEFAULT_DIALOG_STYLE );
			~AboutDialog();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class GeneratePanel
	///////////////////////////////////////////////////////////////////////////////
	class GeneratePanel : public wxPanel 
	{
		private:
		
		protected:
			wxStaticText* m_staticOutputDir;
			wxDirPickerCtrl* m_dirPickerOutputDir;
			wxStaticText* m_staticGenerators;
			wxCheckListBox* m_checkListGenerators;
			wxButton* m_buttonRun;
			wxGauge* m_gaugeRunProgress;
			
			// Virtual event handlers, overide them in your derived class
			virtual void OnRunClick( wxCommandEvent& event ){ event.Skip(); }
			
		
		public:
			GeneratePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,210 ), long style = wxTAB_TRAVERSAL );
			~GeneratePanel();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class DatabasePanel
	///////////////////////////////////////////////////////////////////////////////
	class DatabasePanel : public wxPanel 
	{
		private:
		
		protected:
			wxStaticText* m_staticName;
			wxTextCtrl* m_textName;
			wxStaticText* m_staticNamespace;
			wxTextCtrl* m_textNamespace;
			wxStaticText* m_staticInclude;
			wxTextCtrl* m_textInclude;
		
		public:
			DatabasePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,120 ), long style = wxTAB_TRAVERSAL );
			~DatabasePanel();
		
	};
	
} // namespace ui

#endif //__ui__
