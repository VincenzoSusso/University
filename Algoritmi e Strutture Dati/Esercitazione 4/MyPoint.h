/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#ifndef MYPOINT_H
#define MYPOINT_H

#include <iostream>
#include <string>
#include <cmath>

class MyPoint
{
    public:
        using coord_t = double;
        
        // -- Interfaces --
        MyPoint(void);
        MyPoint(coord_t x, coord_t y);
        ~MyPoint();

        void setX(coord_t x);
        coord_t getX(void);
        
        void setY(coord_t y);
        coord_t getY(void);

        double distance(MyPoint point);
        std::string toString(void);

    private:
        // -- Attributes --
        coord_t x;
        coord_t y;
};

#endif