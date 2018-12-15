#include "Figur.h"

Figur::Figur(string nama, string file, string bgfile)
{
	setNama(nama);
	setFile(file);
	setBackgroundFile(bgfile);
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
void Figur::setBackgroundFile(string file) {
	this->bg = file;
}
string Figur::getNama() {
	return this->nama;
}
string Figur::getFile() {
	return this->file;
}
string Figur::getBackgroundFile() {
	return this->bg;
}