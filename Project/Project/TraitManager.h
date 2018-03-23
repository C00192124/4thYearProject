#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BarChart.h"

using namespace std;

class TraitManager
{
public:
	TraitManager() {}
	TraitManager(vector<int> traits);
	~TraitManager() {}

	vector<int> GetTraits();
	void UpdateTraits(int o, int c, int e, int a, int n);
	void Update(sf::RenderWindow &w);
	void Render(sf::RenderWindow &w);

private:
	int openness;
	int conscientious;
	int extroversion;
	int agreeableness;
	int neuroticism;

	BarChart m_chart;
};

