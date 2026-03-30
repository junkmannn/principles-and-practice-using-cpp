#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Sums all the whitespace-separated integers in the given file (make sure file exists and is readable beforehand).
 * All non-integer values will be ignored.
 * Throws std::ios_base::failure if an unrecoverable occurred while reading the file.
 */
int sum_integers_in_file(ifstream& ist);

int main() {
	cout << "Please enter input file name: ";
	string name;
	cin >> name;

	ifstream ist(name.c_str());
	if (!ist) {
		cerr << "Error: can't open input file " << name << ".\n";
	}
	else {
		try {
			int sum = sum_integers_in_file(ist);
			cout << "The sum of all the numbers in the file is " << sum << '\n';
		}
		catch (ios_base::failure &e) {
			cerr << "Error: exception opening/reading/closing file.\n";
		}
	}

	char c;
	cin >> c;

	return 0;
}

int sum_integers_in_file(ifstream& ist) {
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	int sum = 0;

	while (!ist.eof()) {
		int i = 0;
		ist >> i;

		sum += i;

		if (ist.fail()) {
			// not an integer, ignore it.
			ist.clear();
			string s;
			ist >> s;
		}
	}

	return sum;
}
