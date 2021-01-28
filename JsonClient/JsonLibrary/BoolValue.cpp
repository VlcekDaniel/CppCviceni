#include "pch.h"
#include "BoolValue.h"

// -BOOL value

BoolValue::BoolValue(bool value)
{
    valueBool = value;
}

std::string BoolValue::serialize() const
{
    if (valueBool) {
        return "true";
    }
    else {
        return "false";
    }
}

bool BoolValue::get() const
{
    return false;
}