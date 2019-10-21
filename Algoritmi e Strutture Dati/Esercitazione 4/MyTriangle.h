/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>
#include "MyPoint.h"

class MyTriangle
{
    public:       
        // -- Interfaces --
        MyTriangle(MyPoint v1, MyPoint v2, MyPoint v3);
        ~MyTriangle();

        std::string toString(void);
        double getArea(void);
        double getPerimeter(void);
        std::string getType(void);

    private:
        // -- Attributes --
        MyPoint v1;
        MyPoint v2;
        MyPoint v3;

        double lenghtSide_1;
        double lenghtSide_2;
        double lenghtSide_3;

        double angle_1;
        double angle_2;
        double angle_3;
};

#endif