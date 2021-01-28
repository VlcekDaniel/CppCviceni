#pragma once
#include "pch.h"
#include "platform.h"
#include <string>
#ifndef VALUE_H
#define VALUE_H
// JSON hodnota - reprezentuje abstraktního pøedka pro základní datové typy v JSON (string, number, object, array, bool, null)
class DLL_SPEC Value {
public:
	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
	virtual ~Value();
};
#endif // !VALUE_H


