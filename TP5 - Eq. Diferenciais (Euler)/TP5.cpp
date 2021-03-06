#include <iostream>
#include <cmath>

using namespace std;

double dydx(double x, double y) {
	return x * x + y * y;
}

int Euler()
{
	double sol_0 = 0;
	double sol_1 = 0;
	double sol_2 = 0;
	double a = 0;
	double b = 1.4;
	double h = 0.1;
	for (int j = 0; j < 3; j++) {
		int i = 0;
		double x1 = 0;
		double y1 = 0;
		double x0 = 0;
		double y0 = 0;
		while (x0 <= 1.3999) {
			x1 = x0 + h;
			y1 = y0 + h * dydx(x0, y0);
			x0 = x1;
			y0 = y1;
			cout << "Xn: " << x0 << " Yn: " << y0 << " Xn+1: " << x1 << " Yn+1: " << y1 << endl << endl;
		}
		if (j == 0) {
			sol_0 = y0;
			cout << endl << endl;
		}
		else if (j == 1) {
			sol_1 = y0;
			cout << endl << endl;
		}
		else {
			sol_2 = y0;
			cout << endl << endl;
		}
		h /= 2;
	}
	cout << "S: " << sol_0 << " S': " << sol_1 << " S'': " << sol_2 << endl;
	double qc = (sol_1 - sol_0) / (sol_2 - sol_1);
	if (abs(2 - qc) < 0.5)
		cout << "Passo adequado. Qc: " << qc << " ." << endl;
	else
		cout << "Passo inadeaquado. Qc muito diferente de 2." << endl;
	double erro = sol_2 - sol_1;
	cout << "Erro: " << erro << endl;

    return 0;
}

int main() {
	Euler();
	return 0;
}

