#include "DialogueManager.h"

void DialogueManager::Init(JSONReader &jR)
{
	m_dialogueObject = jR.loadDialogue();
	m_path = "q0";
	m_font.loadFromFile("Resources/arial.ttf");
	m_bubbleTexture.loadFromFile("Resources/Sprites/speechBubble.png");
	m_speechBubble.setTexture(m_bubbleTexture);
	m_speaking = false;
	//PrintObject();
}

void DialogueManager::DisplayText()
{
	GetText();
	m_speaking = true;
}

sf::Vector2f DialogueManager::getPixelCoords(int x, int y, sf::RenderWindow &w)
{
	return sf::Vector2f(w.mapPixelToCoords(sf::Vector2i(x, y)));
}

void DialogueManager::Render(sf::RenderWindow &w)
{
	if (m_speaking)
	{
		m_speechBubble.setPosition(getPixelCoords(0,0,w));
		w.draw(m_speechBubble);
		for (int i = 0; i < m_tempTextVect.size(); i++)
		{
			m_tempTextVect.at(i).setPosition(getPixelCoords(50, 530 +(i*50),w));
			w.draw(m_tempTextVect.at(i));
		}
	}
}

void DialogueManager::GetText()
{
	for (int i = 0; i < m_dialogueObject.second.size(); i++)
	{
		if (m_dialogueObject.second.at(i).m_id == m_path)
		{
			m_tempText.setString(m_dialogueObject.second.at(i).m_Question.m_Text);
			m_tempTextVect.push_back(m_tempText);

			for (int j = 0; j < m_dialogueObject.second.at(i).m_Answers.size(); j++)
			{
				m_tempText.setString(m_dialogueObject.second.at(i).m_Answers.at(j).m_Text);
				m_tempTextVect.push_back(m_tempText);
			}
		}
	}

	for (int k = 0; k < m_tempTextVect.size(); k++)
	{
		m_tempTextVect.at(k).setFont(m_font);
		m_tempTextVect.at(k).setCharacterSize(25);
		m_tempTextVect.at(k).setFillColor(sf::Color::Black);
	}
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

			cout << "Deltas: " << endl;
			
			for (int k = 0; k < m_dialogueObject.second.at(i).m_Answers.at(j).m_deltas.size(); k++)
			{
				cout << "t" + to_string(k) + " " + to_string(m_dialogueObject.second.at(i).m_Answers.at(j).m_deltas.at(k)) << endl;
			}
		}

		cout << "" << endl;
	}
}
