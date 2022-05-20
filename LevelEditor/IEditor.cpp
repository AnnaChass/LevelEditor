///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "IEditor.h"

///////////////////////////////////////////////////////////////////////////

Frame::Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	Menubar = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* NewMenuItem;
	NewMenuItem = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("New") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( NewMenuItem );
	
	wxMenuItem* LoadMenuItem;
	LoadMenuItem = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( LoadMenuItem );
	
	wxMenuItem* SaveMenuItem;
	SaveMenuItem = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( SaveMenuItem );
	
	wxMenuItem* CloseMenuItem;
	CloseMenuItem = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Close") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( CloseMenuItem );
	
	Menubar->Append( FileMenu, wxT("File") ); 
	
	EditMenu = new wxMenu();
	wxMenuItem* CursorMenuItem;
	CursorMenuItem = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("Cursor") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( CursorMenuItem );
	
	AddSubmenu = new wxMenu();
	wxMenuItem* AddSubmenuItem = new wxMenuItem( EditMenu, wxID_ANY, wxT("Add"), wxEmptyString, wxITEM_NORMAL, AddSubmenu );
	#if (defined( __WXMSW__ ) || defined( __WXGTK__ ) || defined( __WXOSX__ ))
	AddSubmenuItem->SetBitmap( wxNullBitmap );
	#endif
	
	wxMenuItem* WallMenuItem;
	WallMenuItem = new wxMenuItem( AddSubmenu, wxID_ANY, wxString( wxT("Wall") ) , wxEmptyString, wxITEM_NORMAL );
	AddSubmenu->Append( WallMenuItem );
	
	wxMenuItem* DestWallMenuItem;
	DestWallMenuItem = new wxMenuItem( AddSubmenu, wxID_ANY, wxString( wxT("Destructible wall") ) , wxEmptyString, wxITEM_NORMAL );
	AddSubmenu->Append( DestWallMenuItem );
	
	wxMenuItem* LadderMenuItem;
	LadderMenuItem = new wxMenuItem( AddSubmenu, wxID_ANY, wxString( wxT("Ladder") ) , wxEmptyString, wxITEM_NORMAL );
	AddSubmenu->Append( LadderMenuItem );
	
	wxMenuItem* SpawnMenuItem;
	SpawnMenuItem = new wxMenuItem( AddSubmenu, wxID_ANY, wxString( wxT("Spawn") ) , wxEmptyString, wxITEM_NORMAL );
	AddSubmenu->Append( SpawnMenuItem );
	
	EditMenu->Append( AddSubmenuItem );
	
	wxMenuItem* DeleteMenuItem;
	DeleteMenuItem = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( DeleteMenuItem );
	
	Menubar->Append( EditMenu, wxT("Edit") ); 
	
	this->SetMenuBar( Menubar );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( NewMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::NewClick ) );
	this->Connect( LoadMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::LoadClick ) );
	this->Connect( SaveMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::SaveClick ) );
	this->Connect( CloseMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::CloseClick ) );
	this->Connect( CursorMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::CursorClick ) );
	this->Connect( WallMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::WallClick ) );
	this->Connect( DestWallMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::DestWallClick ) );
	this->Connect( LadderMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::LadderClick ) );
	this->Connect( SpawnMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::SpawnClick ) );
	this->Connect( DeleteMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::DeleteClick ) );
}

Frame::~Frame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::NewClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::LoadClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::SaveClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::CloseClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::CursorClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::WallClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::DestWallClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::LadderClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::SpawnClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::DeleteClick ) );
	
}
