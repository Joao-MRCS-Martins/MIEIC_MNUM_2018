#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double funcInt(double x) {
	return (sin(x) / (x*x));
}

double TrapezeRule() {
	cout << "Insert the range, a and b, and the number of intervals to use: " << endl;
	double a;
	double b;
	int n  ;
	cin >> a >> b >> n;
	double h = (b - a) / n;
	double y = 0;

	//special case, with values already given, using vector to store them.
	/*vector<double> v1 = { 5,6,5.5,7,7.4,8,6,7,5 };
	for (int i = 0; i <= v1.size(); i++) {
		if (i == 0 || i == v1.size())
			y += h / 2 * funcInt(a + i * h);
		else
			y += h * funcInt(a + i * h);
	}
	cout << "The integral solution is: " << y << endl;
	return y; */
	//

	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n)
			y += h / 2 * funcInt(a + i * h);
		else
			y += h * funcInt(a + i * h);
	}
	cout << "The integral solution is: " << y << endl;
	return y;
}

bool even(int x) {
	return (x % 2 == 0);
}

double SimpsonRule() {
	cout << "Warning: the number of intervals have to be even!" << endl;
	cout << "Insert the range, a and b, and the number of intervals to use: " << endl;
	double a;
	double b;
	int n;
	cin >> a >> b >> n;
	double h = (b - a) / n;
	double y = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n)
			y += h / 3 * funcInt(a + i * h);
		else if (even(i))
			y += 2 * h / 3 * funcInt(a + i * h);
		else
			y += 4 * h/3* funcInt(a + i * h);
	}
	cout << "The integral solution is: " << y << endl;
	return y;
}

bool ConvergenceQuotientTrapeze(double s1, double s2, double s3) {
	double qc = (s2 - s1) / (s3 - s2);
	cout << "The convergence quotient is: " << qc << endl;
	if (abs(4 - qc) > 0.5)
		return false;
	else return true;
}

bool ConvergenceQuotientSimpson(double s1, double s2, double s3) {
	double qc = (s2 - s1) / (s3 - s2);
	cout << "The convergence quotient is: " << qc << endl;
	if (abs(16 - qc) > 0.5)
		return false;
	else return true;
}

double TrapezeError(double s3, double s2) {
	return abs((s3 - s2) / 3);
}

double SimpsonError(double s3, double s2) {
	return abs((s3 - s2) / 15);
}

int main()
{
	int method;
	cout << "The equation is: sin(x)/x^2. Change the equation on the function to fit your needs." << endl <<"Beware of values uninputtable on the console, like pi or euler's number." << endl;
	cout << "Which numerical method to use to solve the simple integral? " << endl<< endl;
	cout << "1 - Trapeze method." << endl
		<< "2 - Simspson method." << endl;
	cout << "-> ";
	cin >> method;
	double solTra1=0, solTra2=0, solTra3=0;
	double solSim1=0, solSim2=0, solSim3=0;

	switch (method) {
	case 1:
		cout <<endl<< "Warning! For the converge quotient to work, the interval in the following 3 calls " << endl << "must remain the same and the number of intervals must double in each call!" << endl;
		solTra1 = TrapezeRule();
		solTra2 = TrapezeRule();
		solTra3 = TrapezeRule();
		if (ConvergenceQuotientTrapeze(solTra1, solTra2, solTra3))
			cout << "The step used was adequate." << endl<<endl;
		else cout << "The step used was inadequate." << endl<<endl;
		cout << "The error in the calculation was: " << TrapezeError(solTra3, solTra2) << endl;
		break;
	case 2:
		cout <<endl<< "Warning! For the converge quotient to work, the interval in the following 3 calls must remain the same and the number of intervals must double in each call!" << endl;
		solSim1 = SimpsonRule();
		solSim2 = SimpsonRule();
		solSim3 = SimpsonRule();
		if (ConvergenceQuotientSimpson(solSim1, solSim2, solSim3))
			cout << "The step used was adequate." << endl<<endl;
		else 
			cout << "The step used was inadequate. Retry the steps starting with the double of initial number of intervals." << endl<<endl;
		cout << "The error in the calculation was: " << SimpsonError(solTra3, solTra2) << endl;
		break;
	}
	return 0;
}