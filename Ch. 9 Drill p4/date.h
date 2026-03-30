#ifndef DATE_H
#define DATE_H

#include <ostream>

class Invalid { };

/*
class Year { // year in [min:max) range
public:
	Year(int y);
	int year() const { return y; }
private:
	static const int min = 1800;
	static const int max = 2200;
	int y;
};
*/

// simple Date (use Month type)
class Date {
public:
	enum Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	Date();
	Date(int y, Month m, int d); // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }
private:
	int y;
	Month m;
	int d;
	bool check();
};

const Date& default_date();
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
