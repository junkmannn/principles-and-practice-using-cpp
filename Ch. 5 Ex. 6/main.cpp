#include "../std_lib_facilities.h"

double ctof(double c) {
	if (c < -273.15) {
		cerr << "error: lowest possible temperature is -273.15C or -459.67F\n";
		return -1;
	}

	double f = 9.0/5 * c + 32;
	return f;
}

double ftoc(double f) {
	if (f < 0) {
		cerr << "error: lowest possible temperature is -273.15C or -459.67F\n";
		return -1;
	}

	double c = (f-32) / (9.0/5);
	return c;
}

int main() {
	cout << "Enter a temperature followed by its unit (c or f)\n";

	double temp = 0.0;
	char unit = ' ';
	cin >> temp >> unit;

	double temp_converted = 0.0;
	if (unit == 'c') {
		temp_converted = ctof(temp);
		cout << temp << "C = " << temp_converted << "F\n";
	}
	else if (unit == 'f') {
		temp_converted = ftoc(temp);
		cout << temp << "F = " << temp_converted << "C\n";
	}
	else {
		cerr << "error: invalid unit\n";
	}

	keep_window_open();
	return 0;
}