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
		if (m == feb && d == 29) {
			if (!leapyear(y + n)) d = 28;
		}
		y += n;
	}

	void Date::add_month(int n) {
		y += (n / 12);

		n = n % 12;
		int month = m + n;
		if (month > Date::dec) {
			++y;
			n -= Date::dec - m;
			month = n;
		}
		m = Month(month);

		int mlength = month_length(m, y);
		if (d > mlength) {
			d = mlength;
		}
	}

	void Date::add_day(int n) {
		int mlength = month_length(m, y);
		int day = d + n;
		if (day > mlength) {
			n -= (mlength - d) + 1;
			d = 1;
			if (m + 1 > Date::dec) {
				m = Date::jan;
				++y;
			}
			else {
				m = Month(m + 1);
			}
		}
		else {
			d = day;
			return;
		}


		int after = 0;
		if (m > Date::feb) after = 1;

		int ylength = year_length(y + after);
		while (n >= ylength) {
			n -= ylength;
			++y;
			ylength = year_length(y + after);
		}


		mlength = month_length(m, y);
		while (n >= mlength) {
			n -= mlength;
			if (m + 1 > Date::dec) {
				m = Date::jan;
				++y;
			}
			else {
				m = Month(m + 1);
			}
			mlength = month_length(m, y);
		}


		d += n;
	}

	// helper functions:

	const Date& default_date() {
		static Date d(2001, Date::jan, 1);
		return d;
	}

	bool is_date(int y, Date::Month m, int d) {
		// assume that y is valid

		if (m < Date::jan || m > Date::dec ||
			d < 1 || d > month_length(m, y)) {
			return false;
		}

		return true;
	}

	bool leapyear(int y) {
		if (y % 4 == 0) {
			if (y % 100 == 0) return (y % 400 == 0);
			return true;
		}
		return false;
	}

	int month_length(Date::Month m, int y) {
		switch (m) {
		case Date::feb:
			return leapyear(y) ? 29 : 28;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			return 30;
		default:
			return 31;
		}
	}

	int year_length(int y) {
		return leapyear(y) ? 366 : 365;
	}

	int week_of_year(const Date& d) {
		int days = -1;
		for (int i = Date::jan; i < d.month(); ++i) {
			days += month_length(Date::Month(i), d.year());
		}
		days += d.day();
		return (days / 7.0) + 1;
	}

	Date::Day day_of_week(const Date& d) {
		int days = -1;
		for (int i = Date::jan; i < d.month(); ++i) {
			days += month_length(Date::Month(i), d.year());
		}
		days += d.day();
		return Date::Day(days % 7);
	}

	Date next_Sunday(const Date& d) {
		Date copy(d);
		copy.add_day(7 - (day_of_week(d) - Date::sunday));
		if (copy.year() > d.year()) copy = Date(copy.year(), Date::jan, 1);
		return copy;
	}

	Date next_workday(const Date& d) {
		Date copy(d);
		Date::Day day = day_of_week(d);
		switch (day) {
		case Date::friday:
			copy.add_day(3);
			break;
		case Date::saturday:
			copy.add_day(2);
			break;
		default:
			copy.add_day(1);
			break;
		}
		if (copy.year() > d.year()) copy = Date(copy.year(), Date::jan, 2);
		return copy;

	}

	/*
	Date next_weekday(const Date& d) {
		return Date();
	}
	*/

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

	Date::Month operator++(Date::Month& m) {
		m = (m == Date::dec) ? Date::jan : Date::Month(m + 1); // "wrap around"
		return m;
	}

}
