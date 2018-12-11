#pragma once
#include<string>

using namespace std;

class Score
{
private:
	int id;
	string nama;
	int score;
	string date;
public:
	Score();
	~Score();

	void setId(int id);
	int getId();
	void setNama(string nama);
	string getNama();
	void setScore(int score);
	int getScore();
	void setDate(string date);
	string getDate();
};

