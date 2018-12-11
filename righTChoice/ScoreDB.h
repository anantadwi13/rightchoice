#pragma once
#include <wx/dynarray.h>
#include "Score.h"
#include "sqlite/sqlite3.h"

WX_DECLARE_OBJARRAY(Score, ScoreArray);

class ScoreDB
{
private:
	ScoreArray scores;
	sqlite3 *db;
	int status = 0;
	char* errorMsg;
public:
	ScoreDB();
	~ScoreDB();

	ScoreArray *getScores();
	ScoreArray getAllScores(int limit);
	Score getScoreById(int id);
	void insert(string nama, int score, string date);
	static int getCallback(void *NotUsed, int argc, char **argv, char **azColName);
};

