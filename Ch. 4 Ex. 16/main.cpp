#include "../std_lib_facilities.h"

void find_min_max_mode(vector<int> &values, int &min, int &max, vector<int> &mode);

int main() {
	cout << "Enter a list of positive integers\n";
	vector<int> values;
	int value = 0;
	while (cin >> value) {
		if (value < 1) {
			cout << "ignored: must be positive\n";
		}
		else {
			values.push_back(value);
		}
	}

	if (values.size() > 0) {
		int min = 0;
		int max = 0;
		vector<int> mode;
		find_min_max_mode(values, min, max, mode);
		cout << "Min value is " << min << '\n'
			 << "Max value is " << max << '\n';
		if (mode.size() == 0) {
			cout << "No mode\n";
		}
		else {
			cout << "Mode is ";
			for (int i = 0; i < mode.size(); ++i) cout << mode[i] << ' ';
			cout << '\n';
		}
	}

	keep_window_open();

	return 0;
}

void find_min_max_mode(vector<int> &values, int &min, int &max, vector<int> &mode) {
	sort(values.begin(), values.end());

	min = values[0];
	max = values[values.size()-1];

	int max_occurrences = 2;
	int occurrences = 1;
	for (int i = 0; i < values.size()-1; ++i) {
		if (values[i] == values[i+1]) {
			++occurrences;
			if (occurrences == max_occurrences) {
				mode.push_back(values[i]);
			}
			else if (occurrences > max_occurrences) {
				++max_occurrences;
				mode.clear();
				mode.push_back(values[i]);
			}
		}
		else {
			occurrences = 1;
		}
	}
}