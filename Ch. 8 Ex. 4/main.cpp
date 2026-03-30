#include "../std_lib_facilities.h"

void print(const vector<int>& v, const string& lbl) {
	cout << lbl << '\n';
	for (int i = 0, size = v.size(); i < size; ++i) {
		cout << v[i] << '\n';
	}
}

void fibonacci(int x, int y, vector<int>& v, int n) {
	if (n < 2) error("number of elements must be at least 2");
	v.push_back(x); // [0]
	v.push_back(y); // [1]
	for (int i = 2; i < n; ++i) {
		v.push_back(v[i-2] + v[i-1]);
	}
}

int approx_max_int_capacity() {
	vector<int> v;
	int i, i2, i3;

	i = 1;
	i2 = 2;

	while (true) {
		fibonacci(i, i2, v, 3);
		i3 = v[2];

		if (i3 < i2) {
			// overflow?
			return i2;
		}
		else {
			v.clear();
			i = i2;
			i2 = i3;
		}
	}
}

int main() {
	cout << approx_max_int_capacity() << '\n';
	// vector<int> v;
	// fibonacci(1, 2, v, 46);
	// print(v, "Fibonacci");

	keep_window_open();

	return 0;
}