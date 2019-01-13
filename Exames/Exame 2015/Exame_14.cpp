#include <iostream>
#include <cmath>

using namespace std;

//exercicio 1

double dTdt(double T) {
	return -0.25*(T - 37);
}

void euler() {
	double t = 5;
	double h = 0.4;
	double T = 3;
	int n = 2;
	cout << "T: " << T << endl;
	while (n > 0) {
		T += h * dTdt(T);
		t += h;
		cout << "T: " << T << endl;
		n--;
	}
}
int main()
{
	//euler();
	return 0;

}
