#pragma once
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;

class WorldObject
{
public:
	WorldObject() {}
	WorldObject(string id, string p, bool pass) { m_id = id; m_path = p; m_pass = pass; }
	~WorldObject() {}

	string getID() { return m_id; }
	string getPath() { return m_path; }
	bool getPass() { return m_pass; }

private:
	string m_id;
	string m_path;
	bool m_pass;

};