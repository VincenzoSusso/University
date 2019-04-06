// -- Librerie --
#include "GestioneUtente.h"

// -- Procedure & Funzioni --
void generaStringaCasuale(const char stringhe_casuali[][LUNGHEZZA_STRINGHE], char stringa[])
{
    unsigned short indice_stringa = (unsigned short) generaValoreCasuale(0, N_STRINGHE - 1);
    unsigned short i = 0; // Indice dell'array

    strcpy(stringa, STRINGAVUOTA); // Pulisco la stringa
    strcat(stringa, "\0");

    i = -1;
    // Utilizzo il ciclo do-while in modo da copiare il carattere terminale nell'array stringa[]
    do
    {
        i++;
        stringa[i] = stringhe_casuali[indice_stringa][i];
    } 
    while (stringhe_casuali[indice_stringa][i] != CARATTERE_TERMINALE);
}

void generaEmail(const char domini_email[][LUNGHEZZA_STRINGHE], Account_t *account)
{
    char dominio[LUNGHEZZA_STRINGHE] = STRINGAVUOTA;
    
    generaStringaCasuale(domini_email, dominio);

    /* Per convertire un decimale in stringa non utilizzo la funzione itoa() in quanto non fa parte dell'ANSI C
       (quindi può non essere disponibile per alcuni compilatori). 
       Per saperne di più consultare i seguenti link: http://www.cplusplus.com/reference/cstdlib/itoa/
                                                      http://www.strudel.org.uk/itoa/
    */
    sprintf(account -> email, "%s%s%d%s", account -> nome, account -> cognome, account -> data_nascita.anno, dominio);
    strcat(account -> email, "\0");
}

void generaPassword(char password[])
{
    unsigned short i = 0; // Indice dell'array

    for(i = 0; i < LUNGHEZZA_PASSWORD - 1; i++)
    {
        password[i] = generaValoreCasuale(MIN_CARATTERE_PASSWORD, MAX_CARATTERE_PASSWORD);
    }

    strcat(password, "\0"); // Aggiungo il carattere terminale della stringa
}

Livello_password_t assegnaLivelloPassword(char password[])
{
    Livello_password_t livello_password = poco_sicura;

    unsigned short i = 0; // Indice della array password[]
    unsigned short numeri = 0; // Contatore dei numeri presenti nella password
    unsigned short caratteri_speciali = 0; // Contatore dei caratteri speciali presenti nella password

    for(i = 0; i < strlen(password); i++)
    {
        /* Non è possibile utilizzare la seguente forma per effettuare un controllo sulla password:
            
            numeri += isdigit(password[i]); 
            caratteri_speciali += ispunct(password[i]); 

            in quanto le funzioni isdigit() e ispunct() restituisce un valore != 0 se il risultato è vero,
            quindi nessuno ci assicura che ci rilasci 1. (ispunct() restituisce 4)
        */

        if(ispunct(password[i]))
        {
            caratteri_speciali++;
        }

        if(isdigit(password[i]))
        {
            numeri++;
        } 

        if((numeri + caratteri_speciali) > PASSWORD_MOLTO_SICURA) 
        {
            // Se la password è sicura forzo l'uscita dal ciclo
            i = strlen(password);
        }

    }

    if ((numeri + caratteri_speciali) > PASSWORD_MOLTO_SICURA)
    {
        // La password è molto sicura
        livello_password = molto_sicura;
    }
    else if ((numeri + caratteri_speciali) >= PASSWORD_SICURA && (numeri + caratteri_speciali) <= PASSWORD_MOLTO_SICURA)
    {
        // La password è sicura
        livello_password = sicura;
    }
    else
    {
        // La password è poco sicura
        livello_password = poco_sicura;
    }

    return livello_password;
}

bool isPasswordCorretta(char password[])
{
    bool password_corretta = false;

    unsigned short i = 0; // Indice della array password[]
    unsigned short numeri = 0; // Contatore dei numeri presenti nella password
    unsigned short maiuscole = 0; // Contatore dei caratteri speciali presenti nella password

    if(strlen(password) == LUNGHEZZA_PASSWORD - 1)
    {
        for(i = 0; i < strlen(password); i++)
        {
            numeri += isdigit(password[i]);
            maiuscole += isupper(password[i]);

            if((maiuscole >= MIN_MAIUSCOLE) && (numeri >= MIN_NUMERI))
            {
                // Se la password è sicura forzo l'uscita dal ciclo
                password_corretta = true;
                i = strlen(password);
            }
        }
    }

    return password_corretta;
}

