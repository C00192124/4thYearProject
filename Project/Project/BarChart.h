#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

class BarChart
{
public:

	BarChart() {}
	~BarChart() {}

	void Init(int xPos, int yPos);
	void AddBar(int value, sf::Color color, string name);
	void Update(sf::RenderWindow &w, vector<int> traits);
	void Render(sf::RenderWindow &w);

private:

	sf::Vector2f m_position;
	sf::RectangleShape m_outline;
	vector<sf::RectangleShape> m_barChart;
	sf::Text m_chartInfo;
	sf::Font m_font;
	string m_info;
	bool drawInfo = false;
};