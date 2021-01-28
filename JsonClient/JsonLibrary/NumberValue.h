#pragma once
#include "pch.h"
#include "platform.h"
#include "Value.h"
#include "KeyValuePair.h"
#include "DynamicArray.h"
#include <string>
#ifndef NUMVER_VALUE_H
#define NUMBER_VALUE_H
// - reprezentuje hodnotu typu JSON èíslo
class DLL_SPEC NumberValue :
	public Value
{
public:
	NumberValue(double value);
	~NumberValue();
	std::string serialize() const;
	// - vrací èíselnou hodnotu 
	double get() const;
private:
	double valueNumber;
};
#endif // !NUMVER_VALUE_H
