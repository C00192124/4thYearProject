#include "SFML\Graphics.hpp"
#include "Player.h"
#include "InputManager.h"
#include "World.h"
#include "NPC.h"
#include "SoundManager.h"
#include "GameState.h"
#include "Menu.h"
#include "JSONReader.h"

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
	Player player(world.getWorld());

	vector<NPC> characters;
	NPC KevinLionetti;
	KevinLionetti.Init("Resources/JSON/kevinlionetti.json", sf::Vector2f(6*64,2*64));
	NPC ThomasSteinkeller;
	ThomasSteinkeller.Init("Resources/JSON/thomassteinkeller.json", sf::Vector2f(9*64, 10*64));
	characters.push_back(KevinLionetti);
	characters.push_back(ThomasSteinkeller);

	while (window.isOpen())
	{
		
		input->CheckInput(window);
		sound.Background();
		window.setView(player.GetView());


		//Update
		if (state == GameState::GAME)
		{
			bool temp = characters.at(0).m_speaking;
			if (!temp)
			{
				player.Update(input, characters);
			}
			for (int i = 0; i < characters.size(); i++)
			{
				characters.at(i).Update(player.m_sprite, input, window);
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