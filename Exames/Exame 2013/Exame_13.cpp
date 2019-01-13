#include <iostream>
#include <cmath>

using namespace std;

//exercicio 3

double f1(double x, double z,double k) {
	return -z / 20 - k * x / 20;
}

double f2(double z) {
	return z;
}

void euler() {
	double t = 0;
	double z = 0;
	double x = 1;
	double h = 0.2;
	double k = 5;
	double xn = 1;
	cout << "t: " << t << "\tx: " << xn << endl;
	while (t <= 5) {

		x = xn + h * f2(z);
		z += h * f1(x, z, k);
		xn = x;
		t += h;
		cout << "t: " << t << "\tx: " << xn << endl;
	}
}

//exercicio 6

double y(double x) {
	return 5*cos(x)-sin(x);
}

void aurea() {
	double x1 = 2;
	double x2 = 4;
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);
	cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << "\tf(x1): " << y(x1) << "\tf(x2): " << y(x2) << "\tf(x3): " << y(x3) << "\tf(x4): " << y(x4) << endl;
	int n = 2;
	while (n > 0) {
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
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << "\tf(x1): " << y(x1) << "\tf(x2): " << y(x2) << "\tf(x3): " << y(x3) << "\tf(x4): " << y(x4) << endl;
		n--;
	}
}

//exercicio 7

double g(double x) {
	return -x + 60 * cos(sqrt(x)) + 2;
}

double dgdx(double x) {
	return -1 - 30 * sin(sqrt(x)) / sqrt(x);
}

void newt() {
	double x = 1.8;
	int n = 2;
	cout << "x: " << x << "\tg(x): " << g(x) << endl;
	while (n > 0) {
		x -= g(x) / dgdx(x);
		cout << "x: " << x << "\tg(x): " << g(x) << endl;
		n--;
	}
}
int main()
{
	//euler();
	//aurea();
	//newt();
	return 0;
}
