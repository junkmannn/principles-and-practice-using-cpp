#include "../std_lib_facilities.h"

int main() {
	cout << "Enter a number of miles. It will then be converted into kilometers.\n";
	double miles;
	cin >> miles;
	double kilometers = miles * 1.609;
	cout << miles << " miles = " << kilometers << " kilometers\n";

	keep_window_open();
	return 0;
}