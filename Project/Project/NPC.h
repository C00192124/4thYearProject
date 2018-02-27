#pragma once
#include "Sprite.h"
#include "JSONReader.h"
#include "DialogueManager.h"
#include "TraitManager.h"

using namespace std;

class NPC : public Sprite
{
public:
	NPC() {};
	~NPC() {};

	void Init(string jsonFile);
	void Update(sf::Sprite &s, InputManager *i);
	void Render(sf::RenderWindow &w);

	bool m_speaking;

private:
	DialogueManager m_dM;
	TraitManager m_tM;
	JSONReader m_jR;
	vector<int> m_traits;
	string m_spriteFile;
	int m_speakTimer;

	bool SpeakCollision(sf::Sprite &s, InputManager *i);
	bool CalculateCollision(float x, float width, float y, float height);
};

