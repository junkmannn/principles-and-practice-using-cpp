#ifndef DATE_H
#define DATE_H

#include <ostream>

class Invalid { };

// simple Date (control access)
class Date {
public:
	Date(int y, int m, int d); // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }
private:
	int y, m, d; // year, month, day
	bool check();
};

std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
