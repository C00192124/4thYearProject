#pragma once
#include "JSONReader.h"
#include "Dialogue.h"

class DialogueManager
{
public:
	DialogueManager();
	DialogueManager(JSONReader &jR);
	~DialogueManager();

private:
	vector<Dialogue> m_dialogueObject;
	void PrintObject();
};

