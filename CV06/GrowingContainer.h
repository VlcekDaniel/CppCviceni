#pragma once
#ifndef GROWING_CONTAINER_H
#define GROWING_CONTAINER_H
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

template<typename DataType, int StartingValue,int GrowingFactor>
class GrowingContainer
{
public:
	GrowingContainer();
	~GrowingContainer();
	
	void AddElement(const DataType& o);
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int ReturnNumberOfValidElements() const;
	void AddElementOnIndex(int index, const DataType& o);
	void DeleteElement(int index);
private:	
	DataType* array;
	unsigned arraySize;
	unsigned numberOfValidElements;
	bool isSpaceInArray() const;
	void expandArray();
};

template<typename DataType, int StartingValue, int GrowingFactor>
GrowingContainer<DataType, StartingValue, GrowingFactor>::GrowingContainer()
{
	arraySize = StartingValue;
	array = new DataType[arraySize];	
	numberOfValidElements = 0;
}

template<typename DataType, int StartingValue, int GrowingFactor>
GrowingContainer<DataType, StartingValue, GrowingFactor>::~GrowingContainer()
{
	delete[] array;
}

template<typename DataType, int StartingValue, int GrowingFactor>
inline bool GrowingContainer<DataType, StartingValue, GrowingFactor>::isSpaceInArray() const
{
	if (numberOfValidElements <= arraySize)
		return true;
	return false;
}

template<typename DataType, int StartingValue, int GrowingFactor>
inline void GrowingContainer<DataType, StartingValue, GrowingFactor>::expandArray()
{
		DataType* tempArray = new DataType[arraySize*GrowingFactor];
		for (size_t i = 0; i < arraySize*GrowingFactor; i++)
		{
			if (i < arraySize) {
				tempArray[i] = array[i];
			}	
		}			
		arraySize= arraySize*GrowingFactor;
		delete[] array;
		array = tempArray;
}

template<typename DataType, int StartingValue, int GrowingFactor>
inline void GrowingContainer<DataType, StartingValue, GrowingFactor>::AddElement(const DataType& o)
{	
	
			array[numberOfValidElements] = o;		
			numberOfValidElements++;	
	if (numberOfValidElements == arraySize-1) {
		expandArray();
	}
}

template<typename DataType, int StartingValue, int GrowingFactor>
inline DataType& GrowingContainer<DataType, StartingValue, GrowingFactor>::operator[](int index)
{
	if (index<0 || index>arraySize)
	{
		throw std::out_of_range("Index is out of range");
	}
	return array[index];
}

template<typename DataType, int StartingValue, int GrowingFactor>
inline DataType GrowingContainer<DataType, StartingValue, GrowingFactor>::operator[](int index) const
{
	if (index<0 || index>arraySize)
	{
		throw std::out_of_range("Index is out of range");
	}
	return array[index];
}

template<typename DataType, int StartingValue, int GrowingFactor>
inline unsigned int GrowingContainer<DataType, StartingValue, GrowingFactor>::ReturnNumberOfValidElements() const
{
	return numberOfValidElements;
}


template<typename DataType, int StartingValue, int GrowingFactor>
inline void GrowingContainer<DataType, StartingValue, GrowingFactor>::AddElementOnIndex(int index, const DataType& o)
{
	
	if (index<0 || index>arraySize)
	{
		throw std::out_of_range("Index is out of range");
	}

	for (size_t i = numberOfValidElements; i < arraySize-index - 1; i--)
	{
		array[i+1] = array[i];
	}
	array[index] = o;
	numberOfValidElements++;

	if (numberOfValidElements == arraySize - 1) {
		expandArray();
	}
}
template<typename DataType, int StartingValue, int GrowingFactor>
inline void GrowingContainer<DataType, StartingValue, GrowingFactor>::DeleteElement(int index)
{
	if (index<0 || index>arraySize)
	{
		throw std::out_of_range("Index is out of range");
	}
	numberOfValidElements--;
	for (size_t i = index; i < arraySize-1; i++)
	{
		array[i] = array[i + 1];
	}
}

#endif // !GROWING_CONTAINER_H