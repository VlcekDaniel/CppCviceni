#pragma once
#ifndef Element_A_H
#define Element_A_H
#include "APotrubniPrvek.h"
#include "Potrubi.h"

class ElementA : public APotrubniPrvek
{
public:
	ElementA(int x,int y,char znak);
	~ElementA();
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const;
private:
};
#endif // Element_A_H
