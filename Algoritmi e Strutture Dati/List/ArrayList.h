/*
	Algoritmi e Strutture Dati - List
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <vector>
#include "List.h"

template <class TypeElement>
class ArrayList : public List<TypeElement, unsigned short>
{
    public:
        typedef typename List<TypeElement, unsigned short>::value_type value_type;
        typedef typename List<TypeElement, unsigned short>::position position;

        // -- Interfaces --
        ArrayList(void);
        ArrayList(TypeElement element);
        ~ArrayList(void);

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
        std::vector<TypeElement> list;
        unsigned short length;

        // -- Private Methods --
        void setLength(unsigned short length);
        unsigned short getLength(void);
        void changeDimensionList(unsigned short length);
};

// -- Implementation --
template <class TypeElement>
ArrayList<TypeElement>::ArrayList(void)
{
    this -> setLength(0);
    this -> changeDimensionList(this -> getLength());
}

template <class TypeElement>
ArrayList<TypeElement>::ArrayList(TypeElement element)
{
    this -> setLength(1);
    this -> changeDimensionList(this -> getLength());
    this -> write(0, element);
}

template <class TypeElement>
ArrayList<TypeElement>::~ArrayList(void)
{
    this -> setLength(0);
    this -> list.~vector();
}

template <class TypeElement>
bool ArrayList<TypeElement>::empty(void)
{
    return (this -> getLength() == 0);
}

template <class TypeElement>
typename ArrayList<TypeElement>::value_type ArrayList<TypeElement>::read(position position)
{
    if(position >= this -> getLength())
    {
        throw "The position that you have entered is bigger than the lenght of the list";
    }

    return this -> list[position];
}

template <class TypeElement>
void ArrayList<TypeElement>::write(position position, const value_type & element)
{
    if(position >= this -> getLength())
    {
        throw "The position that you have entered is bigger than the lenght of the list";
    }

    this -> list[position] = element;
}

template <class TypeElement>
typename ArrayList<TypeElement>::position ArrayList<TypeElement>::begin(void)
{
    if(this -> empty())
    {
        throw "The list is empty";
    }

    return this -> read(0);
}

template <class TypeElement>
bool ArrayList<TypeElement>::end(position position)
{
    return (position == this -> getLength() - 1);
}

template <class TypeElement>
typename ArrayList<TypeElement>::position ArrayList<TypeElement>::next(position position)
{
    if(position >= this -> getLength() || this -> end(position))
    {
        throw "The position that you have entered has not a next one";
    }

    return position + 1;
}

template <class TypeElement>
typename ArrayList<TypeElement>::position ArrayList<TypeElement>::previous(position position)
{
    if(position >= this -> getLength() || position == this -> begin())
    {
        throw "The position that you have entered has not a previous one";
    }

    return position - 1;
}

template <class TypeElement>
void ArrayList<TypeElement>::insert(position position, const value_type & element)
{
    if(position > this -> getLength())
    {
        throw "The position that you have entered is not valid";
    }

    this -> setLength(this -> getLength() + 1);
    this -> changeDimensionList(this -> getLength());

    for(ArrayList<TypeElement>::position i = this -> getLength() - 1; i > position; i = this -> previous(i))
    {
        this -> write(i, this -> read(this -> previous(i)));
    }

    this -> write(position, element);
}

template <class TypeElement>
void ArrayList<TypeElement>::erase(position position)
{
    if(position >= this -> getLength())
    {
        throw "The position that you have entered is bigger than the lenght of the list";
    }

    this -> list.erase(this -> list.begin() + position);

    this -> setLength(this -> getLength() - 1);
}

template <class TypeElement>
std::string ArrayList<TypeElement>::toString(void)
{
    std::string string = " ";
    ArrayList<TypeElement>::position position = 0;

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

template <class TypeElement>
void ArrayList<TypeElement>::setLength(unsigned short length)
{
    this -> length = length;
}

template <class TypeElement>
unsigned short ArrayList<TypeElement>::getLength(void)
{
    return this -> length;
}

template <class TypeElement>
void ArrayList<TypeElement>::changeDimensionList(unsigned short length)
{
    this -> list.resize(length);
}

#endif