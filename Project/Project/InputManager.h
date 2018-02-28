#pragma once
#include "SFML\Graphics.hpp"

class InputManager
{
public:
	InputManager(sf::Event e);
	~InputManager();
	void CheckInput(sf::RenderWindow &w);
	bool down = false;
	bool up = false;
	bool left = false;
	bool right = false;
	bool space = false;
	bool enter = false;
	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;

private:
	sf::Event m_event;
};

