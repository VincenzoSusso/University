/*
	Algoritmi e Strutture Dati - Stack
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <iostream>
#include <vector>
#include "Stack.h"

template <class TypeElement>
class StackArray : public Stack<TypeElement>
{
    public:
        typedef typename Stack<TypeElement>::value_type value_type;

        // -- Interfaces --
        StackArray(void);
        StackArray(TypeElement element);
        ~StackArray(void);

        bool empty(void) override;
	    value_type top(void) override;
        void pop(void) override;
	    void push(const value_type & element) override;

    private:
        // -- Attributes --
        std::vector<TypeElement> stack;
        unsigned short length;

        // -- Private Methods --
        void setLength(unsigned short length);
        unsigned short getLength(void);
        void changeDimensionStack(unsigned short length);
};

// -- Implementation --
template <class TypeElement>
StackArray<TypeElement>::StackArray(void)
{
    this -> setLength(0);
    this -> changeDimensionStack(this -> getLength());
}

template <class TypeElement>
StackArray<TypeElement>::StackArray(TypeElement element)
{
    this -> setLength(0);
    this -> changeDimensionStack(this -> getLength());
    this -> push(element);
}

template <class TypeElement>
StackArray<TypeElement>::~StackArray(void)
{
    this -> setLength(0);
    this -> stack.~vector();
}

template <class TypeElement>
bool StackArray<TypeElement>::empty(void)
{
    return (this -> getLength() == 0);
}

template <class TypeElement>
typename StackArray<TypeElement>::value_type StackArray<TypeElement>::top(void)
{
    if(this -> empty())
    {
        throw "The stack is empty";
    }

    return this -> stack[this -> getLength() - 1];
}

template <class TypeElement>
void StackArray<TypeElement>::pop(void)
{
    if(this -> empty())
    {
        throw "The stack is empty";
    }

    this -> setLength(this -> getLength() - 1);
    this -> changeDimensionStack(this -> getLength());
}

template <class TypeElement>
void StackArray<TypeElement>::push(const value_type & element)
{
    this -> setLength(this -> getLength() + 1);
    this -> changeDimensionStack(this -> getLength());
    this -> stack[this -> getLength() - 1] = element;
}

template <class TypeElement>
void StackArray<TypeElement>::setLength(unsigned short length)
{
    this -> length = length;
}

template <class TypeElement>
unsigned short StackArray<TypeElement>::getLength(void)
{
    return this -> length;
}

template <class TypeElement>
void StackArray<TypeElement>::changeDimensionStack(unsigned short length)
{
    this -> stack.resize(length);
}

#endif