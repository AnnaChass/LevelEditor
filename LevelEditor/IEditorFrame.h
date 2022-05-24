#ifndef __IEditorFrame__
#define __IEditorFrame__

/**
@file
Subclass of Frame, which is generated by wxFormBuilder.
*/

#include "IEditor.h"

//// end generated include
#pragma once
#include "Editor.h"

class Editor;

/** Implementing Frame */
class IEditorFrame : public Frame
{
	protected:
		// Handlers for Frame events.
		void NewClick( wxCommandEvent& event );
		void LoadClick( wxCommandEvent& event );
		void SaveClick( wxCommandEvent& event );
		void CursorClick( wxCommandEvent& event );
		void WallClick( wxCommandEvent& event );
		void DestWallClick( wxCommandEvent& event );
		void LadderClick( wxCommandEvent& event );
		void SpawnClick( wxCommandEvent& event );
		void DeleteClick( wxCommandEvent& event );
		void PositionXChange( wxSpinEvent& event );
		void PositionYChange( wxSpinEvent& event );
		void ChangePropertiesClick( wxCommandEvent& event );
	public:
		/** Constructor */
		IEditorFrame( wxWindow* parent );
	//// end generated class members

		void setEditor(Editor* editor);
		void setProperties(int objectType, int x, int y);

	private:
		Editor* p_editor;

		void setPropertyVisability(bool isVisible = true);
		int newX;
		int newY;


};

#endif // __IEditorFrame__
