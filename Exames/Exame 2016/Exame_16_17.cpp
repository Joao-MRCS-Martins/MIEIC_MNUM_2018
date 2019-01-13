#include <iostream>
#include <cmath>

using namespace std;

//exercicio 2

double f(double x, double y) {
	return pow(x, 2) - y - 1.2;
}

double g(double x, double y) {
	return -x + pow(y, 2) - 1;
}

double fx(double x, double y) {
	return 2 * x;
}

double fy(double x, double y) {
	return -1;
}

double gx(double x, double y) {
	return -1;
}

double gy(double x, double y) {
	return 2 * y;
}

void newt_sist() {
	double xn = 1;
	double yn = 1;
	cout << "xn: " << xn << "\tyn: " << yn << endl;
	double x = 0, y = 0;
	for (int i = 0; i < 2; i++) {
		x = xn - (f(xn, yn)*gy(xn, yn) - g(xn, yn)*fy(xn, yn)) / (fx(xn, yn)*gy(xn, yn) - gx(xn, yn)*fy(xn, yn));
		y = yn - (g(xn, yn)*fx(xn, yn) - f(xn, yn)*gx(xn, yn)) / (fx(xn, yn)*gy(xn, yn) - gx(xn, yn)*fy(xn, yn));
		xn = x;
		yn = y;
		cout << "xn: " << xn << "\tyn: " << yn << endl;
	}
}

//exercicio 4

double f1(double x) {
	return pow(x, 7) + 0.5*x - 0.5;
}

void corda() {
	double xe = 0;
	double xd = 0.8;
	double xn = (xe*f1(xd)-xd*f1(xe))/(f1(xd)-f1(xe));
	cout << "xe: " << xe << "\txd: " << xd << "\txn: " << xn << "\tf(xe): " << f1(xe) << "\tf(xd): " << f1(xd) << "\tf(xn): " << f1(xn) << endl;
	for (int i = 0; i < 3; i++) {
		
		if (f1(xe)*f1(xn) < 0) {
			xd = xn;
		}
		else {
			xe = xn;
		}
		xn = (xe*f1(xd) - xd * f1(xe)) / (f1(xd) - f1(xe));
		cout << "xe: " << xe << "\txd: " << xd << "\txn: " << xn << endl;
	}

}

//exercicio 5

//segunda derivada
double f3(double z, double t) {
	return 0.5 + pow(t, 2) + t * z;
}

//primeira derivada dy/dt = z
double f4(double z) {
	return z;
}

void euler() {
	double h = 0.25;
	double t = 0;
	double y = 0;
	double z = 1;
	cout << "t: " << t << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		y += h * f4(z);
		z += h * f3(z, t);
		t += h;
		cout << "t: " << t << "\ty: " << y << endl;
	}
}

void rk4() {
	double h = 0.25;
	double t = 0;
	double y = 0;
	double z = 1;
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	double e1 = 0, e2 = 0, e3 = 0, e4 = 0;
	cout << "t: " << t << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		d1 = h * f3(z, t);
		d2 = h * f3(z+d1/2, t+h/2);
		d3 = h * f3(z+d2/2, t+h/2);
		d4 = h * f3(z+d3, t+h);
		e1 = h * f4(z);
		e2 = h * f4(z+d1/2);
		e3 = h * f4(z+d2/2);
		e4 = h * f4(z + d3);

		z += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		y += e1 / 6 + e2 / 3 + e3 / 3 + e4 / 6;
		t += h;

		cout << "t: " << t << "\ty: " << y << endl;
	}
}

//exercicio 6

double l(double x) {
	return sqrt(1 + pow(1.5*exp(1.5*x), 2));
}

double trap(double h) {
	double x = 0;
	double i = 0;
	int n = 2 / h; // b-a = 2
	for (int j = 0; j <= n;j++) {
		if (j == 0 || j == n) {
			i += h / 2 * l(x);
		}
		else {
			i += h * l(x);
		}
		x += h;
	}
	return i;
}

void trapeze() {
	double s = trap(0.5);
	double s1 = trap(0.25);
	double s2 = trap(0.125);
	double qc = (s1 - s) / (s2 - s1);
	double err = (s2 - s1) / 3;
	cout << "L1 : " << s << "\tL2: " << s1 << "\tL3: " << s2 << endl << "Qc: " << qc << "\tErro: " << err << endl;
}

double simp(double h) {
	double x = 0;
	double i = 0;
	int n = 2 / h; // b-a = 2
	for (int j = 0; j <= n; j++) {
		if (j == 0 || j == n) {
			i += h / 3 * l(x);
		}
		else if(j%2 ==0) {
			i += 2*h/3 * l(x);
		}
		else {
			i += 4 * h / 3 * l(x);
		}
		x += h;
	}
	return i;
}

void simpson() {
	double s = simp(0.5);
	double s1 = simp(0.25);
	double s2 = simp(0.125);
	double qc = (s1 - s) / (s2 - s1);
	double err = (s2 - s1) / 15;
	cout << "L1 : " << s << "\tL2: " << s1 << "\tL3: " << s2 << endl << "Qc: " << qc << "\tErro: " << err << endl;
}

int main()
{
	//newt_sist();
	//corda();
	//euler();
	//rk4();
	//trapeze();
	//simpson();
	return 0;
}
