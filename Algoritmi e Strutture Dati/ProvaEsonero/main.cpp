/*
	Algoritmi e Strutture Dati - ProvaEsonero
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <iostream>
#include <list>
#include <iterator>

void processa_liste(std::list<int>& lista1, std::list<int>& lista2, std::list<int>& lista3);
void leggiLista(std::list<int>& lista);

int main(void) 
{
	std::list<int> lista1 = std::list<int>();
	std::list<int> lista2 = std::list<int>();
	std::list<int> lista3 = std::list<int>();

	lista1.push_back(5);
	lista1.push_back(15);
	lista1.push_back(2);
	lista1.push_back(14);
	lista1.push_back(13);
	lista1.push_back(7);
	
	std::cout << "Lista1: ";
	leggiLista(lista1);
	std::cout << std::endl << std::endl;

	processa_liste(lista1, lista2, lista3);

	std::cout << "Lista1: ";
	leggiLista(lista1);
	std::cout << std::endl;

	std::cout << "Lista2: ";
	leggiLista(lista2);
	std::cout << std::endl;

	std::cout << "Lista3: ";
	leggiLista(lista3);
	std::cout << std::endl << std::endl;

	system("PAUSE");
	exit(EXIT_SUCCESS);	
}

void processa_liste(std::list<int>& lista1, std::list<int>& lista2, std::list<int>& lista3)
{	
	std::list<int>::iterator i = lista1.begin();

	while(i != lista1.end())
	{
		if(*i > 10)
		{
			if(*i % 2)
			{
				lista3.push_back(*i);
				
			}
			else
			{
				lista2.push_back(*i);
			}
			i = std::next(i);
			lista1.erase(std::prev(i));
		}
		else
		{
			i = std::next(i);
		}
		
	}

	if(lista1.empty())
	{
		std::cout <<"Lista1 vuota" << std::endl;
	}
}

void leggiLista(std::list<int>& lista)
{
	for(std::list<int>::iterator i = lista.begin(); i != lista.end(); i++)
	{
		std::cout << *i << "\t";
	}	
}