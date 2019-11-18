Si assuma di avere una classe C++ per l’implementazione della lista:

template< class T >
class MyList 
{
    public:
        typedef Nodo* position;
        // costruttori e distruttori
        MyList();
        …
        // operatori
        bool vuota() const;
        T leggi(position) const;
        void write(const T &, position);
        position begin() const;
        position successivo(position) const;
        position precedente(position) const;
        void inserisci(const T &, position);
        void rimuovi(position);
        bool ultimo(position);
    private:
        …
}

Scrivere la funzione processa_liste che prenda in input tre liste di interi L1, L2 ed L3, scorra tutti gli elementi
della lista L1 e:
* sposti da L1 ad L2 tutti gli elementi pari maggiori di 10
* sposti da L1 ad L3 tutti gli elementi dispari maggiori di 10
* se L1 rimane vuota, stampi il messaggio “L1 vuota”

Scrivere dunque il main che:
* inizializzi la lista L1 con i valori <5, 15, 2, 14, 13, 7>
* crei L2 ed L3 vuote
* invochi la funzione processa_liste passando L1, L2 ed L3 