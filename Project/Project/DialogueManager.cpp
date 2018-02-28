#include "DialogueManager.h"

void DialogueManager::Init(JSONReader &jR, string name)
{
	m_dialogueObject = jR.loadDialogue();
	m_path = "q0";
	m_font.loadFromFile("Resources/arial.ttf");
	m_bubbleTexture.loadFromFile("Resources/Sprites/speechBubble.png");
	m_speechBubble.setTexture(m_bubbleTexture);
	m_selectorTexture.loadFromFile("Resources/Sprites/textSelector.png");
	m_textSelector.setTexture(m_selectorTexture);
	m_textSelector.setOrigin(m_textSelector.getLocalBounds().width / 2, m_textSelector.getLocalBounds().height / 2);
	m_selectorY = 600;
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
		m_selectorY -= 60;
		m_selected -= 1;
		for (int i = 0; i < m_textVect.size(); i++)
		{
			if (i == m_selected)
			{
				m_textVect.at(i).setFillColor(sf::Color(211, 126, 6));
			}
			else m_textVect.at(i).setFillColor(sf::Color::Black);
		}
	}
}

void DialogueManager::MoveDown()
{
	if (m_selected != m_maxSelections)
	{
		m_selectorY += 60;
		m_selected += 1;
		for (int i = 0; i < m_textVect.size(); i++)
		{
			if (i == m_selected)
			{
				m_textVect.at(i).setFillColor(sf::Color(211, 126, 6));
			}
			else m_textVect.at(i).setFillColor(sf::Color::Black);
		}
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
				m_path = m_previousPath;
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

		m_text.setPosition(getPixelCoords(30, 575, w));
		w.draw(m_text);

		for (int i = 0; i < m_textVect.size(); i++)
		{
			m_textVect.at(i).setPosition(getPixelCoords(600, 575 +(i*60),w));
			w.draw(m_textVect.at(i));
		}

		m_textSelector.setPosition(getPixelCoords(560, m_selectorY, w));
		m_name.setPosition(getPixelCoords(40, 520, w));
		w.draw(m_textSelector);
		w.draw(m_name);
	}
}

string DialogueManager::SetString(string s, int width)
{
	string whitespace = " \t\r";
	size_t currIndex = width - 1;
	size_t sizeToElim;
	while (currIndex < s.length())
	{
		currIndex = s.find_last_of(whitespace, currIndex + 1);
		if (currIndex == string::npos)
			break;
		currIndex = s.find_last_not_of(whitespace, currIndex);
		if (currIndex == string::npos)
			break;
		sizeToElim = s.find_first_not_of(whitespace, currIndex + 1) - currIndex - 1;
		s.replace(currIndex + 1, sizeToElim, "\n");
		currIndex += (width + 1);
	}
	return s;
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
			m_text.setString(SetString(m_dialogueObject.second.at(i).m_Question.m_Text,42));
			m_text.setCharacterSize(25);
			m_text.setFont(m_font);
			m_text.setFillColor(sf::Color::Black);
			
			m_maxSelections = m_dialogueObject.second.at(i).m_Answers.size() - 1;

			for (int j = 0; j < m_dialogueObject.second.at(i).m_Answers.size(); j++)
			{
				m_tempText.setString(SetString(m_dialogueObject.second.at(i).m_Answers.at(j).m_Text,30));
				m_textVect.push_back(m_tempText);
			}
		}
	}

	for (int k = 0; k < m_textVect.size(); k++)
	{
		m_textVect.at(k).setFont(m_font);
		m_textVect.at(k).setCharacterSize(25);
		if (k == 0)
		{
			m_textVect.at(k).setFillColor(sf::Color(211, 126, 6));
		}
		else m_textVect.at(k).setFillColor(sf::Color::Black);
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
