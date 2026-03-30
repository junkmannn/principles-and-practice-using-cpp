#include "chrono.h"

using namespace std;

namespace Chrono {

	// member function definitions:

	// OK
	Date::Date(int year, int month, int day) : year_cache(year), month_cache(month), day_cache(day) {
		if (!is_date(year, month, day)) throw Invalid();
		date = convert(year, month, day);
	}

	// OK
	Date::Date() : Date(default_date()) { }

	// OK
	Date::Date(uint64_t date) : date(date), year_cache(NO_CACHE), month_cache(NO_CACHE), day_cache(NO_CACHE) { };

	// OK
	int Date::get_year() const {
		if (year_cache != NO_CACHE) return year_cache;

		int year = 0;
		uint64_t approx = 0;

		if (date < 548960) {
			year = 1970 + (date / 365);
			approx = Date(year, JANUARY, 1).get_date();
			if (approx > date) --year;
		}
		else {
			year = 1970 + (date / 365.2425);
			approx = Date(year, JANUARY, 1).get_date();
			if (approx > date) {
				do {
					--year;
					approx -= year_length(year);
				} while (approx > date);
			}
			else {
				approx += year_length(year);
				while (approx <= date) {
					++year;
					approx += year_length(year);
				}
			}
		}

		year_cache = year;

		return year;
	}

	// OK
	int Date::get_month() const {
		if (month_cache != NO_CACHE) return month_cache;

		int year = get_year();
		int days = date - Date(year, JANUARY, 1).get_date();

		int month;
		for (month = JANUARY; month < DECEMBER; ++month) {
			int length = month_length(month, year);
			if (days < length) break;
			days -= length;
		}

		month_cache = month;

		return month;
	}

	// OK
	int Date::get_day() const {
		if (day_cache != NO_CACHE) return day_cache;

		int year = get_year();
		int month = get_month();

		int day = (date - Date(year, month, 1).get_date()) + 1;

		day_cache = day;

		return day;
	}

	// OK
	Date::Year_Month_Day Date::get_year_month_day() const {
		get_day(); // will set the cache for year, month and day
		Year_Month_Day ymd;
		ymd.year = year_cache;
		ymd.month = month_cache;
		ymd.day = day_cache;
		return ymd;
	}

	// OK
	void Date::invalidate_cache() {
		year_cache = NO_CACHE;
		month_cache = NO_CACHE;
		day_cache = NO_CACHE;
	}

	// OK
	void Date::add_year(int n) {
		Year_Month_Day ymd = get_year_month_day();

		ymd.year += n;

		if (ymd.month == FEBRUARY && ymd.day == 29) {
			if (!leapyear(ymd.year)) ymd.day = 28;
		}

		date = convert(ymd.year, ymd.month, ymd.day);
		year_cache = ymd.year;
		month_cache = ymd.month;
		day_cache = ymd.day;
	}

	// OK
	void Date::add_month(int n) {
		Year_Month_Day ymd = get_year_month_day();

		ymd.year += n / 12;

		n %= 12; // leftover months
		int month = ymd.month + n;
		if (month > Date::DECEMBER) {
			++ymd.year;
			n -= Date::DECEMBER - ymd.month;
			month = n;
		}
		ymd.month = month;

		int mlength = month_length(ymd.month, ymd.year);
		if (ymd.day > mlength) {
			ymd.day = mlength;
		}

		date = convert(ymd.year, ymd.month, ymd.day);
		year_cache = ymd.year;
		month_cache = ymd.month;
		day_cache = ymd.day;
	}

	// OK
	void Date::add_day(int n) {
		date += n;
		invalidate_cache();
	}

	// helper functions:

	// OK
	uint64_t convert(int year, int month, int day) {
		uint64_t date = 0;

		// years
		// ----------------------------------
		{
			int i1 = year - 1968;
			int num_leap_years = i1 / 4;
			if (i1 % 4 == 0) --num_leap_years;

			if (year > 2100) {
				i1 = (year / 100) - 20;
				int i2 = i1 / 4;
				int num_not_leap_years = i1 - i2;
				if (year % 100 == 0 && i1 % 4 != 0) --num_not_leap_years;

				num_leap_years -= num_not_leap_years;
			}

			date += (year - 1970) * 365ULL + num_leap_years;
		}
		// ----------------------------------

		// months
		date += num_days_before(month, year);

		// days
		date += day;

		return date - 1;
	}

