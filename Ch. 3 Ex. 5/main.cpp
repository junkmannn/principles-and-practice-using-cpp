#include "../std_lib_facilities.h"

int main() {
	cout << "Enter two floating-point values\n";
	double val1 = 0;
	double val2 = 0;
	cin >> val1 >> val2;

	cout << "val1=" << val1 << ", val2=" << val2 << '\n';

	if (val1 > val2) {
		cout << "Smallest value is val2. Largest value is val1.\n";
	}
	else if (val2 > val1) {
		cout << "Smallest value is val1. Largest value is val2.\n";
	}
	else {
		cout << "val1 and val2 are equal\n";
	}

	cout << "val1+val2=" << val1+val2
		<< "\nval1-val2=" << val1-val2
		<< "\nval1*val2=" << val1*val2
		<< "\nval1/val2=" << val1/val2 << '\n';

	keep_window_open();
	return 0;
}