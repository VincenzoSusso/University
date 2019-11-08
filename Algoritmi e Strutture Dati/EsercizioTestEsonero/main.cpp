/*
	Algoritmi e Strutture Dati - EsercitazioneTestEsonero
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <iostream>
#include "LinkedList.h"

void function(LinkedList<int>& list1, LinkedList<int>& list2, LinkedList<int>& list3);
void readList(LinkedList<int>& list);

int main(void) 
{
	LinkedList<int> list1 = LinkedList<int>();
	LinkedList<int> list2 = LinkedList<int>();
	LinkedList<int> list3 = LinkedList<int>();

	
	list1.insert(list1.begin(), 5);
	list1.insert(list1.begin(), 4);
	list1.insert(list1.begin(), 3);
	list1.insert(list1.begin(), 2);
	list1.insert(list1.begin(), 1);

	try
	{
		function(list1, list2, list3);	
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
	}

	std::cout << "List1: ";
	readList(list1);
	std::cout << std::endl;

	std::cout << "List2: ";
	readList(list2);
	std::cout << std::endl;

	std::cout << "List3: ";
	readList(list3);
	std::cout << std::endl;


	list1.~LinkedList();
	list2.~LinkedList();
	list3.~LinkedList();

	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}

void function(LinkedList<int>& list1, LinkedList<int>& list2, LinkedList<int>& list3)
{
	auto temp = list1.begin();

	if(!list1.empty())
	{
		while(!list1.end(temp))
		{
			if(list1.read(temp) <= 0)
			{
				throw "Errore";
			}

			if(list1.read(temp) % 2)
			{
				list3.insert(list3.begin(), list1.read(temp));
			}
			else
			{
				list2.insert(list2.begin(), list1.read(temp));
			}
		
			temp = list1.next(temp);
		}
		if(list1.read(temp) <= 0)
		{
			throw "Errore";
		}

		if(list1.read(temp) % 2)
		{
			list3.insert(list3.begin(), list1.read(temp));
		}
		else
		{
			list2.insert(list2.begin(), list1.read(temp));
		}
	}

}

void readList(LinkedList<int>& list)
{
	auto temp = list.begin();
	
	if(!list.empty())
	{
		while(!list.end(temp))
		{
			std::cout << list.read(temp) << " ";

			temp = list.next(temp);
		}
		std::cout << list.read(temp);	
	}

}