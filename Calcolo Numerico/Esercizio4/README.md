# Esercizio 3

Si scriva una funzione *Matlab* che implementi il seguente metodo numerico per il calcolo della radice n-esima di un numero *S > 0*:

<center>
x<sub>0</sub> =  S;

x<sub>k+1</sub> = 1/n \* ( ((n-1) \* x<sub>k</sub>) + (S / (x<sub>k</sub>^(n-1))) );
</center>

La funzione deve ammettere come dati di input: *S*, *n*, *tolleranza* e *numero massimo di iterate*; come dati di output *l’approssimazione della radice n-esima di S* ed il *numero di iterate effettuate*. Si faccia uso di un criterio di arresto basato sul controllo dell’errore relativo.

Si testi la funzione calcolando le prime 10 cifre significative di della radice di 286797 in base 5.
[Soluzione = 12.3....].
