#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

double funcIntDouble(double x, double y) {
	return exp(y - x);
}

//n=2 a=0 b=0.5 h=b-a/2 hx=hy=0.25

double sumVertices() {
	double sum = funcIntDouble(0, 0) + funcIntDouble(0, 0.5) + funcIntDouble(0.5, 0) + funcIntDouble(0.5, 0.5);
	return sum;
}

double sumInterm() {
	double sum = funcIntDouble(0, 0.25) + funcIntDouble(0.25, 0) + funcIntDouble(0.5, 0.25) + funcIntDouble(0.25, 0.5);
	return sum;
}

double centralPoint() {
	return funcIntDouble(0.25, 0.25);
}

double solTrapeze() {
	return 0.25*0.25 / 4 * (sumVertices() + 2 * sumInterm() + 4 * centralPoint());
}