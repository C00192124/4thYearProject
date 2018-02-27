#pragma once
#include <SFML\Graphics.hpp>

class World
{
public:
	World();
	~World();
	void Render(sf::RenderWindow &w);

	int m_world[24][32] = {
		{ 8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,9 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,11,11,11,11,11,11,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		{ 6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7 }
	};

private:

	const int worldHeight = 24;
	const int worldWidth = 32;

	sf::Texture woodenFloorT;
	sf::Sprite woodenFloor;

	sf::Texture woodenFloorCrackedT;
	sf::Sprite woodenFloorCracked;

	sf::Texture topLeftWallT;
	sf::Sprite topLeftWall;

	sf::Texture bottomLeftWallT;
	sf::Sprite bottomLeftWall;

	sf::Texture topRightWallT;
	sf::Sprite topRightWall;

	sf::Texture bottomRightWallT;
	sf::Sprite bottomRightWall;

	sf::Texture leftWallT;
	sf::Sprite leftWall;

	sf::Texture rightWallT;
	sf::Sprite rightWall;

	sf::Texture topWallT;
	sf::Sprite topWall;

	sf::Texture bottomWallT;
	sf::Sprite bottomWall;

	sf::Texture tableT;
	sf::Sprite table;

	sf::Texture tileFloorT;
	sf::Sprite tileFloor;

};

