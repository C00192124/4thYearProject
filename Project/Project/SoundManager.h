#pragma once
#include "SFML\Audio.hpp"
#include <iostream>

using namespace std;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void PlayNavigate();
	void Background();

private:
	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;
	sf::Music m_background1;
	sf::Music m_background2;

};

