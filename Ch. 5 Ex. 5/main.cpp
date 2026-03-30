#include "../std_lib_facilities.h"

double ctok(double c) {
	if (c < -273.15) {
		cerr << "error: lowest possible temperature is -273.15C or 0K\n";
		return -1;
	}

	double k = c+273.15;
	return k;
}

double ktoc(double k) {
	if (k < 0) {
		cerr << "error: lowest possible temperature is -273.15C or 0K\n";
		return -1;
	}

	double c = k-273.15;
	return c;
}

int main() {
	cout << "Enter a temperature followed by its unit (c or k)\n";

	double temp = 0.0;
	char unit = ' ';
	cin >> temp >> unit;

	double temp_converted = 0.0;
	if (unit == 'c') {
		temp_converted = ctok(temp);
		cout << temp << "C = " << temp_converted << "K\n";
	}
	else if (unit == 'k') {
		temp_converted = ktoc(temp);
		cout << temp << "K = " << temp_converted << "C\n";
	}
	else {
		cerr << "error: invalid unit\n";
	}

	keep_window_open();
	return 0;
}