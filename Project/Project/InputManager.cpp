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
				break;

			case sf::Event::KeyReleased:
				if (m_event.key.code == sf::Keyboard::Down)
					down = false;
				break;

			default:
				break;
		}
		
	}
}

InputManager::~InputManager() {}
