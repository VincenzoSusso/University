/*
	Algoritmi e Strutture Dati - Stack
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef STACKLIST_h
#define STACKLIST_h

#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

template <class TypeElement>
class StackList : public Stack<TypeElement>
{
    public:
        typedef typename Stack<TypeElement>::value_type value_type;

        // -- Interfaces --
        StackList(void);
        StackList(TypeElement element);
        ~StackList(void);

        bool empty(void) override;
	    value_type top(void) override;
        void pop(void) override;
	    void push(const value_type & element) override;

    private:
        // -- Attributes --
        LinkedList<TypeElement> stack;
};

// -- Implementation --
template <class TypeElement>
StackList<TypeElement>::StackList(void)
{
    stack = LinkedList<TypeElement>();
}

template <class TypeElement>
StackList<TypeElement>::StackList(TypeElement element)
{
    stack = LinkedList<TypeElement>(element);
}

template <class TypeElement>
StackList<TypeElement>::~StackList(void)
{
    stack.~LinkedList();
}

template <class TypeElement>
bool StackList<TypeElement>::empty(void)
{
    return this -> stack.empty();
}

template <class TypeElement>
typename StackList<TypeElement>::value_type StackList<TypeElement>::top(void)
{
    if(this -> empty())
    {
        throw "The stack is empty";
    }

    return this -> stack.read(this -> stack.begin());
}

template <class TypeElement>
void StackList<TypeElement>::pop(void)
{
    if(this -> empty())
    {
        throw "The stack is empty";
    }

    this -> stack.erase(this -> stack.begin());
}

template <class TypeElement>
void StackList<TypeElement>::push(const value_type & element)
{
    this -> stack.insert(this -> stack.begin(), element);
}

#endif