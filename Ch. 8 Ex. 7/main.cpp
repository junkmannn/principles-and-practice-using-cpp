#include "../std_lib_facilities.h"

int main() {
	const int COUNT = 5;

	cout << "Enter " << COUNT << " names followed by " << COUNT << " ages.\n";

	vector<string> names(COUNT);
	for (int i = 0; i < COUNT; ++i) {
		cin >> names[i];
	}
	vector<double> ages(COUNT);
	for (int i = 0; i < COUNT; ++i) {
		cin >> ages[i];
	}

	cout << "\n";
	for (int i = 0; i < COUNT; ++i) {
		cout << names[i] << " " << ages[i] << "\n";
	}

	vector<string> names_sorted = names;
	sort(names_sorted.begin(), names_sorted.end());
	vector<double> ages_sorted(COUNT);

	for (int i = 0; i < COUNT; ++i) {
		for (int i2 = 0; i2 < COUNT; ++i2) {
			if (names_sorted[i] == names[i2]) {
				ages_sorted[i] = ages[i2];
				break;
			}
		}
	}

	cout << "\n";
	for (int i = 0; i < COUNT; ++i) {
		cout << names_sorted[i] << " " << ages_sorted[i] << "\n";
	}

	keep_window_open();

	return 0;
}