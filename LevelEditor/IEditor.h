///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __IEDITOR_H__
#define __IEDITOR_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
class Frame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* Menubar;
		wxMenu* FileMenu;
		wxMenu* EditMenu;
		wxMenu* AddSubmenu;
		wxMenu* WallSubmenu;
		wxStaticText* ObjectLabel;
		wxStaticText* ObjectInfo;
		wxStaticText* PositionXLabel;
		wxSpinCtrl* PositionXSpin;
		wxStaticText* PositionYLabel;
		wxSpinCtrl* PositionYSpin;
		wxButton* OkButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void NewClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void LoadClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CursorClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void WallClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DestWallClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void LadderClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SpawnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void PositionXChange( wxSpinEvent& event ) { event.Skip(); }
		virtual void PositionYChange( wxSpinEvent& event ) { event.Skip(); }
		virtual void ChangePropertiesClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 623,301 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Frame();
	
};

#endif //__IEDITOR_H__
