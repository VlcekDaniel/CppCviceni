using namespace std;

struct Trojuhelnik{

	int a, b, c;

	Trojuhelnik(int a, int b , int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	bool lzeSestrojit(Trojuhelnik t) {
		if (a + b > c && a + c > b && b + c > a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};