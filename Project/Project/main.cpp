#include "SFML\Graphics.hpp"
#include "Player.h"
#include "InputManager.h"
#include "World.h"
#include "NPC.h"
#include "SoundManager.h"
#include "GameState.h"
#include "Menu.h"

sf::Event event;

void main()
{
	float windowWidth = 1024;
	float windowHeight = 768;

	GameState state = GameState::MENU;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "4th Year Project");
	window.setFramerateLimit(60);
	
	InputManager *input = new InputManager(event);
	Menu menu(windowWidth, windowHeight, input);
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


		//Update
		if (state == GameState::GAME)
		{
			player.Update(input, characters, world);
			for (int i = 0; i < characters.size(); i++)
			{
				characters.at(i).Update(player.m_sprite, input);
			}
		}
		else
		{
			menu.update();
			menu.selectedItem(window, state);
		}

		//draw
		window.clear();
		
		if (state == GameState::GAME)
		{
			world.Render(window);
			for (int i = 0; i < characters.size(); i++)
			{
				characters.at(i).Render(window);
			}
			player.Render(window);
		}
		else
		{
			menu.draw(window);
		}

		window.display();
	}

}