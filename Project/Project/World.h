#pragma once
#include <SFML\Graphics.hpp>
#include "JSONReader.h"
#include "WorldObject.h"

class World
{
public:
	World();
	~World();
	void Render(sf::RenderWindow &w);

	vector<WorldObject> getWorld() { return world; }

private:

	JSONReader m_jR;
	vector<vector<string>> worldID;
	vector<WorldObject> worldObj;
	vector<WorldObject> world;

};

