/*
	Algoritmi e Strutture Dati - Esercitazione 2
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Librerie --
#include <iostream>
#include <cstdlib>
#include <string>

#include "Studente.h"

// -- Main --
int main(int argc, char *argv[]) 
{
	Studente studente = Studente();
	std::string input = "";
	bool input_valido = false;

	// Input matricola studente
	do
	{
		std::cout << "Inserisci la matricola dello studente: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		input_valido = studente.setMatricola(&input);
	} while(!input_valido);

	input = "";
	input_valido = false;

	// Input nome studente
	do
	{
		std::cout << "Inserisci il nome dello studente: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		input_valido = studente.setNome(&input);
	} while(!input_valido);

	input = "";
	input_valido = false;

	// Input cognome studente
	do
	{
		std::cout << "Inserisci il cognome dello studente: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		input_valido = studente.setCognome(&input);
	} while(!input_valido);

	input = "";
	input_valido = false;

	// Input età studente
	do
	{
		std::cout << "Inserisci l'eta' dello studente: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		input_valido = studente.setEta(&input);
	} while(!input_valido);

	// Output studente
	std::cout << std::endl << "-------------------------------------------------------------------------------" <<std::endl;
	std::cout << "Matricola studente: "<< studente.getMatricola() << std::endl;
	std::cout << "Nome studente: "<< studente.getNome() << std::endl;
	std::cout << "Cognome studente: "<< studente.getCognome() << std::endl;
	std::cout << "Eta' studente: "<< studente.getEta() << std::endl;
	std::cout << "-------------------------------------------------------------------------------" <<std::endl;

	std::cout << std::endl << std::endl;
	system("PAUSE");
	exit(EXIT_SUCCESS);
}