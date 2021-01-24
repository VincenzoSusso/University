# Esercizio 6

Dato il sistema lineare *Ax=b*, *A ∈ R^(n×n)*, *b ∈ R^n*, si consideri il seguente metodo iterativo perla soluzione dei sistemi lineari (detto metodo di Gauss-Seidel):

<center>
Lx<sub>k+1</sub> = b - Ux<sub>k</sub>;
</center>

Dove *A* è una matrice quadrata, L è triangolare inferiore, *U* è triangolare superiore con diagonale nulla.

[Si  noti  che *A=L+U*].  Si  scriva  una  funzione *Matlab* che implementi tale metodo. La funzione deve ammettere come dati di input una matrice *A*, un vettore *b*, una *tolleranza*, un vettore iniziale *x0* ed il *numero massimo di iterate*; come dati di output *l’approssimazione* della soluzione, il *numero di iterate effettuate* ed il residuo *‖Ax<sub>end</sub>−b‖∞*. Si faccia uso di un criterio di arresto basato sul controllo dell’errorerelativo in norma *‖·‖∞*. Si suggerisce di risolvere i sistemi lineari facendo uso dell’operatore backslash (x=A\b`e la soluzione del sistema lineare *Ax=b*), e di calcolare la norma di un vettore (colonna) facendo uso dellafunzione *norm()*.

Si testi la funzione approssimando, con tolleranza *tol=10^−5*, la soluzione del sistema lineare *Ax=b* con:

<center>
A = [2.4, -.8, -.7; .5, 1.5, .7; -.1, .8, 2.1];
b = [.9; 2.7; 2.8];
</center>

[La soluzione esatta `e [1; 1; 1;].  Si suggerisce di scegliere *x0= [0.9; 0.9; 0.9;]*.]
