#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Dialogue
{
public:
	Dialogue(string q, vector<pair<string, string>> a);
	~Dialogue();
};