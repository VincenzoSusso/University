/* 
    Libreria che fornisce diverse funzioni per la gestione delle date
*/

// -- Librerie --
#include <stdlib.h>
#include <stdbool.h>
#include "Utility.h"

// -- Costanti --

/* Nel calendario gregoriano sono bisestili:
   - gli anni non secolari il cui numero è divisibile per 4;
   - gli anni secolari (quindi divisibili per 100) il cui numero è divisibile per 400.
*/
#define ANNO_SECOLARE 100 // Un anno secolare implica che sia divisibile per 100
#define ANNO_BISESTILE_SECOLARE 400 // Un anno secolare bisestile implica che sia divisibile per 400
#define ANNO_BISESTILE 4 // Un anno bisestile non secolare implica che sia divisibile per 4

#define MIN_GIORNO 1
#define MAX_GIORNO 31
#define MAX_GIORNO_FEBBRAIO 29

#define MIN_ANNO 1970
#define MAX_ANNO 2000


// -- Tipi di dati definiti dall'utente --
typedef enum {gennaio = 1, febbraio, marzo, aprile, maggio, giugno, luglio, agosto, settembre, ottobre, novembre, dicembre} Mesi_t;

typedef struct
{
    unsigned short anno;
    unsigned short mese;
    unsigned short giorno;
} Data_t;

// -- Prototipi di Procedure & Funzioni --
Data_t generaDataCasuale(void); //Genera una data casuale
bool isDataCorretta(Data_t data);
bool areDateUguali(Data_t prima_data, Data_t seconda_data);
Data_t dataPiuRecente(Data_t prima_data, Data_t seconda_data); //Restituisce la data più recente tra due date
Data_t dataMenoRecente(Data_t prima_data, Data_t seconda_data); //Restituisce la data meno recente tra due date