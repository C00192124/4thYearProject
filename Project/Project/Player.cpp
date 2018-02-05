#include "Player.h"

Player::Player()
{
	m_texture.loadFromFile("Resources/Sprites/player.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(100, 100);
	m_dir = Down;
	m_sprite.setTextureRect(sf::IntRect(0, m_dir * 64, 64, 64));
	camera = sf::View(sf::FloatRect(0, 0, 1024, 768));
}

void Player::Update(InputManager *i, vector<NPC> &n, World &w)
{
	camera.setCenter(m_sprite.getPosition().x, m_sprite.getPosition().y);

	if (i->down) {
		m_dir = Down;
		m_sprite.move(0, 2.5);
	}
	else if (i->up) {
		m_dir = Up;
		m_sprite.move(0, -2.5);
	}
	else if (i->left) {
		m_dir = Left;
		m_sprite.move(-2.5, 0);
	}
	else if (i->right) {
		m_dir = Right;
		m_sprite.move(2.5, 0);
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

	for (int z = 0; z < n.size(); z++)
	{
		SpriteCollision(n.at(z).m_sprite);
	}
	WorldCollision(w);
}

void Player::SpriteCollision(sf::Sprite &s)
{
	if (CalculateCollision(s.getPosition().x, s.getPosition().x + s.getLocalBounds().width, s.getPosition().y, s.getPosition().y + s.getLocalBounds().height))
	{
		if (m_dir == Right)
		{
			m_sprite.move(-2.5, 0);
		}
		if (m_dir == Left)
		{
			m_sprite.move(2.5, 0);
		}
		if (m_dir == Up)
		{
			m_sprite.move(0, 2.5);
		}
		if (m_dir == Down)
		{
			m_sprite.move(0, -2.5);
		}
	}
}

void Player::WorldCollision(World &w)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			if (w.m_world[j][i] == 2 || w.m_world[j][i] == 3 || w.m_world[j][i] == 4 || w.m_world[j][i] == 5)
			{
				if (CalculateCollision(i * 64, (i * 64) + 64, j * 64, (j * 64) + 64))
				{
					if (m_dir == Right)
					{
						m_sprite.move(-2.5, 0);
					}
					if (m_dir == Left)
					{
						m_sprite.move(2.5, 0);
					}
					if (m_dir == Up)
					{
						m_sprite.move(0, 2.5);
					}
					if (m_dir == Down)
					{
						m_sprite.move(0, -2.5);
					}
				}
			}
		}
	}
}

bool Player::CalculateCollision(float x, float width, float y, float height)
{
	if((m_sprite.getPosition().x + m_sprite.getLocalBounds().width >= x)
		&& (m_sprite.getPosition().x <= width)
		&& (m_sprite.getPosition().y + m_sprite.getLocalBounds().height >= y)
		&& (m_sprite.getPosition().y <= height))
	{
		return true;
	}
	else return false;
}

sf::View Player::GetView()
{
	return camera;
}

Player::~Player() {}