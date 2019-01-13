#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1

//d2xdt2 = this
double f2(double z, double x,double k) {
	return -z / 20 - k * x / 20;
}

//dxdt = z
double f1(double z) {
	return z;
}

void euler() {
	double t = 0;
	double z = 0;
	double x = 1; //pelo grafico
	double h = 0.1; //pelo grafico
	double k = 20; // decidir entre 5,20 ou 40 e comparar resultados
	cout << "t: " << t << "\tx: " << x << endl;
	while (t <= 5) {
		x += h * f1(z);
		z += h * f2(z, x, k);
		t += h;

		cout << "t: " << t << "\tx: " << x << endl;
	}
}


//exercicio 2

double g(double x) {
	return -x + 40 * cos(sqrt(x)) + 3;
}

double gx(double x) {
	return -1 - 20 * sin(sqrt(x)) / sqrt(x);
}

void newton() {
	double xn = 1.7;
	cout << "xn: " << xn << "\tg(xn): " << g(xn) << endl;
	for (int i = 0; i < 2; i++) {
		xn -= g(xn) / gx(xn);
		cout << "xn: " << xn << "\tg(xn): " << g(xn) << endl;
	}
}

// exercicio 5

double y(double x) {
	return 5 * cos(x) - sin(x);
}

void aurea() {
	double x1 = 2;
	double x2 = 4;
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);
	cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4;
	cout << "\ty(x1): " << y(x1) << "\ty(x2): " << y(x2) << "\ty(x3): " << y(x3) << "\ty(x4): " << y(x4) << endl;
	for (int i = 0; i < 2; i++) {
		if (y(x3) < y(x4)) {
			x2 = x4;
			x4 = x3;
			x3 = x1 + A * (x2 - x1);
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = x1 + B * (x2 - x1);
		}
			cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4;
			cout << "\ty(x1): " << y(x1) << "\ty(x2): " << y(x2) << "\ty(x3): " << y(x3) << "\ty(x4): " << y(x4) << endl;
	}
}

int main()
{
	//euler();
	//newton();
	//aurea();
	return 0;
}