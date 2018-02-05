#include "NPC.h"

NPC::NPC(string jsonFile)
{
	m_jR = JSONReader(jsonFile);
	m_traits = m_jR.loadTraits();
	m_spriteFile = m_jR.loadSprite();
	m_tM = TraitManager(m_traits);
	m_dM = DialogueManager(m_jR);
	m_texture.loadFromFile(m_spriteFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(500, 500);
}

void NPC::Update(sf::Sprite &s, InputManager *i)
{
	if (SpeakCollision(s, i))
	{
		//trigger speach
	}
}

bool NPC::SpeakCollision(sf::Sprite &s, InputManager *i)
{
	if (i->space)
	{
		if (CalculateCollision(s.getPosition().x - 32, s.getPosition().x + s.getLocalBounds().width + 32, s.getPosition().y - 32, s.getPosition().y + s.getLocalBounds().height + 32))
		{
			cout << "Speak" << endl;
			return true;
		}
		else return false;
	}
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

NPC::~NPC(){}
