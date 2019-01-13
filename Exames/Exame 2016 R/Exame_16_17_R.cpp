#include <iostream>
#include <cmath>

using namespace std;

//exercicio 2

double f(double x) {
	return log(pow(x + 1, log(x + 1)));
}

void simpson() {
	double h = 0.5;
	double n = 4; //b-a = 2
	double s = 0;
	double x = 3;
	cout << "x: " << x << "\tf(x): " << f(x) << endl;
	for (int i = 0; i < n; i++) {
		
		if (i == 0 || i == n) {
			s += h / 3 * f(x);
		}
		else if (i % 2 == 0) {
			s += 2 * h / 3 * f(x);
		}
		else {
			s += 4 * h / 3 * f(x);
		}
		x += h;
		cout << "x: " << x << "\tf(x): " << f(x) << endl;
	}
	cout << "I: " << s << endl;
}

//exercicio 3

double f1(double x) {
	return -12 + pow(x, 3) + 12.005*cos(2 * x);
}

double f1x(double x) {
	return 3 * pow(x, 2) - 24.01*sin(2 * x);
}

void newton() {
	double xn = 3;
	double x = 3;
	cout << "xn: " << xn << endl;
	do {
		xn = x;
		x = xn - f1(xn)/f1x(xn);
		cout << "xn: " << xn << endl;
	} while (abs(x - xn) > 0.00001);
}

//exercicio 5

double w(double x, double y) {
	return 6 * pow(x, 2) - 1.7*x*y + 12 * y + pow(y, 2) - 8 * x;
}

double wx(double x, double y) {
	return 12 * x - 1.7*y - 8;
}

double wy(double x, double y) {
	return -1.7*x + 12 + 2 * y;
}

void gradient() {
	double xn = 3.9;
	double yn = 3.8;
	double h = 0.1;
	int n = 1;
	double x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		x = xn - h * wx(xn, yn);
		y = yn - h * wy(xn, yn);
		xn = x;
		yn = y;
		cout << "xn: " << xn << "\tyn: " << yn << "\tw(xn,yn): " << w(xn, yn) << endl;
	}
}

//exercicio 6

double dx(double x, double t) {
	return sin(2 * x) + sin(2 * t);
}

double rk4(double h) {
	double t = 1;
	double x = 0;
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	cout << "t: " << t << "\tx: " << x << endl;
	while (t < 1.5) {
		d1 = h * dx(x, t);
		d2 = h * dx(x + d1 / 2, t + h / 2);
		d3 = h * dx(x + d2 / 2, t + h / 2);
		d4 = h * dx(x + d3, t + h);
		x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
		cout << "t: " << t << "\tx: " << x << endl;
	}
	return x;
}

void range_kutta() {
	double s = rk4(0.5);
	cout << endl;
	double s1 = rk4(0.25);
	cout << endl;
	double s2 = rk4(0.125);
	cout << endl;
	double qc = (s1 - s) / (s2 - s1);
	cout << "QC: " << qc << endl;
	if (abs(16 - qc) < 0.001) {
		cout << "Passo adequado." << endl;
	}
	else
		cout << "Passo inadequado. Usar passo h''/2." << endl;
}

int main()
{
	//cout << fixed;
	//cout.precision(7);
	//simpson();
	//newton();
	//gradient();
	//range_kutta();
	return 0;
}

