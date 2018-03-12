#include "Player.h"

Player::Player(vector<sf::IntRect> w)
{
	m_texture.loadFromFile("Resources/Sprites/player.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(6*64, 18*64);
	m_dir = Down;
	m_sprite.setTextureRect(sf::IntRect(0, m_dir * 64, 64, 64));
	camera = sf::View(sf::FloatRect(0, 0, 1024, 768));
	m_world = w;
}

void Player::Update(InputManager *i, vector<NPC> &n)
{
	camera.setCenter(m_sprite.getPosition().x, m_sprite.getPosition().y);

	if (i->s) {
		m_dir = Down;
		m_sprite.move(0, 2.5);
	}
	else if (i->w) {
		m_dir = Up;
		m_sprite.move(0, -2.5);
	}
	else if (i->a) {
		m_dir = Left;
		m_sprite.move(-2.5, 0);
	}
	else if (i->d) {
		m_dir = Right;
		m_sprite.move(2.5, 0);
	}
	
	//Animation
	if (i->w || i->s || i->a || i->d)
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
	WorldCollision();
}

void Player::Render(sf::RenderWindow &w)
{
	w.draw(m_sprite);
}

void Player::SpriteCollision(sf::Sprite &s)
{
	if (CalculateCollision(s.getPosition().x, s.getPosition().x + s.getLocalBounds().width, s.getPosition().y, s.getPosition().y + s.getLocalBounds().height))
	{
		if (m_dir == Right)
		{
			m_sprite.move(-2.5, 0);
		}
		else if (m_dir == Left)
		{
			m_sprite.move(2.5, 0);
		}
		if (m_dir == Up)
		{
			m_sprite.move(0, 2.5);
		}
		else if (m_dir == Down)
		{
			m_sprite.move(0, -2.5);
		}
	}
}

void Player::WorldCollision()
{
	for (int i = 0; i < m_world.size(); i++)
	{
		sf::IntRect r = m_world.at(i);
		if (CalculateCollision(r.left, r.left + r.width, r.top, r.top + r.height))
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