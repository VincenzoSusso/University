# Esercizio 1:

Sia data la seguente interfaccia:
public interfaceFigura {
	//restituisce l'area della figura
	double area();
}

-- Scrivere la classe astratta FiguraCompche implementa sia l'interfaccia Figura che Comparable.
   intcompareTo(Object o)

La classe FiguraCompdeve contentere
-- Due variabili d'istanza dim1 e dim2, di tipo double e dichiarate protected;
-- Un costruttore con due parametri double, che inizializza le variabili d'istanza;
-- Il metodo public intcompareTo(Object o) che realizza il metodo astratto dell'interfaccia Comparable, confrontando due oggetti di tipo FiguraCompin base all'area: un oggetto precede un altro se ha area minore;
-- Il metodo equals, definito in modo consistente con compareTo(se compareTo==0 allora devono essere uguali i due oggetti)
Si noti che la classe FiguraCompdeve essere astratta, perché non fornisce un'implementazione del metodo dell'interfaccia Figura.

Scrivere quindi le classi concrete Rettangoloe Triangolo che estendono FiguraCompe la classe Quadrato che estende Rettangolo. Ricordarsi di definire opportunamente anche il metodo toString()
Per testare le classi, realizzare una classe TestFigurecon un main. In particolare, verificare che con questa organizzazione delle classi è possibile confrontare oggetti di classi diverse (Triangoloe Rettangolo) con compareTo e con equalspoiché questi metodi sono definiti in una superclasse (astratta) comune.