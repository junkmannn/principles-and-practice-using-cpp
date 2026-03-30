#include "../std_lib_facilities.h"

class Over {};

unsigned int factorial(unsigned int a) {
	unsigned int f = 1;
	for (unsigned int i = 2; i <= a; ++i) f *= i;
	return f;
}

unsigned int nPr(unsigned int a, unsigned int b) {
	if (a < b) return 0;
	return factorial(a) / factorial(a-b);
}

unsigned int nCr(unsigned int a, unsigned int b) {
	return nPr(a,b) / factorial(b);
}

bool is_valid_integer(int i) {
	const string err_msg = "Error: must be a positive integer.\n";
	if (!cin.good()) {
		if (cin.eof() || cin.bad()) {
			throw Over();
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << err_msg;
			return false;
		}
	}
	else if (i < 0) {
		cout << err_msg;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

bool is_valid_choice(char c) {
	const string err_msg = "Error: must be a valid choice (P or C).\n";
	if (!cin.good()) {
		/*
		if (cin.eof() || cin.bad()) {
			throw Over();
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << err_msg;
			return false;
		}
		*/
		throw Over();
	}
	else if (!(c == 'P' || c == 'C' || c == 'p' || c == 'c')) {
		cout << err_msg;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

int main() {
	try {
		cout << "Enter two positive integers (a,b) then\nP to calculate nPr(a,b) or C for nCr(a,b).\nUse CTRL+Z to quit.\n";
		while (1) {
			int a = 0;
			do {
				// cout << "a = ";
				cin >> a;
			}
			while (!is_valid_integer(a));

			int b = 0;
			do {
				// cout << "b = ";
				cin >> b;
			}
			while (!is_valid_integer(b));


			// cout << "Enter P to calculate nPr(a,b) or C for nCr(a,b).\n";

			char c = ' ';
			do {
				cin >> c;
			}
			while (!is_valid_choice(c));

			unsigned int result = 0;
			if (c == 'P' || c == 'p') {
				cout << "nPr";
				result = nPr(a, b);
			}
			else {
				cout << "nCr";
				result = nCr(a, b);
			}
			cout << "(" << a << "," << b << ") = " << result << "\n";
		}
	}
	catch (Over& e) {
		cout << "Goodbye!\n";
	}

	keep_window_open();

	return 0;
}