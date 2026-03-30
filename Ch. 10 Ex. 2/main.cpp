#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// a temperature reading
struct Reading {
	int hour; // hour after midnight [0:23]
	double temperature; // in Fahrenheit
	Reading(int h, double t) : hour(h), temperature(t) { }
};

int main() {
	ofstream ost("raw_temps.txt"); // ost writes to a file named raw_temps.txt
	if (!ost) {
		cerr << "Can't open output file raw_temps.txt.\n";
		return 0;
	}

	cout << "Please enter pairs made of an hour [0:23] and a temperature in Fahrenheit (e.g. 4 77.32).\n";
	vector<Reading> readings; // store the readings here
	int hour;
	double temperature;
	while (cin >> hour >> temperature) {
		if (hour < 0 || hour > 23) {
			cerr << "hour out of range\n";
			break;
		}
		readings.push_back(Reading(hour, temperature));
	}

	// write temps to file
	for (int i = 0; i < readings.size(); ++i) {
		ost << readings[i].hour << ' ' << readings[i].temperature << '\n';
	}

	cin.clear();
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;

	return 0;
}