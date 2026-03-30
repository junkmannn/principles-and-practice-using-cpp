#ifndef DATE_H
#define DATE_H

#include <ostream>

class Invalid { };

// simple Date
// guarantee initialization with constructor
// provide some notational convenience
struct Date {
	int y, m, d; // year, month, day
	Date(int y, int m, int d); // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
};

std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
