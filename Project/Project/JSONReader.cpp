#include "JSONReader.h"
JSONReader::JSONReader() {}

JSONReader::JSONReader(std::string const & filename)
{

	loadJSONData(filename);
	m_value = JSON::Parse(m_JSONData.c_str());
	if (NULL == m_value)
	{
		std::string s("Could not parse json in " + filename);
		throw std::exception(s.c_str());
	}
	m_object = m_value->AsObject();
}

JSONReader::~JSONReader() {
	//delete m_value;
}

void JSONReader::loadJSONData(std::string const & filename)
{
	m_JSONData.clear();
	std::ifstream myfile(filename);
	std::string line;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			m_JSONData.append(line);
		}
		myfile.close();
	}
	else
	{
		std::string errorMessage = "Could not open " + filename + " exiting!";
		std::cout << "Could not open " + filename + " exiting!" << std::endl;
		throw std::exception(errorMessage.c_str());
	}
}

vector<int> JSONReader::loadTraits()
{
	vector<int> v;
	string traits("traits");
	wstring wTraits;
	wTraits.assign(traits.begin(), traits.end());
	JSONObject traitObj = m_object[wTraits]->AsObject();
	for (int i = 0; i < traitObj.size(); i++)
	{
		string t("t" + to_string(i));
		wstring wT;
		wT.assign(t.begin(), t.end());
		int str = stoi(traitObj[wT]->AsString());
		v.push_back(str);
	}

	return v;
}

string JSONReader::loadSprite()
{
	string sprite("sprite");
	wstring wSprite;
	wSprite.assign(sprite.begin(), sprite.end());
	string s(m_object[wSprite]->AsString().begin(), m_object[wSprite]->AsString().end());
	return s;
}

vector<Dialogue> JSONReader::loadDialogue()
{
	vector<Dialogue> dialogueVector;

	string dialogue("dialogue");
	wstring wDialogue;
	wDialogue.assign(dialogue.begin(), dialogue.end());
	JSONObject dialObj = m_object[wDialogue]->AsObject();
	for (int i = 0; i < dialObj.size(); i++)
	{
		Dialogue d;

		//Question text
		string q("q" + to_string(i));
		wstring wQ;
		wQ.assign(q.begin(), q.end());
		JSONObject qObj = dialObj[wQ]->AsObject();
		string qtext("qtext");
		wstring wQText;
		wQText.assign(qtext.begin(), qtext.end());
		string sq(qObj[wQText]->AsString().begin(), qObj[wQText]->AsString().end());

		d.AddQuestion(sq);
		
		string ans("ans");
		wstring wAns;
		wAns.assign(ans.begin(), ans.end());
		JSONObject ansObj = qObj[wAns]->AsObject();
		for (int j = 0; j < ansObj.size(); j++)
		{

			//Answer text
			string a("a" + to_string(j));
			wstring wA;
			wA.assign(a.begin(), a.end());
			JSONObject aObj = ansObj[wA]->AsObject();
			string atext("text");
			wstring wAText;
			wAText.assign(atext.begin(), atext.end());
			string sa(aObj[wAText]->AsString().begin(), aObj[wAText]->AsString().end());
			
			//Answer path
			string apath("path");
			wstring wAPath;
			wAPath.assign(apath.begin(), apath.end());
			string sp(aObj[wAPath]->AsString().begin(), aObj[wAPath]->AsString().end());

			d.AddAnswer(sa, sp);
		}

		dialogueVector.push_back(d);
	}

	return dialogueVector;
}
