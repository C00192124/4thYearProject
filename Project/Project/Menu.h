#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "GameState.h"
#include "InputManager.h"

#define Max_Number_Of_Items 2

class Menu
{

public:
	Menu() {}
	Menu(float sW, float sH, InputManager *i);
	~Menu() {}

	void draw(sf::RenderWindow &);
	void moveDown();
	void moveUp();
	void update();
	void selectedItem(sf::RenderWindow &r, GameState &s);
	int getPressedItem() { return m_selectedItem; }

private:
	sf::Sprite m_menuSprite;
	sf::Font m_font;
	sf::Text m_menuText[Max_Number_Of_Items];
	sf::Texture m_menuTexture;
	int m_selectedItem;
	InputManager *m_input;
	int m_timer;
};