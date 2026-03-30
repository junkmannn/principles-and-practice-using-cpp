#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void format_numbers(ifstream& ist, ofstream& ost);
void keep_window_open();

int main() {
	string filename = "numbers.txt";
	ifstream ist(filename);
	if (!ist) {
		cerr << "Can't open input file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	filename = "numbersformatted.txt";
	ofstream ost(filename);
	if (!ost) {
		cerr << "Can't open output file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	format_numbers(ist, ost);

	keep_window_open();

	return 0;
}

void format_numbers(ifstream& ist, ofstream& ost) {
	ost << scientific << setprecision(8);

	int i = 0;
	string s;
	while (ist >> s) {
		try {
			double d = stod(s);
			ost << setw(20) << d;
			if (i == 3) {
				i = 0;
				ost << '\n';
			}
			++i;
		}
		catch (...) {
			// skip
		}
	}
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
