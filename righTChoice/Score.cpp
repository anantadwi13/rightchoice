#include "Score.h"



Score::Score()
{
}


Score::~Score()
{
}

void Score::setId(int id) {
	this->id = id;
}
int Score::getId() {
	return this->id;
}
void Score::setNama(string nama) {
	this->nama = nama;
}
string Score::getNama() {
	return this->nama;
}
void Score::setScore(int score) {
	this->score = score;
}
int Score::getScore() {
	return this->score;
}
void Score::setDate(string date) {
	this->date = date;
}
string Score::getDate() {
	return this->date;
}