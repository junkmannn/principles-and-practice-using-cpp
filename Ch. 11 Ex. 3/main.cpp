#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

void keep_window_open();

enum Base {
	OCT, DEC, HEX
};

struct Value_base {
	Value_base(int value, Base base) : value(value), base(base) { }
	int value;
	Base base;
};

int main() {
	cout << "Please enter a series of integers in any combination of octal, decimal, or hexadecimal, using the 0 and 0x base suffixes.\n";

	vector<Value_base> vb_vec;

	istringstream iss;
	iss.unsetf(ios_base::dec);
	iss.unsetf(ios_base::oct);
	iss.unsetf(ios_base::hex);

	string s;
	while (cin >> s) {
		iss.str(s);
		iss.seekg(0);

		int i = 0;
		if (iss >> i) {
			iss.seekg(0);
			char c = iss.get();
			if (c == '-') c = iss.get();
			if (c == '0') {
				// oct or hex
				c = iss.get();
				if (c == 'x' || c == 'X') vb_vec.push_back(Value_base(i, HEX));
				else vb_vec.push_back(Value_base(i, OCT));
			}
			else {
				vb_vec.push_back(Value_base(i, DEC));
			}
		}
	}

	for (int i = 0, size = vb_vec.size(); i < size; ++i) {
		Value_base& vb = vb_vec[i];
		switch (vb.base) {
		case OCT:
		{
			ostringstream oss;
			oss << showbase << oct;
			if (vb.value >= 0) oss << vb.value;
			else oss << '-' << -vb.value;
			cout << setw(8) << oss.str() << left << setw(12) << " octal";
			break;
		}
		case HEX:
		{
			ostringstream oss;
			oss << showbase << hex;
			if (vb.value >= 0) oss << vb.value;
			else oss << '-' << -vb.value;
			cout << setw(8) << oss.str() << left << setw(12) << " hexadecimal";
			break;
		}
		case DEC:
			cout << setw(8) << vb.value << left << setw(12) << " decimal";
			break;
		}
		cout << " converts to " << right << setw(8) << vb.value << " decimal\n";
	}

	cin.clear();
	keep_window_open();

	return 0;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
