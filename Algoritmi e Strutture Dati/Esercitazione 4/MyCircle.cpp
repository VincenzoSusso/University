/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#include "MyCircle.h"

// -- Implementation methods --
MyCircle::MyCircle(void) : MyCircle(MyPoint(), 1) {}

MyCircle::MyCircle(MyPoint center, double radius)
{
    this -> center = center;
    this -> radius = radius;
}

MyCircle::~MyCircle() {}

void MyCircle::setCenter(MyPoint center)
{
    this -> center = center;
}

MyPoint MyCircle::getCenter(void)
{
    return this -> center;
}

void MyCircle::setRadius(double radius)
{
    this -> radius = radius;
}

double MyCircle::getRadius(void)
{
    return this -> radius;
}

std::string MyCircle::toString(void)
{
    using namespace std;
    return "MyCircle (Radius: " + to_string(this -> getRadius()) + ", Center:(" + to_string(this -> getCenter().getX()) + ", " + to_string(this -> getCenter().getY()) + "))";
}

double MyCircle::getArea(void)
{
    return M_PI * pow(this -> getRadius(), 2);
}

double MyCircle::getCircumference(void)
{
    return 2 * M_PI * this -> getRadius();
}

double MyCircle::distance(MyCircle circle)
{
    return this -> getCenter().distance(circle.getCenter());
}