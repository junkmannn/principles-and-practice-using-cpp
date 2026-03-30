#include "../std_lib_facilities.h"

void find_min_max_mode(vector<string> &values, string &min, string &max, vector<string> &mode);

int main() {
	cout << "Enter a list of strings\n";
	vector<string> values;
	string value = "";
	while (cin >> value) {
		values.push_back(value);
	}

	if (values.size() > 0) {
		string min = "";
		string max = "";
		vector<string> mode;
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

void find_min_max_mode(vector<string> &values, string &min, string &max, vector<string> &mode) {
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