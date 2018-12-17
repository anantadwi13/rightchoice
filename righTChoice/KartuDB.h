#pragma once
#include <wx/dynarray.h>
#include "Kartu.h"
#include "DBHelper.h"

WX_DECLARE_OBJARRAY(Kartu, KartuArray);

class KartuDB : public DBHelper
{
private:
	KartuArray cards;
public:
	KartuDB();
	~KartuDB();

	KartuArray *getCards();
	KartuArray getAllCards();
	Kartu getCardById(int id);
	static int getCallback(void *NotUsed, int argc, char **argv, char **azColName);
};

