// -- Librerie --
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// -- Costanti --
#define MAXSTRINGA 30
#define N_STUDENTI 10
#define N_ESAMI 20
#define N_ELEMENTI_FREQUENZA 32 /* Il numero di elementi della frequenza dei voti dipende dal range dal voto massimo infatti il numero di elementi della frequenza è ottenuta dalla formula MAXVOTO + 1 */

/* Nel calendario gregoriano sono bisestili:
   - gli anni non secolari il cui numero è divisibile per 4;
   - gli anni secolari (quindi divisibili per 100) il cui numero è divisibile per 400.
*/
#define ANNO_SECOLARE 100 //Un anno secolare implica che sia divisibile per 100
#define ANNO_BISESTILE_SECOLARE 400 //Un anno secolare bisestile implica che sia divisibile per 400
#define ANNO_BISESTILE 4 //Un anno bisestile non secolare implica che sia divisibile per 4

#define MIN_GIORNO 1
#define MAX_GIORNO_31 31  // Costanti utilizzate per gestire i mesi con giorni diversi
#define MAX_GIORNO_30 30
#define MAX_GIORNO_29 29
#define MAX_GIORNO_BISESTILE 28

//Costanti utilizzate per la programmazione difensiva

#define MIN_ANNO_NASCITA 1985
#define MAX_ANNO_NASCITA 1999

#define MIN_VOTO 0
#define MAX_VOTO 31

#define MIN_MATRICOLA 0

#define STRINGA_VUOTA "" // Costanti utilizzate per gestire eventuali errori nell'inserimento delle stringhe
#define SPAZIO " "
#define RITORNO_CAPO "\n"

// -- Tipi di dati definiti dall'utente --
typedef enum {gennaio = 1, febbraio, marzo, aprile, maggio, giugno, luglio, agosto, settembre, ottobre, novembre, dicembre} Mesi_t;

typedef struct
{
    unsigned short anno;
    unsigned short mese;
    unsigned short giorno;
} Data_t;

typedef struct 
{
    char nome_esame[MAXSTRINGA];
    unsigned short voto;
} Esame_t;

typedef struct
{
    char nome[MAXSTRINGA];
    char cognome[MAXSTRINGA];
    int matricola;
    Data_t data_nascita;
    Esame_t esame[N_ESAMI];
} Studenti_t;

// -- Prototipi di Procedure & Funzioni --
void pulisci_buffer(void); //Utilizzato per pulire il buffer dal carattere new line (\n) in modo da non andare in loop

unsigned short ricercaIndiceValoreMassimo(unsigned short n_elementi, unsigned short array[]); // Utilizzato per restituire l'indice del valore massimo di un array (utile per il calcolo della moda)
unsigned short nElementiDiversi(const unsigned short n_elementi, unsigned short array[], int elemento); // Utilizzato per restituire il numero di elementi diversi di un numero in un array (utile per il calcolo della mediana)
unsigned short sommaElementiArray(const unsigned short n_elementi, unsigned short array[]); // Utilizzato per restituire la somma degli elementi dell'array (utile per il calcolo della mediana)

int generaValoreCasuale(int min, int max); // Genera un valore casuale nel range min - max
bool controlloStringa(char stringa[]); // Utilizzata per comprendere se il valore inserito è valido (nome/cognome) restituisce true se la stringa è corretta, false altrimenti

Data_t generaDataDiNascita(void); // Utilizzato per generare una data corretta
void leggiEsami(const int n_studenti, Studenti_t studente[]); // Utilizzato per leggere il nome degli esami e assegnare i voti a tutti gli studenti
void leggiStudenti(const int n_studenti, Studenti_t studente[]); // Utilizzato per leggere i dati degli studenti

void assegnazioneFrequenze(const int n_studenti, Studenti_t studente[], unsigned short frequenza_voti[]);
unsigned short calcoloModa(const unsigned short n_elementi, unsigned short frequenza_voti[]);
float calcoloMediana(const unsigned short n_elementi, unsigned short frequenza_voti[]);

float mediaEsami(unsigned short n_esami, Esame_t esame[]);
unsigned short votoMassimoEsame(unsigned short n_esami, Esame_t esame[]);
unsigned short votoMinimoEsame(unsigned short n_esami, Esame_t esame[]);

void scriviDatiStudenti(unsigned short n_studenti, Studenti_t studente[], unsigned short n_elementi_frequenza, unsigned short frequenza[]);

// -- Procedure & Funzioni --
void pulisci_buffer(void)
{
    getchar();
}

unsigned short ricercaIndiceValoreMassimo(unsigned short n_elementi, unsigned short array[])
{
    unsigned short i = 0; // Indice dell'array
    unsigned short massimo = MIN_VOTO;
    unsigned short indice_massimo = MIN_VOTO;

    for(i = 0; i < n_elementi; i++)
    {
        if(massimo < array[i])
        {
            massimo = array[i];
            indice_massimo = i;
        }
    }
    
    return indice_massimo;
}

