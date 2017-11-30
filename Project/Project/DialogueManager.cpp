#include "DialogueManager.h"

DialogueManager::DialogueManager() {}

DialogueManager::DialogueManager(JSONReader &jR)
{
	d = jR.loadDialogue();
}

DialogueManager::~DialogueManager() {}
