#include "pch.h"
#include "KeyValuePair.h"

// - definuje pár klíè (øetìzec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu

KeyValuePair::KeyValuePair()
{
    this->key = "";
    this->valueKeys = nullptr;
}

KeyValuePair::KeyValuePair(std::string key, Value* value)
{
    this->key = key;
    this->valueKeys = value;
}

KeyValuePair::~KeyValuePair()
{

}

std::string KeyValuePair::getKey() const
{
    return key;
}

Value* KeyValuePair::getValue() const
{
    return valueKeys;
}

std::string KeyValuePair::serialize() const
{
    std::string out;
    out.append("\"");
    out.append(key);
    out.append("\"");
    out.append(":");
    out.append(valueKeys->serialize());
    return out;
}