unsigned short nElementiDiversi(const unsigned short n_elementi, unsigned short array[], int elemento)
{
    unsigned short elementi_diversi = 0; // Contatore degli elementi diversi 
    unsigned short i = 0; // Indice dell'array[]
    
    for(i = 0; i < n_elementi; i++)
    {
        if(array[i] != elemento)
        {
            elementi_diversi++;
        }
    }

    return elementi_diversi;
}

unsigned short sommaElementiArray(const unsigned short n_elementi, unsigned short array[])
{
    unsigned short somma_elementi = 0;
    unsigned short i = 0; // Indice dell'array[]    

    for(i = 0; i < n_elementi; i++)
    {
        somma_elementi += array[i];
    }

    return somma_elementi;
}

int generaValoreCasuale(int min, int max)
{
    return rand() % (max - min + 1) + min; 
}

bool controlloStringa(char stringa[])
{
    bool stringa_corretta = true; // Variabile utilizzata per indicare la correttezza della stringa

    if(!strcmp(stringa, STRINGA_VUOTA) || !strcmp(stringa, SPAZIO) || !strcmp(stringa, RITORNO_CAPO))
    {
        printf("\nLa stringa inserita e' vuota\n\n");
        stringa_corretta = false;
    }

    return stringa_corretta;
}
Data_t generaDataDiNascita(void)
{
    Data_t data = {MIN_ANNO_NASCITA, gennaio, MIN_GIORNO};

    data.anno = generaValoreCasuale(MIN_ANNO_NASCITA, MAX_ANNO_NASCITA);
    data.mese = generaValoreCasuale(gennaio, dicembre);

    if(data.mese == gennaio || data.mese == marzo || data.mese == maggio || data.mese == luglio || data.mese == agosto || data.mese == ottobre || data.mese == dicembre)
    {
        // Il mese è composto da 31 giorni
        data.giorno = generaValoreCasuale(MIN_GIORNO, MAX_GIORNO_31);
    }
    else if(data.mese == febbraio)
    {
        if((!(data.anno % ANNO_SECOLARE) && !(data.anno % ANNO_BISESTILE_SECOLARE)) || ((data.anno % ANNO_SECOLARE) && !(data.anno % ANNO_BISESTILE)))
        {
            // L'anno è bisestile
            data.giorno = generaValoreCasuale(MIN_GIORNO, MAX_GIORNO_29);
        }
        else
        {
            // L'anno NON è bisestile
            data.giorno = generaValoreCasuale(MIN_GIORNO, MAX_GIORNO_29 - 1);
        }
    }
    else
    {
        // Il mese è composto da 30 giorni
        data.giorno = generaValoreCasuale(MIN_GIORNO, MAX_GIORNO_30);
    }

    return data;
}

void leggiEsami(const int n_studenti, Studenti_t studente[])
{
    unsigned short i = 0; // Indice degli esami
    unsigned short j = 0; //Indice dell'array studente[]

    char nome_esame[MAXSTRINGA] = STRINGA_VUOTA;
    
    printf("\n----------------------------------------------------\n");
    for(i = 0; i < N_ESAMI; i++)
    {
        do
        {
            printf("Inserisci il nome del %d^ esame: ", i + 1);
            scanf("%[^\n]s", nome_esame);

            pulisci_buffer();
        }
        while(!controlloStringa(nome_esame));

        for(j = 0; j < n_studenti; j++)
        {
            strcpy(studente[j].esame[i].nome_esame, nome_esame);
            studente[j].esame[i].voto = generaValoreCasuale(MIN_VOTO, MAX_VOTO);
        }

        strcpy(nome_esame, STRINGA_VUOTA); /* Resetto il valore del nome dell'esame in modo da non copiare 
                                              lo stesso valore premendo invio */
    }
}

void leggiStudenti(const int n_studenti, Studenti_t studente[])
{
    unsigned short i = 0; // Indice dell'array studente[]

    for(i = 0; i < n_studenti; i++)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n%d^ Studente:\n\n", i + 1);
        do
        {
            printf("Inserisci il nome dello studente: ");
            scanf("%[^\n]s", studente[i].nome);

            pulisci_buffer();
        }
        while(!controlloStringa(studente[i].nome));

        do
        {
            printf("Inserisci il cognome dello studente: ");
            scanf("%[^\n]s", studente[i].cognome);

            pulisci_buffer();
        }
        while(!controlloStringa(studente[i].cognome));

        do
        {
            printf("Inserisci la matricola del studente: ");
            scanf("%d", &studente[i].matricola);
            if(studente[i].matricola < MIN_MATRICOLA)
            {
                printf("\nValore non valido!\n\n");
            }

            pulisci_buffer();
        }
        while(studente[i].matricola < MIN_MATRICOLA);

        studente[i].data_nascita = generaDataDiNascita();
    }
}

