#include "../std_lib_facilities.h"

double maxv(const vector<double>& vec) {
	int size = vec.size();
	if (size == 0) return 0.0;
	double d = vec[0];
	for (int i = 1; i < size; ++i) {
		if (vec[i] > d) d = vec[i];
	}
	return d;
}

int main() {
	vector<double> vec = {3.3, 1.0, 4.2, 9.7, 5.5, 27.3, 1.0, 11.1, 70.2};

	cout << "Largest element in the vector is " << maxv(vec) << "\n";

	keep_window_open();

	return 0;
}