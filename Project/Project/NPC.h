#pragma once
#include "Sprite.h"
#include "JSONReader.h"
#include "DialogueManager.h"

using namespace std;

class NPC : public Sprite
{
public:
	NPC() {};
	~NPC() {};

	void Init(string jsonFile, sf::Vector2f pos);
	void Update(sf::Sprite &s, InputManager *i, sf::RenderWindow &w);
	void Render(sf::RenderWindow &w);

	bool m_speaking;

private:
	DialogueManager m_dM;
	JSONReader m_jR;
	vector<int> m_traits;
	string m_spriteFile;
	int m_speakTimer;
	string m_name;

	bool SpeakCollision(sf::Sprite &s, InputManager *i);
	bool CalculateCollision(float x, float width, float y, float height);
};

