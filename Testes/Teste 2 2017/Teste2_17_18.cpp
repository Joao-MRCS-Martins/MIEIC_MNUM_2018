#include <iostream>
#include <cmath>

using namespace std;

double dz(double z, double t) {
	return 2 + pow(t, 2) + t * z;
}

double dy(double z) {
	return z;
}

void euler() {
	double t = 1;
	double y = 1;
	double z = 0;
	double h = 0.25;
	int n = 0.5 / h;
	cout << "t: " << t << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		y += h * dy(z);
		z += h * dz(z, t);
		t += h;

		cout << "t: " << t << "\ty: " << y << endl;
	}
}

void rk4() {
	double t = 1;
	double y = 1;
	double z = 1;
	double h = 0.25;
	int n = 0.5 / h;
	double y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	double z1 = 0, z2 = 0, z3 = 0, z4 = 0;
	cout << "t: " << t << "\ty: " << y << endl;
	for (int i = 0; i < 2; i++) {
		y1 = h * dy(z);
		z1 = h * dz(z, t);
		y2 = h * dy(z + z1 / 2);
		z2 = h * dz(z + z1 / 2, t + h / 2);
		y3 = h * dy(z + z2 / 2);
		z3 = h * dz(z + z2 / 2, t + h / 2);
		y4 = h * dy(z + z3);
		z4 = h * dz(z + z3, t + h);

		y += y1 / 6 + y2 / 3 + y3 / 3 + y4 / 6;
		z += z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6;
		t += h;

		cout << "t: " << t << "\ty: " << y << endl;
	}
}

int main()
{
	//euler();
	//cout << endl;
	//rk4();
	return 0;
}
