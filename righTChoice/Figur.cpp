#include "Figur.h"



Figur::Figur(string nama, string file)
{
	setNama(nama);
	setFile(file);
}


Figur::~Figur()
{
}

void Figur::setNama(string nama) {
	this->nama = nama;
}
void Figur::setFile(string file) {
	this->file = file;
}
string Figur::getNama() {
	return this->nama;
}
string Figur::getFile() {
	return this->file;
}