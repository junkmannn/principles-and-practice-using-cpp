#include "../std_lib_facilities.h"

int main() {
	vector<double> temps;

	// hotter than the surface of the sun; it should be enough to cover 99.9% of the cases
	const double max_temp = 10000.0;
	// absolute zero (doesn't get colder than that!)
	const double min_temp = -459.67;

	double temp = 0.0;
	double sum = 0.0;
	double high_temp = min_temp;
	double low_temp = max_temp;

	while (cin >> temp) {
		temps.push_back(temp);
	}

	for (int i = 0; i < temps.size(); ++i) {
		if (temps[i] > high_temp) high_temp = temps[i];
		if (temps[i] < low_temp) low_temp = temps[i];
		sum += temps[i];
	}

	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum/temps.size() << '\n';

	keep_window_open();

	return 0;
}
