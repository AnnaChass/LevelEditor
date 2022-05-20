#pragma once
#include "Common.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <array>

#define CELLSIZE 40

class Editor;

class Level
{
private:
	sf::RenderWindow window;
	std::thread graphicsThread;
	Editor* p_editor;

	sf::VertexArray verticalLines;
	sf::VertexArray horizontalLines;

	/*class Tile : public sf::Drawable
	{
	public:
		enum e_type
		{
			empty = -1,
			wall,
			destWall,
			ladder,
			spawn
		};

	private:
		sf::RectangleShape shape;
		e_type type;

	public:
		Tile();
		Tile(float x, float y);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setType(e_type type);

	};
	std::array<std::array<Tile, WIDTH_COUNT>, HEIGHT_COUNT> infoTiles;*/
	std::array<std::array<sf::RectangleShape, HEIGHT_COUNT>, WIDTH_COUNT> tiles;
	int mouseX;
	int mouseY;

	void calculateLines();
	void calculateTiles();
	void draw();
	void graphics();

public:
	Level(Editor* editor);
	~Level();

	void setWall(int x, int y);
	void setDestructibleWall(int x, int y);
	void setLadder(int x, int y);
	void setSpawn(int x, int y);
	void setEmpty(int x, int y);
};

