#include <iostream>
#include <cmath>

using namespace std;

//exercicio 2

void gauss_jacobi() {
	double x1 = .25, x2 = .25, x3 = .25, x4 = .25;
	double x11 = x1, x21 = x2, x31 = x3;
	cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	for (int i = 0; i < 2; i++) {
		x1 = (1 + x2 + x3 - x4) / 4.5;
		x2 = (-1 + x11 - x3 + x4) / 4.5;
		x3 = (-1 + x11 - 2 * x21 + x4) / 4.5;
		x4 = (-2 * x11 + x21 + x31) / 4.5;
		x11 = x1;
		x21 = x2;
		x31 = x3;
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	}
}

//exercicio 4

double dT(double T) {
	return -0.25*(T - 45);
}

void euler() {
	double t = 1;
	double T = 23;
	double h = 0.4;
	for (int i = 0; i < 2; i++) {
		T += h * dT(T);
		t += h;
	}
	cout << "T: " << T << endl;
}

int main()
{
	//gauss_jacobi();
	//euler();
	return 0;
}
