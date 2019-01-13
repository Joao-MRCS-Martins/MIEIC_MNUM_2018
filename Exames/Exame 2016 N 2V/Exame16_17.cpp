#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1


double fdx(double x) {
	return 2.5*exp(2.5*x);
}

double y(double x) {
	return	sqrt(1 + pow(fdx(x), 2));
}

double trapezes(double h) {
	int n = 1 / h;
	double l = 0;
	double x = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n) {
			l += h / 2 * y(x + i*h);
		}
		else {
			l += h * y(x+i*h);
		}
	}
	return l;
}

double simpson(double h) {
	int n = 1 / h;
	double l = 0;
	double x = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n) {
			l += h / 3 * y(x + i * h);
		}
		else if ( i%2 == 0) {
			l += 2*h/3 * y(x + i * h);
		}
		else
			l +=  4*h/3 * y(x + i * h);
	}
	return l;
}

//exercicio 3

double f1(double z) {
	return z;
}

double f2(double t, double z) {
	return 1 + t * t + t * z;
}

void euler() {
	double h = 0.5;
	int n = 2;
	double y = 1;
	double z = 2;
	double t = 0;
	cout << "t: " << t << "\ty: " << y << endl;
	while (n > 0) {
		y += h * f1(z);
		z += h * f2(t, z);
		t += h;
		cout << "t: " << t << "\ty: " << y << endl;
		n--;
	}
}

void rk4() {
	double h = 0.5;
	int n = 2;
	double y = 1;
	double z = 2;
	double t = 0;
	double d1=0, d2=0, d3=0, d4=0;
	double e1=0, e2=0, e3=0, e4=0;
	cout << "t: " << t << "\ty: " << y << endl;
	while (n > 0) {
		d1 = h * f1(z);
		e1 = h * f2(t, z);

		d2 = h * f1(z + e1/2);
		e2 = h * f2(t + h / 2, z + e1/2);
		
		d3 = h * f1(z + e2/2);
		e3 = h * f2(t + h / 2, z + e2/2);
		
		d4 = h * f1(z + e3);
		e4 = h * f2(t + h, z + e3);
		
		y += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		z += e1 / 6 + e2 / 3 + e3 / 3 + e4 / 6;
		t += h;
		cout << "t: " << t << "\ty: " << y << endl;
		n--;
	}
}

//exercicio 5

double g1(double x, double y) {
	return x * x - y - 1.2;
}

double g1x(double x, double y) {
	return 2 * x;
}

double g1y(double x, double y) {
	return -1;
}

double g2(double x, double y) {
	return -x + y * y - 0.5;
}

double g2x(double x, double y) {
	return -1;
}

double g2y(double x, double y) {
	return 2 * y;
}

void newt() {
	double x = 1.5;
	double y = 0.5;
	double xn = x;
	cout << "x: " << x << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		xn = x;
		x -= (g1(x, y)*g2y(x, y) - g2(x, y)*g1y(x, y)) / (g1x(x, y)*g2y(x, y) - g2x(x, y)*g1y(x, y));
		y -= (g2(xn,y)*g1x(xn,y) - g1(xn,y)*g2x(xn,y)) / (g1x(xn, y)*g2y(xn, y) - g2x(xn, y)*g1y(xn, y));
		cout << "x: " << x << "\ty: " << y << endl;
	}
}

//exercicio 6

double f3(double x) {
	return pow(x, 7) - 0.5*x - 1;
}

void corda() {
	double xe = 1;
	double xd = 1.5;
	double xn = 0;
	
	for (int i = 0; i < 4; i++) {
		xn = (xe*f3(xd) - xd * f3(xe)) / (f3(xd) - f3(xe));
		cout << "xe: " << xe << "\txd: " << xd << "\txn: " << xn << "\tf(xe): " << f3(xe) << "\tf(xd): " << f3(xd) << "\tf(xn): " << f3(xn) << endl;
		
		if (f3(xn)*f3(xe) < 0) {
			xd = xn;
		}
		else
			xe = xn;
		
	}
}


int main()
{
	/*
	double l = trapezes(0.25); //subst with simpson
	double l1 = trapezes(0.125);
	double l2 = trapezes(0.0625);
	double qc = (l1 - l) / (l2 - l1);
	double err = (l2 - l1) / 3;
	cout << "h \t" << 0.25 << endl << "h' \t" << 0.125 << endl << "h'' \t" << 0.0625 << endl;
	cout << "Comprimento arco l: \t" << l << endl << "Comprimento arco l': \t" << l1 << endl;
	cout << "Comprimento arco l'': \t" << l2 << endl << "Quociente conver: \t" << qc << endl;
	cout << "Erro estimado: \t" << err << endl;
	*/
	//euler();
	//rk4();
	//newt();
	//corda();
	return 0;
}