void assegnazioneFrequenze(const int n_studenti, Studenti_t studente[], unsigned short frequenza_voti[])
{
    unsigned short i = 0; // Indice dell'array studente[]
    unsigned short j = 0; // Indice dell'array esame[] contenuto in studente[]

    for(i = 0; i < n_studenti; i++)
    {
        for(j = 0; j < N_ESAMI; j++)
        {
            frequenza_voti[ studente[i].esame[j].voto ]++;
        }
    }
}

unsigned short calcoloModa(const unsigned short n_elementi, unsigned short frequenza_voti[])
{
    return ricercaIndiceValoreMassimo(n_elementi, frequenza_voti);
}

float calcoloMediana(const unsigned short n_elementi, unsigned short frequenza_voti[])
{
    unsigned short somma_frequenze = 0;
    unsigned short n_elementi_effettivi = 0; //Utilizzato per comprendere se l'array è pari o dispari
    unsigned short i = 0; // Utilizzato come indice dell'array frequenza_voti[]
    float indice_medio = 0;
    float mediana_superiore = 0; // La mediana superiore verrà utilizzata solo se il numero degli elementi è pari
    float mediana_inferiore = 0; 
    bool flag = true; // Utilizzato per uscire dal ciclo una volta trovata la mediana
    
    indice_medio = (float) (sommaElementiArray(n_elementi, frequenza_voti) / 2);
    n_elementi_effettivi = nElementiDiversi(n_elementi, frequenza_voti, 0);
    
    somma_frequenze = 0;
    i=0;

    while((i < n_elementi) && flag)
    {
        somma_frequenze += frequenza_voti[i];

        if(frequenza_voti[i - 1] != 0 && i > 0) 
        {
            mediana_inferiore = i - 1;
        }
        else if(frequenza_voti[i] > 1)
        {
            mediana_inferiore = i;
        }

        if(somma_frequenze > indice_medio)
        {
            mediana_superiore = i;
            flag = false;
        }
        i++;
    }

    return n_elementi_effettivi % 2 == 0 ? (float)(mediana_superiore + mediana_inferiore)/2 : (float)mediana_superiore;
}

float mediaEsami(unsigned short n_esami, Esame_t esame[])
{
    unsigned short i = 0; //Indice dell'array esame[]
    float media = 0;

    for(i = 0; i < n_esami; i++)
    {
        media += esame[i].voto;
    }

    return media /= n_esami;
}

unsigned short votoMassimoEsame(unsigned short n_esami, Esame_t esame[])
{
    int i = 0; //Indice dell'array esame[]
    unsigned short voto_massimo = MIN_VOTO;

    for(i = 0; i < n_esami; i++)
    {
        if(voto_massimo < esame[i].voto)
        {
            voto_massimo = esame[i].voto;
        }
    }

    return voto_massimo;
}

unsigned short votoMinimoEsame(unsigned short n_esami, Esame_t esame[])
{
    int i = 0; //Indice dell'array esame[]
    unsigned short voto_minimo = MAX_VOTO;

    for(i = 0; i < n_esami; i++)
    {
        if(voto_minimo > esame[i].voto)
        {
            voto_minimo = esame[i].voto;
        }
    }

    return voto_minimo;    
}

void scriviDatiStudenti(unsigned short n_studenti, Studenti_t studente[], unsigned short n_elementi_frequenza, unsigned short frequenza[])
{
    unsigned short i = 0; // Indice dell'array studente[]

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nInformazioni sugli studenti: ");
    printf("\n\v +------------+------------------+-------------------+-----------------+-------------+-------------+------------------+--------------------+");
    printf("\n | N°Studente |       Nome       |      Cognome      | Data Di Nascita |  Matricola  | Media Esami | Minor Voto Esame | Massimo Voto Esame |");
    printf("\n +------------+------------------+-------------------+-----------------+-------------+-------------+------------------+--------------------+");
    
    for(i = 0; i < n_studenti; i++)
    {
        printf("\n | %10d | %16s | %17s |    %2hu/%2hu/%4hu   | %11d | %11.2f | %16d | %18d |"
        , i + 1, studente[i].nome, studente[i].cognome, studente[i].data_nascita.giorno, studente[i].data_nascita.mese
        , studente[i].data_nascita.anno, studente[i].matricola, mediaEsami(N_ESAMI, studente[i].esame)
        , votoMinimoEsame(N_ESAMI, studente[i].esame), votoMassimoEsame(N_ESAMI, studente[i].esame));
        printf("\n +------------+------------------+-------------------+-----------------+-------------+-------------+------------------+--------------------+");
    }

    printf("\n\n\nAnalisi studenti:");
    printf("\n\v +--------------------+-------------+");
    printf("\n |     Moda classe    | %11d |", calcoloModa(n_elementi_frequenza, frequenza));
    printf("\n +--------------------+-------------+");
    printf("\n |   Mediana Classe   | %11.2f |", calcoloMediana(n_elementi_frequenza, frequenza));
    printf("\n +--------------------+-------------+\n");
}