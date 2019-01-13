#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//exercicio 1

double f1(double z, double t) {
	return 0.5 + pow(t, 2) + t * z;
}

double f2(double z) {
	return z;
}

void euler() {
	double h = 0.25;
	double t = 0;
	double y = 0;
	double zn = 1;
	double z = 0;
	cout << "t: " << t << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		z += h * f1(zn, t);
		y += h * f2(zn);
		t += h;
		zn = z;
		cout << "t: " << t << "\ty: " << y << endl;
	}
}

void rk4() {
	double h = 0.25;
	double t = 0;
	double y = 0;
	double zn = 1;
	double z = 0;
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	double e1 = 0, e2 = 0, e3 = 0, e4 = 0;
	cout << "t: " << t << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		d1 = h * f1(zn, t);
		e1 = h * f2(zn);
		
		d2 = h * f1(zn + d1 / 2, t + h / 2);
		e2 = h * f2(zn + e1 / 2);
		
		d3 = h * f1(zn + d2 / 2, t + h / 2);
		e3 = h * f2(zn + e2 / 2);
		
		d4 = h * f1(zn + d3, t + h);
		e4 = h * f2(zn + e3);

		z = zn + d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		y += e1 / 6 + e2 / 3 + e3 / 3 + e4 / 6;

		zn = z;
		cout << "t: " << t << "\ty: " << y << endl;

	}
}

//exercicio 3


double z(double x, double y) {
	return 3 * pow(x, 2) - x * y + 11 * y + pow(y, 2) - 8 * x;
}

double dzdx(double x, double y) {
	return 6 * x - y - 8;
}

double dzdy(double x, double y) {
	return -x + 11 + 2 * y;
}

void grad() {
	double xn = 2;
	double yn = 2;
	double x = 0, y = 0;
	double h = 0.5;
	cout << "x: " << xn <<"\ty: " << yn << "\tz(x,y): " << z(xn, yn) << "\tdzdx: " << dzdx(xn, yn) << "\tdzdy: " << dzdy(xn, yn) << endl;
	int n = 0;
	while (n != 1) {
		x = xn - h* dzdx(xn, yn);
		y = yn - h* dzdy(xn, yn);
		if (z(x, y) < z(xn, yn)) {
			
			xn = x;
			yn = y;
			h *= 2;
			
		}
		else {
			h /= 2;
		}
		cout << "x: " << xn << "\ty: " << yn << "\tz(x,y): " << z(xn, yn) << "\tdzdx: " << dzdx(xn, yn) << "\tdzdy: " << dzdy(xn, yn) << endl;
		n++;
	}
}

//exercicio 4

double f5(double x) {
	return exp(1.5*x);
}

double simp(double h) {
	double x = 1;
	double y = 0;
	int n = 0.5 / h;
	
	for(int i =0; i<=n; i++) {
		if (i == 0 || i == n) {
			y += h / 3 * f5(x+i*h);
		}
		else if (i % 2 == 0) {
			y += 2 * h / 3 * f5(x + i * h);
		}
		else {
			y += 4 * h / 3 * f5(x + i * h);
		}

	}
	return y;
}

void simpson() {
	double s = simp(0.125);
	double s1 = simp(0.0625);
	double s2 = simp(0.03125);
	cout << "h: " << 0.125 << "\ts: " << s << endl;
	cout << "h': " << 0.0625 << "\ts': " << s1 << endl;
	cout << "h'': " << 0.03125 << "\ts'': " << s2 << endl;
	cout << "qc: " << (s1 - s) / (s2 - s1) << "\tErr: " << (s2 - s1) / 15 << endl;

}

//exercicio 5

double f6(double x) {
	return x - 3.7 + pow(cos(x + 1.2), 3);
}

double df6dx(double x) {
	return 1 - 3 * sin(x + 1.2) * pow(cos(x + 1.2), 2);
}

void newt() {
	double x = 3.8;
	x =3.8 -   f6(x) / df6dx(x);
	cout << x << endl;
}

int main()
{
	cout << fixed;
	cout.precision(6);
	//euler();
	//rk4();
	//grad();
	//simpson();
	//newt();
	return 0;
}
