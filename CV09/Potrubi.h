#pragma once
#ifndef POTRUBI_H
#define POTRUBI_H
#include "IPotrubi.h"
#include <string>
struct Potrubi : IPotrubi
{
public:
	Potrubi(std::string text,int velikost);
	~Potrubi();
	const APotrubniPrvek* DejPrvek(int x, int y) const;
	bool JePotrubiOk() const;
	int velikost;
	APotrubniPrvek** prvky;
private:
	
};
#endif // !POTRUBI_H




