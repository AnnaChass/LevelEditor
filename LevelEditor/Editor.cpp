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
			p_tiles[i][j] = new Empty(i, j);
		}
	}

	curMode = cursorMode;
	p_level = new Level(this);
	Sleep(100);
}

Editor::~Editor()
{
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			delete(p_tiles[i][j]);
			p_level->setEmpty(i, j);
		}
	}
	delete(p_level);
}

void Editor::newLevel()
{
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			delete(p_tiles[i][j]);
			p_tiles[i][j] = new Empty(i, j);
			p_level->setEmpty(i, j);
		}
	}
}

void Editor::loadLevel()
{
	std::fstream file("1.txt");
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			int type;
			file >> type;
			switch (type)
			{
			case empty:
				delete(p_tiles[i][j]);
				p_tiles[i][j] = new Empty(i, j);
				p_level->setEmpty(i, j);
				break;
			case simpleWall:
				delete(p_tiles[i][j]);
				p_tiles[i][j] = new Wall(i, j);
				p_level->setWall(i, j);
				break;
			case destructibleWall:
				delete(p_tiles[i][j]);
				p_tiles[i][j] = new Wall(i, j, true);
				p_level->setDestructibleWall(i, j);
				break;
			case ladder:
				delete(p_tiles[i][j]);
				p_tiles[i][j] = new Ladder(i, j);
				p_level->setLadder(i, j);
				break;
			case spawn:
				delete(p_tiles[i][j]);
				p_tiles[i][j] = new Spawn(i, j);
				p_level->setSpawn(i, j);
				break;
			default:
				break;
			}
			
		}
	}
	file.close();
}

void Editor::saveLevel()
{
	std::fstream file("1.txt");
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			file << p_tiles[i][j]->getTypeId() << " ";
		}
	}
	file.close();
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

void Editor::setAddWallMode()
{
	curMode = simpleWallMode;
}

void Editor::tileClicked(int x, int y)
{
	switch (curMode)
	{
	case simpleWallMode:
		if (p_tiles[x][y]->getTypeId() != simpleWall)
		{
			delete(p_tiles[x][y]);
			p_tiles[x][y] = new Wall(x, y);
			p_level->setWall(x, y);
		}
		break;
	case destructibleWallMode:
		if (p_tiles[x][y]->getTypeId() != destructibleWall)
		{
			delete(p_tiles[x][y]);
			p_tiles[x][y] = new Wall(x, y, true);
			p_level->setDestructibleWall(x, y);
		}
		break;
	case ladderMode:
		if (p_tiles[x][y]->getTypeId() != ladder)
		{
			delete(p_tiles[x][y]);
			p_tiles[x][y] = new Ladder(x, y);
			p_level->setLadder(x, y);
		}
		break;
	case spawnMode:
		if (p_tiles[x][y]->getTypeId() != spawn)
		{
			// delete previous spawn tile
			for (int i = 0; i < WIDTH_COUNT; i++)
			{
				bool isSpawnFound = false;
				for (int j = 0; j < HEIGHT_COUNT; j++)
				{
					if (p_tiles[i][j]->getTypeId() == spawn)
					{
						delete(p_tiles[i][j]);
						p_tiles[i][j] = new Empty(i, j);
						p_level->setEmpty(i, j);
						isSpawnFound = true;
						break;
					}
				}
				if (isSpawnFound)
					break;
			}
			// add new spawn tile
			delete(p_tiles[x][y]);
			p_tiles[x][y] = new Spawn(x, y);
			p_level->setSpawn(x, y);
		}
		break;
	case deleteMode:
		if (p_tiles[x][y]->getTypeId() != empty)
		{
			delete(p_tiles[x][y]);
			p_tiles[x][y] = new Empty(x, y);
			p_level->setEmpty(x, y);
		}
		break;
	case cursorMode:
		break;
	default:
		break;
	}	
}

// ---------------------------------------------------------- //

Editor::BasicTile::BasicTile()
{
}

Editor::BasicTile::BasicTile(int x, int y, bool additional)
{
	this->x = x;
	this->y = y;
}

void Editor::BasicTile::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

Editor::BasicTile::~BasicTile()
{
}

// ---------------------------------------------------------- //

Editor::Empty::Empty(int x, int y) : BasicTile::BasicTile(x, y)
{
}

int Editor::Empty::getTypeId()
{
	return empty;
}

// ---------------------------------------------------------- //

Editor::Wall::Wall(int x, int y, bool isDestructible) : BasicTile::BasicTile(x, y, isDestructible)
{
	this->isDestructible = isDestructible;
}

int Editor::Wall::getTypeId()
{
	if (isDestructible)
		return destructibleWall;
	return simpleWall;
}

// ---------------------------------------------------------- //

Editor::Ladder::Ladder(int x, int y) : BasicTile::BasicTile(x, y)
{
}

int Editor::Ladder::getTypeId()
{
	return ladder;
}

// ---------------------------------------------------------- //

Editor::Spawn::Spawn(int x, int y) : BasicTile::BasicTile(x, y)
{
}

int Editor::Spawn::getTypeId()
{
	return spawn;
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
