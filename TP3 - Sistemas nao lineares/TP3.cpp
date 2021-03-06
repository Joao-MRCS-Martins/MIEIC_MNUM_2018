#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f1dx(double x, double y) {
	return (4 * x - y - 5);
}

double f1dy(double x,double y) {
	return -x;
}

double f2dx(double x, double y) {
	return (1 + 3 / x);
}

double f2dy(double x,double y) {
	return (-2 * y);
}

double f1(double x, double y) {
	return (2 * x*x - x * y - 5 * x + 1);
}

double f2(double x, double y) {
	return (x + 3 * log(x) - y*y);
}

void newtonsisl()
{
	double x, y, e = 0.00001;
	int steps = 0;
	cout << "Select the values of x and y to start interation and the max number of steps: " << endl;
	cin >> x >> y >> steps;
	if (abs(f1(x, y)) <= e && abs(f2(x, y)) <= e) {
		cout << "The solution for x is: " << x << " and the solution for y is: " << y << endl;
		return;
	}
	double x1, y1;
	for (int i = 0; i < steps; i++) {
		
		x1 = x - (f1(x, y)*f2dy(x, y) - f2(x, y)*f1dy(x, y)) / (f1dx(x, y)*f2dy(x, y) - f2dx(x, y)*f1dy(x, y));
		y1 = y - (f2(x, y)*f1dx(x, y) - f1(x, y)*f2dx(x, y)) / (f1dx(x, y)*f2dy(x, y) - f2dx(x, y)*f1dy(x, y));
		if (abs(x1 - x) <= e || abs(y1 - y) <= e)
			break;
		x = x1;
		y = y1;
		if (abs(f1(x, y)) <= e && abs(f2(x, y)) <= e)
			break;
		cout << "N. step: " << i + 1 << ": x = " << x << " && y = " << y << endl;
	}

	cout << "The final solution for x is : " << x << " and the solution for y is: " << y << endl;
	return;
}

double f1pp(double x, double y) {
	return sqrt((x*y + 5 * x - 1) / 2);
}

double f2pp(double x, double y) {
	return sqrt(x + 3 * log(x));
}

double f1dxpp(double x, double y) {
	return (y + 5) / (2 * sqrt(2)*sqrt(x*y + 5 * x - 1));
}

double f1dypp(double x, double y) {
	return (1 / (2 * sqrt(2))*x / sqrt(x*y + 5 * x - 1));
}

double f2dxpp(double x, double y) {
	return (1 + 3 / x) / (2 * sqrt(3 * log(x) + x));
}

double f2dypp(double x, double y) {
	return 0;
}

void ppsisl() {
	double x, y, e = 0.00000001;
	cout << "Select the values of x and y to start interation " << endl;
	cin >> x >> y;
	if (abs(f1(x, y)) <= e && abs(f2(x, y)) <= e) {
		cout << "The solution for x is: " << x << " and the solution for y is: " << y << endl;
		return;
	}
	
	if (!(abs(f1dxpp(x, y)) < 1 || abs(f1dypp(x, y)) < 1 || abs(f2dxpp(x, y)) < 1 || abs(f2dypp(x, y)) < 1)) {
		cout << "It will not converge! " << endl;
		return;
	}
	double x1 = f1pp(x, y);
	double y1 = f2pp(x, y);
	int step = 0;
	while(abs(x1 - x) > e && abs(y1 - y) > e) {
		x = x1;
		y = y1;
		if (abs(f1(x, y)) <= e && abs(f2(x, y)) <= e)
			break;
		cout << "N. interation " << ++step << ": x = " << x << " && y = " << y << endl;
		x1 = f1pp(x, y);
		y1 = f2pp(x, y);
	}
	cout << "The final solution for x is : " << x << " and the solution for y is: " << y << endl;
	return;
}
int main() {
	int method;
	cout << "Which method to use to solve the linear equation sistem? " << endl;
	cout << "1 - Newton or tangent method;" << endl
		<< "2 - Picard-Peano method;" << endl;
	cin >> method;

	switch (method) {
	case 1:
		newtonsisl();
		break;
	case 2:
		ppsisl();
		break;
	}
	return 0;
}

