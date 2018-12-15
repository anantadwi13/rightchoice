#pragma once
#include <string>

using namespace std;

class Figur
{
private:
	string nama;
	string file;
	string bg;
public:
	Figur(string nama, string file, string bgfile);
	~Figur();

	void setNama(string nama);
	void setFile(string file);
	void setBackgroundFile(string bgFile);
	string getNama();
	string getFile();
	string getBackgroundFile();
};

