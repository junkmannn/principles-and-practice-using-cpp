#ifndef DATE_H
#define DATE_H

#include <ostream>

class Invalid { };

// simple Date (too simple?)
struct Date {
	int y; // year
	int m; // month in year
	int d; // day of month
};

// helper functions:

// check that (y,m,d) is a valid date
// if it is, use it to initialize dd
void init_date(Date& dd, int y, int m, int d);

// increase dd by n days
void add_day(Date& dd, int n);

std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
