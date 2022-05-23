#include "IEditorFrame.h"

IEditorFrame::IEditorFrame( wxWindow* parent )
:
Frame( parent )
{
	fileMode = nothing;
}

void IEditorFrame::NewClick( wxCommandEvent& event )
{
	p_editor->newLevel();
}

void IEditorFrame::LoadClick( wxCommandEvent& event )
{
	//Browse->SetWindowStyle(wxFLP_OPEN);
	setBrowserVisability();
	fileMode = load;
}

void IEditorFrame::SaveClick( wxCommandEvent& event )
{
	setBrowserVisability();
	fileMode = save;
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

void IEditorFrame::BrowseFile( wxFileDirPickerEvent& event )
{
	if (fileMode == load)
		p_editor->loadLevel(std::string(Browse->GetPath()));
	else if (fileMode == save)
		p_editor->saveLevel(std::string(Browse->GetPath()));

	fileMode = nothing;
	Browse->SetPath("");
	setBrowserVisability(false);
}


void IEditorFrame::setEditor(Editor* editor)
{
	p_editor = editor;
}

void IEditorFrame::setBrowserVisability(bool isVisible)
{
	if (isVisible)
		Browse->Show();
	else
		Browse->Hide();
}