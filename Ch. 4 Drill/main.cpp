#include "../std_lib_facilities.h"

int main() {
	bool first_time = true;
	double smallest = -std::numeric_limits<double>::infinity();
	double largest = std::numeric_limits<double>::infinity();
	double sum = 0.0;
	vector<double> values;
	double d = 0.0;
	string unit = "";
	while (cin >> d >> unit) {
		// convert everything into meters
		if (unit == "cm") {
			d /= 100;
		}
		else if (unit == "m") {
			// already in m
		}
		else if (unit == "in") {
			d /= 39.3701;
		}
		else if (unit == "ft") {
			d /= 3.28084;
		}
		else {
			cout << "invalid unit\n";
			continue;
		}

		if (d < smallest) {
			cout << "the smallest so far\n";
			smallest = d;
		}
		else if (d > largest) {
			cout << "the largest so far\n";
			largest = d;
		}
		else if (first_time) {
			first_time = false;
			cout << "the smallest so far\nthe largest so far\n";
			smallest = d;
			largest = d;
		}
		sum += d;
		values.push_back(d);
	}

	if (!first_time) {
		cout << "the smallest value is " << smallest << "m\n"
			<< "the largest value is " << largest << "m\n"
			<< "sum of values is " << sum << "m\n"
			<< "number of values is " << values.size() << '\n'
			<< "list of values:\n";
		sort(values.begin(), values.end());
		for (int i = 0; i < values.size(); ++i) {
			cout << values[i] << "m\n";
		}
	}

	if (!cin.good()) {
		if (cin.eof()) {
			cin.clear();
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	keep_window_open();

	return 0;
}