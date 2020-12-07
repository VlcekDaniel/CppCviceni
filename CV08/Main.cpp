#include "Matrix.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Matrix<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetMatrix(jednodpole);
	Matrix<int> mt = m.Transposition();
	Matrix<int> maa = m.Sum(mt);
	Matrix<int> ma = m.Sum(2);
	Matrix<int> md = m.Product(2);
	Matrix<int> mmt = m.Product(mt);
	Matrix<double> mmt_d = mmt.Retype<double>();
	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetMatrix(jednodpole_d);
	Matrix<double> mmtn_d = mmt_d.Product(n_d);
	Matrix<int> r = mmtn_d.Retype<int>();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetMatrix(tpole);
	cout << "r==t ? " << (r.isSame(t) ? "true" : "false") << endl;
	return 0;
}