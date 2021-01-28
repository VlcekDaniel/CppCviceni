#include "pch.h"
#include "StringValue.h"

// -STRING value

StringValue::StringValue(std::string value)
{
    this->value = value;
}

StringValue::~StringValue()
{

}

std::string StringValue::serialize() const
{ 
    return "\"" +value+ "\"";
}

std::string StringValue::get() const
{
    return value;
}