#include "World.h"
#include <iostream>

World::World()
{
	m_jR.Init("Resources/JSON/world.json");
	worldObj = m_jR.loadWorldObjects();
	worldID = m_jR.loadWorld();
	index = 0;

	for (int l = 0; l < worldObj.size(); l++)
	{
		worldTexture.push_back(sf::Texture());
		worldTexture.at(l).loadFromFile(worldObj.at(l).getPath());
	}

	for (int i = 0; i < worldID.size(); i++)
	{
		for (int j = 0; j < worldID.at(0).size(); j++)
		{
			for (int k = 0; k < worldObj.size(); k++)
			{
				if (worldID[i][j] == worldObj.at(k).getID())
				{
					worldSprite.push_back(sf::Sprite());
					worldSprite.at(index).setPosition(sf::Vector2f(j*64,i*64));
					worldSprite.at(index).setTexture(worldTexture.at(k));
					
					if (!worldObj.at(k).getPass())
					{
						sf::IntRect rS;
						rS.left = j*64;
						rS.top = i*64;
						rS.width = worldSprite.at(index).getLocalBounds().width;
						rS.height = worldSprite.at(index).getLocalBounds().height;
						collisionRects.push_back(rS);
					}
					index += 1;
				}
			}
		}
	}
}

vector<sf::IntRect> World::getWorld()
{
	return collisionRects;
}

void World::Render(sf::RenderWindow &w)
{
	for (int i = 0; i < worldSprite.size(); i++)
	{
		w.draw(worldSprite.at(i));
	}
}

World::~World(){}
