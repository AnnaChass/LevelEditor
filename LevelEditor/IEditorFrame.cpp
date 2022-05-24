#include "IEditorFrame.h"

IEditorFrame::IEditorFrame( wxWindow* parent )
:
Frame( parent )
{
	
}

void IEditorFrame::NewClick( wxCommandEvent& event )
{
setPropertyVisability(false);
p_editor->newLevel();
}

void IEditorFrame::LoadClick( wxCommandEvent& event )
{
setPropertyVisability(false);
wxFileDialog loadDialog(this);
if (loadDialog.ShowModal() == wxID_CANCEL)
return;

p_editor->loadLevel(std::string(loadDialog.GetPath()));
}

void IEditorFrame::SaveClick( wxCommandEvent& event )
{
setPropertyVisability(false);
wxFileDialog loadDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, wxEmptyString, wxFD_SAVE);
if (loadDialog.ShowModal() == wxID_CANCEL)
return;

p_editor->saveLevel(std::string(loadDialog.GetPath()));
}

void IEditorFrame::CursorClick( wxCommandEvent& event )
{
setPropertyVisability();
p_editor->setCursorMode();
}

void IEditorFrame::WallClick( wxCommandEvent& event )
{
setPropertyVisability(false);
p_editor->setAddWallMode();
}

void IEditorFrame::DestWallClick( wxCommandEvent& event )
{
setPropertyVisability(false);
p_editor->setAddDestructibleWallMode();
}

void IEditorFrame::LadderClick( wxCommandEvent& event )
{
setPropertyVisability(false);
p_editor->setAddLadderMode();
}

void IEditorFrame::SpawnClick( wxCommandEvent& event )
{
setPropertyVisability(false);
p_editor->setAddSpawnMode();
}

void IEditorFrame::DeleteClick( wxCommandEvent& event )
{
setPropertyVisability(false);
p_editor->setDeleteItemMode();
}


void IEditorFrame::setProperties(int objectType, int x, int y)
{
	wxString str;
	str.append("(");
	str.append(std::to_string(x));
	str.append(",");
	str.append(std::to_string(y));
	str.append(")");
	PositionInfo->SetLabelText(str);
	switch(objectType)
	{
	case Editor::empty:
		ObjectInfo->SetLabelText("Empty tile");
		break;
	case Editor::simpleWall:
		ObjectInfo->SetLabelText("Indestructible wall");
		break;
	case Editor::destructibleWall:
		ObjectInfo->SetLabelText("Destructible wall");
		break;
	case Editor::ladder:
		ObjectInfo->SetLabelText("Ladder");
		break;
	case Editor::spawn:
		ObjectInfo->SetLabelText("Spawn");
		break;
	default:
		break;
	}
}

void IEditorFrame::setEditor(Editor* editor)
{
	p_editor = editor;
}

void IEditorFrame::setPropertyVisability(bool isVisible)
{
	if (isVisible)
	{
		ObjectLabel->Show();
		ObjectInfo->Show();
		PositionLabel->Show();
		PositionInfo->Show();
	}
	else
	{
		ObjectLabel->Hide();
		ObjectInfo->Hide();
		PositionLabel->Hide();
		PositionInfo->Hide();
	}
}