/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include "MyPoint.h"

class MyCircle
{
    public:       
        // -- Interfaces --
        MyCircle(void);
        MyCircle(MyPoint center, double radius);
        ~MyCircle();

        void setCenter(MyPoint center);
        MyPoint getCenter(void);

        void setRadius(double radius);
        double getRadius(void);

        std::string toString(void);
        double getArea(void);
        double getCircumference(void);
        double distance(MyCircle circle);

    private:
        // -- Attributes --
        MyPoint center;
        double radius;
};

#endif