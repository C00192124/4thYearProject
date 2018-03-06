#pragma once
#include "Sprite.h"
#include "WorldObject.h"
#include "NPC.h"
#include <iostream>

class Player : public Sprite
{
public:
	Player();
	~Player();

	enum Direction { Down, Left, Right, Up };
	void Update(InputManager *i, vector<NPC> &n);
	void Render(sf::RenderWindow &w);
	sf::View GetView();

private:
	Direction m_dir;
	int m_timer;
	sf::Clock clock;
	sf::Time time;
	sf::View camera;

	bool CalculateCollision(float x, float width, float y, float height);
	void SpriteCollision(sf::Sprite &s);
	void WorldCollision();
	
};