#include "pch.h"
#include "NumberValue.h"

// -Number value

NumberValue::~NumberValue()
{

}

NumberValue::NumberValue(double value)
{
    valueNumber = value;
}

std::string NumberValue::serialize() const
{
    return std::to_string(valueNumber);
}

double NumberValue::get() const
{
    return valueNumber;
}
