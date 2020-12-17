#pragma once
#ifndef Element_B_H
#define Element_B_H
#include "APotrubniPrvek.h"
class ElementB : public APotrubniPrvek
{
public:
	ElementB(int x, int y, char znak);
	~ElementB();
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const;
private:
};
#endif // Element_C_H
