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
	void Update();

private:
	DialogueManager m_dM;
	TraitManager m_tM;
	JSONReader m_jR;
	vector<int> m_traits;
	string m_spriteFile;
};

