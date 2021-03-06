#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//The function used for simplicity reasons is x-x^2
double func(double x) {
	return (x - pow(x,2));
}

//The derivated function is known and its 1 - 2*x
double funcderiv(double x) {
	return (1 - 2 * x);
}

//This is the criteria for continuing the interaction. Only applied to the bissection method and regula-falsi method.
bool criteria(double error, double a, double b, double x) {
	if (abs(b - a) < error)
		return false;
	if (abs(func(x)) < error)
		return false;
	else return true;
}

void bissection()
{
	double a, b, y, x;
	double e = 0.001;
	int steps;
	cout << "Select the interval [a,b], and number of steps for the function: ";
	cin >> a >> b >> steps;
	x = (a + b) / 2;
	for (int i = 0; criteria(e,a,b,x) || i < steps; i++) {
		
		y = func(x);
		if (abs(y) < e)
			break;
		if (func(a)*y < 0)
			b = x;
		else a = x;
		cout << setprecision(3) << "Intermediate solution: " << x << endl;
		x = (a + b) / 2;
	}

	cout << setprecision(3) <<  "The final solution is: " << x << endl;
	return;
}

void newton() {
	double a, y, x, e = 0.001;
	int steps;
	cout << "Select the guess, x0, and number of steps for the function: ";
	cin >> a >> steps;
	x = a - func(a) / funcderiv(a);
	if (func(x) < e) {
		cout << "The solution is: " << setprecision(3) << x << endl;
		return;
	}
	cout << "First solution is: " << x << endl;
	for (int i = 0; abs(a-x) >= e || i < steps; i++) {

		y = func(x);
		if (abs(y) < e)
			break;
		a = x;
		x = a - func(a) / funcderiv(a);
		cout << setprecision(3) << "Intermediate solution: " << x << endl;

	}

	cout << setprecision(3) << "The final solution is: " << x << endl;
	return;
}

void regulafalsi() {
	double a, b, y, x;
	double e = 0.001;
	int steps;
	
	cout << "Select the interval [a,b], and number of steps for the function: ";
	cin >> a >> b >> steps;
	
	x = (a * func(b) - b * func(a)) / (func(b) - func(a));
	if (x < e) {
		cout << "The solution is: " << setprecision(3) << x << endl;
		return;
	}
	cout << "First solution is: " << x << endl;

	for (int i = 0; criteria(e, a, b, x) || i < steps; i++) {

		y = func(x);
		if (abs(y) < e)
			break;
		if (func(a)*y < 0)
			b = x;
		else a = x;
		cout << setprecision(3) << "Intermediate solution: " << x << endl;
		x = (a * func(b) - b * func(a)) / (func(b) - func(a));
	}

	cout << setprecision(3) << "The final solution is: " << x << endl;
	return;
}

void picardpeano() {
	double a,x, e = 0.001;
	int steps;
	cout << "Select the guess, x0, and number of steps for the function: ";
	cin >> a >> steps;
	x = func(a);

	if (func(x) < e) {
		cout << "The solution is: " << setprecision(3) << x << endl;
		return;
	}

	cout << "First solution is: " << x << endl;
	for (int i = 0; abs(a - x) >= e || i < steps; i++) {
		a = x;
		x = func(a);
		if (x < e)
			break;
		cout << setprecision(3) << "Intermediate solution: " << x << endl;

	}

	cout << setprecision(3) << "The final solution is: " << x << endl;
	return;
}

int main() {
	
	cout << "Select the method of resolving equations you want (number): " << endl 
		 << "The error associated is 0.001" << endl
		 << " 1 - bissection method" << endl
		 << " 2 - newton method" << endl
		 << " 3 - regula-falsi method" << endl
		 << " 4 - picard-peano method" << endl;

	int n;
	cin >> n;
	switch (n) {
	case 1 : 
		bissection();
		break;
	case 2 :
		newton();
		break;
	case 3 :
		regulafalsi();
		break;
	case 4 :
		picardpeano();
		break;
	default :
		cerr << "Invalid number!" << endl;
		return 1;
	}

	return 0;
}