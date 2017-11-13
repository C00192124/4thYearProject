#include "Sprite.h"

Sprite::Sprite()
{
	m_texture.loadFromFile("player.png");
	m_sprite.setTexture(m_texture);
}

void Sprite::Render(sf::RenderWindow &w)
{
	w.draw(m_sprite);
}

void Sprite::Update(InputManager *i)
{
	if (i->down)
	{
		m_sprite.move(0, 1);
	}
}

Sprite::~Sprite() {}