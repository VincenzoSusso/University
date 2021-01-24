# Esercizio 7

Dato il sistema lineare *Ax=b*, *A ∈ R^(n×n)*, *b ∈ R^n*, si consideri il seguente metodo iterativo perla soluzione dei sistemi lineari (detto metodo di Jacobi):

<center>
Dx<sub>k+1</sub> = b - Rx<sub>k</sub>;
</center>

Dove *A* è una matrice quadrata, D è una matrice composta dagli elementi della diagonale di *A*, *R* è ottenuta da *A* annullando la diagonale.

Si noti che *A=D+R*. Si scriva una funzione *Matlab* che implementi tale metodo. La funzione deve ammettere come dati di input una matrice *A*, un vettore *b*, una *tolleranza*, un vettore iniziale *x0* ed il *numero massimo di iterate*; come dati di output *l’approssimazione della soluzione*, il *numero di iterate effettuate* ed il residuo *‖Ax<sub>end</sub>−b‖∞*. Si faccia uso di un criterio di arresto basato sul controllo dell’errorerelativo in norma *‖·‖∞*.  Si suggerisce di risolvere i sistemi lineari facendo uso dell’operatore backslash(*x=A\b* è la soluzione del sistema lineare *Ax=b*), e di calcolare la norma di un vettore (colonna) facendo uso della funzione *norm()*.

Si testi la funzione approssimando, con tolleranza *tol=10^−5*, la soluzione del sistema lineare *Ax=b* con:

<center>
A = [4, 2, 1; 2, 4, 2; 1, 2, 4];
b = [7; 8; 7];
</center>

[La soluzione esatta `e [1; 1; 1;].  Si suggerisce di scegliere *x0= [1.1; 1.1; 1.1;]*.]
