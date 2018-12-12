#include "ScoreDB.h"
#include <wx/arrimpl.cpp>
#include <iostream>

using namespace std;

WX_DEFINE_OBJARRAY(ScoreArray);

ScoreDB::ScoreDB()
{
	status = sqlite3_open("test.db", &db);
	if (status != SQLITE_OK)
		cout << "SQLITE ERROR" << endl;
}
void ScoreDB::insert(string nama, int score, string date) {
	string sql = "INSERT INTO Score (nama,score,date) "  \
		"VALUES ('" + nama + "', " + to_string(score) + ", '" + date + "');";

	const char *query = sql.c_str();

	sqlite3_exec(db, query, NULL, NULL, &errorMsg);

}
int ScoreDB::getCallback(void *NotUsed, int argc, char **argv, char **azColName) {
	ScoreDB* scoreDB = (ScoreDB*)NotUsed;

	Score *temp = new Score();

	temp->setId(atoi(argv[0]));
	temp->setNama(argv[1]);
	temp->setScore(atoi(argv[2]));
	temp->setDate(argv[3]);

	scoreDB->getScores()->Add(temp);

	return 0;
}
ScoreArray *ScoreDB::getScores() {
	return &(this->scores);
}
ScoreArray ScoreDB::getAllScores(int limit) {
	scores.Clear();

	string query = "SELECT * from Score order by score desc, id asc ";

	if (limit > 0)
		query += "limit "+to_string(limit);

	const char *sql = query.c_str();

	status = sqlite3_exec(db, sql, getCallback, (void*)this, &errorMsg);
	return scores;
}
Score ScoreDB::getScoreById(int id) {
	scores.Clear();

	string query = "SELECT * from Score where id = " + to_string(id);

	const char *sql = query.c_str();


	status = sqlite3_exec(db, sql, getCallback, (void*)this, &errorMsg);

	if (scores.Count() <= 0)
		scores.Add(new Score());
	return scores[0];
}
ScoreDB::~ScoreDB()
{
	scores.Clear();
	sqlite3_close(db);
}