#include "BarChart.h"

BarChart::BarChart(int xPos, int yPos)
{
	m_position.x = xPos;
	m_position.y = yPos;
	m_outline.setOutlineThickness(2);
	m_outline.setOutlineColor(sf::Color::Magenta);
	m_outline.setSize(sf::Vector2f(100, 100));
	m_outline.setFillColor(sf::Color::Black);
	m_font.loadFromFile("Resources/arial.ttf");
	m_chartInfo.setCharacterSize(32);
	m_chartInfo.setFillColor(sf::Color::Cyan);
	m_chartInfo.setFont(m_font);
}

void BarChart::AddBar(int value, sf::Color color, string name)
{
	sf::RectangleShape rS;
	rS.setFillColor(color);
	rS.setSize(sf::Vector2f(20, value));
	m_barChart.push_back(rS);
	m_outline.setSize(sf::Vector2f(m_barChart.size() * 20, 100));
	m_info.append(name + ": " + to_string(value) + "\n");
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

	m_chartInfo.setString(m_info);
}

void BarChart::Render(sf::RenderWindow &w)
{
	m_outline.setPosition(w.mapPixelToCoords(sf::Vector2i(m_position)));
	w.draw(m_outline);
	
	for (int i = 0; i < m_barChart.size(); i++)
	{
		m_barChart.at(i).setPosition(w.mapPixelToCoords(sf::Vector2i(sf::Vector2f((m_position.x + (i * 20)), (m_position.y + (100 - m_barChart.at(i).getLocalBounds().height))))));
		w.draw(m_barChart.at(i));
	}
	
	if (drawInfo)
	{
		m_chartInfo.setPosition(m_position.x, m_position.y + 100);
		w.draw(m_chartInfo);
	}
}