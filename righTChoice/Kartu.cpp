#include "Kartu.h"



Kartu::Kartu()
{
}
Kartu::~Kartu() {
	if (this->nilai!=NULL)
		delete this->nilai;
}


void Kartu::setId(int id) {
	this->id = id;
}
int Kartu::getId() {
	return this->id;
}
void Kartu::setProblem(string problem) {
	this->problem = problem;
}
string Kartu::getProblem() {
	return this->problem;
}
void Kartu::setRightAnswer(string rightAnswer) {
	this->rightAnswer = rightAnswer;
}
string Kartu::getRightAnswer() {
	return this->rightAnswer;
}
void Kartu::setLeftAnswer(string leftAnswer) {
	this->leftAnswer = leftAnswer;
}
string Kartu::getLeftAnswer() {
	return this->leftAnswer;
}
void Kartu::setNilai(int intelektual, int kesehatan, int hubungan, int finansial) {
	this->nilai = new NilaiPilar();
	this->nilai->setIntelektual(intelektual);
	this->nilai->setKesehatan(kesehatan);
	this->nilai->setHubungan(hubungan);
	this->nilai->setFinansial(finansial);
}
NilaiPilar *Kartu::getNilai() {
	return this->nilai;
}
void Kartu::setRightDay(int rightDay) {
	this->rightDay = rightDay;
}
int Kartu::getRightDay() {
	return this->rightDay;
}
void Kartu::setLetDay(int leftDay) {
	this->leftDay = leftDay;
}
int Kartu::getLeftDay() {
	return this->leftDay;
}
void Kartu::setType(int type) {
	this->type = type;
}
int Kartu::getType() {
	return this->type;
}