
#include <iostream>
#include "Trojuhelnik.cpp"


using namespace std;

int main(int argc, char** argv) {

	int a, b, c;

	cout << "Zadejte stranu A: " << endl;
	cin >> a;

	cout << "Zadejte stranu B: " << endl;
	cin >> b;

	cout << "Zadejte stranu C: " << endl;
	cin >> c;

	Trojuhelnik trojuhelnik(a, b, c);

	Trojuhelnik* ukazatel = &trojuhelnik;

	ukazatel->a = a;
	ukazatel->b = b;
	ukazatel->c = c;

	if (trojuhelnik.lzeSestrojit(ukazatel))
	{
		cout << "Trojuhelnik lze sestrojit, obvod je " << ukazatel->a+ukazatel->b+ukazatel->c << "." << endl;
	}
	else
	{
		cout << "Trojuhelnik nelze sestrojit." << endl;
	}
	return 0;
}