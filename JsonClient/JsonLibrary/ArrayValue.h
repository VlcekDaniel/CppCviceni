#pragma once
#include "pch.h"
#include "platform.h"
#include "Value.h"
#include "DynamicArray.h"
#include <string>
#ifndef ARRAY_VALUE_H
#define ARRAY_VALUE_H
// - reprezentuje hodnotu typu JSON pole
class DLL_SPEC ArrayValue :
	public Value
{
public:
	ArrayValue();
	~ArrayValue();

	// - p�id� element na konec pole
	void append(Value* element);
	// - sma�e element na indexu
	void removeOnIndex(int index);
	// - edit
	void edit(Value* element, int index);
	Value* getElementAtIndex(int index);
	std::string serialize() const;
private:
	// - atribut DynamicArray<Value*> pro uchov�n� jednotliv�ch element� v poli
	DynamicArray<Value*> arrayArrayValue;
};
#endif // !ARRAY_VALUE_H

