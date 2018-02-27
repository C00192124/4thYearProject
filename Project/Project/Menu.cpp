#include "Menu.h"

Menu::Menu(float sW, float sH, InputManager *i)
{
	m_input = i;
	m_timer = 0;
	m_selectedItem = 0;

	m_menuTexture.loadFromFile("Resources/Sprites/bg.png");
	m_menuSprite.setTexture(m_menuTexture);

	m_font.loadFromFile("Resources/arial.ttf");

	m_menuText[0].setFont(m_font);
	m_menuText[0].setFillColor(sf::Color::Red);
	m_menuText[0].setString("Begin");
	m_menuText[0].setCharacterSize(75);
	m_menuText[0].setPosition(sf::Vector2f(sW / 2.5, sH / (Max_Number_Of_Items + 1) * 1));
	
	m_menuText[1].setFont(m_font);
	m_menuText[1].setFillColor(sf::Color::White);
	m_menuText[1].setString("Exit");
	m_menuText[1].setCharacterSize(75);
	m_menuText[1].setPosition(sf::Vector2f(sW / 2.5, sH / (Max_Number_Of_Items + 1) * 1.8));

}

void Menu::draw(sf::RenderWindow &r)
{
	r.draw(m_menuSprite);

	for (int i = 0; i < Max_Number_Of_Items; i++)
	{
		r.draw(m_menuText[i]);
	}
}

void Menu::moveUp()
{
	if (m_selectedItem - 1 >= 0)
	{
		m_menuText[m_selectedItem].setFillColor(sf::Color::White);
		m_selectedItem--;
		m_menuText[m_selectedItem].setFillColor(sf::Color::Red);
	}
	else if (m_selectedItem + 1 < Max_Number_Of_Items)
	{
		m_menuText[m_selectedItem].setFillColor(sf::Color::White);
		m_selectedItem++;
		m_menuText[m_selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (m_selectedItem + 1 < Max_Number_Of_Items)
	{
		m_menuText[m_selectedItem].setFillColor(sf::Color::White);
		m_selectedItem++;
		m_menuText[m_selectedItem].setFillColor(sf::Color::Red);
	}
	else if (m_selectedItem - 1 >= 0)
	{
		m_menuText[m_selectedItem].setFillColor(sf::Color::White);
		m_selectedItem--;
		m_menuText[m_selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::selectedItem(sf::RenderWindow &r, GameState &s)
{
	if (s == GameState::MENU)
	{
		if (m_input->enter && m_selectedItem == 0)
		{
			s = GameState::GAME;
		}
		else if (m_input->enter && m_selectedItem == 1)
		{
			r.close();
		}
	}
}

void Menu::update()
{
	m_timer++;
	if (m_timer > 17)
	{
		if (m_input->up)
		{
			moveUp();
			m_timer = 0;
		}
		else if (m_input->down)
		{
			moveDown();
			m_timer = 0;
		}
	}
}