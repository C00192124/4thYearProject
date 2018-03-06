#pragma once
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;

class WorldObject
{
public:
	WorldObject() {}
	~WorldObject() {}

	void setID(string id) { m_id = id; };
	void setPath(string p) { m_path = p; }
	void setPassable(bool p) { m_pass = p; }

	string getID() { return m_id; }
	string getPath() { return m_path; }
	bool getPassable() { return m_pass; }

	sf::Sprite m_sprite;
	sf::Texture m_texture;

private:
	string m_id;
	string m_path;
	bool m_pass;
};