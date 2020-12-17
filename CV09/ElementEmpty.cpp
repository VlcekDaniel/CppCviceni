#include "ElementEmpty.h"

ElementEmpty::ElementEmpty(int x, int y, char znak)
{
	this->x = x;
	this->y = y;
	this->text = znak;
}

ElementEmpty::~ElementEmpty()
{
}

bool ElementEmpty::JeKorektneZapojen(const Potrubi* potrubi) const
{
	return true;
}
