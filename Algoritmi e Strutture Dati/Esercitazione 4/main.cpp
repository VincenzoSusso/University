/*
	Algoritmi e Strutture Dati - Esercitazione 4
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#include <iostream>
#include "MyPoint.h"
#include "MyCircle.h"
#include "MyTriangle.h"

int main(void)
{
	MyPoint point_1 = MyPoint(3, 5);
	MyPoint point_2 = MyPoint();

	point_2.setX(6);
	point_2.setY(0);

	std::cout << point_1.toString() << std::endl;
	std::cout << point_2.toString() << std::endl;
	std::cout << "The distance between the first and the second point is: " << point_1.distance(point_2) << std::endl;

	std::cout << std::endl << std::endl;
	MyCircle circle_1 = MyCircle();
	MyCircle circle_2 = MyCircle(point_1, 6);

	std::cout << circle_1.toString() << std::endl;
	std::cout << "The area of the first circle is: " << circle_1.getArea() << std::endl;
	std::cout << "The circumference of the first circle is: " << circle_1.getCircumference() << std::endl;
	std::cout << circle_2.toString() << std::endl;
	std::cout << "The distance between the center the first and the second circle is: " << circle_1.distance(circle_2) << std::endl;
	
	std::cout << std::endl << std::endl;
	MyTriangle triangle_1 = MyTriangle(MyPoint(), MyPoint(6, 6), MyPoint(0, 9));
	MyTriangle triangle_2 = MyTriangle(MyPoint(), MyPoint(0, 5), MyPoint(5, 0));

	std::cout << triangle_1.toString() << std::endl;
	std::cout << "The area of the first triangle is: " << triangle_1.getArea() << std::endl;
	std::cout << "The perimeter of the first triangle is: " << triangle_1.getPerimeter() << std::endl;
	std::cout << "The first triangle is: " << triangle_1.getType() << std::endl;
	std::cout << triangle_2.toString() << std::endl;
	std::cout << "The second triangle is: " << triangle_2.getType() << std::endl;

	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}