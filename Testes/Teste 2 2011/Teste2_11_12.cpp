#include <iostream>
#include <cmath>

using namespace std;

//exercicio 2

void gauss_seidel() {
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	for (int i = 0; i < 2; i++) {
		x1 = (1 + x2 + x3 - x4) / 4.8;
		x2 = (-1 + x1 - x3 + x4) / 4.8;
		x3 = (-1 + x1 - 2 * x2 + x4) / 4.8;
		x4 = (-2 * x1 + x2 + x3) / 4.8;
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	}

}

//exercicio 4

//a função esta desenvolvida desta forma porque ao compilar na forma do enunciado os valores não dão certo
double dv(double u, double v) {
	return pow(u, 2)*pow(v, 3) / 2 + u * pow(v, 3) + u * pow(v, 2) + 5 * pow(v, 2) / 2;
}

double eul(double h) {
	double v = 0.1;
	double u = 1;
	int n = 0.8 / h;
	for (int i = 0; i < n; i++) {
		v += h * dv(u, v);
		u += h;
	}
	return v;
}

void euler() {
	double s = eul(0.08);
	double s1 = eul(0.04);
	double s2 = eul(0.02);
	double qc = (s1 - s) / (s2 - s1);
	double err = (s2 - s1);
	cout << "v1: " << s << endl << "v2: " << s1 << endl << "v3: " << s2 << endl << "qc: " << qc << endl << "erro: " << err << endl;
}
int main()
{
	//gauss_seidel();
	//euler();
	return 0;    
}

