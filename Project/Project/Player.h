#pragma once
#include "Sprite.h"
#include "World.h"

class Player : public Sprite
{
public:
	Player();
	~Player();

	enum Direction { Down, Left, Right, Up };
	void Update(InputManager *i);

private:
	void Collision(World &w);

	Direction m_dir;
	int m_timer;
	sf::Clock clock;
	sf::Time time;
	
};