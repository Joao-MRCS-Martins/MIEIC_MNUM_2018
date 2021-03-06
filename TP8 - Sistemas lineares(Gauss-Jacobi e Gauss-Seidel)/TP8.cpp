#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x0 = 5;
	double y0 = 5;
	double z0 = 5;
	double xn, yn, zn;
	//number of iterations
	int n =10;
	//GAUSS-SEIDEL
	for (int i = 0; i < n; i++) {
		xn = (11 - 2*y0 - z0)/4;
		yn = (10 - xn - z0)/3;
		zn = (19 - 2*xn - yn)/5;
		x0 = xn;
		y0 = yn;
		z0 = zn;
	}

	//GAUSS-JACOBI
	/*
	for (int i = 0; i < n; i++) {
		xn = (11 - 2 * y0 - z0) / 4;
		yn = (10 - x0 - z0) / 3;
		zn = (19 - 2 * x0 - y0) / 5;
		x0 = xn;
		y0 = yn;
		z0 = zn;
	}
	*/
	cout << "xn: " << xn << "\tyn: " << yn << "\tzn: " << zn << endl;
	return 0;
}

