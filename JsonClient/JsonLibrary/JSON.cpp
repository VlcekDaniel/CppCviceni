
#include <utility>
#include <limits.h>
#include <stdexcept>
#include <string>
#include "pch.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include "JSON.h"

// -JSON

Value* JSON::deserialize(const std::string& text)
{
    int pointer = 0;
    return deserialize(text, pointer);
}


std::string JSON::serialize(const Value* value)
{
    std::string out = "";
    out.append(value->serialize());  
    return out;
}

Value* JSON::deserialize(const std::string& text, int& pointer)
{
    if (text[pointer]=='{')
    {
        Value* value = readObject(text,pointer);
        return value;
    }
    if (text[pointer] == '[')
    {
        Value* value = readArray(text,pointer);
        return value;
    }
    if (text[pointer] == '\"')
    {
        Value* value =  readText(text,pointer);
        return value;
    }
    if (text[pointer] == '-'|| text[pointer] == '0'|| text[pointer] == '1'|| text[pointer] == '2'|| text[pointer] == '3'||
        text[pointer] == '4'|| text[pointer] == '5'|| text[pointer] == '6'|| text[pointer] == '7'|| text[pointer] == '8'||
        text[pointer] == '9'|| text[pointer] == '.')
    {
        Value* value =readNumber(text,pointer);
        return value;
    }
    if (text[pointer] == 'n'&& text[pointer+1]== 'u' && text[pointer + 2] == 'l' && text[pointer + 3] == 'l')
    {
        Value* value = readNull(text, pointer);
        return value;
    }
    if (text[pointer] == 't' && text[pointer + 1] == 'r' && text[pointer + 2] == 'u' && text[pointer + 3] == 'e')
    {
        Value* value = readTrue(text, pointer);
        return value;
    }
    if (text[pointer] == 'f' && text[pointer + 1] == 'a' && text[pointer + 2] == 'l' && text[pointer + 3] == 's' && text[pointer + 4] == 'e')
    {
        Value* value = readFalse(text,pointer);
        return value;
    }
    else {
        throw std::exception("invalid char");
    }
}

Value* JSON::readObject(const std::string& text, int& pointer)
{
    ObjectValue* objectValue = new ObjectValue{};

    while (text[pointer]!='}')
    {
        pointer++;
        if (text[pointer] == '}') {
            break;
        }
        StringValue* key =((StringValue*)deserialize(text, pointer));
        pointer++;
        Value* value = deserialize(text,pointer);
        objectValue->append(KeyValuePair{key->get(),value});
        delete key;
    }
    pointer++;
    return objectValue;
}


Value* JSON::readArray(const std::string& text, int& pointer)
{
    ArrayValue* arrayValue = new ArrayValue{};
    while (text[pointer] != ']')
    {
        pointer++;
        if (text[pointer] == ']') {
            break;
        }
        Value* value = deserialize(text, pointer);
        arrayValue->append(value);
    }
    pointer++;
    return arrayValue;
}

Value* JSON::readText(const std::string& text, int& pointer)
{
    pointer++;
    std::string a;
    while (text[pointer] != '"')
    {
        if (text[pointer] == '\\') {
            pointer++;
        }
        a.push_back(text[pointer]);
        pointer++;
    }
    pointer++;
    return new StringValue(a);
}

Value* JSON::readNumber(const std::string& text, int& pointer)
{
    std::string number;
    while (text[pointer] == '-' || text[pointer] == '0' || text[pointer] == '1' || text[pointer] == '2' || text[pointer] == '3' ||
        text[pointer] == '4' || text[pointer] == '5' || text[pointer] == '6' || text[pointer] == '7' || text[pointer] == '8' ||
        text[pointer] == '9' || text[pointer] == '.')
    {
        number.push_back(text[pointer]);
        pointer++;
    }
    return new NumberValue(round(stoi(number)));
}

Value* JSON::readNull(const std::string& text, int& pointer)
{
    pointer += 4;
    return new NullValue();
}

Value* JSON::readTrue(const std::string& text, int& pointer)
{
    pointer += 4;
    return new BoolValue(true);
}

Value* JSON::readFalse(const std::string& text, int& pointer)
{
    pointer += 5;
    return new BoolValue(false);  
}

std::string JSON::readFile(std::string name)
{
    std::string myArray;
    std::ifstream MyReadFile(name);
    getline(MyReadFile, myArray);
    return myArray;
}


void JSON::saveFile(std::string name, std::string json)
{
    std::ofstream myfile;
    myfile.open(name);
    myfile << json;
    myfile.close();
}
Value::~Value()
{
}
///////////////////////////////////////////////////////////////////////////////


