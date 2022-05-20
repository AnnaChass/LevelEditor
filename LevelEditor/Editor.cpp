#include "Editor.h"

IMPLEMENT_APP(Editor)

bool Editor::OnInit()
{
	IEditorFrame* p_frame = new IEditorFrame((wxWindow*)NULL);
	p_frame->setEditor(this);
	p_frame->Show();
	SetTopWindow(p_frame);
	return true;
}

Editor::Editor() 
{
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			tiles[i][j].setType(Tile::empty);
			tiles[i][j].setPosition(j, i);
		}
	}

	curMode = cursorMode;
	p_level = new Level(this);
	Sleep(100);
}

void Editor::setAddDestructibleWallMode()
{
	curMode = destructibleWallMode;
}

void Editor::setDeleteItemMode()
{
	curMode = deleteMode;
}

void Editor::setAddLadderMode()
{
	curMode = ladderMode;
}

void Editor::setCursorMode()
{
	curMode = cursorMode;
}

void Editor::setAddSpawnMode()
{
	curMode = spawnMode;
}

Editor::~Editor()
{
	delete(p_level);
}

void Editor::newLevel()
{
}

void Editor::closeLevel()
{
}

void Editor::setAddWallMode()
{
	curMode = wallMode;
}

void Editor::tileClicked(int x, int y)
{
	switch (curMode)
	{
	case wallMode:
		tiles[x][y].setType(Tile::wall);
		p_level->setWall(x, y);
		break;
	case destructibleWallMode:
		tiles[x][y].setType(Tile::destructibleWall);
		p_level->setDestructibleWall(x, y);
		break;
	case ladderMode:
		tiles[x][y].setType(Tile::ladder);
		p_level->setLadder(x, y);
		break;
	case spawnMode:
		for (int i = 0; i < WIDTH_COUNT; i++)
		{
			bool isSpawnFound = false;
			for (int j = 0; j < HEIGHT_COUNT; j++)
			{
				if (tiles[i][j].getType() == Tile::spawn)
				{
					tiles[i][j].setType(Tile::empty);
					p_level->setEmpty(i, j);
					isSpawnFound = true;
					break;
				}
			}
			if (isSpawnFound)
				break;
		}
		tiles[x][y].setType(Tile::spawn);
		p_level->setSpawn(x, y);
		break;
	case deleteMode:
		tiles[x][y].setType(Tile::empty);
		p_level->setEmpty(x, y);
	}
	
}

// ---------------------------------------------------------- //

Editor::Tile::Tile()
{
	type = empty;
}

Editor::Tile::Tile(float x, float y) 
{
	type = empty;
	this->x = x;
	this->y = y;
}

void Editor::Tile::setType(e_type type)
{
	this->type = type;
}

void Editor::Tile::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

Editor::Tile::e_type Editor::Tile::getType()
{
	return type;
}

// ---------------------------------------------------------- //

void Level::graphics()
{
	window.create(sf::VideoMode(WIDTH_COUNT * CELLSIZE, HEIGHT_COUNT * CELLSIZE), "Level");
	calculateLines();
	calculateTiles();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if (event.type == sf::Event::Closed)
			//	window.close();
			switch (event.type)
			{
			case sf::Event::MouseMoved:
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					p_editor->tileClicked(mouseX / CELLSIZE, mouseY / CELLSIZE);
				}
				break;
			default:
				break;
			}
		}

		draw();
	}
}