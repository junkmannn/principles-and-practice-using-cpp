#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double calculate_mean(vector<double> temps);
double calculate_median(vector<double> temps);

// a temperature reading
struct Reading {
	int hour; // hour after midnight [0:23]
	double temperature; // in Fahrenheit
	Reading(int h, double t) : hour(h), temperature(t) { }
};

int main() {
	ifstream ist("raw_temps.txt");
	if (!ist) {
		cerr << "Can't open input file raw_temps.txt.\n";
		return 0;
	}

	ofstream ost("temp_stats.txt");
	if (!ost) {
		cerr << "Can't open output file temp_stats.txt.\n";
		return 0;
	}

	vector<double> temps;
	int hour;
	double temperature;
	while (ist >> hour >> temperature) {
		temps.push_back(temperature);
	}

	double mean = calculate_mean(temps);
	double median = calculate_median(temps);

	ost << "Mean: " << mean << "f\n";
	ost << "Median: " << median << "f\n";

	return 0;
}

double calculate_mean(vector<double> temps) {
	int size = temps.size();

	if (size > 0) {
		double total = 0.0;
		for (int i = 0; i < size; ++i) total += temps[i];
		return total / size;
	}
	else {
		return 0.0;
	}
}

double calculate_median(vector<double> temps) {
	int size = temps.size();
	if (size > 0) {
		sort(temps.begin(), temps.end());
		int mid = size / 2;
		if (size % 2 == 0) { // even
			return (temps[mid] + temps[mid-1]) / 2;
		}
		else { // odd
			return temps[mid];
		}
	}
	else {
		return 0.0;
	}
}
