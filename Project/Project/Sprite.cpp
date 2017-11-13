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
	if (i->down) {
		m_sprite.move(0, 1);
	}
	if (i->up) {
		m_sprite.move(0, -1);
	}
	if (i->left) {
		m_sprite.move(-1, 0);
	}
	if (i->right) {
		m_sprite.move(1, 0);
	}
}

Sprite::~Sprite() {}