#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter the number of values you want to sum:\n";
	int count = 0;
	cin >> count;

	cout << "Please enter some integers (press '|' to stop):\n";
	vector<int> integers;
	int integer = 0;
	while (cin >> integer) integers.push_back(integer);

	if (count > integers.size()) {
		cerr << "error: not enough values entered\n";
	}
	else {
		cout << "The sum of the first " << count << " numbers is ( ";
		int sum = 0;
		for (int i = 0; i < count; ++i) {
			cout << integers[i] << ' ';
			sum += integers[i];
		}
		cout << ") is " << sum << ".\n";
	}

	keep_window_open("~");

	return 0;
}
