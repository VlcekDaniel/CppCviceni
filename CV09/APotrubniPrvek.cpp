#include "APotrubniPrvek.h"

APotrubniPrvek::~APotrubniPrvek()
{
}

bool APotrubniPrvek::JeKorektneZapojen(const IPotrubi* potrubi) const
{
		
			if (potrubi->DejPrvek(x, y) == "I")
			{
				if (y == 0 || y == potrubi->velikost - 1)
				{
					return false;
				}
				if (potrubi->DejPrvek(x, y-1) == " " || potrubi->DejPrvek(x, y+1) == " ")
				{
					return false;
				}
			}
			if (potrubi->DejPrvek(x, y) == "+")
			{
				if (y == 0 || y == potrubi->velikost - 1|| x == 0 || x == potrubi->velikost - 1)
				{
					return false;
				}
				if (potrubi->DejPrvek(x, y - 1) == " " || potrubi->DejPrvek(x, y + 1) == " ")
				{
					return false;
				}
				if (potrubi->DejPrvek(x - 1, y) == " " || potrubi->DejPrvek(x + 1, y) == " ")
				{
					return false;
				}
			}
			if (potrubi->DejPrvek(x, y) == "T")
			{
				if (y == potrubi->velikost - 1 || x == 0 || x == potrubi->velikost - 1)
				{
					return false;
				}
				if (potrubi->DejPrvek(x - 1, y) == " " || potrubi->DejPrvek(x + 1, y) == " ")
				{
					return false;
				}
				if (potrubi->DejPrvek(x, y + 1) == " ")
				{
					return false;
				}
			}
    return true;
}
