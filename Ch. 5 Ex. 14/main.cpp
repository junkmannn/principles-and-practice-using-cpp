#include "../std_lib_facilities.h"

int main() {
	vector<int> monday;
	vector<int> tuesday;
	vector<int> wednesday;
	vector<int> thursday;
	vector<int> friday;
	vector<int> saturday;
	vector<int> sunday;

	int rejected_count = 0;

	string day_of_week = "";
	int value;
	while (cin >> day_of_week >> value) {
		if (day_of_week == "Monday" || day_of_week == "monday" || day_of_week == "Mon") {
			monday.push_back(value);
		}
		else if (day_of_week == "Tuesday" || day_of_week == "tuesday" || day_of_week == "Tue") {
			tuesday.push_back(value);
		}
		else if (day_of_week == "Wednesday" || day_of_week == "wednesday" || day_of_week == "Wed") {
			wednesday.push_back(value);
		}
		else if (day_of_week == "Thursday" || day_of_week == "thursday" || day_of_week == "Thu") {
			thursday.push_back(value);
		}
		else if (day_of_week == "Friday" || day_of_week == "friday" || day_of_week == "Fri") {
			friday.push_back(value);
		}
		else if (day_of_week == "Saturday" || day_of_week == "saturday" || day_of_week == "Sat") {
			saturday.push_back(value);
		}
		else if (day_of_week == "Sunday" || day_of_week == "sunday" || day_of_week == "Sun") {
			sunday.push_back(value);
		}
		else {
			++rejected_count;
		}
	}


	int sum = 0;
	cout << "Monday: ";
	for (int i = 0; i < monday.size(); ++i) {
		cout << monday[i] << ' ';
		sum += monday[i];
	}
	cout << "(sum = " << sum << ")\n";

	sum = 0;
	cout << "Tuesday: ";
	for (int i = 0; i < tuesday.size(); ++i) {
		cout << tuesday[i] << ' ';
		sum += tuesday[i];
	}
	cout << "(sum = " << sum << ")\n";

	sum = 0;
	cout << "Wednesday: ";
	for (int i = 0; i < wednesday.size(); ++i) {
		cout << wednesday[i] << ' ';
		sum += wednesday[i];
	}
	cout << "(sum = " << sum << ")\n";

	sum = 0;
	cout << "Thursday: ";
	for (int i = 0; i < thursday.size(); ++i) {
		cout << thursday[i] << ' ';
		sum += thursday[i];
	}
	cout << "(sum = " << sum << ")\n";

	sum = 0;
	cout << "Friday: ";
	for (int i = 0; i < friday.size(); ++i) {
		cout << friday[i] << ' ';
		sum += friday[i];
	}
	cout << "(sum = " << sum << ")\n";

	sum = 0;
	cout << "Saturday: ";
	for (int i = 0; i < saturday.size(); ++i) {
		cout << saturday[i] << ' ';
		sum += saturday[i];
	}
	cout << "(sum = " << sum << ")\n";

	sum = 0;
	cout << "Sunday: ";
	for (int i = 0; i < sunday.size(); ++i) {
		cout << sunday[i] << ' ';
		sum += sunday[i];
	}
	cout << "(sum = " << sum << ")\n";

	cout << "Number of rejected values: " << rejected_count << '\n';


	keep_window_open();

	return 0;
}
