#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	double gains = exp(1) - 1;
	cout << "Year 0: " << gains << endl;
	for (int i = 1; i <= 25; i++) {
		gains = gains* i - 1;
		cout << "Year " << i << ": "<< setprecision(13) << gains << endl;
		
	}
	return 0;
}
