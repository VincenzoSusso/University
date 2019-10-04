/*
	Algoritmi e Strutture Dati - Esercitazione 2
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef STUDENTE_H
#define STUDENTE_H

#include <cstdbool>
#include <string>
#include <algorithm>
#include <iostream>

class Studente
{
    public:
        // -- Interfacce --
        bool setMatricola(std::string *matricola);
        int getMatricola(void);

        bool setNome(std::string *nome);
        std::string getNome(void);

        bool setCognome(std::string *cognome);
        std::string getCognome(void);

        bool setEta(std::string *eta);
        int getEta(void);

    private:
        // -- Costanti --
        const int min_matricola = 255312;
        const int max_matricola = 499999;
        const int lunghezza_stringhe = 30;
        const unsigned short min_eta = 12;
        const unsigned short max_eta = 105;

        // - Attributi --
        int matricola;
        std::string nome;
        std::string cognome;
        unsigned short eta;
};

#endif