/*
	Algoritmi e Strutture Dati - Stack
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <iostream>
#include "StackList.h"
#include "StackArray.h"

int main(void) 
{
	StackList<int> stack1 = StackList<int>();
	StackArray<int> stack2 = StackArray<int>();

	try
	{
		std::cout << "Checking if the stack1 is empty: " << stack1.empty() << std::endl << std::endl;
		
		std::cout << "Entering the sequence <22, 12, 15> into the stack1" << std::endl << std::endl;
		stack1.push(15);
		stack1.push(12);
		stack1.push(22);
		while(!(stack1.empty()))
		{
			std::cout << "Element at the top of stack1: " << stack1.top() << std::endl;
			std::cout << "Pop of stack1" << std::endl;
			stack1.pop();
		}
		std::cout << std::endl << "Stack1 is empty" << std::endl << std::endl;
	}
	catch(const char* error) 
	{
		std::cerr << std::endl << error << std::endl;
	}

	stack1.~StackList();
	std::cout << "----------------------------------" << std::endl << std::endl;

	try
	{
		std::cout << "Checking if the stack2 is empty: " << stack2.empty() << std::endl << std::endl;
		
		std::cout << "Entering the sequence <22, 12, 15> into the stack2" << std::endl << std::endl;
		stack2.push(15);
		stack2.push(12);
		stack2.push(22);

		while(!(stack2.empty()))
		{
			std::cout << "Element at the top of stack2: " << stack2.top() << std::endl;
			std::cout << "Pop of stack2" << std::endl;
			stack2.pop();
		}
		std::cout << std::endl << "Stack2 is empty" << std::endl << std::endl;
	}
	catch(const char* error) 
	{
		std::cerr << std::endl << error << std::endl;
	}

	stack2.~StackArray();
	
	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}