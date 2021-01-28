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
// - tøída pro práci s JSON
class DLL_SPEC JSON
{
public:
	// - provede deserializaci øetìzce na vytvoøené objekty
	// - pøeètu znak a rozhodnu se
	// -- '{' - zaèínám èíst objekt
	// -------- ètu znaky, pak musí být dvojteèka, potom volám rekurzivnì deserialize(); následuje èárka nebo '}', podle situace se ètení opakuje
	// -- '[' - zaèínám èíst pole
	// -------- volám rekurzivnì deserialize(); následuje èárka nebo ']', podle situace se ètení opakuje
	// -- '"' - zaèínám èíst øetìzec - pozor na escapované uvozovky
	// -- [-0123456789] - zaèínám èíst èíslo - naètu všechny èíslice (pozor na možnou desetinnou teèku)
	// -- 'n' - 'null'
	// -- 't' - 'true'
	// -- 'f' - 'false'
	// -- cokoliv jiného - vyvolávám výjimku
	// - není pøípustné vracet nullptr
	// - deserializace musí být rozumnì implementována - není pøípustné zde napsat jednu extrémnì dlouhou metodu
	static Value* deserialize(const std::string& string);
	
	// - provede serializaci do JSON øetìzce
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


