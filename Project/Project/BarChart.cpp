#include "BarChart.h"

void BarChart::Init(int xPos, int yPos)
{
	m_position.x = xPos;
	m_position.y = yPos;
	m_outline.setOutlineThickness(2);
	m_outline.setOutlineColor(sf::Color::Magenta);
	m_outline.setSize(sf::Vector2f(200, 200));
	m_outline.setFillColor(sf::Color::Black);
	m_font.loadFromFile("Resources/arial.ttf");
}

void BarChart::AddBar(int value, sf::Color color, string name)
{
	sf::RectangleShape rS;
	rS.setFillColor(color);
	rS.setSize(sf::Vector2f(40, value*2));
	m_barChart.push_back(rS);
	m_outline.setSize(sf::Vector2f(m_barChart.size() * 40, 200));
	m_info.append(name + ": " + to_string(value) + "\n");
	m_chartInfo.setString(sf::String(m_info));
	cout << m_info << endl;
}

void BarChart::Update(sf::RenderWindow &w, vector<int> traits)
{
	if ((sf::Mouse::getPosition(w).x < (m_position.x + m_outline.getSize().x))
		&& (sf::Mouse::getPosition(w).x > m_position.x)
		&& (sf::Mouse::getPosition(w).y < (m_position.y + m_outline.getSize().y))
		&& (sf::Mouse::getPosition(w).y > m_position.y))
	{
		drawInfo = true;
	}
	else drawInfo = false;
}

void BarChart::Render(sf::RenderWindow &w)
{
	m_outline.setPosition(w.mapPixelToCoords(sf::Vector2i(m_position)));
	w.draw(m_outline);
	
	for (int i = 0; i < m_barChart.size(); i++)
	{
		m_barChart.at(i).setPosition(w.mapPixelToCoords(sf::Vector2i(sf::Vector2f((m_position.x + (i * 40)), (m_position.y + (200 - m_barChart.at(i).getLocalBounds().height))))));
		w.draw(m_barChart.at(i));
	}
	
	if (drawInfo)
	{
		m_chartInfo.setFont(m_font);
		m_chartInfo.setCharacterSize(22);
		m_chartInfo.setFillColor(sf::Color::Cyan);
		m_chartInfo.setPosition(w.mapPixelToCoords(sf::Vector2i(sf::Vector2f(m_position.x, m_position.y + 200))));
		w.draw(m_chartInfo);
	}
}