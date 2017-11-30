#include "Player.h"

Player::Player()
{
	m_texture.loadFromFile("Resources/Sprites/player.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(100, 100);
	m_dir = Down;
	m_sprite.setTextureRect(sf::IntRect(0, m_dir * 64, 64, 64));
}

void Player::Update(InputManager *i)
{
	if (i->down) {
		m_dir = Down;
		m_sprite.move(0, 2);
	}
	if (i->up) {
		m_dir = Up;
		m_sprite.move(0, -2);
	}
	if (i->left) {
		m_dir = Left;
		m_sprite.move(-2, 0);
	}
	if (i->right) {
		m_dir = Right;
		m_sprite.move(2, 0);
	}
	
	//Animation
	if (i->up || i->down || i->left || i->right)
	{
		time = clock.getElapsedTime();
		if (time.asMilliseconds() >= 250)
		{
			m_timer++;
			if (m_timer * 64 >= m_texture.getSize().x)
				m_timer = 0;
			clock.restart();
		}
		m_sprite.setTextureRect(sf::IntRect(m_timer * 64, m_dir * 64, 64, 64));
	}
}

void Player::Collision(World &w)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			if (w.m_world[j][i] == 1)
			{

			}
		}
	}
}

Player::~Player() {}