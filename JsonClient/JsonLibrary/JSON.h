#pragma once
#include <string>
#include "pch.h"
#include "platform.h"
#include "DynamicArray.h"
#include "Value.h"
#include "KeyValuePair.h"
#include "StringValue.h"
#include "NullValue.h"
#include "NumberValue.h"
#include "ObjectValue.h"
#include "BoolValue.h"
#include "ArrayValue.h"
#include <iostream>
// - t��da pro pr�ci s JSON
class DLL_SPEC JSON
{
public:
	// - provede deserializaci �et�zce na vytvo�en� objekty
	// - p�e�tu znak a rozhodnu se
	// -- '{' - za��n�m ��st objekt
	// -------- �tu znaky, pak mus� b�t dvojte�ka, potom vol�m rekurzivn� deserialize(); n�sleduje ��rka nebo '}', podle situace se �ten� opakuje
	// -- '[' - za��n�m ��st pole
	// -------- vol�m rekurzivn� deserialize(); n�sleduje ��rka nebo ']', podle situace se �ten� opakuje
	// -- '"' - za��n�m ��st �et�zec - pozor na escapovan� uvozovky
	// -- [-0123456789] - za��n�m ��st ��slo - na�tu v�echny ��slice (pozor na mo�nou desetinnou te�ku)
	// -- 'n' - 'null'
	// -- 't' - 'true'
	// -- 'f' - 'false'
	// -- cokoliv jin�ho - vyvol�v�m v�jimku
	// - nen� p��pustn� vracet nullptr
	// - deserializace mus� b�t rozumn� implementov�na - nen� p��pustn� zde napsat jednu extr�mn� dlouhou metodu
	static Value* deserialize(const std::string& string);
	
	// - provede serializaci do JSON �et�zce
	static std::string serialize(const Value* value);
	static std::string readFile(std::string name);
	static void saveFile(std::string name, std::string json);
private:
	static Value* deserialize(const std::string& string, int& pointer);
	static Value* readObject(const std::string& text, int& pointer);
	static Value* readArray(const std::string& text, int& pointer);
	static Value* readText(const std::string& text, int& pointer);
	static Value* readNumber(const std::string& text, int& pointer);
	static Value* readNull(const std::string& text, int& pointer);
	static Value* readTrue(const std::string& text, int& pointer);
	static Value* readFalse(const std::string& text, int& pointer);
};


