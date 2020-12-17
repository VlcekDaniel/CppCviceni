#include "ElementA.h"
ElementA::ElementA(int x,int y,char znak)
{
	this->x = x;
	this->y = y;
	this->text = znak;
}
ElementA::~ElementA()
{
}
bool ElementA::JeKorektneZapojen(const Potrubi* potrubi) const
{	
		if (x == 0 || x == potrubi->velikost - 1)
		{
			return false;
		}
		if (potrubi->DejPrvek(x - 1, y)->text==(' ') ||
			potrubi->DejPrvek(x + 1, y)->text==(' '))			
		{
			return false;
		}
		return true;	
}