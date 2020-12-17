#pragma once
#ifndef A_POTRUBNI_PRVEK_H
#define A_POTRUBNI_PRVEK_H
struct Potrubi;
struct APotrubniPrvek {
	virtual ~APotrubniPrvek() {};
	virtual bool JeKorektneZapojen(const Potrubi* potrubi) const = 0;
char text;
int x;
int y;
};
#endif // !A_POTRUBNI_PRVEK_H
