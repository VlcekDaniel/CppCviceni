#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>
using namespace std;
struct IObject
{
public:
	IObject();
	~IObject();
	virtual string toString() const = 0;
};
#endif // IOBJECT_H
