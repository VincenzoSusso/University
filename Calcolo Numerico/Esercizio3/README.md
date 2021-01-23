# Esercizio 3

Si scriva una funzione *Matlab* che implementi il seguente metodo numerico a due passi (detto *metodo di Traub*) per il calcolo degli zeri di funzione.  Dato x<sub>k</sub>, per ogni k≥0, si calcola:

<center>
y<sub>k</sub> =  x<sub>k</sub> - (f(x<sub>k</sub>) / f'(x<sub>k</sub>))

x<sub>k+1</sub> =  y<sub>k</sub> - (f(y<sub>k</sub>) / f'(x<sub>k</sub>))
</center>

La funzione deve ammettere come dati di input *f*, *f′* , *x0*, *tolleranza* e *numero massimo di iterate*; come dati di output *l’approssimazione dello zero* ed il *numero di iterate effettuate*.  Si faccia uso di un criterio di arresto basato sul controllo dell’errore relativo.  Al fine di ottimizzare il numero di valutazioni di funzione, si tenga conto del fatto che ogni passo richiede una sola valutazione di *f′*.

Si testi la funzione calcolando le prime 10 cifre significative dello zero di *f(x) = 1 − ((x^2) / 2) − x^3* nell’intervallo [0 1].
[La soluzione `e 0.85....]