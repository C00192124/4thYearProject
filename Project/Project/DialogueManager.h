#pragma once
#include "JSONReader.h"
#include "Dialogue.h"
#include <SFML\Graphics.hpp>
#include "InputManager.h"

class DialogueManager
{
public:
	DialogueManager() {};
	~DialogueManager() {};

	void Init(JSONReader &jR, string name);
	void DisplayText();
	void Render(sf::RenderWindow &w);
	void MoveUp();
	void MoveDown();
	void Select();
	bool isSpeaking() { return m_speaking; }

	pair<vector<Threshold>,vector<Dialogue>> m_dialogueObject;

private:
	
	void PrintObject();
	void GetText();
	sf::Vector2f getPixelCoords(int x, int y, sf::RenderWindow &w);

	sf::Font m_font;
	string m_previousPath;
	string m_path;
	sf::Text m_name;
	sf::Text m_tempText;
	sf::Text m_text;
	vector<sf::Text> m_textVect;
	sf::Sprite m_speechBubble;
	sf::Texture m_bubbleTexture;
	sf::Sprite m_textSelector;
	sf::Texture m_selectorTexture;
	int m_selectorY;
	int m_selected;
	int m_maxSelections;
	bool m_speaking;

};

