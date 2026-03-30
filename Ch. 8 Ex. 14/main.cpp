#include "../std_lib_facilities.h"

/*
 * Vector must be sorted first
 */
string first(const vector<string>& vec) {
	if (vec.size() == 0) error("vector must not be empty");
	return vec[0];
}

/*
 * Vector must be sorted first
 */
string last(const vector<string>& vec) {
	int size = vec.size();
	if (size == 0) error("vector must not be empty");
	return vec[size-1];
}

string shortest(const vector<string>& vec) {
	int size = vec.size();
	if (size == 0) error("vector must not be empty");
	int min = vec[0].size();
	string s = vec[0];
	for (int i = 1; i < size; ++i) {
		int tmp = vec[i].size();
		if (tmp < min) {
			min = tmp;
			s = vec[i];
		}
	}
	return s;
}

string longest(const vector<string>& vec) {
	int size = vec.size();
	if (size == 0) error("vector must not be empty");
	int max = vec[0].size();
	string s = vec[0];
	for (int i = 1; i < size; ++i) {
		int tmp = vec[i].size();
		if (tmp > max) {
			max = tmp;
			s = vec[i];
		}
	}
	return s;
}

vector<int> number_of_characters(const vector<string>& vec) {
	int size = vec.size();
	if (size == 0) error("vector must not be empty");
	vector<int> noc(size);
	for (int i = 0; i < size; ++i) {
		noc[i] = vec[i].length();
	}
	return noc;
}

int main() {
	vector<string> vec = {"troll", "lel", "bs", "junk", "toaster", "potato", "dong"};

	vector<int> noc = number_of_characters(vec);
	for (int i = 0; i < noc.size(); ++i) {
		cout << vec[i] << " = " << noc[i] << "\n";
	}

	cout << "\nShortest: " << shortest(vec) << "\n";

	cout << "\nLongest: " << longest(vec) << "\n";

	sort(vec.begin(), vec.end());

	cout << "\nFirst: " << first(vec) << "\n";

	cout << "\nLast: " << last(vec) << "\n";

	keep_window_open();

	return 0;
}