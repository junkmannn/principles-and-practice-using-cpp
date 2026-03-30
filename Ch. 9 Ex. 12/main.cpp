#include "chrono.h"

using namespace Chrono;
using namespace std;

void test_convert();
void test_get_year();
void test_get_month();
void test_get_day();
void test_get_year_month_day();
void test_add_day();
void test_add_month();
void test_add_year();
void test_week_of_year();
void test_day_of_week();
void test_next_Sunday();
void test_next_workday();

inline void keep_window_open();

int main() {
	try {
		// test_convert();
		// test_get_year();
		// test_get_month();
		// test_get_day();
		// test_get_year_month_day();
		// test_add_day();
		// test_add_month();
		// test_add_year();
		// test_week_of_year();
		// test_day_of_week();
		test_next_Sunday();
		// test_next_workday();

		keep_window_open();
		return 0;
	}
	catch (Date::Invalid &e) {
		cout << "invalid date\n";
		keep_window_open();
		return 1;
	}
}

void test_convert() {
	cout << "test_convert()...\n";

	cout << "1. " << convert(1970, Date::JANUARY, 1) << " = 0\n";

	cout << "2. " << convert(1970, Date::FEBRUARY, 1) << " = 31\n";

	cout << "3. " << convert(2000, Date::JANUARY, 1) << " = 10957\n";

	cout << "4. " << convert(2000, Date::APRIL, 28) << " = 11075\n";

	cout << "5. " << convert(2000, Date::DECEMBER, 31) << " = 11322\n";

	cout << "6. " << convert(2001, Date::FEBRUARY, 28) << " = 11381\n";

	cout << "7. " << convert(2003, Date::OCTOBER, 3) << " = 12328\n";

	cout << "8. " << convert(2100, Date::JUNE, 13) << " = 47645\n";

	cout << "9. " << convert(2100, Date::JUNE, 13) << " = 47645\n";

	cout << "10. " << convert(2101, Date::JUNE, 13) << " = 48010\n";

	cout << "11. " << convert(2200, Date::JUNE, 13) << " = 84169\n";

	cout << "12. " << convert(2250, Date::JUNE, 13) << " = 102431\n";

	cout << "13. " << convert(2400, Date::JUNE, 13) << " = 157218\n";

	cout << "14. " << convert(2425, Date::JUNE, 13) << " = 166349\n";

	cout << "15. " << convert(2700, Date::JUNE, 13) << " = 266790\n";

	cout << "16. " << convert(2701, Date::JUNE, 13) << " = 267155\n";

	cout << '\n';
}

void test_get_year() {
	cout << "test_get_year()...\n";

	for (int y = 1970; y < 1000000; ++y) {
		for (int m = Date::JANUARY; m <= Date::DECEMBER; ++m) {
			int mlength = month_length(m, y);
			for (int d = 1; d <= mlength; ++d) {
				Date date(y, m, d);
				int ytest = date.get_year();
				if (ytest != y) {
					cout << "Error: year " << ytest << " expected " << y << '\n';
					cout << '(' << y << ',' << m << ',' << d << ")\n";
					cout << date.get_date() << "\n\n";
					return;
				}
			}
		}
	}

	cout << '\n';
}

void test_get_month() {
	cout << "test_get_month()...\n";

	for (int y = 1970; y < 1000000; ++y) {
		for (int m = Date::JANUARY; m <= Date::DECEMBER; ++m) {
			int mlength = month_length(m, y);
			for (int d = 1; d <= mlength; ++d) {
				Date date(y, m, d);
				int mtest = date.get_month();
				if (mtest != m) {
					cout << "Error: month " << mtest << " expected " << m << '\n';
					cout << '(' << y << ',' << m << ',' << d << ")\n";
					cout << date.get_date() << "\n\n";
					return;
				}
			}
		}
	}

	cout << '\n';
}

