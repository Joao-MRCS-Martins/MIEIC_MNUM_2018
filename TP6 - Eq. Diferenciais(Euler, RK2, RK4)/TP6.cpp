#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x, double y, double z)
{
	return z * y + x;
}

double g(double x, double y, double z)
{
	return z * x + y;
}

vector<double> eulermethod()
{
	double h = 0.1;
	int n = 5;
	vector <double> sol = { 0,0,0,0,0,0 };
	double xn = 0;
	double yn = 1;
	double zn = 1;
	
	double x1, y1, z1;

	for(int i =0; i<n; i++)
	{ 
		x1 = xn + h;
		y1 = yn + h * f(xn, yn, zn);
		z1 = zn + h * g(xn, yn, zn);
		
		xn = x1;
		yn = y1;
		zn = z1;
	}
	sol[0] = yn;
	sol[1] = zn;

	cout << "S: " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	xn = 0;
	yn = 1;
	zn = 1;
	h /= 2;
	n = 10;

	for (int i = 0; i<n; i++)
	{
		x1 = xn + h;
		y1 = yn + h * f(xn, yn, zn);
		z1 = zn + h * g(xn, yn, zn);
		
		xn = x1;
		yn = y1;
		zn = z1;
	}
	sol[2] = yn;
	sol[3] = zn;

	cout << "S': " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	xn = 0;
	yn = 1;
	zn = 1;
	h /= 2;
	n = 20;

	for (int i = 0; i<n; i++)
	{
		x1 = xn + h;
		y1 = yn + h * f(xn, yn, zn);
		z1 = zn + h * g(xn, yn, zn);
		
		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[4] = yn;
	sol[5] = zn;

	cout << "S'': " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;
	return sol;
}

double error_euler(double s2, double s1)
{
	return s2 - s1;
}

double error_rk2(double s2, double s1)
{
	return (s2 - s1) / 3;
}

double error_rk4(double s2, double s1)
{
	return (s2 - s1) / 15;
}

double qc(double s, double s1, double s2)
{
	return (s1 - s) / (s2 - s1);
}


vector <double > rk2()
{
	double h = 0.1;
	int n = 5;
	vector <double> sol = { 0,0,0,0,0,0 };
	double xn = 0;
	double yn = 1;
	double zn = 1;

	double x1, y1, z1;

	for (int i = 0; i < n; i++)
	{
		x1 = xn + h;
		y1 = yn + h * f(xn + h / 2, yn + h / 2 * f(xn, yn, zn), zn + h / 2 * g(xn, yn, zn));
		z1 = zn + h * g(xn + h / 2, yn + h / 2 * f(xn, yn, zn), zn + h / 2 * g(xn, yn, zn));

		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[0] = yn;
	sol[1] = zn;

	cout << "S: " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	xn = 0;
	yn = 1;
	zn = 1;
	h /= 2;
	n *= 2;

	for (int i = 0; i < n; i++)
	{
		x1 = xn + h;
		y1 = yn + h * f(xn + h / 2, yn + h / 2 * f(xn, yn, zn), zn + h / 2 * g(xn, yn, zn));
		z1 = zn + h * g(xn + h / 2, yn + h / 2 * f(xn, yn, zn), zn + h / 2 * g(xn, yn, zn));

		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[2] = yn;
	sol[3] = zn;

	cout << "S': " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	xn = 0;
	yn = 1;
	zn = 1;
	h /= 2;
	n *= 2;

	for (int i = 0; i < n; i++)
	{
		x1 = xn + h;
		y1 = yn + h * f(xn + h / 2, yn + h / 2 * f(xn, yn, zn), zn + h / 2 * g(xn, yn, zn));
		z1 = zn + h * g(xn + h / 2, yn + h / 2 * f(xn, yn, zn), zn + h / 2 * g(xn, yn, zn));

		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[4] = yn;
	sol[5] = zn;

	cout << "S'': " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	return sol;
}

double $y1(double h, double xn, double yn, double zn)
{
	return h * f(xn, yn, zn);
}

double $k1(double h, double xn, double yn, double zn)
{
	return h * g(xn, yn, zn);
}

double $y2(double h, double xn, double yn, double zn)
{
	return h * f(xn + h / 2, yn + $y1(h, xn, yn, zn) / 2, zn + $k1(h, xn, yn, zn) / 2);
}

double $k2(double h, double xn, double yn, double zn)
{
	return h * g(xn + h / 2, yn + $y1(h, xn, yn, zn) / 2, zn + $k1(h, xn, yn, zn) / 2);
}

double $y3(double h, double xn, double yn, double zn)
{
	return h * f(xn + h / 2, yn + $y2(h, xn, yn, zn) / 2, zn + $k2(h, xn, yn, zn) / 2);
}

double $k3(double h, double xn, double yn, double zn)
{
	return h * g(xn + h / 2, yn + $y2(h, xn, yn, zn) / 2, zn + $k2(h, xn, yn, zn) / 2);
}

double $y4(double h, double xn, double yn, double zn)
{
	return h * f(xn + h / 2, yn + $y3(h, xn, yn, zn), zn + $k3(h, xn, yn, zn));
}

double $k4(double h, double xn, double yn, double zn)
{
	return h * g(xn + h / 2, yn + $y3(h, xn, yn, zn), zn + $k3(h, xn, yn, zn));
}

vector <double > rk4()
{
	double h = 0.1;
	int n = 5;
	vector <double> sol = { 0,0,0,0,0,0 };
	double xn = 0;
	double yn = 1;
	double zn = 1;

	double x1, y1, z1;

	for (int i = 0; i < n; i++)
	{
		x1 = xn + h;
		y1 = yn + $y1(h, xn, yn, zn)/6 + $y2(h, xn, yn, zn)/3 + $y3(h, xn, yn, zn)/3 + $y4(h,xn,yn,zn)/6;
		z1 = zn + $k1(h,xn,yn,zn)/6 + $k2(h,xn,yn,zn)/3 + $k3(h,xn,yn,zn)/3 + $k4(h,xn,yn,zn)/6;

		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[0] = yn;
	sol[1] = zn;

	cout << "S: " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	xn = 0;
	yn = 1;
	zn = 1;
	h /= 2;
	n *= 2;

	for (int i = 0; i < n; i++)
	{
		x1 = xn + h;
		y1 = yn + $y1(h, xn, yn, zn) / 6 + $y2(h, xn, yn, zn) / 3 + $y3(h, xn, yn, zn) / 3 + $y4(h, xn, yn, zn) / 6;
		z1 = zn + $k1(h, xn, yn, zn) / 6 + $k2(h, xn, yn, zn) / 3 + $k3(h, xn, yn, zn) / 3 + $k4(h, xn, yn, zn) / 6;

		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[2] = yn;
	sol[3] = zn;

	cout << "S': " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	xn = 0;
	yn = 1;
	zn = 1;
	h /= 2;
	n *= 2;

	for (int i = 0; i < n; i++)
	{
		x1 = xn + h;
		y1 = yn + $y1(h, xn, yn, zn) / 6 + $y2(h, xn, yn, zn) / 3 + $y3(h, xn, yn, zn) / 3 + $y4(h, xn, yn, zn) / 6;
		z1 = zn + $k1(h, xn, yn, zn) / 6 + $k2(h, xn, yn, zn) / 3 + $k3(h, xn, yn, zn) / 3 + $k4(h, xn, yn, zn) / 6;

		xn = x1;
		yn = y1;
		zn = z1;
	}

	sol[4] = yn;
	sol[5] = zn;

	cout << "S'': " << endl << "xn: " << xn << " yn: " << yn << " zn: " << zn << endl;

	return sol;
}
int main()
{
	vector <double> sol = eulermethod();
	double qc_y = qc(sol[0], sol[2], sol[4]);
	double qc_z = qc(sol[1], sol[3], sol[5]);
	double err_y = error_euler(sol[4], sol[2]);
	double err_z = error_euler(sol[5], sol[3]);
	cout << "QC y = " << qc_y << " QC z = " << qc_z << " Error y = " << err_y << " Error z = " << err_z << endl;
	sol = rk2();
	qc_y = qc(sol[0], sol[2], sol[4]);
	qc_z = qc(sol[1], sol[3], sol[5]);
	err_y = error_rk2(sol[4], sol[2]);
	err_z = error_rk2(sol[5], sol[3]);
	cout << "QC y = " << qc_y << " QC z = " << qc_z << " Error y = " << err_y << " Error z = " << err_z << endl;
	sol = rk4();
	qc_y = qc(sol[0], sol[2], sol[4]);
	qc_z = qc(sol[1], sol[3], sol[5]);
	err_y = error_rk4(sol[4], sol[2]);
	err_z = error_rk4(sol[5], sol[3]);
	cout << "QC y = " << qc_y << " QC z = " << qc_z << " Error y = " << err_y << " Error z = " << err_z << endl;

    return 0;
}

