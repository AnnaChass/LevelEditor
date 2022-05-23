#include "IEditorFrame.h"

IEditorFrame::IEditorFrame( wxWindow* parent )
:
Frame( parent )
{

}

void IEditorFrame::NewClick( wxCommandEvent& event )
{
	p_editor->newLevel();
}

void IEditorFrame::LoadClick( wxCommandEvent& event )
{
wxFileDialog loadDialog(this);
if (loadDialog.ShowModal() == wxID_CANCEL)
return;

p_editor->loadLevel(std::string(loadDialog.GetPath()));
}

void IEditorFrame::SaveClick( wxCommandEvent& event )
{
wxFileDialog loadDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, wxEmptyString, wxFD_SAVE);
if (loadDialog.ShowModal() == wxID_CANCEL)
return;

p_editor->saveLevel(std::string(loadDialog.GetPath()));
}

void IEditorFrame::CursorClick( wxCommandEvent& event )
{
	p_editor->setCursorMode();
}

void IEditorFrame::WallClick( wxCommandEvent& event )
{
	p_editor->setAddWallMode();
}

void IEditorFrame::DestWallClick( wxCommandEvent& event )
{
	p_editor->setAddDestructibleWallMode();
}

void IEditorFrame::LadderClick( wxCommandEvent& event )
{
	p_editor->setAddLadderMode();
}

void IEditorFrame::SpawnClick( wxCommandEvent& event )
{
	p_editor->setAddSpawnMode();
}

void IEditorFrame::DeleteClick( wxCommandEvent& event )
{
	p_editor->setDeleteItemMode();
}


void IEditorFrame::setEditor(Editor* editor)
{
	p_editor = editor;
}