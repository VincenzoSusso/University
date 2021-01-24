# Esercizio 5

Si scriva una funzione *Matlab* che implementi il seguente metodo numerico per il calcolo degli zeri di una funzione, detto di *Steffensen*:

<center>
x<sub>k+1</sub> = x<sub>k</sub> - ( ( (f(x<sub>k</sub>))^2 ) / ( f(x<sub>k</sub> + f(x<sub>k</sub>)) - f(x<sub>k</sub>) ) );
</center>

La function deve ammettere come dati di input *f*, *x0*, *tolleranza* e *numero massimo di iterate*; come dati di output *l’approssimazione dello zero*, il *numero di iterate effettuate* ed il *residuo*.  Si faccia uso di un criterio di arresto basato sul controllo dell’errore relativo.

Si usi la function creata per calcolare le prime 12 cifre significative dell’unico zero strettamente positivo di *f(x) = sin(x)−(x^3)*.  
[La soluzione è 0.92...]
