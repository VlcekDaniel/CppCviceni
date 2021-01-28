#pragma once
#include "pch.h"
#include "platform.h"
#include "Value.h"
#include "KeyValuePair.h"
#include "DynamicArray.h"
#include <string>
#ifndef OBJECT_VALUE_H
#define OBJECT_VALUE_H
// - reprezentuje hodnotu typu JSON objekt
class DLL_SPEC ObjectValue :
	public Value
{
public:

	ObjectValue();
	~ObjectValue();

	// - pøidá klíè-element do objektu
	void append(const KeyValuePair& pair);
	std::string serialize() const;
private:
	// - atribut DynamicArray<KeyValuePair> pro uchování jednotlivých hodnot a klíèù v objektu
	DynamicArray<KeyValuePair> arrayObjectValue;
};
#endif // !OBJECT_VALUE_H
