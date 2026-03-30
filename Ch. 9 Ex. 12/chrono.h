#ifndef CHRONO_H
#define CHRONO_H

#include <iostream>
#include <vector>
#include <cstdint>

namespace Chrono {

	class Date {
	public:
		class Invalid { }; // exception class

		struct Year_Month_Day {
			int year;
			int month;
			int day;
		};

		// Months
		static const int JANUARY = 1;
		static const int FEBRUARY = 2;
		static const int MARCH = 3;
		static const int APRIL = 4;
		static const int MAY = 5;
		static const int JUNE = 6;
		static const int JULY = 7;
		static const int AUGUST = 8;
		static const int SEPTEMBER = 9;
		static const int OCTOBER = 10;
		static const int NOVEMBER = 11;
		static const int DECEMBER = 12;

		// Days
		static const int MONDAY = 1;
		static const int TUESDAY = 2;
		static const int WEDNESDAY = 3;
		static const int THURSDAY = 4;
		static const int FRIDAY = 5;
		static const int SATURDAY = 6;
		static const int SUNDAY = 7;

		// Limits
		static const int MIN_YEAR = 1970;
		static const int MAX_YEAR = 10000000;

		Date(); // default constructor
		Date(int year, int month, int day); // check for valid date and initialize
		Date(uint64_t date);
		// the default copy operations are fine

		// nonmodifying operations:
		int get_year() const;
		int get_month() const;
		int get_day() const;
		Year_Month_Day get_year_month_day() const;
		uint64_t get_date() const { return date; }

		// modifying operations:
		void add_year(int n);
		void add_month(int n);
		void add_day(int n);
	private:
		static const int NO_CACHE = -1;

		uint64_t date;
		mutable int year_cache;
		mutable int month_cache;
		mutable int day_cache;

		void invalidate_cache();
	};

	uint64_t convert(int year, int month, int day);

	const Date& default_date();

	bool is_date(int year, int month, int day); // true for valid date

	bool leapyear(int year); // true if y is a leap year

	int num_days_before(int month, int year);

	int month_length(int month, int year = 0);
	int year_length(int year);

	int week_of_year(const Date& date);
	int day_of_week(const Date& date);

	Date next_Sunday(const Date& date);
	Date next_workday(const Date& date);

	bool operator==(const Date& date1, const Date& date2);
	bool operator!=(const Date& date1, const Date& date2);

	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::istream& operator>>(std::istream& is, Date& date);

}

#endif
