#include "Editor.h"

IMPLEMENT_APP(Editor)

bool Editor::OnInit()
{
	p_frame = new IEditorFrame((wxWindow*)NULL);
	p_frame->setEditor(this);
	p_frame->Show();
	SetTopWindow(p_frame);
	return true;
}

Editor::Editor() 
{	curMode = cursorMode;
	p_level = new Level(this);
	Sleep(100);

	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			p_tiles[i][j] = new Empty(i, j);
			p_level->setEmpty(i, j);
		}
	}

	changingX = -1;
	changingY = -1;
}

void Editor::errorMessage(std::string msg)
{
	wxMessageDialog errorMessage(NULL, msg, ERROR_TITLE, wxOK | wxICON_ERROR);
	errorMessage.ShowModal();
}

Editor::~Editor()
{
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			delete(p_tiles[i][j]);
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

void Editor::loadLevel(std::string filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		newLevel();
		errorMessage("The file could not be opened.");
		return;
	}
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			if (!file)
			{
				newLevel();
				errorMessage("The file is corrupted!");
				return;
			}

			int type = -1;
			file.sync();
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
				newLevel();
				errorMessage("The file is corrupted!");
				return;
			}
		}
	}
	file.close();
}

void Editor::saveLevel(std::string filename)
{
	std::ofstream file(filename);
	if (!file)
	{
		newLevel();
		errorMessage("The file could not be opened.");
		return;
	}
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
	changingX = -1;
	changingY = -1;

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

void Editor::changeItemPosition(int newX, int newY)
{
	if (changingX < 0 || changingY < 0)
		return;

	int type = p_tiles[changingX][changingY]->getTypeId();

	delete(p_tiles[changingX][changingY]);
	p_tiles[changingX][changingY] = new Empty(changingX, changingY);
	p_level->setEmpty(changingX, changingY);

	int x = (newX > 0) ? newX : changingX;
	int y = (newY > 0) ? newY : changingY;

	delete(p_tiles[x][y]);
	switch (type)
	{
	case empty:
		p_tiles[x][y] = new Empty(x, y);
		p_level->setEmpty(x, y);
		break;
	case simpleWall:
		p_tiles[x][y] = new Wall(x, y);
		p_level->setWall(x, y);
		break;
	case destructibleWall:
		p_tiles[x][y] = new Wall(x, y, true);
		p_level->setDestructibleWall(x, y);
		break;
	case ladder:
		p_tiles[x][y] = new Ladder(x, y);
		p_level->setLadder(x, y);
		break;
	case spawn:
		p_tiles[x][y] = new Spawn(x, y);
		p_level->setSpawn(x, y);
		break;
	}

	changingX = x;
	changingY = y;
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
		changingX = x;
		changingY = y;
		p_frame->setProperties(p_tiles[x][y]->getTypeId(), x, y);
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
	while (window.isOpen() && !stop)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseMoved:
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
					p_editor->tileClicked(mouseX / CELLSIZE, mouseY / CELLSIZE);
				break;
			default:
				break;
			}
		}

		draw();
	}
}
