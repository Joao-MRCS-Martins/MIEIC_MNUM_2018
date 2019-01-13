#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1

double y(double x) {
	return pow(x - 1, 2) + pow(x, 4);
}

void aurea() {
	double B = (sqrt(5) - 1) / 2;
	double A = B * B;
	double x1 = -0.5;
	double x2 = 1.5;
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);
	while (abs(x1 - x4) > 0.0001 && abs(x2 - x3) > 0.0001) {
		if (y(x3) < y(x4)) {
			x2 = x4;
			x4 = x3;
			x3 = x1 + A * (x2 - x1);
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = x1 + B * (x2 - x1);
		}
		cout << "x1: " << x1 << "\tx2: " << x2 << "\tx3: " << x3 << "\tx4: " << x4 << endl;
	}

	if (y(x3) < y(x4)) {
		cout << "O minimo esta no intervalo: [ " << x1 << ", " << x4 << " ] " << endl;
	}
	else {
		cout << "O minimo esta no intervalo: [ " << x1 << ", " << x4 << " ] " << endl;
	}
}

//exercicio 2

double f(double x) {
	return sqrt(1 + pow(2.5*exp(2.5*x), 2));
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
	double h = 0.125;
	double s = simp(h);
	double s1 = simp(h / 2);
	double s2 = simp(h / 4);
	double qc = (s1 - s) / (s2 - s1);
	double err = (s2 - s1) / 15;
	cout << "h: " << h << endl << "h': " << h / 2 << endl << "h'': " << h / 4 << endl;
	cout << "L: " << s << endl << "L': " << s1 << endl << "L'': " << s2 << endl;
	cout << "Qc: " << qc << endl << "Erro: " << err << endl;;
}

double trap(double h) {
	int n = 1 / h;
	double l = 0;
	double x = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n) {
			l += h / 2 * f(x);
		}
		
		else {
			l +=  h * f(x);
		}
		x += h;
	}
	return l;
}

void trapezes() {
	double h = 0.125;
	double s = trap(h);
	double s1 = trap(h / 2);
	double s2 = trap(h / 4);
	double qc = (s1 - s) / (s2 - s1);
	double err = (s2 - s1) / 3;
	cout << "h: " << h << endl << "h': " << h / 2 << endl << "h'': " << h / 4 << endl;
	cout << "L: " << s << endl << "L': " << s1 << endl << "L'': " << s2 << endl;
	cout << "Qc: " << qc << endl << "Erro: " << err << endl;
}

//exercicio 4

double dC(double C, double T) {
	return -exp(-0.5 / (T + 273))*C;
}

double dT(double C, double T) {
	return 30 * exp(-0.5 / (T + 273))*C - 0.5*(T - 20);
}

double euler(double h) {
	double t = 0;
	double Cn = 2.5;
	double Tn = 25;
	double C = 0, T = 0;
	cout << "t: " << t << "\tC: " << Cn << "\tT: " << Tn << endl;
	while (t < 0.5) {
		C = Cn + h * dC(Cn, Tn);
		T = Tn + h * dT(Cn, Tn);
		t += h;
		Tn = T;
		Cn = C;
		cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	}
	return T;
}

void euler() {
	double h = 0.25;
	double s1 = euler(h);
	cout << endl;
	double s2 = euler(h / 2);
	cout << endl;
	double s3 = euler(h / 4);
	cout << endl;
	double qc = (s2 - s1) / (s3 - s2);
	double err = (s3 - s2);
	cout << "Qc: " << qc << "\tErro: " << err << endl<<endl;
}

void rk4() {
	double h = 0.25;
	double t = 0;
	double C = 2.5;
	double T = 25;
	double c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	while (t < 0.5) {
		c1 = h * dC(C, T);
		t1 = h * dT(C, T);
		
		c2 = h * dC(C + c1 / 2, T + t1 / 2);
		t2 = h * dT(C + c1 / 2, T + t1 / 2);

		c3= h * dC(C + c2 / 2, T + t2 / 2);
		t3= h * dT(C + c2 / 2, T + t2 / 2);
		
		c4= h * dC(C + c3, T + t3);
		t4 = h * dT(C + c3, T + t3);

		C += c1 / 6 + c2 / 3 + c3 / 3 + c4 / 6;
		T += t1 / 6 + t2 / 3 + t3 / 3 + t4 / 6;
		t += h;

		cout << "t: " << t << "\tC: " << C << "\tT: " << T << endl;
	}
}

//exercicio 5

double w(double x, double y) {
	return -1.1*x*y + 12 * y + 7 * x*x - 8 * x;
}

double wx(double x, double y) {
	return -1.1*y + 14 * x - 8;
}

double wy(double x, double y) {
	return -1.1*x + 12;
}

void gradient() {
	double xn = 3;
	double yn = 1;
	double h = 0.1;
	int n = 1;
	double x = 0, y = 0;
	cout << "xn: " << xn << "\tyn: " << yn << "\tw(xn,yn): " << w(xn,yn) << endl;
	for (int i = 0; i < n; i++) {
		x =xn- h * wx(xn, yn);
		y =yn- h * wy(xn, yn);
		xn = x;
		yn = y;
		cout << "xn: " << xn << "\tyn: " << yn << "\tw(xn,yn): " << w(xn, yn) << endl;
	}
}

int main()
{
	//aurea();
	//trapezes();
	//simpson();
	//euler();
	//rk4();
	//gradient();
	return 0;
}
