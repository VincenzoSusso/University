/*
	Algoritmi e Strutture Dati - Esercitazione 3
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrice.h"

#define MAX_RAND 100

int main(void) 
{
	Matrice<int> matrice_1 = Matrice<int>(5,4);
	Matrice<int> matrice_2 = Matrice<int>();

	srand(time(NULL));

	matrice_1.RiempiMatrice(1);

	try
	{
		for(unsigned short i = 0; i < matrice_1.getNRighe(); i++)
		{
			for(unsigned short j = 0; j < matrice_1.getNColonne(); j++)
			{
				matrice_1.scriviElemento(i, j, rand() % MAX_RAND);
			}
		}
	}
	catch(const char *strException)
	{
		std::cerr << std::endl << strException << std::endl;
	}

	std::cout << "Matrice 1: " << std::endl << std::endl;
	matrice_1.stampaMatrice();

	std::cout << std::endl << "Matrice 1 trasposta: " << std::endl << std::endl;

	matrice_2.copiaMatrice(matrice_1);
	matrice_1.trasposta();
	matrice_1.stampaMatrice();

	std::cout << std::endl << "Matrice 2: " << std::endl << std::endl;
	matrice_2.prodottoScalare(2);
	matrice_2.stampaMatrice();

	try
	{
		matrice_1.prodotto(matrice_2);
	}
	catch(const char *strException)
	{
		std::cerr << std::endl << strException << std::endl;
	}

	std::cout << std::endl << "Prodotto tra matrice 1 trasposta e matrice 2: " << std::endl << std::endl;
	matrice_1.stampaMatrice();

	std::cout << std::endl << std::endl;

	system("PAUSE");
	exit(EXIT_SUCCESS);
}