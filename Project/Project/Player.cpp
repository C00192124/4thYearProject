#include "Player.h"

Player::Player()
{
	m_texture.loadFromFile("Resources/Sprites/player.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(100, 100);
	m_dir = Down;
	m_sprite.setTextureRect(sf::IntRect(0, m_dir * 32, 32, 32));
}

void Player::Update(InputManager *i)
{
	if (i->down) {
		m_dir = Down;
		m_sprite.move(0, 1);
	}
	if (i->up) {
		m_dir = Up;
		m_sprite.move(0, -1);
	}
	if (i->left) {
		m_dir = Left;
		m_sprite.move(-1, 0);
	}
	if (i->right) {
		m_dir = Right;
		m_sprite.move(1, 0);
	}
	
	//Animation
	if (i->up || i->down || i->left || i->right)
	{
		time = clock.getElapsedTime();
		if (time.asMilliseconds() >= 300)
		{
			m_timer++;
			if (m_timer * 32 >= m_texture.getSize().x)
				m_timer = 0;
			clock.restart();
		}
		m_sprite.setTextureRect(sf::IntRect(m_timer * 32, m_dir * 32, 32, 32));
	}
}

void Player::Collision(World &w)
{
	
}

Player::~Player() {}