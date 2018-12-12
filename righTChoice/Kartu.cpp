#include "Kartu.h"

Kartu::Kartu()
{
}
Kartu::~Kartu() {
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
void Kartu::setRightValue(int intelektual, int kesehatan, int hubungan, int finansial) {
	this->rightValue = new NilaiPilar();
	this->rightValue->setIntelektual(intelektual);
	this->rightValue->setKesehatan(kesehatan);
	this->rightValue->setHubungan(hubungan);
	this->rightValue->setFinansial(finansial);
}
NilaiPilar *Kartu::getRightValue() {
	return this->rightValue;
}
void Kartu::setLeftValue(int intelektual, int kesehatan, int hubungan, int finansial) {
	this->leftValue = new NilaiPilar();
	this->leftValue->setIntelektual(intelektual);
	this->leftValue->setKesehatan(kesehatan);
	this->leftValue->setHubungan(hubungan);
	this->leftValue->setFinansial(finansial);
}
NilaiPilar *Kartu::getLeftValue() {
	return this->leftValue;
}
void Kartu::setRightDay(int rightDay) {
	this->rightDay = rightDay;
}
int Kartu::getRightDay() {
	return this->rightDay;
}
void Kartu::setLeftDay(int leftDay) {
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