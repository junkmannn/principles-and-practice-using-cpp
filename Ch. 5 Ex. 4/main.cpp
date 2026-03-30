#include "../std_lib_facilities.h"

double ctok(double c) {
	if (c < -273.15) {
		cerr << "error: lowest possible temperature is -273.15C or 0K\n";
		return -1;
	}

	double k = c+273.15;
	return k;
}

int main() {
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << endl;

	keep_window_open();
	return 0;
}