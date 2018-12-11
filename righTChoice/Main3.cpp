/*#include<iostream>
#include"Kartu.h"
#include"KartuDB.h"
#include<math.h>
#include<ctime>

WX_DECLARE_OBJARRAY(int, IntegerArray);

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(IntegerArray);
using namespace std;

const int MIN = 0;
const int MAX = 10;

bool inRange(int pilar) {
	if (pilar > MIN && pilar < MAX)
		return true;
	return false;
}

int random(int size) {
	return rand()%size;
}

void printPilar(int intelektual, int kesehatan, int hubungan, int finansial) {
	if (intelektual < MIN)
		intelektual = MIN;
	if (kesehatan < MIN)
		kesehatan = MIN;
	if (hubungan < MIN)
		hubungan = MIN;
	if (finansial < MIN)
		finansial = MIN;
	if (intelektual > MAX)
		intelektual = MAX;
	if (kesehatan > MAX)
		kesehatan = MAX;
	if (hubungan > MAX)
		hubungan = MAX;
	if (finansial > MAX)
		finansial = MAX;

	cout << intelektual << " " << kesehatan << " " << hubungan << " " << finansial << " " << endl;
}


int mainan() {
	/*sqlite3 *db;
	char *msg;
	sqlite3_open("test.db", &db);
	for (int i = 2; i <= 20; i++) {
		string sql = "INSERT INTO Kartu (problem,rightAnswer,leftAnswer,rightDay,leftDay,type,Lintelektual,Lkesehatan,Lhubungan,Lfinansial,Rintelektual,Rkesehatan,Rhubungan,Rfinansial) "  \
			"VALUES ('Ini Masalah Ke-"+to_string(i)+"', 'rightAnswer" + to_string(i) + "', 'leftAnswer" + to_string(i) + "', 1, 2, 1, 1,2,3,4,-1,-2,-3,-4 );";
		const char *query = sql.c_str();

		sqlite3_exec(db, query, NULL, NULL, &msg);
	}
	sqlite3_close(db);
	system("pause");
	return 0;*/
/*
	KartuDB *kartuDB = new KartuDB();
	Kartu card = kartuDB->getCardById(1);
	KartuArray cards = kartuDB->getAllCards();
	IntegerArray a;
	IntegerArray b;
	int flag = 0;
	for (int i = 1; i <= cards.Count(); i++) {
		a.Add(i);
	}

	srand(time(NULL));
	int intelektual = 5;
	int kesehatan = 5;
	int hubungan = 5;
	int finansial = 5;
	int nilai[22];
	memset(nilai, 0, sizeof(nilai));
	while (inRange(intelektual) && inRange(kesehatan) && inRange(hubungan) && inRange(finansial))
	{
		int rand,angka,choose;
		if (flag==0) {
			rand = random(a.Count());
			angka = a[rand];
			a.RemoveAt(rand, 1);
			b.Add(angka);
			nilai[angka]++;
			if (a.Count() <= 0)
				flag = 1;
		}
		else {
			rand = random(b.Count());
			angka = b[rand];
			b.RemoveAt(rand, 1);
			a.Add(angka);
			nilai[angka]++;
			if (b.Count() <= 0)
				flag = 0;
		}
		card = kartuDB->getCardById(angka);

		cout << endl << card.getProblem() << endl;

		cin >> choose;

		if (choose == 1) {
			intelektual += card.getRightValue()->getIntelektual();
			kesehatan += card.getRightValue()->getKesehatan();
			hubungan += card.getRightValue()->getHubungan();
			finansial += card.getRightValue()->getFinansial();
		}
		else
		{
			intelektual += card.getLeftValue()->getIntelektual();
			kesehatan += card.getLeftValue()->getKesehatan();
			hubungan += card.getLeftValue()->getHubungan();
			finansial += card.getLeftValue()->getFinansial();
		}
		printPilar(intelektual, kesehatan, hubungan, finansial);

		/*for (int i = 1; i <= cards.Count(); i++)
			cout << nilai[i] << " ";*/
/*
	}

	if (intelektual <= MIN)
		cout << "Dibodohi";
	else if (kesehatan <= MIN)
		cout << "Nggak sehat";
	else if (hubungan <= MIN)
		cout << "Apatis";
	else if (finansial <= MIN)
		cout << "Melarat";
	else if (intelektual >= MAX)
		cout << "Gila";
	else if (kesehatan >= MAX)
		cout << "Terlalu sehat";
	else if (hubungan >= MAX)
		cout << "Terlalu sibuk";
	else if (finansial >= MAX)
		cout << "Jadi pengusaha";

	cout << endl;

	delete kartuDB;

	system("pause");
	return 0;
}
*/