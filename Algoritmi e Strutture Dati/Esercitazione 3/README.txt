Esercitazione 3:

Realizzare in C++ la struttura dati matrice (che rappresenti l'ente geometrico matrice e le operazioni che la 
matematica prevede). In particolare:
 * definire il tipo tipoelem typedef double tipoelem;
 * definire la classe matrice
       class matrice {
           public:
               matrice(int, int); /* costruttore */
               tipoelem leggimatrice(int, int);
               void scrivimatrice(int, int, tipoelem);
           private:
               int righe;
               int colonne;
               tipoelem **elementi;
       };
       // costruttore
       matrice::matrice(int c, int r){
           colonne = c;
           righe = r;
           // allocazione dinamica della matrice
           int i;
           elementi = new tipoelem* [righe];
           for (i=0; i < righe; i++)
               elementi[i] = new tipoelem[colonne];
           // inizializzazione degli elementi
           ...
       }

ESERCIZI:
 * completare la definizione della classe fornendo le implementazioni per il costruttore, e per i metodi
   leggimatrice (restituisce l'elemento in posizone i,j) e scrivimatrice (scrive l'elemento in posizione i,j)
 * realizzare il metodo prodottoScalare(double scalare) che moltiplica ogni elemento della matrice con
   uno scalare
 * realizzare il metodo trasposta(), che restituisce la trasposta di una matrice
 * realizzare il metodo prodotto(matrice M), che restituisce il prodotto di due matrici

ATTENZIONE:
 * Definire nel file header matrice.h la definizione della classe
 * Implementare nel file matrice.cpp i metodi della classe matrice
 * Testare la classe matrice nel file TestMatrice.cpp