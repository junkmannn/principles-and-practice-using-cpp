#ifndef CHRONO_H
#define CHRONO_H

#include <iostream>

namespace Chrono {

	class Date {
	public:
		class Invalid { }; // exception class

		enum Month {
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		enum Day {
			sunday, monday, tuesday, wednesday, thursday, friday, saturday
		};

		Date(); // default constructor
		Date(int y, Month m, int d); // check for valid date and initialize
		// the default copy operations are fine

		// nonmodifying operations:
		int year() const { return y; }
		Month month() const { return m; }
		int day() const { return d; }

		// modifying operations:
		void add_year(int n);
		void add_month(int n);
		void add_day(int n);
	private:
		int y;
		Month m;
		int d;
	};

	const Date& default_date();

	bool is_date(int y, Date::Month m, int d); // true for valid date

	bool leapyear(int y); // true if y is a leap year

	int month_length(Date::Month m, int y = 0);
	int year_length(int y);

	int week_of_year(const Date& d);
	Date::Day day_of_week(const Date& d);

	Date next_Sunday(const Date& d);
	Date next_workday(const Date& d);
	// Date next_weekday(const Date& d);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& d);

	Date::Month operator++(Date::Month& m);

}

#endif
