#ifndef _JSONREADER_H
#define _JSONREADER_H

#include "Json/JSON.h"
#include <fstream>
#include <iostream>
#include "Dialogue.h"
#include "WorldObject.h"

using namespace std;

class JSONReader {
public:

	JSONReader() {};
	~JSONReader() {};

	void Init(std::string const & filename);
	vector<int> loadTraits();
	pair<vector<Threshold>, vector<Dialogue>> loadDialogue();
	vector<vector<string>> loadWorld();
	vector<WorldObject> loadWorldObjects();
	string loadSprite();
	string loadName();

private:
	JSONValue *m_value;
	std::string m_JSONData;
	JSONObject m_object;

	vector<WorldObject> getWorldObject(JSONArray jA);
	void loadJSONData(std::string const & filename);

};

#endif