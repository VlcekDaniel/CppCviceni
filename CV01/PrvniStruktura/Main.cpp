#include <iostream>
#include "Trojuhelnik.cpp"


using namespace std;

int main() {

	int a, b, c;

	cout << "Zadejte stranu A: " << endl;
	cin >> a;

	cout << "Zadejte stranu B: " << endl;
	cin >> b;

	cout << "Zadejte stranu C: " << endl;
	cin >> c;

	Trojuhelnik trojuhelnik(a,b,c);

	if (trojuhelnik.lzeSestrojit(trojuhelnik))
	{
		cout << "Trojuhelnik lze sestrojit, obvod je " << a + b + c << "." << endl;
	}
	else
	{
		cout << "Trojuhelnik nelze sestrojit." << endl;
	}
	return 0;	
}