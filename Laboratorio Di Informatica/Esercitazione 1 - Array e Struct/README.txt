LABORATORIO DI INFORMATICA 2018/2019 - TRACK B
Docente: Veronica Rossano

ESERCITAZIONE 1  
11.03.2019
Consegna: Giovedì 14 Marzo, ore 23.59

TRACCIA
---------------
Una classe è composta da 10 studenti. Ciascuno studente è descritto da nome, cognome, data di nascita, matricola, ed ha un libretto dove memorizza i voti degli esami.
Ogni studente sostiene 20 esami. Ogni esame è descritto da un voto in trentesimi.

Scrivere un programma che 
1) Acquisisca in input i dati della classe (nome, cognome, data di nascita, matricola)
2) Generi in automatico i voti per i venti esami. I voti devono essere realistici.
3) Calcoli la media d'esame per ogni studente, e la stampi. 
4) Stampi in output nome e cognome dello studente che ha la media più alta
5) Calcoli la moda e la mediana dei voti dell'intera classe, e stampi il valore della moda e della mediana


INPUT
---------------
- Nome, Cognome, Data di Nascita, Matricola e voto d'esame per 10 studenti

OUTPUT
---------------
- Media d'esame di ogni studente
- Nome e Cognome dello Studente che ha la media pi˘ alta
- Media e Mediana dei voti dell'intera classe

NOTE
---------------
Per il punto (1) sono sufficienti dei controlli su giorno di nascita e anno di nascita.

Per il punto (2) generare i voti in un range corretto di valori. Il voto 30 e Lode può essere memorizzato come 31

Per il punto (3) si puÚ scegliere se aggiungere un ulteriore campo (float) alla struct oppure se calcolare la media successivamente e stamparla al momento senza memorizzarla.

La moda è il valore più frequente di un insieme di valori. La mediana è il valore centrale dellíinsieme di valori ordinato

Esempio = {1, 2, 3, 3, 5, 5, 5 } , la moda è 5 , la mediana è 3.
https://it.wikipedia.org/wiki/Moda - https://it.wikipedia.org/wiki/Mediana_(statistica) 

IMPORTANTE: NON USARE ALGORITMI DI ORDINAMENTO!


SUGGERIMENTI
---------------
Per la generazione di un numero random in un range tra MIN e MAX utilizzare il seguente frammento di codice

#include "stdlib.h" // libreria che include la funzione rand()
#include "time.h" // libreria per randomizzare il seed

int seed = time(NULL);
srand(seed);
int randomValue = rand() % (MAX-MIN+1) + MIN; 

Se vogliamo generare un numero tra 10 e 30 la funzione sarà
int randomValue = rand() % 21 + 10; 

Perché l'operatore % ci restituisce un valore tra 0 e 20, cui sommeremo 10 che Ë il valore minimo possibile.

Per il calcolo di moda e mediana creare un "vettore di frequenze" in cui memorizziamo i voti dell'intera classe.

ESTENSIONI
---------------
Aggiungere un meccanismo per generare random anche date di nascita e dati anagrafici (nome e cognome).
Aggiungere controlli sulla correttezza complessiva della data
Estendere il libretto, trasformandolo in una struct che preveda anche un nome d'esame oltre al voto
Mostrare per ogni studente l'esame in cui ha ricevuto il voto più basso e quello più alto.
INDICARE NEL CODICE SORGENTE EVENTUALI ESTENSIONI IMPLEMENTATE
