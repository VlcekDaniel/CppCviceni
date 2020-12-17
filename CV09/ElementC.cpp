#include "ElementC.h"
#include "Potrubi.h"
ElementC::ElementC(int x, int y, char znak)
{
	this->x = x;
	this->y = y;
	this->text = znak;
}
ElementC::~ElementC()
{
}
bool ElementC::JeKorektneZapojen(const Potrubi* potrubi) const
{
	if (potrubi->DejPrvek(x, y)->text==('+'))
	{
		if (y == 0 || y == potrubi->velikost - 1)
		{
			return false;
		}
		if (potrubi->DejPrvek(x, y - 1)->text==(' ') ||
			potrubi->DejPrvek(x, y + 1)->text==(' '))
		{
			return false;
		}
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
}