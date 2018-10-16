#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

double funcIntDouble(double x, double y) {
	return exp(y-x);
}

double sumVertices(double a1,double b1,double a2,double b2) {
	return funcIntDouble(a1, a2) + funcIntDouble(a1, b2) + funcIntDouble(b1, a2) + funcIntDouble(b1, b2);
}

double sumInterm(double a1, double hx, double a2, double hy, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i > 0 || i < (n - 1)) && (j > 0 || i < (n - 1)))
				continue;
			else
				sum += funcIntDouble(a1 + i * hx, a2 + j * hy);
		}
	}
	return sum;
}

double centralPoint(double a1, double hx, double a2, double hy, int n) {
	double sum = 0;
	for (int i = 1; i < (n - 1); i++) {
		for (int j = 1; j < (n - 1); j++) {
			sum += funcIntDouble(a1 + i * hx, a2 + j * hy);
		}
	}
	return sum;
}

double solTrapeze(double a1,double b1,double a2,double b2,int n) {
	double hx = (b1 - a1) / n;
	double hy = (b2 - a2) / n;
	return hx*hy / 4 * (sumVertices(a1,b1,a2,b2) + 2 * sumInterm(a1, hx, a2, hy, n) + 4 * centralPoint(a1, hx, a2, hy, n));
}

double solSimpson(double a1, double b1, double a2, double b2, int n) {
	double hx = (b1 - a1) / n;
	double hy = (b2 - a2) / n;
	return hx*hy / 9 * (sumVertices(a1, b1, a2, b2) + 4 * sumInterm(a1, hx, a2, hy, n) + 16 * centralPoint(a1, hx, a2, hy, n));
}

int main() {
	int method;
	cout << "The equation is: e^(y-x). Change the equation on the function to fit your needs." << endl << "Beware of values uninputtable on the console, like pi or euler's number." << endl;
	cout << "Which numerical method you want to use to solve the double integral? " << endl << endl;
	cout << "1 - Trapeze method." << endl
		<< "2 - Simspson method." << endl;
	cout << "-> ";
	cin >> method;
	
	double a1, b1, a2, b2;
	int n;
	cout << endl << "Insert intervals of x, a1 & b1, and intervals of y, a2 & b2, and the number of intervals: " << endl;
	cin >> a1 >> b1 >> a2 >> b2 >> n;
	switch (method) {
	case 1:
		cout << "The solution is : " << solTrapeze(a1,b1,a2,b2,n) << endl;
		break;
	case 2:
		cout << "The solution is : " << solSimpson(a1, b1, a2, b2, n) << endl;
		break;
	}
	return 0;
}