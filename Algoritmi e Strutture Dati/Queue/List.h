/*
	Algoritmi e Strutture Dati - Queue
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef LIST_H
#define LIST_H

// Abstract class
template<class TypeElement, class Position>
class List
{
    public:
	    typedef TypeElement value_type;
	    typedef Position position;
	
	    // -- Virtual Methods --
	    virtual bool empty(void) = 0; // True if the list's size is 0
	    virtual value_type read(position position) = 0; //  Read at position
	    virtual void write(position position, const value_type & element) = 0; // Write element at position
	    virtual position begin(void) = 0; // Returns a position pointing to the beginning of the list
	    virtual bool end(position position) = 0; // Verify whether a position points to the end of the list
	    virtual position next(position position) = 0; // Returns the next position
	    virtual position previous(position position) = 0; // Returns the previous position
	    virtual void insert(position position, const value_type & element) = 0; // Insert an element 
	    virtual void erase(position position) = 0; // Erases the element at position pos
};

#endif