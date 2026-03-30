#include "../std_lib_facilities.h"

int main() {
	vector<double> temps;
	double temp = 0.0;
	while (cin >> temp) {
		temps.push_back(temp);
	}

	if (temps.size() > 0) {
		double sum = 0.0;
		for (int i = 0; i < temps.size(); ++i) sum += temps[i];
		cout << "Average temperature: " << sum/temps.size() << '\n';

		sort(temps.begin(), temps.end());
		double median = 0.0;
		if (temps.size() % 2 == 0) { // even
			median = (temps[temps.size()/2] + temps[(temps.size()/2)-1]) / 2;
		}
		else { // odd
			median = temps[temps.size()/2];
		}
		cout << "Median temperature: " << median << '\n';
	}

	keep_window_open();

	return 0;
}