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

void NPC::Update()
{

}

NPC::~NPC(){}
