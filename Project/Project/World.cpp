#include "World.h"

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
	bottomLeftWall.setTexture(bottomLeftWallT);
	rightWallT.loadFromFile("Resources/Sprites/rightWall.png");
	rightWall.setTexture(rightWallT);
	topWallT.loadFromFile("Resources/Sprites/topWall.png");
	topWall.setTexture(topWallT);
	bottomWallT.loadFromFile("Resources/Sprites/bottomWall.png");
	bottomWall.setTexture(bottomWallT);

}

void World::Render(sf::RenderWindow &w)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_world[i][j] == 0)
			{
				woodenFloorCracked.setPosition(sf::Vector2f(i * 32, j * 32));
				w.draw(woodenFloorCracked);
			}
			if (m_world[i][j] == 1)
			{
				woodenFloor.setPosition(sf::Vector2f(i * 32, j * 32));
				w.draw(woodenFloor);
			}
		}
	}
}

World::~World(){}
