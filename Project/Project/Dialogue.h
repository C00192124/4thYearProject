#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Answer
{
public:
	Answer() {}
	Answer(string s, string p) { m_Text = s; m_path = p; }
	~Answer() {}
	string m_Text;
	string m_path;
};

class Question
{
public:
	Question() {}
	Question(string s) { m_Text = s; }
	~Question() {}
	string m_Text;
};

class Dialogue
{
public:
	Dialogue() {}
	~Dialogue() {}
	Question m_Question;
	vector<Answer> m_Answers;
	void AddQuestion(string s) { Question q(s); m_Question = q; }
	void AddAnswer(string s, string p) { Answer answer(s, p); m_Answers.push_back(answer); }
};