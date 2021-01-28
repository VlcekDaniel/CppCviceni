#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
// - �ablona s parametrem datov�ho typu ulo�en�ch hodnot
// - nen� povoleno u�it� STL kontejner� ani jin�ch knihoven pro ukl�d�n� dat
// - realizace mus� vyu��vat dynamicky alokovan� pole, spojov� seznam nebo jinou vhodnou V�mi implementovanou ADS 
template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();

	// - p�id� element na konec pole
	void append(const T& element);

	void editElementAtIndex(T& element, int index);

	// - v�jimky p�i neplatn�m nebo nekorektn�m indexu
	const T& getElementAt(int index) const;

	// - sma�e vybran� element
	void removeElementAtIndex(int index);

	// - vrac� velikost (po�et prvk�) v poli
	int getSize() const;

	// - zdvojn�sob� kapacitu pole
	void expandArray();
private:
	T* dynamicArray;
	int size;
	int numberOfElements;
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
    size = 10;
    numberOfElements = 0;
    dynamicArray = new T[size];
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] dynamicArray;
}

template<typename T>
void DynamicArray<T>::append(const T& element)
{
    dynamicArray[numberOfElements] = element;
    numberOfElements++;

    if (numberOfElements == size - 1) {
        expandArray();
    }
}

template<typename T>
void DynamicArray<T>::editElementAtIndex(T& element, int index) {
    dynamicArray[index] = element;
}

template<typename T>
const T& DynamicArray<T>::getElementAt(int index) const
{
    return dynamicArray[index];
}

template<typename T>
void DynamicArray<T>::removeElementAtIndex(int index)
{

    if (dynamicArray[index] == dynamicArray[numberOfElements - 1])
    {
        dynamicArray[index] = nullptr;
    }
    else {
        dynamicArray[index] = dynamicArray[numberOfElements - 1];
    }
    numberOfElements--;
}

template<typename T>
int DynamicArray<T>::getSize() const
{
    return numberOfElements;
}

template<typename T>
void DynamicArray<T>::expandArray()
{
    T* tempArray = new T[size * 2];
    for (int i = 0; i < size * 2; i++)
    {
        if (i < size) {
            tempArray[i] = dynamicArray[i];
        }
    }
    size = size * 2;
    delete[] dynamicArray;
    dynamicArray = tempArray;
}

#endif DYNAMIC_ARRAY_H
