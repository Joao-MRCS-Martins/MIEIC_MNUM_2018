#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

double funcIntDouble(double x, double y) {
	return x + y;//exp(y-x);
}

double sumVertices(double a1,double b1,double a2,double b2) {
	return funcIntDouble(a1, a2) + funcIntDouble(a1, b2) + funcIntDouble(b1, a2) + funcIntDouble(b1, b2);
}

double sumInterm(double a1, double b1, double a2, double b2) {
	return funcIntDouble(b1 / 2, a2) + funcIntDouble(b1 / 2, b2) + funcIntDouble(a1, b2 / 2) + funcIntDouble(b1, b2 / 2);
}

double centralPoint(double b1, double b2) {
	return funcIntDouble(b1 / 2, b2 / 2);
}


double simpson(double a1, double b1, double a2, double b2) {
	double hx = (b1 - a1) / 2;
	double hy = (b2 - a2) / 2;
	return hx * hy / 9 * (sumVertices(a1, b1, a2, b2) + 4 * sumInterm(a1, b1, a2, b2) + 16 * centralPoint(b1,b2));
}
double solSimpson(double a1,double b1,double a2,double b2,int n) {
	
	double hx = abs(b1 - a1) / n;
	double hy = abs(b2 - a2) / n;
	double integral = 0;
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				integral += simpson(a1 + i*hx, a1+(i+1)*hx, a2+j*hy,a2+(j+1)* hy);
			}
		}

	
	return integral;
}

int main() {
	cout << "The equation is: e^(y-x). Change the equation on the function to fit your needs." << endl << "Beware of values uninputtable on the console, like pi or euler's number." << endl;
	double a1, b1, a2, b2;
	int n;
	cout << endl << "Insert intervals of x, a1 & b1, and intervals of y, a2 & b2, and the number of intervals: " << endl;
	cin >> a1 >> b1 >> a2 >> b2 >> n;
	cout << "The solution is : " << solSimpson(a1, b1, a2, b2, n) << endl;
	return 0;
}