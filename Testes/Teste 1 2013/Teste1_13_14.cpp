#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1

double f(double x) {
	return exp(0.7*x) - x * x - 0.5;
}

void bissec() {
	double a = -1;
	double b = 0;
	double m = 0;
	for (int i = 0; i < 3; i++) {
		m = (a + b) / 2;
		cout << "a: " << a << "\tb: " << b << "\tm: " << m << "\tf(a): " << f(a) << "\tf(b): " << f(b) << "\tf(m): " << f(m) << endl;
		
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}
	cout << "Erro abs: " << abs(b - a) << endl;
}

//exercicio 2

double f(double x, double y) {
	return x * x - y - 1.2;
}

double fx(double x) {
	return 2 * x;
}

double fy() {
	return -1;
}

double g(double x, double y) {
	return -x + y * y - 0.5;
}

double gx() {
	return -1;
}

double gy(double y) {
	return 2 * y;
}

void newt_sist() {
	double xn = 1.1;
	double yn = 1.1;
	double x = 0, y = 0;
	cout << "x: " << x << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		x = xn - (f(xn, yn)*gy(yn) - g(xn, yn)*fy()) / (fx(xn)*gy(yn) - gx()*fy());
		y = yn - (g(xn,yn)*fx(xn)-f(xn,yn)*gx()) / (fx(xn)*gy(yn) - gx()*fy());
		xn = x;
		yn = y;
		cout << "x: " << x << "\ty: " << y << endl;
	}
}
int main()
{
	//bissec();
	//newt_sist();
	return 0;
}
