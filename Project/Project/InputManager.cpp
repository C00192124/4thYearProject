#include "InputManager.h"

InputManager::InputManager(sf::Event e)
{
	m_event = e;
}

void InputManager::CheckInput(sf::RenderWindow &w)
{
	while (w.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			w.close();
			break;

		case sf::Event::KeyPressed:
			if (m_event.key.code == sf::Keyboard::Down)
				down = true;
			if (m_event.key.code == sf::Keyboard::Up)
				up = true;
			if (m_event.key.code == sf::Keyboard::Left)
				left = true;
			if (m_event.key.code == sf::Keyboard::Right)
				right = true;
			if (m_event.key.code == sf::Keyboard::Space)
				space = true;
			if (m_event.key.code == sf::Keyboard::Return)
				enter = true;
			break;

		case sf::Event::KeyReleased:

			if (m_event.key.code == sf::Keyboard::Down)
				down = false;
			if (m_event.key.code == sf::Keyboard::Up)
				up = false;
			if (m_event.key.code == sf::Keyboard::Left)
				left = false;
			if (m_event.key.code == sf::Keyboard::Right)
				right = false;
			if (m_event.key.code == sf::Keyboard::Space)
				space = false;
			if (m_event.key.code == sf::Keyboard::Return)
				enter = false;
			break;

		default:
			break;
		}
		
	}
}

InputManager::~InputManager() {}
