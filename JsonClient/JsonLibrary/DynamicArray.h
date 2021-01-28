#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
// - šablona s parametrem datového typu uložených hodnot
// - není povoleno užití STL kontejnerù ani jiných knihoven pro ukládání dat
// - realizace musí využívat dynamicky alokované pole, spojový seznam nebo jinou vhodnou Vámi implementovanou ADS 
template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();

	// - pøidá element na konec pole
	void append(const T& element);

	void editElementAtIndex(T& element, int index);

	// - výjimky pøi neplatném nebo nekorektním indexu
	const T& getElementAt(int index) const;

	// - smaže vybraný element
	void removeElementAtIndex(int index);

	// - vrací velikost (poèet prvkù) v poli
	int getSize() const;

	// - zdvojnásobí kapacitu pole
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
