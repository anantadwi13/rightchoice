#include "KartuDB.h"
#include <wx/arrimpl.cpp>
#include<iostream>
#include<string>
WX_DEFINE_OBJARRAY(KartuArray);

using namespace std;

KartuDB::KartuDB()
{
	status = sqlite3_open("test.db", &db);
	if (status != SQLITE_OK)
		cout << "SQLITE ERROR" << endl;
}

int KartuDB::getCallback(void *NotUsed, int argc, char **argv, char **azColName) {
	KartuDB* kartuDB = (KartuDB*) NotUsed;

	Kartu *temp = new Kartu();

	temp->setId(atoi(argv[0]));
	temp->setProblem(argv[1]);
	temp->setRightAnswer(argv[2]);
	temp->setLeftAnswer(argv[3]);
	temp->setRightDay(atoi(argv[4]));
	temp->setLeftDay(atoi(argv[5]));
	temp->setType(atoi(argv[6]));
	temp->setLeftValue(atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]));
	temp->setRightValue(atoi(argv[11]), atoi(argv[12]), atoi(argv[13]), atoi(argv[14]));

	kartuDB->getCards()->Add(temp);

	return 0;
}

KartuArray *KartuDB::getCards() {
	return &(this->cards);
}

KartuArray KartuDB::getAllCards() {
	cards.Clear();

	string query = "SELECT * from Kartu";

	const char *sql = query.c_str();

	status = sqlite3_exec(db, sql, getCallback, (void*) this, &errorMsg);
	return cards;
}

Kartu KartuDB::getCardById(int id) {
	cards.Clear();

	string query = "SELECT * from Kartu where id = " + to_string(id);

	const char *sql = query.c_str();
	

	status = sqlite3_exec(db, sql, getCallback, (void*)this, &errorMsg);

	if (cards.Count()<=0)
		cards.Add(new Kartu());
	return cards[0];
}

KartuDB::~KartuDB()
{
	cards.Clear();
	sqlite3_close(db);
}
