#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1

double f1(double x) {
	return x - 2.6 + pow(cos(x + 1.1), 3);
}

double f1x(double x) {
	return 1 - 3 * sin(x + 1.1)*pow(cos(x + 1.1), 2);
}

void newt() {
	double x = 1.8;
	x -= f1(x) / f1x(x);
	cout << "x: " << x << endl;
}

//exercicio 4

double f(double x) {
	return 5 * cos(x) - sin(x);
}

void aurea() {
	int n = 2;
	double h = 2;
	double x1 = 2;
	double x2 = 4;
	double B = (sqrt(5) - 1) / 2;
	double A = B * B;
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);
	cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << "\tf(x1): " << f(x1) << "\tf(x2): " << f(x2) << "\tf(x3): " << f(x3) << "\tf(x4): " << f(x4) << endl;
	while (n > 0) {
		if (f(x3) < f(x4)) {
			x2 = x4;
			x4 = x3;
			x3 = x1 + A * (x2 - x1);
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = x1 + B * (x2 - x1);
		}
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << "\tf(x1): " << f(x1) << "\tf(x2): " << f(x2) << "\tf(x3): " << f(x3) << "\tf(x4): " << f(x4) << endl;
		n--;
	}
}

//exercicio 5

double f(double x, double t) {
	return sin(x) + sin(2 * t);
}

void rk4() {
	double x = 1;
	double t = 1;
	double h = 0.5;

	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	cout << "t: " << t << "\tx: " << x << endl;
	for (int i = 0; i < 1; i++) {
		d1 = h * f(x, t);
		d2 = h * f(x + d1 / 2, t + h / 2);
		d3 = h * f(x + d2 / 2, t + h / 2);
		d4 = h * f(x + d3, t + h);
		x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
		cout << "t: " << t << "\tx: " << x << endl;
	}
	cout << endl;

	double s = x;
	x = 1;
	t = 1;
	h = 0.25;
	cout << "t: " << t << "\tx: " << x << endl;

	for (int i = 0; i < 2; i++) {
		d1 = h * f(x, t);
		d2 = h * f(x + d1 / 2, t + h / 2);
		d3 = h * f(x + d2 / 2, t + h / 2);
		d4 = h * f(x + d3, t + h);
		x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
		cout << "t: " << t << "\tx: " << x << endl;
	}
	cout << endl;
	double s1 = x;
	x = 1;
	t = 1;
	h = 0.125;
	cout << "t: " << t << "\tx: " << x << endl;
	for (int i = 0; i < 4; i++) {
		d1 = h * (x, t);
		d2 = h * f(x + d1 / 2, t + h / 2);
		d3 = h * f(x + d2 / 2, t + h / 2);
		d4 = h * f(x + d3, t + h);
		x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
		cout << "t: " << t << "\tx: " << x << endl;
	}

	double s2 = x;
	double qc =  (s1 - s)/ (s2 - s1);
	cout << "Qc: " << qc << endl;
}

int main()
{
	//newt();
	//aurea();
	//rk4();
	return 0;
}
