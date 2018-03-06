#include "World.h"
#include <iostream>

World::World()
{
	m_jR.Init("Resources/JSON/world.json");
	worldID = m_jR.loadWorld();
	worldObj = m_jR.loadWorldObjects();

	for (int k = 0; k < worldObj.size(); k++)
	{
		worldObj.at(k).m_texture.loadFromFile(worldObj.at(k).getPath());
		worldObj.at(k).m_sprite.setTexture(worldObj.at(k).m_texture);
	}

	for (int i = 0; i < worldID.size(); i++)
	{
		for (int j = 0; j < worldID.at(0).size(); j++)
		{
			for (int l = 0; l < worldObj.size(); l++)
			{
				if (worldID[i][j] == worldObj.at(l).getID())
				{
					WorldObject w = WorldObject(worldObj.at(l));
					sf::Vector2f v = sf::Vector2f(j * 64, i * 64);
					w.m_sprite.setPosition(v);
					world.push_back(w);
				}
			}
		}
	}
	cout << "done" << endl;
}

void World::Render(sf::RenderWindow &w)
{
	for (int i = 0; i < world.size(); i++)
	{
		w.draw(world.at(i).m_sprite);
	}
}

World::~World(){}
