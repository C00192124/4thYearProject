#include "SoundManager.h"

SoundManager::SoundManager()
{
	if (!m_buffer.loadFromFile("Resources/Sound/navigate.wav"))
	{
		cout << "Unable to open navigate" << endl;
	}
	if (!m_background1.openFromFile("Resources/Sound/background1.ogg"))
	{
		cout << "Unable to open background1" << endl;
	}
	if (!m_background2.openFromFile("Resources/Sound/background2.ogg"))
	{
		cout << "Unable to open background2" << endl;
	}
	m_background1.play();
}

void SoundManager::PlayNavigate()
{
	m_sound.setBuffer(m_buffer);
	m_sound.play();
}

void SoundManager::Background()
{
	
}

SoundManager::~SoundManager() {}
