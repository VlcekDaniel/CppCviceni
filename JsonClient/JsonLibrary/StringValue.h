#pragma once
#include "pch.h"
#include "platform.h"
#include "Value.h"
#include "DynamicArray.h"
#include <string>
#ifndef STRING_VALUE_H
#define STRING_VALUE_H
// - reprezentuje hodnotu typu JSON �et�zec (string)
class DLL_SPEC StringValue :
	public Value
{
public:
	~StringValue();
	StringValue(std::string value);
	std::string serialize() const;
	// - vrac� �et�zcovou hodnotu
	std::string get() const;
private:
	std::string value;
};
#endif // !STRING_VALUE_H
