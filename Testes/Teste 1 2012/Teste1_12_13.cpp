#include <iostream>
#include <cmath>

using namespace std;

//exercicio 5

double f(double x) {
	return pow(x, 3) + 2 * x*x + 10 * x - 17;
}

double df(double x) {
	return 3 * x*x + 4 * x + 10;
}

void newt() {
	double x = 0;
	cout << "x: " << x << endl;
	for (int i = 0; i < 2; i++) {
		x -= f(x) / df(x);
		cout << "x: " << x << endl;
	}
}

//exercicio 6

double g(double x, double y) {
	return y - log(x - 1);
}

double gx(double x) {
	return -1 / (x - 1);
}

double gy() {
	return 1;
}

double h(double x, double y) {
	return y * y + pow(x - 3, 2) - 4;
}

double hx(double x) {
	return 2 * (x - 3);
}

double hy(double y) {
	return 2 * y;
}

void newt_sist() {
	double xn = 1.5;
	double yn = 1.3;
	cout << "xn: " << xn << "\tyn: " << yn << endl;
	double x = 0, y = 0;
	for (int i = 0; i < 2; i++) {
		x = xn - (g(xn, yn)*hy(yn) - h(xn, yn)*gy()) / (gx(xn)*hy(yn) - hx(xn)*gy());
		y = yn - (h(xn, yn)*gx(xn) - g(xn, yn)*hx(xn)) / (gx(xn)*hy(yn) - hx(xn)*gy());
		xn = x;
		yn = y;
		cout << "xn: " << xn << "\tyn: " << yn << endl;
	}
}
int main()
{
	//newt();
	//newt_sist();
	return 0;
}

