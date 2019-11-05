/*
	Algoritmi e Strutture Dati - Queue
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <iostream>
#include "Queue.h"
#include "LinkedList.h"

template <class TypeElement>
class QueueList : public Queue<TypeElement>
{
    public:
        typedef typename Queue<TypeElement>::value_type value_type;

        // -- Interfaces --
        QueueList(void);
        QueueList(TypeElement element);
        ~QueueList(void);

        bool empty(void) override;
	    value_type front(void) override;
        void dequeue(void) override;
	    void enqueue(const value_type & element) override;

    private:
        // -- Attributes --
        LinkedList<TypeElement> queue;

        // -- Private Methods --
        Node<TypeElement>* lastNode(); 
};

// -- Implementation --
template <class TypeElement>
QueueList<TypeElement>::QueueList(void) {}

template <class TypeElement>
QueueList<TypeElement>::QueueList(TypeElement element)
{
    this -> queue = LinkedList<TypeElement>(element);
}

template <class TypeElement>
QueueList<TypeElement>::~QueueList(void)
{
    this -> queue.~LinkedList();
}

template <class TypeElement>
bool QueueList<TypeElement>::empty(void)
{
    return this -> queue.empty();
}

template <class TypeElement>
typename QueueList<TypeElement>::value_type QueueList<TypeElement>::front(void)
{
    if(this -> empty())
    {
        throw "The queue is empty";
    }

    return this -> queue.read(this -> lastNode());
}

template <class TypeElement>
void QueueList<TypeElement>::dequeue(void)
{
    if(this -> empty())
    {
        throw "The queue is empty";
    }

    this -> queue.erase(this -> lastNode());
}

template <class TypeElement>
void QueueList<TypeElement>::enqueue(const value_type & element)
{
    this -> queue.insert(this -> queue.begin(), element);
}

template <class TypeElement>
Node<TypeElement>* QueueList<TypeElement>::lastNode()
{
    Node<TypeElement> *last_node = nullptr;

    if(this -> queue.empty())
    {
       throw "The queue is empty"; 
    }

    last_node = this -> queue.begin();
    while(!(this -> queue.end(last_node)))
    {
        last_node = this -> queue.next(last_node);
    }

    return last_node;
}

#endif