void test_get_day() {
	cout << "test_get_day()...\n";

	for (int y = 1970; y < 1000000; ++y) {
		for (int m = Date::JANUARY; m <= Date::DECEMBER; ++m) {
			int mlength = month_length(m, y);
			for (int d = 1; d <= mlength; ++d) {
				Date date(y, m, d);
				int dtest = date.get_day();
				if (dtest != d) {
					cout << "Error: day " << dtest << " expected " << d << '\n';
					cout << '(' << y << ',' << m << ',' << d << ")\n";
					cout << date.get_date() << "\n\n";
					return;
				}
			}
		}
	}

	cout << '\n';
}

void test_get_year_month_day() {
	cout << "test_get_year_month_day()...\n";

	for (int y = 1970; y < 1000000; ++y) {
		for (int m = Date::JANUARY; m <= Date::DECEMBER; ++m) {
			int mlength = month_length(m, y);
			for (int d = 1; d <= mlength; ++d) {
				Date date(y, m, d);
				Date::Year_Month_Day ymd = date.get_year_month_day();
				if (ymd.day != d) {
					cout << "Error: day " << ymd.day << " expected " << d << '\n';
					cout << '(' << y << ',' << m << ',' << d << ")\n";
					cout << date.get_date() << "\n\n";
					return;
				}
				if (ymd.month != m) {
					cout << "Error: month " << ymd.month << " expected " << m << '\n';
					cout << '(' << y << ',' << m << ',' << d << ")\n";
					cout << date.get_date() << "\n\n";
					return;
				}
				if (ymd.year != y) {
					cout << "Error: year " << ymd.year << " expected " << y << '\n';
					cout << '(' << y << ',' << m << ',' << d << ")\n";
					cout << date.get_date() << "\n\n";
					return;
				}
			}
		}
	}

	cout << '\n';
}

