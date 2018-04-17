#include "DialogueManager.h"

void DialogueManager::Init(JSONReader &jR, string name, vector<int> traits)
{
	//Dialogue
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
	
	//Traits
	openness = traits.at(0);
	conscientious = traits.at(1);
	extroversion = traits.at(2);
	agreeableness = traits.at(3);
	neuroticism = traits.at(4);
	m_chart.Init(814, 10);
	m_chart.AddBar(openness, sf::Color::Blue, "Openness");
	m_chart.AddBar(conscientious, sf::Color::Yellow, "Conscientious");
	m_chart.AddBar(extroversion, sf::Color::Green, "Extroversion");
	m_chart.AddBar(agreeableness, sf::Color::Red, "Agreeableness");
	m_chart.AddBar(neuroticism, sf::Color::White, "Neuroticism");
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
			ChangeTraits(m_dialogueObject.second.at(i).m_Answers.at(m_selected).m_deltas);

			if (!CheckThresholds())
			{
				m_previousPath = m_path;
				m_path = m_dialogueObject.second.at(i).m_Answers.at(m_selected).m_path;
			}
			
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

bool DialogueManager::CheckThresholds()
{
	for (int i = 0; i < m_dialogueObject.first.size(); i++)
	{
		if (m_dialogueObject.first.at(i).m_trait == "t0")
		{
			if (m_dialogueObject.first.at(i).m_con == "below")
			{
				if (openness <= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
			else
			{
				if (openness >= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
		}
		else if (m_dialogueObject.first.at(i).m_trait == "t1")
		{
			if (m_dialogueObject.first.at(i).m_con == "below")
			{
				if (conscientious <= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
			else
			{
				if (conscientious >= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
		}
		else if (m_dialogueObject.first.at(i).m_trait == "t2")
		{
			if (m_dialogueObject.first.at(i).m_con == "below")
			{
				if (extroversion <= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
			else
			{
				if (extroversion >= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
		}
		else if (m_dialogueObject.first.at(i).m_trait == "t3")
		{
			if (m_dialogueObject.first.at(i).m_con == "below")
			{
				if (agreeableness <= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
			else
			{
				if (agreeableness >= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
		}
		else if (m_dialogueObject.first.at(i).m_trait == "t4")
		{
			if (m_dialogueObject.first.at(i).m_con == "below")
			{
				if (neuroticism <= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
			else
			{
				if (neuroticism >= m_dialogueObject.first.at(i).m_num)
				{
					ProcessThresholds(i);
					return true;
				}
			}
		}
	}
	return false;
}

void DialogueManager::ProcessThresholds(int i)
{
	m_previousPath = m_path;
	m_path = m_dialogueObject.first.at(i).m_path;
	vector<Threshold>::iterator iter(m_dialogueObject.first.begin());
	m_dialogueObject.first.erase(iter + i);
}

void DialogueManager::ChangeTraits(vector<int> t)
{
	//Openness
	openness += t.at(0);
	if (openness > 100) { openness = 100; }
	else if (openness < 0) { openness = 0; }
	
	//Conscientious
	conscientious += t.at(1);
	if (conscientious > 100) { conscientious = 100; }
	else if (conscientious < 0) { conscientious = 0; }
	
	//Extroversion
	extroversion += t.at(2);
	if (extroversion > 100) { extroversion = 100; }
	else if (extroversion < 0) { extroversion = 0; }
	
	//Agreeableness
	agreeableness += t.at(3);
	if (agreeableness > 100) { agreeableness = 100; }
	else if (agreeableness < 0) { agreeableness = 0; }

	//Neuroticism
	neuroticism += t.at(4);
	if (neuroticism > 100) { neuroticism = 100; }
	else if (neuroticism < 0) { neuroticism = 0; }

	m_chart.UpdateValues(openness, conscientious, extroversion, agreeableness, neuroticism);
}

void DialogueManager::Update(sf::RenderWindow &w)
{
	if (m_speaking)
	{
		m_chart.Update(w);
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

		m_chart.Render(w);
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
				m_tempText.setString(SetString(m_dialogueObject.second.at(i).m_Answers.at(j).m_Text,33));
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
