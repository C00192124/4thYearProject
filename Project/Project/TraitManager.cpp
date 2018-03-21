#include "TraitManager.h"

TraitManager::TraitManager() {}

TraitManager::TraitManager(vector<int> traits)
{
	openness = traits.at(0);
	conscientious = traits.at(1);
	extroversion = traits.at(2);
	agreeableness = traits.at(3);
	neuroticism = traits.at(4);
	m_chart = BarChart(914, 10);
	m_chart.AddBar(openness, sf::Color::Blue, "Openness");
	m_chart.AddBar(conscientious, sf::Color::Yellow, "Conscientious");
	m_chart.AddBar(extroversion, sf::Color::Green, "Extroversion");
	m_chart.AddBar(agreeableness, sf::Color::Red, "Agreeableness");
	m_chart.AddBar(neuroticism, sf::Color::White, "Neuroticism");
}

vector<int> TraitManager::GetTraits()
{
	vector<int> traits;
	traits.push_back(openness);
	traits.push_back(conscientious);
	traits.push_back(extroversion);
	traits.push_back(agreeableness);
	traits.push_back(neuroticism);
	return traits;
}

void TraitManager::Update(sf::RenderWindow &w)
{
	m_chart.Update(w, GetTraits());
}

void TraitManager::Render(sf::RenderWindow &w)
{
	m_chart.Render(w);
}

void TraitManager::AddOpenness(int x) { openness + x; }

void TraitManager::SubOpenness(int x) { openness - x; }

void TraitManager::AddConscientious(int x) { conscientious + x; }

void TraitManager::SubConscientious(int x) { conscientious - x; }

void TraitManager::AddExtroversion(int x) { extroversion + x; }

void TraitManager::SubExtroversion(int x) { extroversion - x; }

void TraitManager::AddAgreeableness(int x) { agreeableness + x; }

void TraitManager::SubAgreeableness(int x) { agreeableness - x; }

void TraitManager::AddNeuroticism(int x) { neuroticism + x; }

void TraitManager::SubNeuroticism(int x) { neuroticism - x; }

TraitManager::~TraitManager() {}
