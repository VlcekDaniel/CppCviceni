#pragma once
#include "platform.h"
#include <string>
#include "Value.h"
#ifndef KEY_VALUE_PAIR_H
#define KEY_VALUE_PAIR_H
///////////////////////////////////////////////////////////////////////////////
// - definuje p�r kl�� (�et�zec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair {
public:
	KeyValuePair();
	KeyValuePair(std::string key, Value* value);
	~KeyValuePair();
	// - vr�t� kl��
	std::string getKey() const;
	// - vr�t� hodnotu
	Value* getValue() const;
	std::string serialize() const;
private:
	std::string key;
	Value* valueKeys;
};
#endif // !KEY_VALUE_PAIR_H
