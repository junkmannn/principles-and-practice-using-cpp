#include "../std_lib_facilities.h"

vector<int> reverse_v(vector<int> v) {
	vector<int> reversed(v.size());
	for (int i = v.size()-1, i2 = 0; i >= 0; --i, ++i2) {
		reversed[i2] = v[i];
	}
	return reversed;
}

void reverse_r(vector<int>& v) {
	int mid = v.size()/2;
	for (int i = v.size()-1, i2 = 0; i >= mid; --i, ++i2) {
		int tmp = v[i2];
		v[i2] = v[i];
		v[i] = tmp;
	}
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	/*
	vector<int> v2 = reverse_v(v);
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