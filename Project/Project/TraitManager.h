#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TraitManager
{
public:
	TraitManager();
	TraitManager(vector<int> traits);
	vector<int> GetTraits();
	~TraitManager();

private:
	int openness;
	int conscientious;
	int extroversion;
	int agreeableness;
	int neuroticism;

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

