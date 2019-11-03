/*
	Algoritmi e Strutture Dati - Stack
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "List.h"

template <class TypeElement>
struct Node
{
    Node *next;
    Node *previous;
    TypeElement element;
};

template <class TypeElement>
class LinkedList : public List<TypeElement, Node<TypeElement>* >
{
    public:
        typedef typename List<TypeElement, Node<TypeElement>* >::value_type value_type;
        typedef typename List<TypeElement, Node<TypeElement>* >::position position;

        // -- Interfaces --
        LinkedList(void);
        LinkedList(TypeElement element);
        ~LinkedList(void);

        bool empty(void) override;
        value_type read(position position) override;
        void write(position position, const value_type & element) override;
        position begin(void) override;
        bool end(position position) override;
        position next(position position) override;
        position previous(position position) override;
        void insert(position position, const value_type & element) override;
        void erase(position position) override;

        std::string toString(void);
    private:
        // -- Attributes --
        Node<TypeElement> *head;
};

// -- Implementation --
template <class TypeElement>
LinkedList<TypeElement>::LinkedList(void)
{
    this -> head = nullptr;
}

template <class TypeElement>
LinkedList<TypeElement>::LinkedList(TypeElement element)
{
    Node<TypeElement> *node = (Node<TypeElement>*) malloc(sizeof(*node));

    node -> previous = nullptr;
    node -> next = nullptr;
    node -> element = element;
    this -> head = node;
}

template <class TypeElement>
LinkedList<TypeElement>::~LinkedList(void)
{
    Node<TypeElement> *position = this -> begin();
    Node<TypeElement> *temp = nullptr;
    
    if(!(this -> empty()))
    {
        while(!(this -> end(position)))
        {   
            temp = position;
            position = this -> next(position);
            free(temp);
        }
        free(position);
        this -> head = nullptr;
    }
}

template <class TypeElement>
bool LinkedList<TypeElement>::empty(void)
{
    return (this -> head == nullptr);
}

template <class TypeElement>
typename LinkedList<TypeElement>::value_type LinkedList<TypeElement>::read(position position)
{
    if(this -> empty())
    {
        throw "The list is empty";
    }

    return position -> element;
}

template <class TypeElement>
void LinkedList<TypeElement>::write(position position, const value_type & element)
{
    if(this -> empty())
    {
        throw "The list is empty";
    }

    position -> element = element;
}

template <class TypeElement>
typename LinkedList<TypeElement>::position LinkedList<TypeElement>::begin(void)
{
    return this -> head;
}

template <class TypeElement>
bool LinkedList<TypeElement>::end(position position)
{
    return (position -> next == nullptr);
}

template <class TypeElement>
typename LinkedList<TypeElement>::position LinkedList<TypeElement>::next(position position)
{
    return position -> next;
}

template <class TypeElement>
typename LinkedList<TypeElement>::position LinkedList<TypeElement>::previous(position position)
{
    if(position -> previous == nullptr)
    {
        throw "The position that you have entered has not a previous one";
    }

    return position -> previous;
}

template <class TypeElement>
void LinkedList<TypeElement>::insert(position position, const value_type & element)
{
    Node<TypeElement> *node = (Node<TypeElement>*) malloc(sizeof(*node));
    
    node -> element = element;
    if(this -> empty())
    {
        this -> head = node;
        node -> next = nullptr;
        node -> previous = nullptr;
    }
    else if(position == nullptr)
    {
        Node<TypeElement> *temp = this -> begin();
        while(!this -> end(temp))
        {
            temp = this -> next(temp);
        }

        temp -> next = node;
        node -> next = nullptr;
        node -> previous = temp;
    }
    else if(this -> begin() == position)
    {
        this -> head = node;
        node -> next = position;
        node -> previous = nullptr;
        position -> previous = node;
    }
    else
    {
        node -> next = position;
        node -> previous = position -> previous;
        position -> previous -> next = node;
        position -> previous = node;    
    }
}

template <class TypeElement>
void LinkedList<TypeElement>::erase(position position)
{
    if(this -> empty())
    {
        throw "The list is empty";
    }

    if(this -> begin() == position && this -> next(position) == nullptr)
    {
        free(position);
        this -> head = nullptr;
    }
    else if(this -> begin() == position)
    {
        this -> head = position -> next;
        position -> next -> previous = nullptr;
        free(position);
    }
    else if(this -> end(position))
    {
        position -> previous -> next = nullptr;
        free(position);
    }
    else
    {
        position -> previous -> next = position -> next;
        position -> next -> previous = position -> previous;
        free(position);
    }
}

template <class TypeElement>
std::string LinkedList<TypeElement>::toString(void)
{
    std::string string = "";
    position position = this -> begin();
    
    if(!(this -> empty()))
    {
        while(!(this -> end(position)))
        {
            string += std::to_string(this -> read(position)) + " ";
            position = this -> next(position);
        }
        string += std::to_string(this -> read(position)) + " ";
    }
    
    return string;
}

#endif