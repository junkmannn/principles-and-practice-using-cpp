#include "../std_lib_facilities.h"

int guess_number(int lep, int uep);

int main() {
	// [lep,uep]
	const int lep = 0; // lower endpoint of the interval
	const int uep = 100; // upper endpoint of the interval

	cout << "Guess a number between " << lep << " and " << uep << ".\n";
	int number = guess_number(lep, uep);
	if (number != -1) {
		cout << "The number is " << number << '\n';
	}

	keep_window_open();

	return 0;
}

int guess_number(int lep, int uep) {
	if (lep == uep) {
		return uep;
	}
	else if (uep-lep == 1) {
		cout << "Is the number you are thinking of " << lep << "?\n";
		char c = ' ';
		cin >> c;
		switch (c) {
		case 'y': return lep;
		case 'n': return uep;
		default:  return -1; // throwing an exception would be a better choice here...
		}
	}
	else {
		int mid = (lep+uep)/2;
		cout << "Is the number you are thinking of less than " << mid << "?\n";
		char c = ' ';
		cin >> c;
		switch (c) {
		case 'y': return guess_number(lep, mid-1);
		case 'n': return guess_number(mid, uep);
		default:  return -1; // exception...
		}
	}
}

