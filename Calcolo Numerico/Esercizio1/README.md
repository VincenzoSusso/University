# Esercizio 1

Si scriva una funzione *Matlab* che implementi il metodo delle secanti per il calcolo degli zeri di funzione:

<center>
x<sub>k</sub> =  x<sub>k-1</sub> - ((f(x<sub>k-1</sub>) * (x<sub>k-1</sub> - x<sub>k-2</sub>)) / (f(x<sub>k-1</sub> - x<sub>k-2</sub>)))
</center>

La funzione deve ammettere come dati di input: *f*, x<sub>0</sub> e x<sub>1</sub>, tolleranza e numero massimo di iterate; come dati di output l’approssimazione dello zero ed il numero di iterate effettuate. Si faccia uso di un criterio di arresto basato sul controllo dell’errore relativo.

Si usi la funzione creata per calcolare le prime 10 cifre significative dello zero di *f(x) =(sin(x)/x)−x*; si scelga x<sub>0</sub>=1 e x<sub>1</sub>= 0.9. [La soluzione è 0.87....]