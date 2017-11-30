#include "SFML\Graphics.hpp"
#include "Player.h"
#include "InputManager.h"
#include "World.h"
#include "NPC.h"

sf::Event event;

void main()
{
	sf::RenderWindow window(sf::VideoMode(2048, 1536), "4th Year Project");
	window.setFramerateLimit(60);
	InputManager *input = new InputManager(event);
	World world;
	Player player;
	NPC npc("Resources/JSON/character1.json");

	while (window.isOpen())
	{
		input->CheckInput(window);
		player.Update(input);

		window.clear();
		//draw
		world.Render(window);
		npc.Render(window);
		player.Render(window);

		window.display();
	}

}