void gestionePassword(Account_t *account, unsigned short indice)
{
    Scelta_t scelta_password = scelta_non_definita; /* Variabile utilizzata per indicare se l'utente vuole inserire manualmente 
                                                       o preferisce generarla casualmente */
    Livello_password_t livello_password = non_definita; /* Variabile utilizzata per indicare il livello di sicurezza che l'utente 
                                                           desidera per la password */

    do
    {
        printf("Per il %d^ utente vuoi inserire una password (0) o vuoi che sia generata casualmente (1): ", indice + 1);
        scanf("%d", &scelta_password);

        pulisciBuffer();

        if (scelta_password != password_manuale && scelta_password != password_casuale)
        {
            printf("\nIl valore inserito non è corretto!\n\n");
        }
    } 
    while (scelta_password != password_manuale && scelta_password != password_casuale);

    if (scelta_password == password_manuale)
    {
        do
        {
            printf("Inserire una password (8 caratteri, almeno una maiuscola e un numero): ");
            scanf("%8s", account -> password);
            strcat(account -> password, "\0"); // Aggiungo il carattere terminale della stringa

            pulisciBuffer();

            if (!isPasswordCorretta(account -> password))
            {
                if(strlen(account -> password) != LUNGHEZZA_PASSWORD - 1)
                {
                    printf("\nLa dimensione della password inserita è errata!\n\n");
                }
                else
                {
                    printf("\nLa password inserita non contiene una maiuscola e/o un numero!\n\n");   
                }
            }
        } 
        while (!isPasswordCorretta(account -> password));
        account -> livello_password = assegnaLivelloPassword(account -> password);
    }
    else
    {
        do
        {
            printf("Vuoi generare una password poco sicura (0), sicura (1) o molto sicura (2): ");
            scanf("%1d", &livello_password);

            if ((livello_password != poco_sicura) && (livello_password != sicura) && (livello_password != molto_sicura))
            {
                printf("\nIl valore inserito non è corretto!\n\n");
            }
        } 
        while ((livello_password != poco_sicura) && (livello_password != sicura) && (livello_password != molto_sicura));

        switch (livello_password)
        {
            case poco_sicura:
                do
                {
                    generaPassword(account -> password);
                    account -> livello_password = assegnaLivelloPassword(account -> password);
                } 
                while (account -> livello_password != poco_sicura);
            break;

            case sicura:
                do
                {
                    generaPassword(account -> password);
                    account -> livello_password = assegnaLivelloPassword(account -> password);
                } 
                while (account -> livello_password != sicura);
            break;

            default: // In caso di default genera una password molto sicura
                do
                {
                    generaPassword(account -> password);
                    account -> livello_password = assegnaLivelloPassword(account -> password);
                } 
                while (account -> livello_password != molto_sicura);
            break;
        }
    }
}

char *visualizzaLivelloPassword(Livello_password_t livello_password)
{
    static char livello_password_stringa[LUNGHEZZA_STRINGHE] = STRINGAVUOTA;

    switch(livello_password)
    {
        case poco_sicura:
            strcpy(livello_password_stringa, "Poco Sicura");
        break;

        case sicura:
            strcpy(livello_password_stringa, "Sicura");
        break;

        case molto_sicura:
            strcpy(livello_password_stringa, "Molto Sicura");
        break;

        default:
            strcpy(livello_password_stringa, "Non Definita");
        break;
    }

    return livello_password_stringa;
}

char *oscuraPassword(char password[])
{
    static char password_oscurata[LUNGHEZZA_PASSWORD] = "";

    unsigned short i = 0; // Indice dell'array password_oscurata

    strcpy(password_oscurata, password);

    for(i = 1; i < strlen(password) - 1; i++)
    {
        password_oscurata[i] = CARATTERE_OSCURATO;
    }

    return password_oscurata;
}

