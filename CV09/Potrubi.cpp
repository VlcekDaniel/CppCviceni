#include "Potrubi.h"
#include "ElementA.h"
#include "ElementB.h"
#include "ElementC.h"
#include "ElementD.h"
#include "ElementE.h"
#include "ElementEmpty.h"
#include <iostream>
using namespace std;

Potrubi::Potrubi(string znaky, int velikostPotrubi)
{
	velikost = velikostPotrubi;
	prvky = new APotrubniPrvek * [velikostPotrubi * velikostPotrubi];
	for (int i = 0; i < velikostPotrubi * velikostPotrubi; i++)
	{
		if (znaky[i] == '-') {
			prvky[i] = new ElementA(i%velikost,i/velikost,'-');
			//cout << "Aloc:" << prvky[i]->text << " " << prvky[i]->x << " " << prvky[i]->y << "\n";
		}
		if (znaky[i] == 'I') {
			prvky[i] = new ElementB(i % velikost, i / velikost, 'I');
			//cout << "Aloc:" << prvky[i]->text << " " << prvky[i]->x << " " << prvky[i]->y << "\n";
		}
		if (znaky[i] == '+') {
			prvky[i] = new ElementC(i % velikost, i / velikost, '+');
			//cout << "Aloc:" << prvky[i]->text << " " << prvky[i]->x << " " << prvky[i]->y << "\n";
		}
		if (znaky[i] == 'O') {
			prvky[i] = new ElementD(i % velikost, i / velikost, 'O');
			//cout << "Aloc:" << prvky[i]->text << " " << prvky[i]->x << " " << prvky[i]->y << "\n";
		}
		if (znaky[i] == 'T') {
			prvky[i] = new ElementE(i % velikost, i / velikost, 'T');
			//cout << "Aloc:" << prvky[i]->text << " " << prvky[i]->x << " " << prvky[i]->y << "\n";
		}
		if (znaky[i] == ' ') {
			prvky[i] = new ElementEmpty(i % velikost, i / velikost, ' ');
			//cout << "Aloc:" << prvky[i]->text << " " << prvky[i]->x << " " << prvky[i]->y << "\n";
		}
	}
}

Potrubi::~Potrubi()
{
	delete[] prvky;
}

const APotrubniPrvek* Potrubi::DejPrvek(int x, int y) const
{
	return prvky[(y * velikost) + x];
}

bool Potrubi::JePotrubiOk() const
{
	for (int i = 0; i < velikost*velikost; i++)
	{
		//cout<<"text: "<< prvky[i]->text << " " << prvky[i]->x << " "<< prvky[i]->y<< "\n";
		if (prvky[i]->JeKorektneZapojen(this))
		{
		}
		else
		{
			return false;
		}
	}
	return true;
}


