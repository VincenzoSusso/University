/*
	Algoritmi e Strutture Dati - Esercitazione 2
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include "Studente.h"

// -- Implementazioni Metodi --
bool Studente::setMatricola(std::string *matricola)
{
    const std::string stringa_vuota = "";

    bool matricola_valida = false;
    int matricola_input = min_matricola - 1;
    
    matricola_valida = std::all_of((matricola -> begin()), (matricola -> end()), ::isdigit);

    if(matricola_valida)
    {
        if(matricola -> compare(stringa_vuota))
        {
            matricola_input = std::stoi(*matricola);
        }

        if(matricola_input >= min_matricola && matricola_input <= max_matricola)
        {
            this -> matricola = matricola_input;
        }
        else
        {
            matricola_valida = false;
        }
    }

    return matricola_valida;
}

int Studente::getMatricola(void)
{
    return this -> matricola;
}

bool Studente::setNome(std::string *nome)
{
    const std::string stringa_vuota = "";

    bool nome_valido = false;

    nome_valido = std::all_of(nome -> begin(), nome -> end(), ::isalpha);

    if(nome_valido)
    {
        if(!(nome -> compare(stringa_vuota)))
        {
            nome_valido = false;
        }

        if((nome -> length()) > lunghezza_stringhe)
        {
            nome_valido = false;
        }
    }

    if(nome_valido)
    {
        this -> nome = *nome;
        this -> nome[0] = toupper(this -> nome[0]);
    }

    return nome_valido;
}

std::string Studente::getNome(void)
{
    return this -> nome;
}

bool Studente::setCognome(std::string *cognome)
{
    const std::string stringa_vuota = "";

    bool cognome_valido = false;

    cognome_valido = std::all_of(cognome -> begin(), cognome -> end(), ::isalpha);

    if(cognome_valido)
    {
        if(!(cognome -> compare(stringa_vuota)))
        {
            cognome_valido = false;
        }

        if((cognome -> length()) > lunghezza_stringhe)
        {
            cognome_valido = false;
        }
    }

    if(cognome_valido)
    {
        this -> cognome = *cognome;
        this -> cognome[0] = toupper(this -> cognome[0]);
    }

    return cognome_valido;
}

std::string Studente::getCognome(void)
{
    return this -> cognome;
}

bool Studente::setEta(std::string *eta)
{
    const std::string stringa_vuota = "";

    bool eta_valida = false;
    int eta_input = min_eta - 1;;
    
    eta_valida = std::all_of((eta -> begin()), (eta -> end()), ::isdigit);

    if(eta_valida)
    {
        if(eta -> compare(stringa_vuota))
        {
            eta_input = std::stoi(*eta);
        }

        if(eta_input >= min_eta && eta_input <= max_eta)
        {
            this -> eta = eta_input;
        }
        else
        {
            eta_valida = false;
        }
        
    }

    return eta_valida;
}

int Studente::getEta(void)
{
    return this -> eta;
}