# Esercizio 8

Si scriva una funzione *Matlab* che implementi il seguente metodo numerico (detto dei trapezi) per il calcolo approssimato degli integrali definiti.  Dati una funzione a valori reali *f* definita nell’intervallo *[a,b]* ,*n≥1* intero naturale, siano *h= (b−a)/n* e *xj=a+jh*, per ogni *j= 0,...,n*.  Allora si ha:

<center>
Integrale tra *a* e *b* di *f(x)* ~ I<sub>n</sub>
</center>

Dove

<center>
    I<sub>n</sub> = h/2 * [f(x<sub>0</sub>) + 2 * sommatoria di *j = 1* a *n-1* f(x<sub>j</sub>) + f(x<sub>n</sub>)]
</center>

La funzione deve ammettere come dati di input funzione *f*,  intervallo *[a,b]* e numero di sottointervalli *n*; come dati di output l’approssimazione I<sub>n</sub>.

Utilizzando la funzione appena creata, implementare la seguente procedura automatica per approssimare il valore di *integrale da 0 a 1 di sin(π x)dx* a meno di un errore assoluto inferiore a 10−3: raddoppiare progressivamente il valoredi *n*, a partire da *n=4*, fino a quando la differenza tra approssimazioni successive I<sub>n</sub> e I<sub>n+1</sub> sarà scesa sotto la tolleranza indicata. Il valore esatto dell’integrale `e 2/π.