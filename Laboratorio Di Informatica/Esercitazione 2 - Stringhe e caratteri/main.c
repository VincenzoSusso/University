/* LABORATORIO DI INFORMATICA - Track B (INF)
   Docente: Veronica Rossano
   Esercitazione 2 - 03/04/2019 (consegna entro 06/04/2019)
   -----------------------------
   Nome: Vincenzo
   Cognome: Susso
   Matricola: 697538
   ------------------------------ 
   Estensioni aggiunte : - Offuscamento Password
                         - Generazione email automatiche
*/

// -- Librerie --
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GestioneUtente.h"

// -- Main --
int main(void)
{
    // Costanti utilizzate per generare le stringhe casuali
    const char nomi[N_STRINGHE][LUNGHEZZA_STRINGHE] = {"Giovanni\0", "Leonardo\0", "Alessio\0", 
                                                       "Lorenzo\0", "Mattia\0", "Andrea\0", "Gabriele\0", 
                                                       "Riccardo\0", "Matteo\0", "Tommaso\0", "Sofia\0",
                                                       "Giulia\0", "Aurora\0", "Alice\0", "Ginevra\0", 
                                                       "Emma\0", "Giorgia\0", "Greta\0", "Martina\0", "Beatrice\0"};
    
    const char cognomi[N_STRINGHE][LUNGHEZZA_STRINGHE] = {"Rossi\0", "Ferrari\0", "Russo\0", "Bianchi\0", 
                                                        "Romano\0", "Gallo\0", "Costa\0", "Fontana\0", 
                                                        "Conti\0", "Esposito\0", "Ricci\0", "Bruno\0", 
                                                        "Rizzo\0", "Moretti\0", "Marino\0", "Greco\0", 
                                                        "Barbieri\0", "Lombardi\0", "Giordano\0", "Rinaldi\0"};

    const char domini_email [N_STRINGHE][LUNGHEZZA_STRINGHE] = {"@gmail.com\0", "@outlook.com\0", "@yahoo.com\0", 
                                                                "@virgilio.it\0", "@libero.it\0", "@hotmail.it\0", 
                                                                "@hotmail.com\0", "@live.it\0", "@email.it\0", 
                                                                "@icloud.com\0", "@gmx.com\0", "@hushmail.com\0",
                                                                "@alice.com\0", "@zoho.com\0", "@lycos.com\0",
                                                                "@yandex.com\0", "@aol.com\0", "@tiscali.it\0",
                                                                "@teletu.it\0", "@tim.it\0"};

    Account_t account[N_UTENTI] = {STRINGAVUOTA, STRINGAVUOTA, {MIN_ANNO, gennaio, MIN_GIORNO}, STRINGAVUOTA, STRINGAVUOTA, non_definita};

    srand(time(NULL)); // Randomizzo i valori

    generaAccount(account, nomi, cognomi, domini_email);

    visualizzaAccount(account);

    visualizzaAccountPassword(account, poco_sicura);
    visualizzaAccountPassword(account, molto_sicura);

    visualizzaUtentePiuVecchio(account);
    
    printf("\n\n");

    exit(EXIT_SUCCESS);
}