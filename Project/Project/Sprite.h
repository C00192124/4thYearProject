#pragma once
#include "SFML\Graphics.hpp"
#include "InputManager.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	void Render(sf::RenderWindow &w);

	sf::Texture m_texture;
	sf::Sprite m_sprite;

private:


};