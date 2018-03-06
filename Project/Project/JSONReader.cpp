#include "JSONReader.h"

void JSONReader::Init(std::string const & filename)
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

string JSONReader::loadName()
{
	string name("name");
	wstring wName;
	wName.assign(name.begin(), name.end());
	string s(m_object[wName]->AsString().begin(), m_object[wName]->AsString().end());
	return s;
}

string JSONReader::loadSprite()
{
	string sprite("sprite");
	wstring wSprite;
	wSprite.assign(sprite.begin(), sprite.end());
	string s(m_object[wSprite]->AsString().begin(), m_object[wSprite]->AsString().end());
	return s;
}

vector<vector<string>> JSONReader::loadWorld()
{
	vector<vector<string>> world;

	string cabin("cabin");
	wstring wCabin;
	wCabin.assign(cabin.begin(), cabin.end());
	JSONArray cabinArray = m_object[wCabin]->AsArray();
	
	for (int i = 0; i < cabinArray.size(); i++)
	{
		vector<string> temp;
		JSONArray c = cabinArray[i]->AsArray();
		for (int j = 0; j < c.size(); j++)
		{
			string s(c[j]->AsString().begin(), c[j]->AsString().end());
			temp.push_back(s);
		}
		world.push_back(temp);
	}

	return world;
}

vector<WorldObject> JSONReader::getWorldObject(JSONArray jA)
{
	vector<WorldObject> wObj;
	WorldObject w;

	for (int i = 0; i < jA.size(); i++)
	{

		JSONObject o = jA[i]->AsObject();

		string id("id");
		wstring wId;
		wId.assign(id.begin(), id.end());
		string s(o[wId]->AsString().begin(), o[wId]->AsString().end());
		w.setID(s);

		string path("path");
		wstring wPath;
		wPath.assign(path.begin(), path.end());
		string st(o[wPath]->AsString().begin(), o[wPath]->AsString().end());
		w.setPath(st);

		string pass("passable");
		wstring wPass;
		wPass.assign(pass.begin(), pass.end());
		bool b = o[wPass]->AsBool();
		w.setPassable(b);

		wObj.push_back(w);

	}

	return wObj;
}

vector<WorldObject> JSONReader::loadWorldObjects()
{
	vector<WorldObject> worldObj;
	vector<WorldObject> w;

	string objects("objects");
	wstring wObjects;
	wObjects.assign(objects.begin(), objects.end());
	JSONObject objectObj = m_object[wObjects]->AsObject();

	string floors("floors");
	wstring wFloors;
	wFloors.assign(floors.begin(), floors.end());
	JSONArray floorArray = objectObj[wFloors]->AsArray();
	w = getWorldObject(floorArray);
	for (int i = 0; i < w.size(); i++)
	{
		worldObj.push_back(w.at(i));
	}

	string walls("walls");
	wstring wWalls;
	wWalls.assign(walls.begin(), walls.end());
	JSONArray wallArray = objectObj[wWalls]->AsArray();
	w = getWorldObject(wallArray);
	for (int j = 0; j < w.size(); j++)
	{
		worldObj.push_back(w.at(j));
	}

	string furniture("furniture");
	wstring wFurniture;
	wFurniture.assign(furniture.begin(), furniture.end());
	JSONArray furnitureArray = objectObj[wFurniture]->AsArray();
	w = getWorldObject(furnitureArray);
	for (int k = 0; k < w.size(); k++)
	{
		worldObj.push_back(w.at(k));
	}
	
	return worldObj;

}

pair<vector<Threshold>,vector<Dialogue>> JSONReader::loadDialogue()
{
	vector<Dialogue> dialogueVector;
	vector<Threshold> thresholdVector;

	string thresholds("thresholds");
	wstring wThresholds;
	wThresholds.assign(thresholds.begin(), thresholds.end());
	JSONObject threshObj = m_object[wThresholds]->AsObject();
	for (int i = 0; i < threshObj.size(); i++)
	{
		Threshold t;

		string sThresh("tr" + to_string(i));
		wstring wthreshText;
		wthreshText.assign(sThresh.begin(), sThresh.end());
		JSONObject trObj = threshObj[wthreshText]->AsObject();

		//Threshold trait
		string sTrait("trait");
		wstring wtText;
		wtText.assign(sTrait.begin(), sTrait.end());
		string tTrait(trObj[wtText]->AsString().begin(), trObj[wtText]->AsString().end());

		//Threshold value
		string sValue("value");
		wstring wvValue;
		wvValue.assign(sValue.begin(), sValue.end());
		int tValue = trObj[wvValue]->AsNumber();

		//Threshold condition
		string sCon("condition");
		wstring wcText;
		wcText.assign(sCon.begin(), sCon.end());
		string tCon(trObj[wcText]->AsString().begin(), trObj[wcText]->AsString().end());

		//Threshold path
		string sPath("path");
		wstring wtPath;
		wtPath.assign(sPath.begin(), sPath.end());
		string tPath(trObj[wtPath]->AsString().begin(), trObj[wtPath]->AsString().end());

		t = Threshold(tTrait, tValue, tCon, tPath);
		thresholdVector.push_back(t);

	}

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

		d.m_id = q;
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

			//Answer deltas
			string dpath("deltas");
			wstring wDPath;
			wDPath.assign(dpath.begin(), dpath.end());
			JSONObject deltaObj = aObj[wDPath]->AsObject();
			vector<int> deltaVector;
			for (int k = 0; k < deltaObj.size(); k++)
			{
				string d("t" + to_string(k));
				wstring wD;
				wD.assign(d.begin(), d.end());
				int dint = deltaObj[wD]->AsNumber();
				deltaVector.push_back(dint);
			}

			d.AddAnswer(sa, sp, deltaVector);
		}

		dialogueVector.push_back(d);
	}

	pair<vector<Threshold>, vector<Dialogue>> pair;
	pair.first = thresholdVector;
	pair.second = dialogueVector;
	return pair;
}
