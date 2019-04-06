/* 
    Libreria che fornisce diverse funzioni per la gestione degli utenti
*/

// -- Librerie --
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "Data.h"
#include "Utility.h"

// -- Costanti --
#define N_STRINGHE 20 // Numero dei possibili nomi e cognomi
#define STRINGAVUOTA "" // Utilizzato per "pulire la stringa" quando vengono generati i nomi e i cognomi casuali
#define CARATTERE_TERMINALE '\0' /* Utilizzato per terminare la stringa (non ho utilizzato gli apici singoli in modo 
                                    da poter utilizzare le funzioni presenti in string.h) */
#define CARATTERE_OSCURATO '*' // Utilizzato per oscurare la password

#define MIN_CARATTERE_PASSWORD '!' // Range di caratteri utilizzati per la generazione della password casuale (vedi codice ASCII)
#define MAX_CARATTERE_PASSWORD '~'

#define LUNGHEZZA_STRINGHE 15 // Dimensione massima del nome, cognome e della email
#define LUNGHEZZA_PASSWORD 9 /* La lunghezza della password deve essere di 8 caratteri, l'ultimo carattere
                                è riservato al carattere terminale '\0' */
#define LUNGHEZZA_EMAIL 60

#define PASSWORD_SICURA 3 // La password è sicura se il numero di caratteri speciali e numeri (in totale) è compreso tra 3 e 5
#define PASSWORD_MOLTO_SICURA 5 // La password è sicura se il numero di caratteri speciali e numeri (in totale) è maggiore di 5

#define N_DOMINI 10

#define MIN_MAIUSCOLE 1 // La password inserita dall'utente deve contenere almeno una maiuscola e un numero
#define MIN_NUMERI 1

#define N_UTENTI 20

// -- Tipi definiti dall'utente --
typedef enum             
{        
    password_manuale,     // Tipo definito dall'utente,  utilizzato per comprendere se l'utente vuole inserire la
    password_casuale,    // password manualmente o se desidera generare la password casualmente (aumenta scalabilità)
    scelta_non_definita  // --> (Valore utilizzato per inizializzare la variabile)
}   Scelta_t;

typedef enum 
{
    poco_sicura,
    sicura,
    molto_sicura,
    non_definita        // --> (Valore utilizzato per inizializzare la variabile)
}   Livello_password_t;

typedef struct 
{
    char nome[LUNGHEZZA_STRINGHE];
    char cognome[LUNGHEZZA_STRINGHE];
    Data_t data_nascita;
    char email[LUNGHEZZA_EMAIL];
    char password[LUNGHEZZA_PASSWORD];
    Livello_password_t livello_password;
}   Account_t;

// -- Prototipi di Procedure & Funzioni --
void generaStringaCasuale(const char stringhe_casuali[][LUNGHEZZA_STRINGHE], char stringa[]); /* Procedura utilizzata per assegnare all'array stringa[] una 
                                                                                                 delle stringhe casuali presenti nella matrice 
                                                                                                 stringhe_casuali[][] */
void generaEmail(const char domini_email[][LUNGHEZZA_STRINGHE], Account_t *account);
void generaPassword(char password[]); 
Livello_password_t assegnaLivelloPassword(char password[]); /* Funzione utilizzata per associare la password 
                                                               ad uno dei tre livelli di sicurezza */
bool isPasswordCorretta(char password[]); /* Funzione utilizzata per controllare se la password inserita dall'utente
                                             è corretta */
void gestionePassword(Account_t *account, unsigned short indice); // Procedura utilizzata per la generazione della password
char *visualizzaLivelloPassword(Livello_password_t livello_password); // Converte il livello della password nella corrispettiva stringa
char *oscuraPassword(char password[]);
void generaAccount(Account_t account[], const char stringhe_nomi[][LUNGHEZZA_STRINGHE], const char stringhe_cognomi[][LUNGHEZZA_STRINGHE], const char domini_email[][LUNGHEZZA_STRINGHE]);
void visualizzaAccount(Account_t account[]); // Visualizza tutti gli account
void visualizzaAccountPassword(Account_t account[], Livello_password_t livello_password); /* Visualizza gli account con un determinato 
                                                                                             livello di sicurezza della password */
void visualizzaUtentePiuVecchio(Account_t account[]);
Account_t utentePiuVecchio(Account_t account[]);