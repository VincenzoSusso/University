/*
	Algoritmi e Strutture Dati - Esercitazione 5.0
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <iostream>
#include "LinkedList.h"

int main(void) 
{
	LinkedList<int> list = LinkedList<int>();

	try
	{
		std::cout << "Checking if the list is void: " << list.empty() << std::endl << std::endl;

		std::cout << "Entering the sequence <22, 12, 15> into the list" << std::endl;
		list.insert(list.begin(), 22);
		list.insert(list.next(list.begin()), 12);
		list.insert(list.next(list.next(list.begin())), 15);
		std::cout << "list: " << list.toString() << std::endl << std::endl;

		std::cout << "Changing the element of position 1 with the number 42: " << std::endl;
		list.write(list.next(list.begin()), 42);
		std::cout << "list: " << list.toString() << std::endl << std::endl;

		std::cout << "Erasing the element of position 0" << std::endl;
		list.erase(list.begin());
		std::cout << "list: " << list.toString() << std::endl << std::endl;

		std::cout << "Entering the element <50> in position 0" << std::endl;
		list.insert(list.begin(), 50);
		std::cout << "list: " << list.toString() << std::endl;

		std::cout << "Length of the list: " << list.getLengthList() << std::endl << std::endl;

		std::cout << "Reversing the list" << std::endl;
		list.reverse();
		std::cout << "list: " << list.toString() << std::endl << std::endl;

		std::cout << "Checking if the list is palindrome: " << list.palindrome() << std::endl << std::endl;
	}
	catch(const char* error) 
	{
		std::cerr << std::endl << error << std::endl;
	}

	list.~LinkedList();

	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}