#pragma once
#include <SFML\Graphics.hpp>

class World
{
public:
	World();
	~World();
	void Render(sf::RenderWindow &w);

private:
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

	int m_world[10][10] = { 
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,0 },
		{ 0,0,0,0,0,0,0,0,0,0 } 
	};
};

