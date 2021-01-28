#pragma once
#include "pch.h"
#include "platform.h"
#include "Value.h"
#include <string>
#include "pch.h"
#include "Value.h"
#ifndef NULL_VALUE_H
#define NULL_VALUE_H
// - reprezentuje hodnotu typu JSON null
class DLL_SPEC NullValue : public Value
{
public:
	std::string serialize() const;
};
#endif // !NULL_VALUE_H
