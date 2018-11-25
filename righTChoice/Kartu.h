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
	NilaiPilar *nilai = NULL;
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
	void setNilai(int intelektual, int kesehatan, int hubungan, int finansial);
	NilaiPilar *getNilai();
	void setRightDay(int rightDay);
	int getRightDay();
	void setLetDay(int leftDay);
	int getLeftDay();
	void setType(int type);
	int getType();
};

