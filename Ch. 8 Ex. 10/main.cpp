#include "../std_lib_facilities.h"

double index(const vector<double>& price, const vector<double>& weight) {
	int size = price.size();
	if (size != weight.size()) error("both vectors must be the same size");
	double d = 0.0;
	for (int i = 0; i < size; ++i) {
		d += price[i] * weight[i];
	}
	return d;
}

int main() {
	vector<double> price = {3.44, 5.23, 5.00, 9.08, 4.12};
	vector<double> weight = {4.7, 19.0, 1.0, 7.8, 3.2, 4.4};

	try {
		double d = index(price, weight);
		cout << "Index: " << d << "\n";
	}
	catch (runtime_error &e) {
		cout << e.what() << "\n";
	}

	keep_window_open();

	return 0;
}