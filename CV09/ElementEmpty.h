#pragma once
#ifndef Element_EMPTY_H
#define Element_EMPTY_H
#include "APotrubniPrvek.h"
#include "Potrubi.h"
class ElementEmpty : public APotrubniPrvek
{
public:
	ElementEmpty(int x, int y, char znak);
	~ElementEmpty();
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const;
private:
};
#endif // Element_EMPTY_H
