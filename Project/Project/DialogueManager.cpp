#include "DialogueManager.h"

void DialogueManager::Init(JSONReader &jR, string name)
{
	m_dialogueObject = jR.loadDialogue();
	m_path = "q0";
	m_font.loadFromFile("Resources/blackjack.otf");
	m_bubbleTexture.loadFromFile("Resources/Sprites/speechBubble.png");
	m_speechBubble.setTexture(m_bubbleTexture);
	m_selectorTexture.loadFromFile("Resources/Sprites/textSelector.png");
	m_textSelector.setTexture(m_selectorTexture);
	m_textSelector.setOrigin(m_textSelector.getLocalBounds().width / 2, m_textSelector.getLocalBounds().height / 2);
	m_selectorY = 605;
	m_selected = 0;
	m_speaking = false;
	m_name.setString(name);
	m_name.setFont(m_font);
	m_name.setFillColor(sf::Color::White);
	m_name.setCharacterSize(30);
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

void DialogueManager::MoveUp()
{
	if (m_selected != 0)
	{
		m_selectorY -= 50;
		m_selected -= 1;
	}
}

void DialogueManager::MoveDown()
{
	if (m_selected != m_maxSelections)
	{
		m_selectorY += 50;
		m_selected += 1;
	}
}

void DialogueManager::Select()
{
	bool brk = false;
	for (int i = 0; i < m_dialogueObject.second.size(); i++)
	{
		if (m_dialogueObject.second.at(i).m_id == m_path)
		{
			m_previousPath = m_path;
			m_path = m_dialogueObject.second.at(i).m_Answers.at(m_selected).m_path;
			if (m_path != "exit")
			{
				GetText();
				brk = true;
			}
			else
			{
				m_speaking = false;
			}
		}
		if (brk) break;
	}
}

void DialogueManager::Render(sf::RenderWindow &w)
{
	if (m_speaking)
	{
		m_speechBubble.setPosition(getPixelCoords(0,0,w));
		w.draw(m_speechBubble);

		m_text.setPosition(getPixelCoords(50, 530, w));
		w.draw(m_text);

		for (int i = 0; i < m_textVect.size(); i++)
		{
			m_textVect.at(i).setPosition(getPixelCoords(100, 585 +(i*50),w));
			w.draw(m_textVect.at(i));
		}

		m_textSelector.setPosition(getPixelCoords(60, m_selectorY, w));
		m_name.setPosition(getPixelCoords(800, 520, w));
		w.draw(m_textSelector);
		w.draw(m_name);
	}
}

void DialogueManager::GetText()
{
	m_text = sf::Text();
	m_textVect = vector<sf::Text>();
	m_selected = 0;
	m_selectorY = 605;

	for (int i = 0; i < m_dialogueObject.second.size(); i++)
	{
		if (m_dialogueObject.second.at(i).m_id == m_path)
		{
			m_text.setString(m_dialogueObject.second.at(i).m_Question.m_Text);
			m_text.setCharacterSize(36);
			m_text.setFont(m_font);
			m_text.setFillColor(sf::Color(9, 150, 18, 255));
			
			m_maxSelections = m_dialogueObject.second.at(i).m_Answers.size() - 1;

			for (int j = 0; j < m_dialogueObject.second.at(i).m_Answers.size(); j++)
			{
				m_tempText.setString(m_dialogueObject.second.at(i).m_Answers.at(j).m_Text);
				m_textVect.push_back(m_tempText);
			}
		}
	}

	for (int k = 0; k < m_textVect.size(); k++)
	{
		m_textVect.at(k).setFont(m_font);
		m_textVect.at(k).setCharacterSize(30);
		m_textVect.at(k).setFillColor(sf::Color::Black);
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
