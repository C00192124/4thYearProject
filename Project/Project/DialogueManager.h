#pragma once
#include "JSONReader.h"
#include "Dialogue.h"

class DialogueManager
{
public:
	DialogueManager();
	DialogueManager(JSONReader &jR);
	~DialogueManager();

	vector<Dialogue> m_dialogueObject;

private:
	
	void PrintObject();

	string previousPath;
	string path;
};

