#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>
using namespace std;
struct IObject
{
public:
	virtual ~IObject();
	virtual string ToString() const = 0;
};
#endif // IOBJECT_H