void test_add_day() {
	cout << "test_add_day()...\n";

	Date d;

	// Batch 1
	// --------------------------------------------------------------
	d = Date(2010, Date::MARCH, 1);
	d.add_day(0);
	cout << "1. " << d << " = " << Date(2010, Date::MARCH, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(1);
	cout << "2. " << d << " = " << Date(2010, Date::MARCH, 2) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(30);
	cout << "3. " << d << " = " << Date(2010, Date::MARCH, 31) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(31);
	cout << "4. " << d << " = " << Date(2010, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(60);
	cout << "5. " << d << " = " << Date(2010, Date::APRIL, 30) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(61);
	cout << "6. " << d << " = " << Date(2010, Date::MAY, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(92);
	cout << "7. " << d << " = " << Date(2010, Date::JUNE, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(122);
	cout << "8. " << d << " = " << Date(2010, Date::JULY, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(153);
	cout << "9. " << d << " = " << Date(2010, Date::AUGUST, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(184);
	cout << "10. " << d << " = " << Date(2010, Date::SEPTEMBER, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(214);
	cout << "11. " << d << " = " << Date(2010, Date::OCTOBER, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(245);
	cout << "11. " << d << " = " << Date(2010, Date::NOVEMBER, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(275);
	cout << "11. " << d << " = " << Date(2010, Date::DECEMBER, 1) << '\n';
	// --------------------------------------------------------------

	// Batch 2
	// --------------------------------------------------------------
	d = Date(2010, Date::MARCH, 1);
	d.add_day(396);
	cout << "12. " << d << " = " << Date(2011, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(762);
	cout << "13. " << d << " = " << Date(2012, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(1127);
	cout << "14. " << d << " = " << Date(2013, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(1492);
	cout << "15. " << d << " = " << Date(2014, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(1857);
	cout << "16. " << d << " = " << Date(2015, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_day(2223);
	cout << "17. " << d << " = " << Date(2016, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(396);
	cout << "18. " << d << " = " << Date(2011, Date::FEBRUARY, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(761);
	cout << "19. " << d << " = " << Date(2012, Date::FEBRUARY, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(1127);
	cout << "20. " << d << " = " << Date(2013, Date::FEBRUARY, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(1492);
	cout << "21. " << d << " = " << Date(2014, Date::FEBRUARY, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(1857);
	cout << "22. " << d << " = " << Date(2015, Date::FEBRUARY, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(2222);
	cout << "23. " << d << " = " << Date(2016, Date::FEBRUARY, 1) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(2588);
	cout << "24. " << d << " = " << Date(2017, Date::FEBRUARY, 1) << '\n';
	// --------------------------------------------------------------

	// Batch 3
	// --------------------------------------------------------------
	d = Date(2010, Date::NOVEMBER, 1);
	d.add_day(61);
	cout << "25. " << d << " = " << Date(2011, Date::JANUARY, 1) << '\n';

	d = Date(2010, Date::NOVEMBER, 1);
	d.add_day(120);
	cout << "26. " << d << " = " << Date(2011, Date::MARCH, 1) << '\n';

	d = Date(2011, Date::NOVEMBER, 1);
	d.add_day(120);
	cout << "27. " << d << " = " << Date(2012, Date::FEBRUARY, 29) << '\n';

	d = Date(2011, Date::NOVEMBER, 1);
	d.add_day(121);
	cout << "28. " << d << " = " << Date(2012, Date::MARCH, 1) << '\n';

	d = Date(2011, Date::JANUARY, 1);
	d.add_day(424);
	cout << "29. " << d << " = " << Date(2012, Date::FEBRUARY, 29) << '\n';

	d = Date(2010, Date::JANUARY, 1);
	d.add_day(424);
	cout << "29. " << d << " = " << Date(2012, Date::MARCH, 1) << '\n';
	// --------------------------------------------------------------

	cout << '\n';
}

void test_add_month() {
	cout << "test_add_month()...\n";

	Date d;

	d = Date(2010, Date::MARCH, 1);
	d.add_month(1);
	cout << "1. " << d << " = " << Date(2010, Date::APRIL, 1) << '\n';

	d = Date(2010, Date::MARCH, 31);
	d.add_month(1);
	cout << "2. " << d << " = " << Date(2010, Date::APRIL, 30) << '\n';

	d = Date(2010, Date::MARCH, 1);
	d.add_month(24);
	cout << "3. " << d << " = " << Date(2012, Date::MARCH, 1) << '\n';

	d = Date(2012, Date::FEBRUARY, 29);
	d.add_month(12);
	cout << "4. " << d << " = " << Date(2013, Date::FEBRUARY, 28) << '\n';

	d = Date(2012, Date::FEBRUARY, 29);
	d.add_month(48);
	cout << "5. " << d << " = " << Date(2016, Date::FEBRUARY, 29) << '\n';

	d = Date(2012, Date::DECEMBER, 31);
	d.add_month(1);
	cout << "6. " << d << " = " << Date(2013, Date::JANUARY, 31) << '\n';

	d = Date(2012, Date::JULY, 31);
	d.add_month(7);
	cout << "7. " << d << " = " << Date(2013, Date::FEBRUARY, 28) << '\n';

	cout << '\n';
}

void test_add_year() {
	cout << "test_add_year()...\n";

	Date d;

	d = Date(2010, Date::MARCH, 1);
	d.add_year(1);
	cout << "1. " << d << " = " << Date(2011, Date::MARCH, 1) << '\n';

	d = Date(2010, Date::FEBRUARY, 28);
	d.add_year(2);
	cout << "2. " << d << " = " << Date(2012, Date::FEBRUARY, 28) << '\n';

	d = Date(2012, Date::FEBRUARY, 29);
	d.add_year(4);
	cout << "3. " << d << " = " << Date(2016, Date::FEBRUARY, 29) << '\n';

	d = Date(2012, Date::FEBRUARY, 29);
	d.add_year(5);
	cout << "4. " << d << " = " << Date(2017, Date::FEBRUARY, 28) << '\n';

	cout << '\n';
}

void test_week_of_year() {
	cout << "test_week_of_year()...\n";

	Date d;

	d = Date(2010, Date::JANUARY, 1);
	cout << "1. " << week_of_year(d) << " = 1\n";

	d = Date(2010, Date::JANUARY, 7);
	cout << "2. " << week_of_year(d) << " = 1\n";

	d = Date(2010, Date::JANUARY, 8);
	cout << "3. " << week_of_year(d) << " = 2\n";

	d = Date(2010, Date::JANUARY, 14);
	cout << "4. " << week_of_year(d) << " = 2\n";

	d = Date(2010, Date::JANUARY, 15);
	cout << "5. " << week_of_year(d) << " = 3\n";

	d = Date(2010, Date::JANUARY, 29);
	cout << "6. " << week_of_year(d) << " = 5\n";

	d = Date(2010, Date::FEBRUARY, 4);
	cout << "7. " << week_of_year(d) << " = 5\n";

	d = Date(2010, Date::FEBRUARY, 5);
	cout << "8. " << week_of_year(d) << " = 6\n";

	d = Date(2010, Date::MARCH, 4);
	cout << "9. " << week_of_year(d) << " = 9\n";

	d = Date(2012, Date::MARCH, 4);
	cout << "10. " << week_of_year(d) << " = 10\n";

	d = Date(2010, Date::DECEMBER, 31);
	cout << "11. " << week_of_year(d) << " = 53\n";

	d = Date(2012, Date::DECEMBER, 31);
	cout << "12. " << week_of_year(d) << " = 53\n";

	cout << '\n';
}

void test_day_of_week() {
	cout << "test_day_of_week()...\n";

	Date d;

	d = Date(2010, Date::JANUARY, 1);
	cout << "1. " << day_of_week(d) << " = 1\n";

	d = Date(2010, Date::JANUARY, 7);
	cout << "2. " << day_of_week(d) << " = 7\n";

	d = Date(2010, Date::JANUARY, 8);
	cout << "3. " << day_of_week(d) << " = 1\n";

	d = Date(2010, Date::JANUARY, 10);
	cout << "4. " << day_of_week(d) << " = 3\n";

	d = Date(2010, Date::MARCH, 4);
	cout << "5. " << day_of_week(d) << " = 7\n";

	d = Date(2012, Date::MARCH, 4);
	cout << "6. " << day_of_week(d) << " = 1\n";

	cout << '\n';
}

void test_next_Sunday() {
	cout << "test_next_Sunday()...\n";

	Date d;

	d = Date(2010, Date::JANUARY, 1);
	cout << "1. " << next_Sunday(d) << " = " << Date(2010, Date::JANUARY, 7) << '\n';

	d = Date(2010, Date::JANUARY, 4);
	cout << "2. " << next_Sunday(d) << " = " << Date(2010, Date::JANUARY, 7) << '\n';

	d = Date(2010, Date::JANUARY, 28);
	cout << "3. " << next_Sunday(d) << " = " << Date(2010, Date::FEBRUARY, 4) << '\n';

	d = Date(2010, Date::JANUARY, 30);
	cout << "4. " << next_Sunday(d) << " = " << Date(2010, Date::FEBRUARY, 4) << '\n';

	/*
	d = Date(2010, Date::DECEMBER, 31);
	cout << "5. " << next_Sunday(d) << " = " << Date(2011, Date::JANUARY, 1) << '\n';

	d = Date(2010, Date::DECEMBER, 24);
	cout << "6. " << next_Sunday(d) << " = " << Date(2010, Date::DECEMBER, 31) << '\n';
	*/

	cout << '\n';
}

void test_next_workday() {
	cout << "test_next_workday()...\n";

	Date d;

	d = Date(2010, Date::JANUARY, 1);
	cout << "1. " << next_workday(d) << " = " << Date(2010, Date::JANUARY, 2) << '\n';

	d = Date(2010, Date::JANUARY, 2);
	cout << "2. " << next_workday(d) << " = " << Date(2010, Date::JANUARY, 3) << '\n';

	d = Date(2010, Date::JANUARY, 5);
	cout << "3. " << next_workday(d) << " = " << Date(2010, Date::JANUARY, 6) << '\n';

	d = Date(2010, Date::JANUARY, 6);
	cout << "4. " << next_workday(d) << " = " << Date(2010, Date::JANUARY, 9) << '\n';

	d = Date(2010, Date::DECEMBER, 28);
	cout << "5. " << next_workday(d) << " = " << Date(2010, Date::DECEMBER, 29) << '\n';

	d = Date(2010, Date::DECEMBER, 29);
	cout << "6. " << next_workday(d) << " = " << Date(2011, Date::JANUARY, 2) << '\n';

	cout << '\n';
}









inline void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}
