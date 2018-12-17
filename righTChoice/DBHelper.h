#pragma once
#include "sqlite3.h"

class DBHelper
{
protected:
	sqlite3 *db;
	int status = 0;
	char* errorMsg;
public:
	DBHelper();
	~DBHelper();
};

