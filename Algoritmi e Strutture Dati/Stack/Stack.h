/*
	Algoritmi e Strutture Dati - Stack
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef STACK_H
#define STACK_H

// Abstract class
template<class TypeElement>
class Stack
{
    public:
	    typedef TypeElement value_type;
        
	    // -- Virtual Methods --
	    virtual bool empty(void) = 0; // True if the stack's size is 0
	    virtual value_type top(void) = 0; //  Read element from the top
        virtual void pop(void) = 0; // Erase the element at the top
	    virtual void push(const value_type & element) = 0; // Insert an element to the top
};

#endif