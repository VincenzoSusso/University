/*
	Algoritmi e Strutture Dati - List
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

int main(void) 
{
	ArrayList<int> list1 = ArrayList<int>();
	LinkedList<int> list2 = LinkedList<int>();
	
	try
	{
		std::cout << "Checking if the list1 is void: " << list1.empty() << std::endl << std::endl;

		std::cout << "Entering the sequence <22, 12, 15> into the list1" << std::endl;
		list1.insert(0, 22);
		list1.insert(1, 12);
		list1.insert(2, 15);
		std::cout << "List1: " << list1.toString() << std::endl << std::endl;

		std::cout << "Changing the element of position 1 with the number 42: " << std::endl;
		list1.write(1, 42);
		std::cout << "List1: " << list1.toString() << std::endl << std::endl;

		std::cout << "Erasing the element of position 0" << std::endl;
		list1.erase(0);
		std::cout << "List1: " << list1.toString() << std::endl << std::endl;

		std::cout << "Entering the element <50> in position 0" << std::endl;
		list1.insert(0, 50);
		std::cout << "List1: " << list1.toString() << std::endl << std::endl;
	}
	catch(const char* errore) 
	{
		std::cerr << std::endl << errore << std::endl;
	}

	list1.~ArrayList();
	std::cout << "----------------------------------" << std::endl << std::endl;

	try
	{
		std::cout << "Checking if the list2 is void: " << list2.empty() << std::endl << std::endl;

		std::cout << "Entering the sequence <22, 12, 15> into the list" << std::endl;
		list2.insert(list2.begin(), 22);
		list2.insert(list2.next(list2.begin()), 12);
		list2.insert(list2.next(list2.next(list2.begin())), 15);
		std::cout << "List2: " << list2.toString() << std::endl << std::endl;

		std::cout << "Changing the element of position 1 with the number 42: " << std::endl;
		list2.write(list2.next(list2.begin()), 42);
		std::cout << "List2: " << list2.toString() << std::endl << std::endl;

		std::cout << "Erasing the element of position 0" << std::endl;
		list2.erase(list2.begin());
		std::cout << "List2: " << list2.toString() << std::endl << std::endl;

		std::cout << "Entering the element <50> in position 0" << std::endl;
		list2.insert(list2.begin(), 50);
		std::cout << "List2: " << list2.toString() << std::endl << std::endl;
	}
	catch(const char* errore) 
	{
		std::cerr << std::endl << errore << std::endl;
	}

	list2.~LinkedList();

	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}