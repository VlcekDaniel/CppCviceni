#include "ElementD.h"
ElementD::ElementD(int x, int y, char znak)
{
	this->x = x;
	this->y = y;
	this->text = znak;
}
ElementD::~ElementD()
{
}
bool ElementD::JeKorektneZapojen(const Potrubi* potrubi) const
{
		return true;	
}