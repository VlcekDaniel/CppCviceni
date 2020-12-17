#include "ElementB.h"
#include "Potrubi.h"
ElementB::ElementB(int x, int y, char znak)
{
	this->x = x;
	this->y = y;
	this->text = znak;
}
ElementB::~ElementB()
{
}
bool ElementB::JeKorektneZapojen(const Potrubi* potrubi) const
{
	if (potrubi->DejPrvek(x, y)->text==('I'))
	{
		if (y == 0 || y == potrubi->velikost - 1)
		{
			return false;
		}
		if (potrubi->DejPrvek(x, y-1)->text==(' ') ||
			potrubi->DejPrvek(x, y+1)->text==(' '))
		{
			return false;
		}
		return true;
	}
}
