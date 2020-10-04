#include <iostream>
#include "Trojuhelnik.cpp"

using namespace std;

int main(int argc, char** argv) {

	int a, b, c, pocetTrojuhelniku;

	cout << "Kolik chcete zadat trojuhelniku?" << endl;
	cin >> pocetTrojuhelniku;


	Trojuhelnik* ukazatel = new Trojuhelnik[pocetTrojuhelniku];

	for (size_t i = 0; i < pocetTrojuhelniku; i++)
	{

		cout << "Trojuhelnik cislo " << i+1 << endl;
		cout << "Zadejte stranu A: " << endl;
		cin >> a;

		cout << "Zadejte stranu B: " << endl;
		cin >> b;

		cout << "Zadejte stranu C: " << endl;
		cin >> c;

		ukazatel[i].a = a;
		ukazatel[i].b = b;
		ukazatel[i].c = c;

		if (ukazatel->lzeSestrojit(ukazatel))
		{
			cout << "Trojuhelnik lze sestrojit, obvod je " << ukazatel->a + ukazatel->b + ukazatel->c << "." << endl;
		}
		else
		{
			cout << "Trojuhelnik nelze sestrojit." << endl;
		}
	}

	cout << "Vypis vsech trojuhelniku: "<< endl;

	for (size_t i = 0; i < pocetTrojuhelniku; i++)
	{
		cout << "Trojuhelnik cislo " << i + 1 << ": " << ukazatel[i].a << ", " << ukazatel[i].b << ", " << ukazatel[i].c << endl;
	}

	delete[] ukazatel;

	return 0;
}