/*
	Algoritmi e Strutture Dati - Queue
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef QUEUE_H
#define QUEUE_H

// Abstract class
template<class TypeElement>
class Queue
{
    public:
	    typedef TypeElement value_type;
        
	    // -- Virtual Methods --
	    virtual bool empty(void) = 0; // True if the queue's size is 0
	    virtual value_type front(void) = 0; //  Read element
        virtual void dequeue(void) = 0; // Erase the element from the queue
	    virtual void enqueue(const value_type & element) = 0; // Insert an element to the queue
};

#endif