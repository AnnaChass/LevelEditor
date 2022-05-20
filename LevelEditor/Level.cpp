#include "Level.h"
#include <Windows.h>

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

Level::Level(Editor* editor) :
	graphicsThread(&Level::graphics, this),
	p_editor (editor)
{
}

Level::~Level()
{
	
}

void Level::setWall(int x, int y)
{
	tiles[x][y].setFillColor(sf::Color::Green);
}

void Level::setDestructibleWall(int x, int y)
{
	tiles[x][y].setFillColor(sf::Color::Magenta);
}

void Level::setLadder(int x, int y)
{
	tiles[x][y].setFillColor(sf::Color::Blue);
}

void Level::setSpawn(int x, int y)
{	
	tiles[x][y].setFillColor(sf::Color::Yellow);
}

void Level::setEmpty(int x, int y)
{
	tiles[x][y].setFillColor(sf::Color::White);
}

/*

Level::Tile::Tile() : shape(sf::Vector2f(CELLSIZE, CELLSIZE))
{
	type = empty;
	//shape.setPosition(sf::Vector2f(0, 0));
	shape.setFillColor(sf::Color::Green);
}

Level::Tile::Tile(float x, float y) : shape(sf::Vector2f(CELLSIZE, CELLSIZE))
{
	type = empty;
	shape.setPosition(sf::Vector2f(x, y));
	shape.setFillColor(sf::Color::Green);
}

void Level::Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

void Level::Tile::setType(e_type type)
{
	this->type = type;
}
*/