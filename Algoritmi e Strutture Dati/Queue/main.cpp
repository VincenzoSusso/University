/*
	Algoritmi e Strutture Dati - Queue
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <iostream>
#include "QueueList.h"
#include "QueueArray.h"

int main(void) 
{
	QueueList<int> queue1 = QueueList<int>();
	QueueArray<int> queue2 = QueueArray<int>();

	try
	{
		std::cout << "Checking if the queue1 is empty: " << queue1.empty() << std::endl << std::endl;

		std::cout << "Entering the sequence <22, 12, 15> into the queue1" << std::endl << std::endl;
		queue1.enqueue(22);
		queue1.enqueue(12);
		queue1.enqueue(15);
		while (!(queue1.empty()))
		{
			std::cout << "Element to dequeue: " << queue1.front() << std::endl;
			std::cout << "Dequeque of the element" << std::endl;
			queue1.dequeue();
		}
		std::cout << std::endl << "queue1 is empty" << std::endl << std::endl;
	}
	catch(const char* error) 
	{
		std::cerr << std::endl << error << std::endl;
	}

	queue1.~QueueList();
	std::cout << "----------------------------------" << std::endl << std::endl;

	try
	{
		std::cout << "Checking if the queue2 is empty: " << queue2.empty() << std::endl << std::endl;

		std::cout << "Entering the sequence <22, 12, 15> into the queue2" << std::endl << std::endl;
		queue2.enqueue(22);
		queue2.enqueue(12);
		queue2.enqueue(15);
		while (!(queue2.empty()))
		{
			std::cout << "Element to dequeue: " << queue2.front() << std::endl;
			std::cout << "Dequeque of the element" << std::endl;
			queue2.dequeue();
		}
		std::cout << std::endl << "queue2 is empty" << std::endl << std::endl;
	}
	catch(const char* error) 
	{
		std::cerr << std::endl << error << std::endl;
	}

	queue2.~QueueArray();

	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}