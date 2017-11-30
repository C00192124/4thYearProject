#include "World.h"
#include <iostream>

World::World()
{

	woodenFloorT.loadFromFile("Resources/Sprites/woodenFloor.png");
	woodenFloor.setTexture(woodenFloorT);
	woodenFloorCrackedT.loadFromFile("Resources/Sprites/woodenFloorCracked.png");
	woodenFloorCracked.setTexture(woodenFloorCrackedT);
	topLeftWallT.loadFromFile("Resources/Sprites/topLeftWall.png");
	topLeftWall.setTexture(topLeftWallT);
	bottomLeftWallT.loadFromFile("Resources/Sprites/bottomLeftWall.png");
	bottomLeftWall.setTexture(bottomLeftWallT);
	topRightWallT.loadFromFile("Resources/Sprites/topRightWall.png");
	topRightWall.setTexture(topRightWallT);
	bottomRightWallT.loadFromFile("Resources/Sprites/bottomRightWall.png");
	bottomRightWall.setTexture(bottomRightWallT);
	leftWallT.loadFromFile("Resources/Sprites/leftWall.png");
	leftWall.setTexture(leftWallT);
	rightWallT.loadFromFile("Resources/Sprites/rightWall.png");
	rightWall.setTexture(rightWallT);
	topWallT.loadFromFile("Resources/Sprites/topWall.png");
	topWall.setTexture(topWallT);
	bottomWallT.loadFromFile("Resources/Sprites/bottomWall.png");
	bottomWall.setTexture(bottomWallT);

}

void World::Render(sf::RenderWindow &w)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			if (m_world[j][i] == 0)
			{
				woodenFloorCracked.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(woodenFloorCracked);
			}
			if (m_world[j][i] == 1)
			{
				woodenFloor.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(woodenFloor);
			}
			if (m_world[j][i] == 2)
			{
				leftWall.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(leftWall);
			}
			if (m_world[j][i] == 3)
			{
				rightWall.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(rightWall);
			}
			if (m_world[j][i] == 4)
			{
				topWall.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(topWall);
			}
			if (m_world[j][i] == 5)
			{
				bottomWall.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(bottomWall);
			}
		}
	}
}

World::~World(){}
