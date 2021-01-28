#include "pch.h"
#include "ArrayValue.h"

// -ARRAY value

ArrayValue::ArrayValue()
{
}

ArrayValue::~ArrayValue()
{
    for (size_t i = 0; i < arrayArrayValue.getSize(); i++)
    {
        delete arrayArrayValue.getElementAt(i);
    }
}

void ArrayValue::removeOnIndex(int index)
{
    arrayArrayValue.removeElementAtIndex(index);
}

void ArrayValue::edit(Value* elementNew, int index)
{
    arrayArrayValue.editElementAtIndex(elementNew, index);
}

Value* ArrayValue::getElementAtIndex(int index)
{
    return arrayArrayValue.getElementAt(index);
}

void ArrayValue::append(Value* element)
{
    arrayArrayValue.append(element);
}

std::string ArrayValue::serialize() const
{
    std::string out;
    out.append("[");
    for (int i = 0; i < arrayArrayValue.getSize(); i++)
    {
        out.append(arrayArrayValue.getElementAt(i)->serialize());
        if (i != arrayArrayValue.getSize() - 1)
        {
            out.append(",");
        }
    }
    out.append("]");
    return out;
}
