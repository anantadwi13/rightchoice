#include "DBHelper.h"
#include <iostream>

using namespace std;

DBHelper::DBHelper()
{
	status = sqlite3_open("test.db", &db);
	if (status != SQLITE_OK)
		cout << "SQLITE ERROR" << endl;
}

DBHelper::~DBHelper()
{
	sqlite3_close(db);
}
