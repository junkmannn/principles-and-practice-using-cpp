#include "../std_lib_facilities.h"

int main() {
	vector<double> distances;

	double distance = 0.0;
	while (cin >> distance) {
		distances.push_back(distance);
	}

	if (distances.size() > 0) {
		double smallest = distances[0];
		double largest = distances[0];
		double sum = 0.0;
		double mean = 0.0;
		for (int i = 0; i < distances.size(); ++i) {
			sum += distances[i];
			if (distances[i] < smallest) {
				smallest = distances[i];
			}
			else if (distances[i] > largest) {
				largest = distances[i];
			}
		}
		mean = sum / distances.size();

		cout << "Total distance is " << sum << '\n';
		cout << "Smallest distance is " << smallest << '\n';
		cout << "Largest distance is " << largest << '\n';
		cout << "Mean distance is " << mean << '\n';
	}

	keep_window_open();

	return 0;
}