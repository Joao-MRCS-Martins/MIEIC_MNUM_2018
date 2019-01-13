#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//exercicio 1

void pp() {
	double x = 0.9;
	int n = 1;
	cout << "x: " << x << endl;
	double xn = x;
	for (int i = 0; i < n; i++) {
		x = 2 * log(2 * x);
		cout << "x: " << x << endl;
	}
	cout << "res: " << x - xn << endl;
	
}

//exercicio 3

double dxdt(double x, double t) {
	return sin(x) + sin(2 * t);
}

double rk4(double h) {
	double t = 1;
	double x = 0;
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	cout << "t: " << t << "\tx: " << x << endl;
	while (t != 1.5) {
		d1 = h * dxdt(x, t);
		d2 = h * dxdt(x + d1 / 2, t + h / 2);
		d3 = h * dxdt(x + d2 / 2, t + h / 2);
		d4 = h * dxdt(x + d3, t + h);

		x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
		cout << "t: " << t << "\tx: " << x << endl;
	}
	return x;
}

//exercicio 5


double z(double x, double y) {
	return 6 * pow(x, 2) - x * y + 12 * y + pow(y, 2) - 8 * x;
}

double dzdx(double x, double y) {
	return 12 * x - y - 8;
}

double dzdy(double x, double y) {
	return -x + 12 + 2 * y;
}

void grad() {
	double xn = 0;
	double yn = 0;
	double x = 0;
	double y = 0;
	double h = 0.25;
	cout << "x: " << x <<"\ty: " << y << "\tz(x,y): " << z(x, y) << "\tdzdx: " << dzdx(x, y) << "\tdzdy: " << dzdy(x, y) << endl;
	x -= h * dzdx(xn, yn);
	y -= h * dzdy(xn, yn);
	cout << "x: " << x <<"\ty: " << y << "\tz(x,y): " << z(x, y) << "\tdzdx: " << dzdx(x, y) << "\tdzdy: " << dzdy(x, y) << endl;
}

int main()
{
	cout << fixed;
	cout.precision(6);
	//pp();
	/*double s1 = rk4(0.5);
	cout << endl;
	double s2 = rk4(0.25);
	cout << endl;
	double s3 = rk4(0.125);
	cout << endl;
	double qc = (s2 - s1) / (s3 - s2);
	cout << "Qc: " << qc << endl;*/
	//grad();
	return 0;
}

