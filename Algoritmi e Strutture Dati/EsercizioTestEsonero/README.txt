Laboratorio (opzionale):
Si assuma di avere una classe C++ per l’implementazione della lista:
    template< class T >
    class MyList {
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
        private:
            …
    }

Scrivere una funzione che prenda in input tre liste di interi L1, L2 ed L3, scorra tutti gli elementi
della lista L1 e:
* aggiunga tutti gli elementi dispari positivi ad L2
* aggiunga tutti gli elementi pari positivi ad L3
* se L1 contiene almeno un elemento negativo o 0, lanci una eccezione

Scrivere dunque il main() che:
* inizializzi la lista L1 con i valori <1,2,3,4,5>
* crei L2 ed L3
* invochi la funzione creata, gestendo eventuali eccezioni stampando il messaggio “Individuati elementi
  non positivi”