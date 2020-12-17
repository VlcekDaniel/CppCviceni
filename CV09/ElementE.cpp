#include "ElementE.h"
ElementE::ElementE(int x, int y, char znak)
{
	this->x = x;
	this->y = y;
	this->text = znak;
}
ElementE::~ElementE()
{
}
bool ElementE::JeKorektneZapojen(const Potrubi* potrubi) const
{
	if (potrubi->DejPrvek(x, y)->text==('T'))
	{
		if (y == potrubi->velikost - 1)
		{
			return false;
		}
		if (potrubi->DejPrvek(x, y + 1)->text==(' '))
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
	return false;
}