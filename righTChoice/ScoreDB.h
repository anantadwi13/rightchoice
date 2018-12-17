#pragma once
#include <wx/dynarray.h>
#include "Score.h"
#include "DBHelper.h"

WX_DECLARE_OBJARRAY(Score, ScoreArray);

class ScoreDB : public DBHelper
{
private:
	ScoreArray scores;
public:
	ScoreDB();
	~ScoreDB();

	ScoreArray *getScores();
	ScoreArray getAllScores(int limit);
	Score getScoreById(int id);
	void insert(string nama, int score, string date);
	static int getCallback(void *NotUsed, int argc, char **argv, char **azColName);
};

