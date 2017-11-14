#include "Sprite.h"

Sprite::Sprite() {}

void Sprite::Render(sf::RenderWindow &w)
{
	w.draw(m_sprite);
}

Sprite::~Sprite() {}