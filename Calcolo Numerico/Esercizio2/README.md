# Esercizio 2

Si scriva una funzione Matlab che implementi il seguente metodo numerico per il calcolo deglizeri di una funzione, detto di Halley:

<center>
x<sub>k+1</sub> =  x<sub>k</sub> - ( (2 * f(x<sub>k</sub>) * f'(x<sub>k</sub>)) / ((2 * f'(x<sub>k</sub>)^2)-(f(x<sub>k</sub>) * f''(x_k))) )
</center>

La funzione deve ammettere come dati di input *f*,*f′*,*f′′*, punto iniziale *x0*, *tolleranza* e *numero massimo di iterate*; come dati di output l’approssimazione dello zero, il numero di iterate effettuate ed il residuo *f(x<sub>end</sub>)*.  Si faccia uso di un criterio di arresto basato sul controllo dell’errore relativo.

Si usi la funzione creata per calcolare le prime 12 cifre significative dell’unico zero strettamente positivo di f(x) = sin(x)−x3.  
[La soluzione `e 0.92...]