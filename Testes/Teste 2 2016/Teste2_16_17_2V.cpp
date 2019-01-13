#include <iostream>
#include <cmath>

using namespace std;

//exercicio 2

double dT(double T) {
	return -0.25*(T - 41);
}

void euler() {
	double t = 4;
	double T = 15;
	double h = 0.3;
	for (int i = 0; i < 2; i++) {
		T += h * dT(T);
		t += h;
	}
	cout << "T: " << T << endl;
}

//exercicio 3

double dC(double C, double T) {
	return -exp((-.5) / (T + 273))*C;
}

double dT(double C, double T) {
	return 20 * exp((-.5) / (T + 273))*C - .5*(T - 20);
}

double eul(double h) {
	double t = 0;
	double Tn = 15;
	double Cn = 1;
	double T = 0, C = 0;
	int n = 0.5 / h;
	cout << "t: " << t << "\tC: " << Cn << "\tT: " << Tn << endl;
	for (int i = 0; i < n; i++) {
		T = Tn + h * dT(Cn, Tn);
		C = Cn + h * dC(Cn, Tn);
		
		Tn = T;
		Cn = C;
		t += h;

		cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	}
	cout << endl;
	return T;
}

void euler_2nd() {
	double h = 0.25;
	double t = eul(h);
	double t1 = eul(h / 2);
	double t2 = eul(h / 4);
	double qc = (t1 - t) / (t2 - t1);
	double err = (t2 - t1);
	cout << "T': " << t1 << endl << "T'': " << t2 << endl << "Qc: " << qc << endl << "Erro: " << err << endl << endl;
}

void rk4() {
	double t = 0;
	double T = 15;
	double C = 1;
	double c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	double h = 0.25;
	cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	for (int i = 0; i < 2; i++) {
		c1 = h * dC(C, T);
		t1 = h * dT(C, T);

		c2 = h * dC(C + c1 / 2, T + t1 / 2);
		t2 = h * dT(C + c1 / 2, T + t1 / 2);
		
		c3 = h * dC(C + c2 / 2, T + t2 / 2);
		t3 = h * dT(C + c2 / 2, T + t2 / 2);
		
		c4 = h * dC(C + c3, T + t3);
		t4 = h * dT(C + c3, T + t3);

		C += c1 / 6 + c2 / 3 + c3 / 3 + c4 / 6;
		T += t1 / 6 + t2 / 3 + t3 / 3 + t4 / 6;
		t += h;

		cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	}
}

//exercicio 4

void gauss_seidel() {
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	int n = 1;
	for (int i = 0; i < n; i++) {
		x1 = (2.5 - .5*x2 - 3 * x3*-.25) / 6;
		x2 = (3.8 - 1.2*x1 - .25*x3 - .2*x4)/3;
		x3 = (10 + x1 - .25*x2 - 2 * x4) / 4;
		x4 = (7 - 2 * x1 - 4 * x2 - x3) / 8;
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	}
}



int main()
{
	//euler();
	//euler_2nd();
	//rk4();
	//gauss_seidel();
	return 0;
}