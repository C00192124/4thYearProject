#pragma once
#include "Dialogue.h"
#include "JSONReader.h"

class DialogueManager
{
public:
	DialogueManager();
	DialogueManager(JSONReader &jR);
	~DialogueManager();

private:
	vector<Dialogue> d;
};

