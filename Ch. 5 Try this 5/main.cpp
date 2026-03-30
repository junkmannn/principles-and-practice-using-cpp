#include "../std_lib_facilities.h"

int main() {
	vector<double> temps;

	double temp = 0.0;
	double sum = 0.0;
	double high_temp = 0.0;
	double low_temp = 0.0;

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
