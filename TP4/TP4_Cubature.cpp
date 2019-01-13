#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double funcIntDouble(double x, double y) {
	return exp(y-x);
}

double sumVertices(double a1,double b1,double a2,double b2) {
	return 1.1+2.4+3.5+1.2;
}

double sumInterm(double a1, double b1, double a2, double b2) {
	return 2.1+1.4+1.5+2.2;
}

double centralPoint(double b1, double b2) {
	return 1.5;
}


double simpson(double a1, double b1, double a2, double b2) {
	double hx = (b1 - a1) / 2;
	double hy = (b2 - a2) / 2;
	cout << " a1: " << a1 << " b1: " << b1 << " a2: " << a2 << " b2: " << b2 << " hx: " << hx << " hy: " << hy << endl;
	return hx * hy / 4 * (sumVertices(a1, b1, a2, b2) + 2* sumInterm(a1, b1, a2, b2) + 4 * centralPoint(b1,b2));
}
double solSimpson(double a1,double b1,double a2,double b2,int n) {
	
	double hx = abs(b1 - a1) / n;
	double hy = abs(b2 - a2) / n;
	double integral = 0;
	for (int i = 0; i < (n/2); i++) {
		for (int j = 0; j < (n/2); j++) {
			integral += simpson(a1 + 2*i * hx, a1 + 2*(i + 1)*hx, a2 + 2*j * hy, a2 + 2*(j + 1)* hy);
		}
	}
	
	return integral;
}

int main() {
	cout << fixed;
	cout.precision(3);
	cout << "The equation is: e^(y-x). Change the equation on the function to fit your needs." << endl << "Beware of values uninputtable on the console, like pi or euler's number." << endl;
	double a1, b1, a2, b2;
	int n;
	cout << endl << "Insert intervals of x, a1 & b1, and intervals of y, a2 & b2, and the number of intervals: " << endl;
	cin >> a1 >> b1 >> a2 >> b2 >> n;
	cout << "The solution is : " << solSimpson(a1, b1, a2, b2, n) << endl;
	return 0;
}