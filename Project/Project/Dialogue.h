#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Answer
{
public:
	Answer() {}
	Answer(string s, string p, vector<int> d) { m_Text = s; m_path = p; m_deltas = d; }
	~Answer() {}
	string m_Text;
	string m_path;
	vector<int> m_deltas;
};

class Question
{
public:
	Question() {}
	Question(string s) { m_Text = s; }
	~Question() {}
	string m_Text;
};

class Threshold
{
public:
	Threshold() {}
	Threshold(string t, int n, string c, string p) { m_trait = t; m_num = n; m_con = c; m_path = p; }
	~Threshold() {}
	string m_trait;
	int m_num;
	string m_con;
	string m_path;
};

class Dialogue
{
public:
	Dialogue() {}
	~Dialogue() {}
	Question m_Question;
	vector<Answer> m_Answers;
	vector<Threshold> m_Thresholds;
	void AddQuestion(string s) { Question q(s); m_Question = q; }
	void AddAnswer(string s, string p, vector<int> d) { Answer answer(s, p, d); m_Answers.push_back(answer); }
	void AddThreshold(string t, int n, string c, string p) { Threshold threshold(t, n, c, p); m_Thresholds.push_back(threshold); }
};