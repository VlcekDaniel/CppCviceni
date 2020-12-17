#pragma once
#ifndef Element_C_H
#define Element_C_H
#include "APotrubniPrvek.h"
class ElementC : public APotrubniPrvek
{
public:
	ElementC(int x, int y, char znak);
	~ElementC();
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const;
private:
};
#endif // Element_C_H
