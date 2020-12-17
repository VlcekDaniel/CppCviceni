#pragma once
#ifndef Element_E_H
#define Element_E_H
#include "APotrubniPrvek.h"
#include "Potrubi.h"
class ElementE : public APotrubniPrvek
{
public:
	ElementE(int x, int y, char znak);
	~ElementE();
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const;
private:
};
#endif // Element_E_H
