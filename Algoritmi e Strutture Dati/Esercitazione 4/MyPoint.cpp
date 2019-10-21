/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#include "MyPoint.h"

// -- Implementation methods --
MyPoint::MyPoint(void) : MyPoint(0,0) {}

MyPoint::MyPoint(coord_t x, coord_t y)
{
	setX(x);
	setY(y);
}

MyPoint::~MyPoint() {}

void MyPoint::setX(coord_t x)
{
	this -> x = x;
}

MyPoint::coord_t MyPoint::getX(void)
{
	return this -> x;
}

void MyPoint::setY(coord_t y)
{
	this -> y = y;
}

MyPoint::coord_t MyPoint::getY(void)
{
	return this -> y;
}

double MyPoint::distance(MyPoint point)
{
	return sqrt(pow(this -> getX() - point.getX(), 2) + pow(this -> getY() - point.getY(), 2));
}

std::string MyPoint::toString(void)
{
	return "MyPoint (" + std::to_string(this -> getX()) + ", " + std::to_string(this -> getY()) + ")";
}