	// OK
	const Date& default_date() {
		static Date d(2001, Date::JANUARY, 1);
		return d;
	}

	// OK
	bool is_date(int year, int month, int day) {
		if (year < Date::MIN_YEAR || year > Date::MAX_YEAR ||
			month < Date::JANUARY || month > Date::DECEMBER ||
			day < 1 || day > month_length(month, year)) {
			return false;
		}

		return true;
	}

	// OK
	bool leapyear(int year) {
		if (year % 4 == 0) {
			if (year % 100 == 0) return (year % 400 == 0);
			return true;
		}

		return false;
	}

	// OK
	int num_days_before(int month, int year) {
		int leap = leapyear(year) ? 1 : 0;
		switch (month) {
		case Date::JANUARY:
			return 0;
		case Date::FEBRUARY:
			return 31;
		case Date::MARCH:
			return 59 + leap;
		case Date::APRIL:
			return 90 + leap;
		case Date::MAY:
			return 120 + leap;
		case Date::JUNE:
			return 151 + leap;
		case Date::JULY:
			return 181 + leap;
		case Date::AUGUST:
			return 212 + leap;
		case Date::SEPTEMBER:
			return 243 + leap;
		case Date::OCTOBER:
			return 273 + leap;
		case Date::NOVEMBER:
			return 304 + leap;
		case Date::DECEMBER:
			return 334 + leap;
		}
	}

	// OK
	int month_length(int month, int year) {
		switch (month) {
		case Date::FEBRUARY:
			return leapyear(year) ? 29 : 28;
		case Date::APRIL: case Date::JUNE: case Date::SEPTEMBER: case Date::NOVEMBER:
			return 30;
		default:
			return 31;
		}
	}

	// OK
	int year_length(int year) {
		return leapyear(year) ? 366 : 365;
	}

	// OK
	int week_of_year(const Date& date) {
		return ((date.get_date() - Date(date.get_year(), Date::JANUARY, 1).get_date()) / 7) + 1;
	}

	// OK
	int day_of_week(const Date& date) {
		return ((date.get_date() - Date(date.get_year(), Date::JANUARY, 1).get_date()) % 7) + 1;
	}

	// TODO
	Date next_Sunday(const Date& date) {
		/*
		Date copy(d);
		copy.add_day(7 - (day_of_week(d) - Date::sun));
		if (copy.get_year() > d.get_year()) copy = Date(copy.get_year(), Date::jan, 1);
		return copy;
		*/

		int add = 0;
		int dow = day_of_week(date);
		if (dow == Date::SUNDAY) add = 7;
		else add = Date::SUNDAY - dow;

		return Date(date.get_date() + add);
	}

	// TODO
	Date next_workday(const Date& date) {
		/*
		Date copy(d);
		Date::Day day = day_of_week(d);
		switch (day) {
		case Date::fri:
			copy.add_day(3);
			break;
		case Date::sat:
			copy.add_day(2);
			break;
		default:
			copy.add_day(1);
			break;
		}
		if (copy.get_year() > d.get_year()) copy = Date(copy.get_year(), Date::jan, 2);
		return copy;
		*/

		return default_date();
	}

	// OK
	bool operator==(const Date& date1, const Date& date2) {
		return date1.get_date() == date2.get_date();
	}

	// OK
	bool operator!=(const Date& date1, const Date& date2) {
		return !(date1 == date2);
	}

	// OK
	ostream& operator<<(ostream& os, const Date& date) {
		return os << '(' << date.get_year()
			<< ',' << date.get_month()
			<< ',' << date.get_day() << ')';
	}

	// OK
	istream& operator>>(std::istream& is, Date& date) {
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}

		date = Date(y, m, d);

		return is;
	}

}
