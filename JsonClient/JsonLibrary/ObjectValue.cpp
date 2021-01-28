#include "pch.h"
#include "ObjectValue.h"

// -OBJECT value

ObjectValue::ObjectValue()
{

}

ObjectValue::~ObjectValue()
{

    for (size_t i = 0; i < arrayObjectValue.getSize(); i++)
    {
        delete arrayObjectValue.getElementAt(i).getValue();
    }
}


void ObjectValue::append(const KeyValuePair& pair)
{
    arrayObjectValue.append(pair);
}


std::string ObjectValue::serialize() const
{
    std::string out;
    out.append("{");
    for (int i = 0; i < arrayObjectValue.getSize(); i++)
    {
        out.append(arrayObjectValue.getElementAt(i).serialize());
        if (i != arrayObjectValue.getSize() - 1)
        {
            out.append(",");
        }
    }
    out.append("}");
    return out;
}

