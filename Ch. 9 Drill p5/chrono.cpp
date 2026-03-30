#include "chrono.h"

using namespace std;

namespace Chrono {

	// member function definitions:

	Date::Date(int y, Month m, int d) : y(y), m(m), d(d) {
		if (!is_date(y, m, d)) throw Invalid();
	}

	Date::Date() : y(default_date().y),
				   m(default_date().m),
				   d(default_date().d) {
	}

	void Date::add_year(int n) {
		if (m == feb && d == 29 && !leapyear(y+n)) {
			m = mar;
			d = 1;
		}
		y += n;
	}

	void Date::add_month(int n) {
		// ...
	}

	void Date::add_day(int n) {
		// ...
		++d;
	}

	// helper functions:

	const Date& default_date() {
		static Date dd(2001, Date::jan, 1);
		return dd;
	}

	bool is_date(int y, Date::Month m, int d) {
		// assume that y is valid

		if (d <= 0) return false; // d must be positive
		if (m < Date::jan || m > Date::dec) return false;

		int days_in_month = 31; // most months have 31 days

		switch (m) {
		case Date::feb: // the length of February varies
			days_in_month = leapyear(y) ? 29 : 28;
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}

		if (d > days_in_month) return false;

		return true;
	}

	bool leapyear(int y) {
		// see exercise 10
		return true;
	}

	Date::Day day_of_week(const Date& d) {
		// ...
		return Date::sunday;
	}

	Date next_Sunday(const Date& d) {
		// ...
		return Date();
	}

	Date next_weekday(const Date& d) {
		// ...
		return Date();
	}

	bool operator==(const Date& a, const Date& b) {
		return a.year() == b.year() &&
			   a.month() == b.month() &&
			   a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Date& d) {
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day() << ')';
	}

	std::istream& operator>>(std::istream& is, Date& dd) {
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}

		dd = Date(y, Date::Month(m), d);

		return is;
	}

}
