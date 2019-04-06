LABORATORIO DI INFORMATICA 2018/2019 - TRACK B
Docente: Veronica Rossano

ESERCITAZIONE 2  
3.04.2018
Consegna: Sabato 5 Aprile, ore 23.59

TRACCIA
---------------
Creare una struct account, che preveda nome, cognome, data di nascita, email, password e creare un vettore di 20 account utente. 

Il sistema deve anche essere in grado di associare a ciascuna password il proprio livello di sicurezza. Una password è detta sicura se contiene più di 5 caratteri speciali e numeri (in totale). Una password è mediamente sicura se il numero è compreso tra 3 e 5, mentre è poco sicura se il totale è inferiore a 3.

Implementare un programma che:
(1) Generi random nome, cognome, data di nascita ed e-mail (per ciascun account) e mostrare in output il risultato
(2) Mostri in output il nome e cognome dell'utente più giovane e dell'utente più vecchio
(3) Per ogni account, chieda all'utente se vuole generare la password in automatico o se vuole inserirla a mano
	Nel primo caso il sistema deve chiedere all'utente il livello di complessità richiesto (poco-mediamente-molto sicura), e mostrare in output la password generata
	Nel secondo caso il sistema deve controllare che la password inserita risponda ai vincoli minimi: esattamente 8 caratteri di lunghezza, almeno 1 maiuscola ed almeno un numero (chiaramente deve ciclare finchè la password inserita non è corretta)

(4) Il sistema deve infine mostrare tutti i dati degli utenti che hanno una password non sicura e nome e cognome degli utenti che hanno una password molto sicura


INPUT
---------------
- Nome, Cognome, Data di Nascita, email e password per 20 utenti

OUTPUT
---------------
- Nome e Cognome dell'utente più vecchio
- Nome e Cognome degli utenti che hanno una password non sicura
- Nome e Cognome degli utenti che hanno una password molto sicura

NOTE
---------------
Implementare gli opportuni controlli per generare dei valori di input realistici. 
(es. l'email deve contenere la chiocciola, la data di nascita deve essere realistica, etc.)

SUGGERIMENTI
---------------
- Quasi tutti i controlli sono già disponibili come funzioni delle librerie <ctype.h> e <string.h>
- Per la generazione di un numero random in un range tra MIN e MAX utilizzare il consueto frammento di codice
- Per la generazione random dei nomi e cognomi si può utilizzare la funzione strcpy che copia dei nomi e cognomi "standard" in una stringa.

ESTENSIONI
---------------
- Aggiungere alla struct account anche un membro l'Indirizzo, e assicurarsi che sia realistico (che inizi con Via , Piazza, Corso, etc.)
- Nel mostrare in output la password, offuscare tutte le lettere esclusa la prima e l'ultima (es. password ? p******d).
- Generare in automatico degli indirizzi email realistici concatenando porzioni di dati anagrafici (es. nomeCognomeAnno ? cataldomusto82@gmail.com) e domini reali.

INDICARE NEL CODICE SORGENTE EVENTUALI ESTENSIONI IMPLEMENTATE



