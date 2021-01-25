# Esercizio 9

Si scriva una funzione *Matlab* che implementi il seguente metodo numerico (detto dei trapezi) per il calcolo approssimato degli integrali definiti.  Dati una funzione a valori reali *f* definita nell’intervallo *[a,b]* ,*n≥1* intero naturale, siano *h= (b−a)/n* e *xj=a+jh*, per ogni *j= 0,...,n*.  Allora si ha:

<center>
Integrale tra *a* e *b* di *f(x)* ~ I<sub>n</sub>
</center>

Dove

<center>
    I<sub>n</sub> = h/3 * (f(x<sub>0</sub> + 2 * f(x_j) se j è pari o + 4 * f(x_j) altrimenti per j=1,2, ..., n))
</center>

La funzione deve ammettere come dati di input funzione *f*,  intervallo *[a,b]* e numero di sottointervalli *n*; come dati di output l’approssimazione I<sub>n</sub>.

Utilizzando la funzione appena creata, implementare la seguente procedura automatica per approssimare il valore di *integrale da 0 a pi/4 di tan(x) dx* a meno di un errore assoluto inferiore a 10−4: raddoppiare progressivamente il valoredi *n*, a partire da *n=4*, fino a quando la differenza tra approssimazioni successive I<sub>n</sub> e I<sub>n+1</sub> sarà scesa sotto la tolleranza indicata. Il valore esatto dell’integrale `e log(2)/2.