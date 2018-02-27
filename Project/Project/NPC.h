#pragma once
#include "Sprite.h"
#include "JSONReader.h"
#include "DialogueManager.h"
#include "TraitManager.h"

using namespace std;

class NPC : public Sprite
{
public:
	NPC(string jsonFile);
	~NPC();

	void Update(sf::Sprite &s, InputManager *i);
	void Render(sf::RenderWindow &w);

private:
	DialogueManager m_dM;
	TraitManager m_tM;
	JSONReader m_jR;
	vector<int> m_traits;
	string m_spriteFile;
	bool m_speaking;

	bool SpeakCollision(sf::Sprite &s, InputManager *i);
	bool CalculateCollision(float x, float width, float y, float height);
};

