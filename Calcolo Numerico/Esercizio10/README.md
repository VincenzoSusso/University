# Esercizio 10

Si scriva una funzione Matlab che implementi il seguente metodo, detto *metodo delle potenze*, per il calcolo dell’autovalore di massimo modulo di una matrice quadrata.  Dati una matrice A∈R^(n×n) ed un vettore x<sub>0</sub>∈ R^n, per ogni *k ≥ 0* si calcola:

<center>
y<sub>k</sub> = x<sub>0</sub> / norm(x<sub>0</sub>, 2);
x<sub>k</sub> = A * y<sub>k</sub>;
v<sub>k</sub> = (y<sub>k</sub>') * x<sub>k</sub>;
</center>

Al termine della procedura, l’autovalore di massimo modulo sarà λmax=ν<sub>end</sub>, dove ν<sub>end</sub> è l’ultimo valore di ν<sub>k</sub> calcolato.  La funzione deve ammettere come dati di input una matrice quadrata *A*, un vettore iniziale *x<sub>0</sub>* di dimensioni compatibili con *A*, *tolleranza* e *numero massimo di iterate*; come dati di output l’autovalore di massimo modulo λ<sub>max</sub> ed il numero di iterate effettuate.  Per ciò che riguarda il controllo dell’errore, si faccia uso del seguente criterio:

<center>
|v<sub>k+1</sub> - v<sub>k</sub>| < tolleranza * |v<sub>k+1</sub>|
</center>

Si noti che sarà necessario effettuare almeno due iterate per poter implementare tale controllo.  Per calcolarele norme vettoriali, si può utilizzare la funzione *norm()*.

Si testi la funzione approssimando, con tolleranza 10−6, l’autovalore di massimo modulo di:

<center>
A = [3, 2, 1; 2, 2, 1; 1, 1, 1]
</center>

Si scelga x<sub>0</sub> = [1; 1; 1].

[La soluzione esatta `e 5.04....].