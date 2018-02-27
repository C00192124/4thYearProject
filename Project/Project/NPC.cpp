#include "NPC.h"

void NPC::Init(string jsonFile)
{
	m_jR = JSONReader(jsonFile);
	m_traits = m_jR.loadTraits();
	m_spriteFile = m_jR.loadSprite();
	m_tM = TraitManager(m_traits);
	m_dM.Init(m_jR);
	m_texture.loadFromFile(m_spriteFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(300, 300);
	m_speaking = false;
	m_speakTimer = 0;
}

void NPC::Update(sf::Sprite &s, InputManager *i)
{
	if (!m_speaking)
	{
		if (SpeakCollision(s, i))
		{
			//trigger speach
			cout << "Trigger Speech" << endl;
			m_dM.DisplayText();
			m_speaking = true;
		}
	}
	else
	{
		m_speakTimer++;
		if (i->up && m_speakTimer > 20)
		{
			m_dM.MoveUp();
			m_speakTimer = 0;
		}
		else if (i->down && m_speakTimer > 20)
		{
			m_dM.MoveDown();
			m_speakTimer = 0;
		}
	}
}

void NPC::Render(sf::RenderWindow &w)
{
	w.draw(m_sprite);
	if (m_speaking)
	{
		m_dM.Render(w);
	}
}

bool NPC::SpeakCollision(sf::Sprite &s, InputManager *i)
{
	if (i->space)
	{
		if (CalculateCollision(s.getPosition().x - 32, s.getPosition().x + s.getLocalBounds().width + 32, s.getPosition().y - 32, s.getPosition().y + s.getLocalBounds().height + 32))
		{
			return true;
		}
		else return false;
	}
	else return false;
}

bool NPC::CalculateCollision(float x, float width, float y, float height)
{
	if ((m_sprite.getPosition().x + m_sprite.getLocalBounds().width >= x)
		&& (m_sprite.getPosition().x <= width)
		&& (m_sprite.getPosition().y + m_sprite.getLocalBounds().height >= y)
		&& (m_sprite.getPosition().y <= height))
	{
		return true;
	}
	else return false;
}