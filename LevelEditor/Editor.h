#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "IEditorFrame.h"
#include "Level.h"
#include "Common.h"
#include <wx/wx.h>
#include <fstream>
#include <array>
#include <map>


class Editor : public wxApp
{
public:
	class Tile
	{
	public:
		enum e_type
		{
			empty = -1,
			wall,
			destructibleWall,
			ladder,
			spawn
		};

	private:
		e_type type;
		float x;
		float y;

	public:
		Tile();
		Tile(float x, float y);
		void setType(e_type type);
		void setPosition(float x, float y);
		e_type getType();

	};

private:
	Level* p_level;
	std::array<std::array<Tile, HEIGHT_COUNT>, WIDTH_COUNT> tiles;
	enum
	{
		cursorMode,
		wallMode,
		destructibleWallMode,
		ladderMode,
		spawnMode,
		deleteMode
	} curMode;

public:
	Editor();
	~Editor();
	bool OnInit() wxOVERRIDE;
	void newLevel();
	void closeLevel();
	void setCursorMode();
	void setAddWallMode();
	void setAddDestructibleWallMode();
	void setAddLadderMode();
	void setAddSpawnMode();
	void setDeleteItemMode();
	
	void tileClicked(int x, int y);
};

DECLARE_APP(Editor)