void generaAccount(Account_t account[], const char stringhe_nomi[][LUNGHEZZA_STRINGHE], const char stringhe_cognomi[][LUNGHEZZA_STRINGHE], const char domini_email[][LUNGHEZZA_STRINGHE])
{
    unsigned short i = 0; // Indice della array account[]
    Scelta_t scelta_password = scelta_non_definita; /* Variabile utilizzata per indicare se l'utente vuole inserire manualmente 
                                                       o preferisce generarla casualmente */
    Livello_password_t livello_password = non_definita;

    for(i = 0; i < N_UTENTI; i++)
    {
        generaStringaCasuale(stringhe_nomi, account[i].nome);
        generaStringaCasuale(stringhe_cognomi, account[i].cognome);
        
        do
        {
            account[i].data_nascita = generaDataCasuale();
        } 
        while (!isDataCorretta(account[i].data_nascita));
        
        generaEmail(domini_email, &account[i]);

        printf("\n----------------------------------------------------\n");
        gestionePassword(&account[i], i);
    }
}

void visualizzaAccount(Account_t account[])
{
    unsigned short i = 0; // Indice dell'array account[]

    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nTabella Account: ");
    printf("\n\v +----+--------------+-------------+-----------------+-----------------------------------------+----------+-------------------+------------------+");
    printf("\n | N° |     Nome     |   Cognome   | Data Di Nascita |                   Email                 | Password | Password Oscurata | Livello Password |");
    printf("\n +----+--------------+-------------+-----------------+-----------------------------------------+----------+-------------------+------------------+");
    
    for(i = 0; i < N_UTENTI; i++)
    {
        printf("\n | %2d | %12s | %11s |   %2hu/%2hu/%4hu    | %39s | %8s |      %8s     |   %12s   |"
        , i + 1, account[i].nome, account[i].cognome, account[i].data_nascita.giorno, account[i].data_nascita.mese
        , account[i].data_nascita.anno, account[i].email, account[i].password, oscuraPassword(account[i].password)
        , visualizzaLivelloPassword(account[i].livello_password));
        printf("\n +----+--------------+-------------+-----------------+-----------------------------------------+----------+-------------------+------------------+");
    }
}

void visualizzaAccountPassword(Account_t account[], Livello_password_t livello_password)
{
    unsigned short i = 0; // Indice dell'array account[]

    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nAccount con sicurezza livello: %s", visualizzaLivelloPassword(livello_password));
    printf("\n\v +----+--------------+-------------+");
    printf("\n | N° |     Nome     |   Cognome   |");
    printf("\n +----+--------------+-------------+");
    
    for(i = 0; i < N_UTENTI; i++)
    {
        if(account[i].livello_password == livello_password)
        {
            // Visualizza solamente gli account con il livello della password specificato
            printf("\n | %2d | %12s | %11s |"
            , i + 1, account[i].nome, account[i].cognome);
            printf("\n +----+--------------+-------------+");
        }
    }
}

void visualizzaUtentePiuVecchio(Account_t account[])
{
    Account_t utente_piu_vecchio = utentePiuVecchio(account);

    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nInformazioni utente più vecchio: ");
    printf("\n\v +--------------+-------------+");
    printf("\n |     Nome     |   Cognome   |");
    printf("\n +--------------+-------------+");
    printf("\n | %12s | %11s |", utente_piu_vecchio.nome, utente_piu_vecchio.cognome);
    printf("\n +--------------+-------------+");
}

Account_t utentePiuVecchio(Account_t account[])
{
    Account_t utente_piu_vecchio = account[0];

    unsigned short i = 0; // Indice dell'array account[]

    for(i = 1; i < N_UTENTI; i++)
    {
        /* 
            Inizialmente confronto le due date e vedo qual è la meno recente, successivamente controllo se la data
            dell'utente più vecchio coincide con quella dell'account selezionato dall'indice, in caso positivo 
            copio gli altri campi dell'account nella struct dell'utente più vecchio 
        */

        utente_piu_vecchio.data_nascita = dataMenoRecente(utente_piu_vecchio.data_nascita, account[i].data_nascita);

        if(areDateUguali(utente_piu_vecchio.data_nascita, account[i].data_nascita))
        {
            utente_piu_vecchio = account[i];
        }
    }

    return utente_piu_vecchio;
}