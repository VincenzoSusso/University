/*
	Algoritmi e Strutture Dati - Esercitazione 3
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <vector>

template <typename Elementi_matrice>
class Matrice
{
    public:
        // -- Interfacce --
        Matrice(void);
        Matrice(unsigned short n_righe, unsigned short n_colonne);
        ~Matrice(void);

        void CambiaDimensioneMatrice(void);
        void setRighe(unsigned short n_righe);
        unsigned short getNRighe(void);
        void setColonne(unsigned short n_colonne);
        unsigned short getNColonne(void);

        void scriviElemento(unsigned short n_riga, unsigned short n_colonna, Elementi_matrice elemento);
        Elementi_matrice leggiElementoMatrice(unsigned short n_riga, unsigned short n_colonna);

        void copiaMatrice(Matrice<Elementi_matrice> matrice);
        void RiempiMatrice(Elementi_matrice elemento);
        void stampaMatrice(void);
        void prodottoScalare(Elementi_matrice elemento);
        void trasposta(void);
        void prodotto(Matrice<Elementi_matrice> matrice);
    private:
        // - Attributi --
        unsigned short n_righe;
        unsigned short n_colonne;
        std::vector< std::vector<Elementi_matrice> > matrice;
};

// -- Implementazioni Metodi --
template <typename Elementi_matrice>
Matrice<Elementi_matrice>::Matrice(void) : Matrice(1,1){}

template <typename Elementi_matrice>
Matrice<Elementi_matrice>::Matrice(unsigned short n_righe, unsigned short n_colonne)
{
    this -> setRighe(n_righe);
	this -> setColonne(n_colonne);

    this -> CambiaDimensioneMatrice();
}

template <typename Elementi_matrice>
Matrice<Elementi_matrice>::~Matrice(void) {}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::CambiaDimensioneMatrice(void)
{
    this -> matrice.resize(this -> n_righe);
    for(unsigned short i = 0; i < this -> n_righe; i++)
    {
        this -> matrice[i].resize(this -> n_colonne);
    }
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::setRighe(unsigned short n_righe)
{
    this -> n_righe = n_righe;
}

template <typename Elementi_matrice>
unsigned short Matrice<Elementi_matrice>::getNRighe(void)
{
    return this -> n_righe;
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::setColonne(unsigned short n_colonne)
{
    this -> n_colonne = n_colonne;
}

template <typename Elementi_matrice>
unsigned short Matrice<Elementi_matrice>::getNColonne(void)
{
    return this -> n_colonne;
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::scriviElemento(unsigned short n_riga, unsigned short n_colonna, Elementi_matrice elemento)
{
    if(n_riga >= this -> getNRighe())
    {
        throw "Il numero di riga che hai inserito non è valida";
    }

    if(n_colonna >= this -> getNColonne())
    {
        throw "Il numero di colonna che hai inserito non è valido";
    }

    this -> matrice[n_riga][n_colonna] = elemento;
}

template <typename Elementi_matrice>
Elementi_matrice Matrice<Elementi_matrice>::leggiElementoMatrice(unsigned short n_riga, unsigned short n_colonna)
{
    if(n_riga >= this -> getNRighe())
    {
        throw "Il numero di riga che hai inserito non è valida";
    }

    if(n_colonna >= this -> getNColonne())
    {
        throw "Il numero di colonna che hai inserito non è valido";
    }

    return this -> matrice[n_riga][n_colonna]; 
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::copiaMatrice(Matrice<Elementi_matrice> matrice)
{
    this -> setRighe(matrice.getNRighe());
    this -> setColonne(matrice.getNColonne());

    this -> CambiaDimensioneMatrice();

    for(unsigned short i = 0; i < this -> getNRighe(); i++)
    {
        for(unsigned short j = 0; j < this -> getNColonne(); j++)
        {
            this -> scriviElemento(i, j, matrice.leggiElementoMatrice(i, j));
        }
    }
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::RiempiMatrice(Elementi_matrice elemento)
{
    for(unsigned short i = 0; i < this -> getNRighe(); i++)
    {
        for(unsigned short j = 0; j < this -> getNColonne(); j++)
        {
            this -> scriviElemento(i, j, elemento);
        }
    }
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::stampaMatrice(void)
{
    for(unsigned short i = 0; i < this -> getNRighe(); i++)
    {
        for(unsigned short j = 0; j < this -> getNColonne(); j++)
        {
            std::cout << leggiElementoMatrice(i, j) << "\t"; 
        }
        std::cout<<std::endl;
    }
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::prodottoScalare(Elementi_matrice elemento)
{
    for(unsigned short i = 0; i < this -> getNRighe(); i++)
    {
        for(unsigned short j = 0; j < this -> getNColonne(); j++)
        {
            scriviElemento(i, j, elemento * leggiElementoMatrice(i ,j));
        }
    }
}

template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::trasposta(void)
{
    Matrice<Elementi_matrice> temp = Matrice<Elementi_matrice>();

    temp.copiaMatrice(*this);

    this -> setRighe(temp.getNColonne());
    this -> setColonne(temp.getNRighe());

    this -> CambiaDimensioneMatrice();

    for(unsigned short i = 0; i < this -> getNRighe(); i++)
    {
        for(unsigned short j = 0; j < this -> getNColonne(); j++)
        {
            this -> scriviElemento(i, j, temp.leggiElementoMatrice(j,i));
        }
    }
}
template <typename Elementi_matrice>
void Matrice<Elementi_matrice>::prodotto(Matrice<Elementi_matrice> matrice)
{
    Matrice<Elementi_matrice> temp = Matrice<Elementi_matrice>();

    if(this -> getNColonne() != matrice.getNRighe())
    {
        throw "Il numero di colonne della prima matrice è diverso dal numero di righe della seconda matrice";
    }

    temp.copiaMatrice(*this);

    this -> setRighe(temp.getNRighe());
    this -> setColonne(matrice.getNColonne());

    this -> CambiaDimensioneMatrice();

    for(unsigned short i = 0; i < temp.getNRighe(); i++)
    {
        for(unsigned short j = 0; j < matrice.getNColonne(); j++)
        {
            this -> scriviElemento(i, j, 0);
            for(unsigned short k = 0; k < matrice.getNRighe(); k++)
            {
                this -> scriviElemento(i, j, this -> leggiElementoMatrice(i, j) + temp.leggiElementoMatrice(i, k) * matrice.leggiElementoMatrice(k, j));
            }
        }
    }
}

#endif