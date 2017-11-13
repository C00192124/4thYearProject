#include "SFML\Graphics.hpp"
#include "Sprite.h"
#include "InputManager.h"

sf::Event event;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "4th Year Project");
	window.setFramerateLimit(60);
	InputManager *input = new InputManager(event);
	Sprite player;

	while (window.isOpen())
	{
		input->CheckInput(window);
		player.Update(input);

		window.clear();
		//draw
		player.Render(window);

		window.display();
	}

}