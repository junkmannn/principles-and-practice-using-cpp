#include "../std_lib_facilities.h"

vector<string> reverse_v(vector<string> v) {
	vector<string> reversed(v.size());
	for (int i = v.size()-1, i2 = 0; i >= 0; --i, ++i2) {
		reversed[i2] = v[i];
	}
	return reversed;
}

void reverse_r(vector<string>& v) {
	int mid = v.size()/2;
	for (int i = v.size()-1, i2 = 0; i >= mid; --i, ++i2) {
		string tmp = v[i2];
		v[i2] = v[i];
		v[i] = tmp;
	}
}

int main() {
	vector<string> v = {"1", "2", "3", "4", "5", "6"};

	/*
	vector<string> v2 = reverse_v(v);
	for (int i = 0; i < v2.size(); ++i) {
		cout << v2[i] << '\n';
	}
	*/

	reverse_r(v);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << '\n';
	}

	keep_window_open();

	return 0;
}