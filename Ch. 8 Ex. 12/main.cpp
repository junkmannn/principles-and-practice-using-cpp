#include "../std_lib_facilities.h"

struct Results {
	double smallest;
	double largest;
	double mean;
	double median;
};

Results info(vector<double>& vec) {
	int size = vec.size();
	if (size == 0) error("vector must not be empty");
	Results r;
	sort(vec.begin(), vec.end());
	r.smallest = vec[0];
	r.largest = vec[size-1];
	if (size % 2 == 0) {
		int high_mid = size/2;
		int low_mid = high_mid-1;
		r.median = (vec[low_mid] + vec[high_mid]) / 2;
	}
	else {
		r.median = vec[size/2];
	}
	r.mean = 0.0;
	for (int i = 0; i < size; ++i) r.mean += vec[i];
	r.mean /= size;
	return r;
}

int main() {
	vector<double> vec = {3.3, 1.0, 4.2, 9.7, 70.2, 27.3, 1.0, 11.1, 5.5};

	Results r = info(vec);
	cout << "Smallest: " << r.smallest
		 << "\nLargest: " << r.largest
		 << "\nMean: " << r.mean
		 << "\nMedian " << r.median << "\n";

	keep_window_open();

	return 0;
}