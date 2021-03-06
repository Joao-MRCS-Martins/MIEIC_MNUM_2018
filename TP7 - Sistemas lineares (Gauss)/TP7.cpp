#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> gauss(vector <vector<double>> A) {
	int n = A.size();

	for (int i = 0; i < n; i++) {
		double maxCol = abs(A[i][i]);
		int maxRow = i;
		for (int k = i + 1; k < n; k++) {
			if (abs(A[k][i]) > maxCol) {
				maxCol = abs(A[k][i]);
				maxRow = k;
			}
		}


		for (int k = i; k < n + 1; k++) {
			double tmp = A[maxRow][k];
			A[maxRow][k] = A[i][k];
			A[i][k] = tmp;
		}

		for (int k = i + 1; k < n; k++) {
			double c = -A[k][i] / A[i][i];
			for (int j = i; j < n + 1; j++) {
				if (i == j) {
					A[k][j] = 0;
				}
				else {
					A[k][j] += c * A[i][j];
				}
			}
		}
	}

	vector<double> x(n);
	for (int i = n - 1; i >= 0; i--) {
		x[i] = A[i][n] / A[i][i];
		for (int k = i - 1; k >= 0; k--) {
			A[k][n] -= A[k][i] * x[i];
		}
	}
	return x;
}

vector<vector<double>> equation_system() {
	vector<vector<double>> vec = { {7, 2, 0, 24},{4,10,1,27},{5, -2, 8,27 } };
	return vec;
}

vector<vector<double>> eq_sys_ext(double residue) {
	vector<vector<double>> vec = { { 7, 2, 0, residue },{ 4,10,1,residue },{ 5, -2, 8,residue } };
	return vec;
}
vector<double> SolveSystem(double x, double y, double z) {
	vector<double> vec;
	vec.push_back(7 * x + 2 * y - 24);
	vec.push_back(4 * x + 10 * y + z - 27);
	vec.push_back(5 * x - 2 * y + 8 * z - 27);
	return vec;
}


vector<double> residue(vector<double> sol) {
	vector<double> vec;
	for (int i = 0; i < sol.size(); i++) {
		double val = 0;
		for(int j = 0; j < sol.size(); j++) {
			val += 0.5*sol[j];
		}
		vec.push_back(val);
	}
	return vec;
}

int main()
{
	cout << fixed;
	cout.precision(4);
	
	vector <double> sol = gauss(equation_system());
	cout << "Solution is: \t";
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << "\t";
	}

	vector<double> InternalStability = SolveSystem(sol[0], sol[1], sol[2]);
	cout << endl << endl << "Internal stability is: \t";
	for (int i = 0; i < InternalStability.size(); i++) {
		cout << InternalStability[i] << "\t";
	}
	vector<double> res = residue(sol);
	vector<double> ExternalStability = gauss(eq_sys_ext(res[0]));
	cout << endl << endl << "External stability is: \t";
	for (int i = 0; i < ExternalStability.size(); i++) {
		cout << ExternalStability[i] << "\t";
	}
    return 0;
}

