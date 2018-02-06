#include "DialogueManager.h"

DialogueManager::DialogueManager() {}

DialogueManager::DialogueManager(JSONReader &jR)
{
	m_dialogueObject = jR.loadDialogue();
	path = "q1";
	PrintObject();
}

void DialogueManager::PrintObject()
{

	for (int i = 0; i < m_dialogueObject.second.size(); i++)
	{
		//Question
		cout << "Question: " + m_dialogueObject.second.at(i).m_Question.m_Text << endl;
		
		for (int j = 0; j < m_dialogueObject.second.at(i).m_Answers.size(); j++)
		{
			//Answer
			cout << "Answer: " + m_dialogueObject.second.at(i).m_Answers.at(j).m_Text << endl;
			//Path
			cout << "Path: " + m_dialogueObject.second.at(i).m_Answers.at(j).m_path << endl;
		}

		cout << "" << endl;
	}
}

DialogueManager::~DialogueManager() {}
