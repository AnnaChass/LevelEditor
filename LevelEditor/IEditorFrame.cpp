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
	p_editor->loadLevel();
}

void IEditorFrame::SaveClick( wxCommandEvent& event )
{
	p_editor->saveLevel();
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