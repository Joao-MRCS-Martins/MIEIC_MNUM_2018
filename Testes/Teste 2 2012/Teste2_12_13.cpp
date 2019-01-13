#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1

void gauss_jacobi() {
	double x1 = 0.25, x2 = .25, x3 = .25, x4 = .25;
	double x1n = 0.25, x2n = .25, x3n = .25;
	cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	for (int i = 0; i < 2; i++) {
		x1 = (1 + x2 + x3 - x4) / 4.5;
		x2 = (-1 + x1n - x3 + x4) / 4.5;
		x3 = (-1 + x1n - 2 * x2n + x4) / 4.5;
		x4 = (-2 * x1n + x2n + x3n) / 4.5;
		x1n = x1;
		x2n = x2;
		x3n = x3;
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	}
}

//exercicio 2

double dx(double x, double t) {
	return sin(2 * x) + sin(2 * t);
}

double rk4(double h) {
	double t = 1;
	double x = 1;
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	int n = 0.5 / h;
	cout << "t: " << t << "\tx: " << x << endl;
	for (int i = 0; i < n; i++) {
		x1 = h * dx(x, t);
		x2 = h * dx(x + x1 / 2, t + h / 2);
		x3 = h * dx(x + x2 / 2, t + h / 2);
		x4 = h * dx(x + x3, t + h);

		x += x1 / 6 + x2 / 3 + x3 / 3 + x4 / 6;
		t += h;

		cout << "t: " << t << "\tx: " << x << endl;
	}
	cout << endl;
	return x;
}

void runge_kutta() {
	double h = 0.5;
	double x = rk4(h);
	double x1 = rk4(h/2);
	double x2 = rk4(h/4);
	double qc = (x1 - x) / (x2 - x1);
	cout << "Qc: " << qc << endl;
	if(abs(16-qc) < 0.01) {
		cout << "Passo adequado. Passo a utilizar: " << h / 4 << endl;
	}
	else {
		cout << "Passo inadequado. Passo a utilizar: " << h / 8 << endl;
	}
}

//exercicio 3

double f(double x) {
	return sqrt(1 + pow(1.5*exp(1.5*x), 2));
}

double simp(double h) {
	int n = 1 / h;
	double l = 0;
	double x = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n) {
			l += h / 3 * f(x);
		}
		else if (i % 2 == 0) {
			l += 2 * h / 3 * f(x);
		}
		else {
			l += 4 * h / 3 * f(x);
		}
		x += h;
	}
	return l;
}

void simpson() {
	double l = simp(0.25);
	double l1 = simp(0.125);
	double l2 = simp(0.0625);

	double qc = (l1 - l) / (l2 - l1);
	double err = (l2 - l1) / 15;
	cout << "L1: " << l << endl << "L2: " << l1 << endl << "L3: " << l2 << endl << "Qc: " << qc << endl << "Erro: " << err << endl;
}

double trap(double h) {
	int n = 1 / h;
	double l = 0;
	double x = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n) {
			l += h / 2 * f(x);
		}
		else  {
			l += h* f(x);
		}
		x += h;
	}
	return l;
}

void trapezes() {
	double l = trap(0.25);
	double l1 = trap(0.125);
	double l2 = trap(0.0625);

	double qc = (l1 - l) / (l2 - l1);
	double err = (l2 - l1) / 3;
	cout << "L1: " << l << endl << "L2: " << l1 << endl << "L3: " << l2 << endl << "Qc: " << qc << endl << "Erro: " << err << endl<<endl;

}

//exercicio 4

double dC(double C, double T) {
	return -exp(-0.5 / (T + 273))*C;
}

double dT(double C, double T) {
	return 20 * exp(-0.5 / (T + 273))*C - 0.5*(T - 20);
}

double eul(double h) {
	double t = 0;
	double Cn = 2;
	double Tn = 20;
	double C = 0, T = 0;
	int n = 0.4 / h;
	cout << "t: " << t << "\tC: " << Cn << "\tT: " << Tn << endl;
	for (int i = 0; i < n; i++) {
		C = Cn + h * dC(Cn, Tn);
		T = Tn + h * dT(Cn, Tn);
		t += h;
		Tn = T;
		Cn = C;

		cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	}
	cout << endl;
	return C;
}

void euler() {
	double c = eul(0.2);
	double c1 = eul(0.1);
	double c2 = eul(0.05);
	double qc = (c1 - c) / (c2 - c1);
	double err = c2 - c1;
	cout << "h': " << 0.1 << "\tCh': " << c1 << endl << "h'': " << 0.05 << "\tCh'': " << c2 << endl;
	cout << "       \tQc: " << qc << endl << "       \tErro: " << err << endl<<endl;
}

void rk4() {
	double t = 0;
	double C = 2;
	double T = 20;
	double c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	double h = 0.2;
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

int main()
{
	//gauss_jacobi();
	//runge_kutta();
	//trapezes();
	//simpson();
	//euler();
	//rk4();
	return 0;
}
