#pragma once
#include<string>
#include"NilaiPilar.h"

using namespace std;

class Kartu
{
private:
	int id;
	string problem;
	string rightAnswer;
	string leftAnswer;
	NilaiPilar *rightValue = NULL;
	NilaiPilar *leftValue = NULL;
	int rightDay;
	int leftDay;
	int type;
public:
	Kartu();
	~Kartu();
	void setId(int id);
	int getId();
	void setProblem(string problem);
	string getProblem();
	void setRightAnswer(string rightAnswer);
	string getRightAnswer();
	void setLeftAnswer(string leftAnswer);
	string getLeftAnswer();
	void setRightValue(int intelektual, int kesehatan, int hubungan, int finansial);
	NilaiPilar *getRightValue();
	void setLeftValue(int intelektual, int kesehatan, int hubungan, int finansial);
	NilaiPilar *getLeftValue();
	void setRightDay(int rightDay);
	int getRightDay();
	void setLeftDay(int leftDay);
	int getLeftDay();
	void setType(int type);
	int getType();
};

