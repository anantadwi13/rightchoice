#pragma once
#include <wx/dynarray.h>
#include "Kartu.h"
#include "sqlite/sqlite3.h"

WX_DECLARE_OBJARRAY(Kartu, KartuArray);

class KartuDB
{
private:
	KartuArray cards;
	sqlite3 *db;
	int status = 0;
	char* errorMsg;
public:
	KartuDB();
	~KartuDB();

	KartuArray *getCards();
	KartuArray getAllCards();
	Kartu getCardById(int id);
	static int insertCallback(void *NotUsed, int argc, char **argv, char **azColName);
};

