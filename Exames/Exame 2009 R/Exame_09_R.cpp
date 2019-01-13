#include <cmath>
#include <iostream>

using namespace std;

//exercicio 3
double w(double x, double y) {
	return -1.7*x*y + 12 * y + 7 * pow(x, 2) - 8 * x;
}

double wdx(double x, double y) {
	return -1.7*y + 14 * x - 8;
}

double wdy(double x, double y) {
	return -1.7 * x + 12;
}

void gradient() {
	double x0 = 2.4;
	double y0 = 4.3;
	double lambda = 0.1;
	double x = x0 - lambda * wdx(x0, y0);
	double y = y0 - lambda * wdy(x0, y0);
	if (w(x, y) < w(x0, y0)) {
		x0 = x;
		y0 = y;
		lambda *= 2;
	}
	else {
		lambda /= 2;
	}
	cout << "x: " << x0 << "\ty: " << y0 << "\tw(x,y): "<< w(x0,y0) << endl;

}

//exercicio 5

double f1(double x, double y) {
	return pow(x, 2) - y - 2;
}

double f1x(double x, double y) {
	return 2 * x;
}

double f1y(double x, double y) {
	return -1;
}

double f2(double x, double y) {
	return -x + pow(y, 2) - 2;
}

double f2x(double x, double y) {
	return -1;
}

double f2y(double x, double y) {
	return 2 * y;
}

void newton() {
	double xn = 1.5;
	double yn = 0.8;
	int n = 2;
	double x = 0, y = 0;
	cout << "xn: " << xn << "\tyn: " << yn << endl;
	while (n > 0) {
		x = xn - (f1(xn, yn)*f2y(xn, yn) - f2(xn, yn)*f1y(xn, yn)) / (f1x(xn, yn)*f2y(xn, yn) - f2x(xn, yn)*f1y(xn, yn));
		y = yn - (f2(xn,yn)*f1x(xn,yn)-f1(xn,yn)*f2x(xn,yn))/ (f1x(xn, yn)*f2y(xn, yn) - f2x(xn, yn)*f1y(xn, yn));
		xn = x;
		yn = y;
		n--;
		cout << "xn: " << xn << "\tyn: " << yn << endl;
	}

}

int main()
{
	//gradient();
	//newton();
	return 0;
}
