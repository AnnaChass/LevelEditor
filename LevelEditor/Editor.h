#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "IEditorFrame.h"
#include "Level.h"
#include "Common.h"
#include <wx/wx.h>
#include <fstream>
#include <array>
#include <map>

class IEditorFrame;

class Editor : public wxApp
{
public:
	enum e_type
	{
		empty,
		simpleWall,
		destructibleWall,
		ladder,
		spawn
	};

private:
	class BasicTile
	{
	protected:
		int x;
		int y;

	public:
		BasicTile();
		BasicTile(int x, int y, bool additional = false);
		void setPosition(int x, int y);
		virtual int getTypeId() = 0;
		virtual ~BasicTile();
	};
	class Empty : public BasicTile
	{
	public:
		Empty(int x, int y);
		int getTypeId();
	};
	class Wall : public BasicTile
	{
	private:
		bool isDestructible;
	public:
		Wall(int x, int y, bool isDestructible = false);
		int getTypeId();
	};
	class Ladder : public BasicTile
	{
	public:
		Ladder(int x, int y);
		int getTypeId();
	};
	class Spawn : public BasicTile
	{
	public:
		Spawn(int x, int y);
		int getTypeId();
	};
	
	Level* p_level;
	IEditorFrame* p_frame;
	std::array<std::array<BasicTile *, HEIGHT_COUNT>, WIDTH_COUNT> p_tiles;
	enum
	{
		cursorMode,
		simpleWallMode,
		destructibleWallMode,
		ladderMode,
		spawnMode,
		deleteMode
	} curMode;
	int changingX;
	int changingY;

	void errorMessage(std::string msg);

public:
	Editor();
	~Editor();
	bool OnInit() wxOVERRIDE;

	void newLevel();
	void loadLevel(std::string filename);
	void saveLevel(std::string filename);

	void setCursorMode();
	void setAddWallMode();
	void setAddDestructibleWallMode();
	void setAddLadderMode();
	void setAddSpawnMode();
	void setDeleteItemMode();

	void changeItemPosition(int newX, int newY);
	
	void tileClicked(int x, int y);
};

DECLARE_APP(Editor)

