#include <iostream>
#include <cmath>

using namespace std;

double invert_hessian_gradient_x(double x) {
	return (5*sin(10*x)-x+3)/(50*cos(10*x)-1);
}

double invert_hessian_gradient_y(double x,double y) {
	return ((50*cos(10*x)-1)*y+5*sin(10*x)+(-50*x-150)*cos(10*x)+6)/(50*cos(10*x)-1);
}

double gradient_x(double x,double y) {
	return -2*y-10*sin(10*x)+4*x;
}

double gradient_y( double x,double y) {
	return 2 * (y - x-3);
}

double f(double x, double y) {
	return y*y-2*x*y-6*y+2*x*x+15+cos(10*x);
}


void lm() {
	double x0 = 1;
	double y0 = 1;
	double lambda = 0.1;
	double x=1, y=1;
	int i = 1;
	do {
		x0 = x;
		y0 = y;
		x = x0 - invert_hessian_gradient_x(x0) - lambda * gradient_x(x0,y0);
		y = y0 - invert_hessian_gradient_y(x0,y0) - lambda * gradient_y(x0,y0);

		if (f(x, y) < f(x0, y0)) {
			lambda /= 2;
		}
		else {
			lambda *= 2;
		}
		

		cout << "i: " << i<< "\tx: " << x << "\ty: " << y << "\tf(x,y): " << f(x, y) << endl;
		i++;
	} while (abs(x-x0) > 0.01 && abs(y-y0) > 0.01);
}

int main()
{
	lm();
    return 0;
}

