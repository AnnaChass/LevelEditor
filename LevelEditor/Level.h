#pragma once
#include "Common.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <array>

#define CELLSIZE 45

class Editor;

class Level
{
private:
	sf::RenderWindow window;
	std::thread graphicsThread;
	Editor* p_editor;

	sf::Image spawnImage;
	sf::Texture emptyTexture;
	sf::Texture simpleWallTexture;
	sf::Texture destructibleWallTexture;
	sf::Texture ladderTexture;
	sf::Texture spawnTexture;

	sf::VertexArray verticalLines;
	sf::VertexArray horizontalLines;

	std::array<std::array<sf::RectangleShape, HEIGHT_COUNT>, WIDTH_COUNT> tiles;
	int mouseX;
	int mouseY;
	bool stop;

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

