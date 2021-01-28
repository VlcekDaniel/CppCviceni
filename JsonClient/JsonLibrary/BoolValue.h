#pragma once
#include "pch.h"
#include "platform.h"
#include "Value.h"
#include "KeyValuePair.h"
#include "DynamicArray.h"
#include <string>
#ifndef BOOL_VALUE_H
#define BOOL_VALUE_H
// - reprezentuje hodnotu typu JSON bool
class DLL_SPEC BoolValue :
	public Value
{
public:
	BoolValue(bool value);
	std::string serialize() const;
	// - vrací bool hodnotu
	bool get() const;
private:
	bool valueBool;
};
#endif // !BOOL_VALUE_H
