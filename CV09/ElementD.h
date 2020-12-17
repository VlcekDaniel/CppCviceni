#pragma once
#ifndef Element_D_H
#define Element_D_H
#include "APotrubniPrvek.h"
#include "Potrubi.h"
class ElementD : public APotrubniPrvek
{
public:
	ElementD(int x, int y, char znak);
	~ElementD();
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const;
private:
};
#endif // Element_D_H
