#ifndef _JSONREADER_H
#define _JSONREADER_H

#include "Json/JSON.h"
#include <fstream>
#include <iostream>
#include "Dialogue.h"

using namespace std;

class JSONReader {
public:

	JSONReader();
	JSONReader(std::string const & filename);
	~JSONReader();
	vector<int> loadTraits();
	vector<Dialogue> loadDialogue();
	string loadSprite();

private:
	JSONValue *m_value;
	std::string m_JSONData;
	JSONObject m_object;

	void loadJSONData(std::string const & filename);

};

#endif