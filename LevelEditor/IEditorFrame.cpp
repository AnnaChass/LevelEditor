#include "IEditorFrame.h"

IEditorFrame::IEditorFrame( wxWindow* parent )
:
Frame( parent )
{
	newX = -1;
	newY = -1;
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

void IEditorFrame::PositionXChange( wxSpinEvent& event )
{
	newX = PositionXSpin->GetValue();
}

void IEditorFrame::PositionYChange( wxSpinEvent& event )
{
	newY = PositionYSpin->GetValue();
}

void IEditorFrame::ChangePropertiesClick( wxCommandEvent& event )
{
p_editor->changeItemPosition(newX, newY);
newX = -1;
newY = -1;
}


void IEditorFrame::setProperties(int objectType, int x, int y)
{
	PositionXSpin->SetValue(x);
	PositionYSpin->SetValue(y);

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
		PositionXLabel->Show();
		PositionXSpin->Show();
		PositionYLabel->Show();
		PositionYSpin->Show();
		OkButton->Show();
	}
	else
	{
		PositionXSpin->SetValue(-1);
		PositionYSpin->SetValue(-1);
		ObjectLabel->Hide();
		ObjectInfo->Hide();
		PositionXLabel->Hide();
		PositionXSpin->Hide();
		PositionYLabel->Hide();
		PositionYSpin->Hide();
		OkButton->Hide();
	}
}