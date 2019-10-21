/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#include "MyTriangle.h"

// -- Implementation methods --
MyTriangle::MyTriangle(MyPoint v1, MyPoint v2, MyPoint v3)
{
    this -> v1 = v1;
    this -> v2 = v2;
    this -> v3 = v3;

    this -> lenghtSide_1 = this -> v1.distance(this -> v2); // b
    this -> lenghtSide_2 = this -> v1.distance(this -> v3); // c
    this -> lenghtSide_3 = this -> v2.distance(this -> v3); // a

    this -> angle_1 = acos((pow(this -> lenghtSide_1, 2.0) + pow(this -> lenghtSide_2, 2.0) - pow(this -> lenghtSide_3, 2.0)) / (2 * this -> lenghtSide_1 * this -> lenghtSide_2));
    this -> angle_2 = acos((pow(this -> lenghtSide_3, 2.0) + pow(this -> lenghtSide_2, 2.0) - pow(this -> lenghtSide_1, 2.0)) / (2 * this -> lenghtSide_3 * this -> lenghtSide_2));
    this -> angle_3 = acos((pow(this -> lenghtSide_3, 2.0) + pow(this -> lenghtSide_1, 2.0) - pow(this -> lenghtSide_2, 2.0)) / (2 * this -> lenghtSide_3 * this -> lenghtSide_1));

    // Rad to degree
    this -> angle_1 *= (180.0 / M_PI);
    this -> angle_2 *= (180.0 / M_PI);
    this -> angle_3 *= (180.0 / M_PI);
}

MyTriangle::~MyTriangle() {}

std::string MyTriangle::toString(void)
{
    using namespace std;

    string string_triangle_point = "MyTriangle (v1:(" + to_string(this -> v1.getX())+", " + to_string(this -> v1.getY()) + "), v2:(" + to_string(this -> v2.getX()) + ", " + to_string(this -> v2.getY()) + "), v3:(" + to_string(this -> v3.getX()) + ", "+ to_string(this -> v3.getY()) + "))\n";
    string string_triangle_lenght = "First side: " + to_string(this -> lenghtSide_1) +", second side: " + to_string(this -> lenghtSide_2) + ", third side: " + to_string(this -> lenghtSide_3) + "\n";
    string string_triangle_angle = "First angle: " + to_string(this -> angle_1) +"deg, second angle: " + to_string(this -> angle_2) + "deg, third angle: " + to_string(this -> angle_3) + "deg\n";

    return string_triangle_point + string_triangle_lenght + string_triangle_angle;
}

double MyTriangle::getArea(void)
{
    return (this -> lenghtSide_3 * this -> lenghtSide_1 * sin(this -> angle_3 * M_PI / 180)) / (2.0);
}

double MyTriangle::getPerimeter(void)
{
    return this -> lenghtSide_1 + this -> lenghtSide_2 + this -> lenghtSide_3;
}

std::string MyTriangle::getType(void)
{
    std::string type = "Scalene";

    if((int)(this -> angle_1 + .5) == 90 || (int)(this -> angle_2 + .5) == 90 || (int)(this -> angle_3 + .5) == 90)
    {
        type = "Right-angled";
    }
    
    if(this -> lenghtSide_1 == this -> lenghtSide_2 == this -> lenghtSide_3)
    {
        type = "Equilateral";
    }

    return type;
}