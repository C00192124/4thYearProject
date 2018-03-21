#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BarChart.h"

using namespace std;

class TraitManager
{
public:
	TraitManager();
	TraitManager(vector<int> traits);
	~TraitManager();

	vector<int> GetTraits();
	void Update(sf::RenderWindow &w);
	void Render(sf::RenderWindow &w);

private:
	int openness;
	int conscientious;
	int extroversion;
	int agreeableness;
	int neuroticism;

	BarChart m_chart;

	void AddOpenness(int x);
	void SubOpenness(int x);
	void AddConscientious(int x);
	void SubConscientious(int x);
	void AddExtroversion(int x);
	void SubExtroversion(int x);
	void AddAgreeableness(int x);
	void SubAgreeableness(int x);
	void AddNeuroticism(int x);
	void SubNeuroticism(int x);
};

