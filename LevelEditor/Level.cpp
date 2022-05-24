#include "Level.h"
#include <Windows.h>

Level::Level(Editor* editor) :
	graphicsThread(&Level::graphics, this),
	p_editor(editor)
{
	emptyTexture.loadFromFile("images//empty.bmp");
	simpleWallTexture.loadFromFile("images//simpleWall.bmp");
	destructibleWallTexture.loadFromFile("images//destructibleWall.bmp");
	ladderTexture.loadFromFile("images//ladder.bmp");
	spawnTexture.loadFromFile("images//spawn.bmp");

	stop = false;
}

Level::~Level()
{
	stop = true;
	graphicsThread.join();
}

void Level::calculateLines()
{
	verticalLines = sf::VertexArray(sf::Lines, (WIDTH_COUNT - 1) * 2);
	for (int i = 0; i < WIDTH_COUNT - 1; i++)
	{
		verticalLines[2 * i].position = sf::Vector2f((i + 1) * CELLSIZE, 0);
		verticalLines[2 * i].color = sf::Color::Black;

		verticalLines[2 * i + 1].position = sf::Vector2f((i + 1) * CELLSIZE, HEIGHT_COUNT * CELLSIZE);
		verticalLines[2 * i + 1].color = sf::Color::Black;
	}

	horizontalLines = sf::VertexArray(sf::Lines, (HEIGHT_COUNT - 1) * 2);
	for (int i = 0; i < HEIGHT_COUNT - 1; i++)
	{
		horizontalLines[2 * i].position = sf::Vector2f(0, (i + 1) * CELLSIZE);
		horizontalLines[2 * i].color = sf::Color::Black;

		horizontalLines[2 * i + 1].position = sf::Vector2f(WIDTH_COUNT * CELLSIZE, (i + 1) * CELLSIZE);
		horizontalLines[2 * i + 1].color = sf::Color::Black;
	}
}

void Level::calculateTiles()
{
	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{
			tiles[i][j].setPosition(i * CELLSIZE, j * CELLSIZE);
			tiles[i][j].setSize({ CELLSIZE, CELLSIZE });
		}
	}
}

void Level::draw()
{
	window.clear(sf::Color::White);

	for (auto _tiles : tiles)
	{
		for (auto elem : _tiles)
		{
			window.draw(elem);
		}
	}
	window.draw(verticalLines);
	window.draw(horizontalLines);

	window.display();
}

void Level::setWall(int x, int y)
{
	tiles[x][y].setTexture(&simpleWallTexture);
}

void Level::setDestructibleWall(int x, int y)
{
	tiles[x][y].setTexture(&destructibleWallTexture);
}

void Level::setLadder(int x, int y)
{
	tiles[x][y].setTexture(&ladderTexture);
}

void Level::setSpawn(int x, int y)
{
	tiles[x][y].setTexture(&spawnTexture);
}

void Level::setEmpty(int x, int y)
{
	tiles[x][y].setTexture(&emptyTexture);
}