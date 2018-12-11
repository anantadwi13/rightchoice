#pragma once
#include <string>

using namespace std;

class Figur
{
private:
	string nama;
	string file;
public:
	Figur(string nama, string file);
	~Figur();

	void setNama(string nama);
	void setFile(string file);
	string getNama();
	string getFile();
};

