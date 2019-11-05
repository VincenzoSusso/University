/*
	Algoritmi e Strutture Dati - Queue
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>
#include <vector>

template <class TypeElement>
class QueueArray : public Queue<TypeElement>
{
    public:
        typedef typename Queue<TypeElement>::value_type value_type;

        // -- Interfaces --
        QueueArray(void);
        QueueArray(TypeElement element);
        ~QueueArray(void);

        bool empty(void) override;
	    value_type front(void) override;
        void dequeue(void) override;
	    void enqueue(const value_type & element) override;

    private:
        // -- Attributes --
        std::vector<TypeElement> queue;
        unsigned short length;

        // -- Private Methods --
        void setLength(unsigned short length);
        unsigned short getLength(void);
        void changeDimensionStack(unsigned short length);
};

// -- Implementation --
template <class TypeElement>
QueueArray<TypeElement>::QueueArray(void)
{
    this -> setLength(0);
    this -> changeDimensionStack(this -> getLength());
}

template <class TypeElement>
QueueArray<TypeElement>::QueueArray(TypeElement element)
{
    this -> setLength(0);
    this -> enqueue(element);
}

template <class TypeElement>
QueueArray<TypeElement>::~QueueArray(void)
{
    this -> queue.~vector();
}

template <class TypeElement>
bool QueueArray<TypeElement>::empty(void)
{
    return (this -> length == 0);
}

template <class TypeElement>
typename QueueArray<TypeElement>::value_type QueueArray<TypeElement>::front(void)
{
    if(this -> empty())
    {
        throw "The queue is empty";
    }

    return this -> queue[this -> getLength() - 1];
}

template <class TypeElement>
void QueueArray<TypeElement>::dequeue(void)
{
    if(this -> empty())
    {
        throw "The queue is empty";
    }

    this -> setLength(this -> getLength() - 1);
    this -> changeDimensionStack(this -> getLength());
}

template <class TypeElement>
void QueueArray<TypeElement>::enqueue(const value_type & element)
{
    this -> setLength(this -> getLength() + 1);
    this -> changeDimensionStack(this -> getLength());

    for(unsigned short i = this -> getLength() - 1; i > 0; i--)
    {
        this -> queue[i] = this -> queue[i-1];
    }

    this -> queue[0] = element;
}

template <class TypeElement>
void QueueArray<TypeElement>::setLength(unsigned short length)
{
    this -> length = length;
}

template <class TypeElement>
unsigned short QueueArray<TypeElement>::getLength(void)
{
    return this -> length;
}

template <class TypeElement>
void QueueArray<TypeElement>::changeDimensionStack(unsigned short length)
{
    this -> queue.resize(length);
}

#endif