#include "SFML\Graphics.hpp"
#include "Player.h"
#include "InputManager.h"
#include "World.h"

sf::Event event;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "4th Year Project");
	window.setFramerateLimit(60);
	InputManager *input = new InputManager(event);
	World world;
	Player player;

	while (window.isOpen())
	{
		input->CheckInput(window);
		player.Update(input);

		window.clear();
		//draw
		world.Render(window);
		player.Render(window);

		window.display();
	}

}