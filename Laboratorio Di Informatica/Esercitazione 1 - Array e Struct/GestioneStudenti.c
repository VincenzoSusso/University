// LABORATORIO DI INFORMATICA - Track B (INF)
// Docente: Veronica Rossano
// Esercitazione 1 - 11/03/2018 (consegna entro 14/03/2018)
// -----------------------------
// Nome: Vincenzo
// Cognome: Susso
// Matricola: 697538
// ------------------------------

/* Estensioni aggiunte : - Generazione random data di nascita
                         - Controlli sulla data
                         - Estensione libretto
                         - Voto massimo e minimo di ogni studente
*/

// -- Librerie --
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GestioneStudenti.h"

// -- Main --
int main(void)
{
    Studenti_t studente[N_STUDENTI] = {{STRINGA_VUOTA, STRINGA_VUOTA, MIN_MATRICOLA, {MIN_GIORNO, gennaio, MIN_ANNO_NASCITA}, {STRINGA_VUOTA, MIN_VOTO}}};
    unsigned short frequenza_voti[N_ELEMENTI_FREQUENZA] = {MIN_VOTO};

    srand(time(NULL));

    leggiStudenti(N_STUDENTI, studente);
    leggiEsami(N_STUDENTI, studente);
    assegnazioneFrequenze(N_STUDENTI, studente, frequenza_voti);

   scriviDatiStudenti(N_STUDENTI, studente, N_ELEMENTI_FREQUENZA, frequenza_voti);

    printf("\n\n");

    exit(EXIT_SUCCESS);
}