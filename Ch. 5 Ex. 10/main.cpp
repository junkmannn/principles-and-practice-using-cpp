#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter some values (press '|' to stop):\n";
	vector<double> values;
	double value = 0;
	while (cin >> value) values.push_back(value);

	if (values.size() > 1) {
		vector<double> differences(values.size()-1);
		for (int i = 0; i < values.size()-1; ++i) {
			differences[i] = values[i+1] - values[i];
		}

		cout << "Differences between adjacent values:\n";
		for (int i = 0; i < differences.size(); ++i) cout << differences[i] << '\n';
	}


	keep_window_open("~");

	return 0;
}
