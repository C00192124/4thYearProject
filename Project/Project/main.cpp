#include "SFML\Graphics.hpp"
#include "Player.h"
#include "InputManager.h"
#include "World.h"
#include "NPC.h"
#include "SoundManager.h"

sf::Event event;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "4th Year Project");
	window.setFramerateLimit(60);
	
	InputManager *input = new InputManager(event);
	SoundManager sound;
	World world;
	Player player;

	vector<NPC> characters;
	NPC npc("Resources/JSON/character1.json");
	characters.push_back(npc);

	while (window.isOpen())
	{
		
		input->CheckInput(window);
		sound.Background();
		window.setView(player.GetView());
		player.Update(input, characters, world);
		
		window.clear();
		//draw
		world.Render(window);
		for (int i = 0; i < characters.size(); i++)
		{
			characters.at(i).Render(window);
		}
		player.Render(window);

		window.display();
	}

}