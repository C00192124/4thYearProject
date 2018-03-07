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
	vector<sf::IntRect> getWorld();

private:

	JSONReader m_jR;
	vector<WorldObject> worldObj;
	vector<vector<string>> worldID;
	vector<sf::Sprite> worldSprite;
	vector<sf::Texture> worldTexture;
	vector<sf::IntRect> collisionRects;
	int index;

};

