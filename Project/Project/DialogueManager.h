#pragma once
#include "JSONReader.h"
#include "Dialogue.h"
#include <SFML\Graphics.hpp>

class DialogueManager
{
public:
	DialogueManager() {};
	~DialogueManager() {};

	void Init(JSONReader &jR);
	void DisplayText();
	void Render(sf::RenderWindow &w);

	pair<vector<Threshold>,vector<Dialogue>> m_dialogueObject;

private:
	
	void PrintObject();
	void GetText();
	sf::Vector2f getPixelCoords(int x, int y, sf::RenderWindow &w);

	sf::Font m_font;
	string m_previousPath;
	string m_path;
	sf::Text m_tempText;
	vector<sf::Text> m_tempTextVect;
	sf::Sprite m_speechBubble;
	sf::Texture m_bubbleTexture;
	bool m_speaking;

};

