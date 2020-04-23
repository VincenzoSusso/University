# Esercizio 5:

1. Progettare la gestione di un negozio online considerando che:

    - Ogni utente ha un id, username, uno storico degli ordini effettuati;
    
    - Ci sono due tipologie di utenti: utente normale che paga il costo di spedizione normale e un utente «prime» che paga un costo di spedizione fisso di 1€ ad ordine;

    - Ogni articolo è caratterizzato da un id, una descrizione, un costo unitario, un peso in grammi;

    - Ogni ordine è caratterizzato dall’utente che ha effettuato l’ordine e dalla lista di articoli inseriti nell’ordine e dal costo totale (diviso in costo merce e costo spedizioni);

    - Il magazzino raccoglie tutti gli articoli disponibili e per ogni articolo la quantità presente nel magazzino;

    - Le spese di spedizione di un ordine dipendono dal peso e sono di 2€ per ogni chilogrammo, se il peso è minore di un chilogrammo il costo è 2€ (gli utenti «prime» pagano 1€ per ogni ordine).

2. Realizzare le seguenti funzioni:
    
    - Simulare il carello di un potenziale acquisto, se il magazzino ha a disposizione gli oggetti presenti nel carrello:

        - Calcolare il costo complessivo del carrello;

        - Calcolare le spese di spedizione;

        - Assegnare all’utente l’ordine inserendolo nello storico degli ordini dell’utente.

    - Ricerca di un articolo nel magazzino;

    - Visualizzazione di tutte gli ordini di un utente;

    - Ricerca degli articoli nel magazzino la cui disponibilità è inferiore ad una certa quantità;

    - Lista dei primi 5 articoli più venduti;