#include "../std_lib_facilities.h"
#include "chrono.h"

using namespace Chrono;

void test_add_day();
void test_add_month();
void test_add_year();
void test_week_of_year();
void test_day_of_week();
void test_next_Sunday();
void test_next_workday();

int main() {
	try {
		test_add_day();
		test_add_month();
		test_add_year();
		test_week_of_year();
		test_day_of_week();
		test_next_Sunday();
		test_next_workday();
		keep_window_open();
		return 0;
	}
	catch (Date::Invalid &e) {
		cout << "invalid date\n";
		keep_window_open();
		return 1;
	}
}

void test_add_day() {
	cout << "test_add_day()...\n";

	Date d;

	// Batch 1
	// --------------------------------------------------------------
	d = Date(2010, Date::mar, 1);
	d.add_day(0);
	cout << "1. " << d << " = " << Date(2010, Date::mar, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(1);
	cout << "2. " << d << " = " << Date(2010, Date::mar, 2) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(30);
	cout << "3. " << d << " = " << Date(2010, Date::mar, 31) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(31);
	cout << "4. " << d << " = " << Date(2010, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(60);
	cout << "5. " << d << " = " << Date(2010, Date::apr, 30) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(61);
	cout << "6. " << d << " = " << Date(2010, Date::may, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(92);
	cout << "7. " << d << " = " << Date(2010, Date::jun, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(122);
	cout << "8. " << d << " = " << Date(2010, Date::jul, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(153);
	cout << "9. " << d << " = " << Date(2010, Date::aug, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(184);
	cout << "10. " << d << " = " << Date(2010, Date::sep, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(214);
	cout << "11. " << d << " = " << Date(2010, Date::oct, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(245);
	cout << "11. " << d << " = " << Date(2010, Date::nov, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(275);
	cout << "11. " << d << " = " << Date(2010, Date::dec, 1) << '\n';
	// --------------------------------------------------------------

	// Batch 2
	// --------------------------------------------------------------
	d = Date(2010, Date::mar, 1);
	d.add_day(396);
	cout << "12. " << d << " = " << Date(2011, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(762);
	cout << "13. " << d << " = " << Date(2012, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(1127);
	cout << "14. " << d << " = " << Date(2013, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(1492);
	cout << "15. " << d << " = " << Date(2014, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(1857);
	cout << "16. " << d << " = " << Date(2015, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_day(2223);
	cout << "17. " << d << " = " << Date(2016, Date::apr, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(396);
	cout << "18. " << d << " = " << Date(2011, Date::feb, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(761);
	cout << "19. " << d << " = " << Date(2012, Date::feb, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(1127);
	cout << "20. " << d << " = " << Date(2013, Date::feb, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(1492);
	cout << "21. " << d << " = " << Date(2014, Date::feb, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(1857);
	cout << "22. " << d << " = " << Date(2015, Date::feb, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(2222);
	cout << "23. " << d << " = " << Date(2016, Date::feb, 1) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(2588);
	cout << "24. " << d << " = " << Date(2017, Date::feb, 1) << '\n';
	// --------------------------------------------------------------

	// Batch 3
	// --------------------------------------------------------------
	d = Date(2010, Date::nov, 1);
	d.add_day(61);
	cout << "25. " << d << " = " << Date(2011, Date::jan, 1) << '\n';

	d = Date(2010, Date::nov, 1);
	d.add_day(120);
	cout << "26. " << d << " = " << Date(2011, Date::mar, 1) << '\n';

	d = Date(2011, Date::nov, 1);
	d.add_day(120);
	cout << "27. " << d << " = " << Date(2012, Date::feb, 29) << '\n';

	d = Date(2011, Date::nov, 1);
	d.add_day(121);
	cout << "28. " << d << " = " << Date(2012, Date::mar, 1) << '\n';

	d = Date(2011, Date::jan, 1);
	d.add_day(424);
	cout << "29. " << d << " = " << Date(2012, Date::feb, 29) << '\n';

	d = Date(2010, Date::jan, 1);
	d.add_day(424);
	cout << "29. " << d << " = " << Date(2012, Date::mar, 1) << '\n';
	// --------------------------------------------------------------

	cout << '\n';
}

void test_add_month() {
	cout << "test_add_month()...\n";

	Date d;

	d = Date(2010, Date::mar, 1);
	d.add_month(1);
	cout << "1. " << d << " = " << Date(2010, Date::apr, 1) << '\n';

	d = Date(2010, Date::mar, 31);
	d.add_month(1);
	cout << "2. " << d << " = " << Date(2010, Date::apr, 30) << '\n';

	d = Date(2010, Date::mar, 1);
	d.add_month(24);
	cout << "3. " << d << " = " << Date(2012, Date::mar, 1) << '\n';

	d = Date(2012, Date::feb, 29);
	d.add_month(12);
	cout << "4. " << d << " = " << Date(2013, Date::feb, 28) << '\n';

	d = Date(2012, Date::feb, 29);
	d.add_month(48);
	cout << "5. " << d << " = " << Date(2016, Date::feb, 29) << '\n';

	d = Date(2012, Date::dec, 31);
	d.add_month(1);
	cout << "6. " << d << " = " << Date(2013, Date::jan, 31) << '\n';

	d = Date(2012, Date::jul, 31);
	d.add_month(7);
	cout << "7. " << d << " = " << Date(2013, Date::feb, 28) << '\n';

	cout << '\n';
}

void test_add_year() {
	cout << "test_add_year()...\n";

	Date d;

	d = Date(2010, Date::mar, 1);
	d.add_year(1);
	cout << "1. " << d << " = " << Date(2011, Date::mar, 1) << '\n';

	d = Date(2010, Date::feb, 28);
	d.add_year(2);
	cout << "2. " << d << " = " << Date(2012, Date::feb, 28) << '\n';

	d = Date(2012, Date::feb, 29);
	d.add_year(4);
	cout << "3. " << d << " = " << Date(2016, Date::feb, 29) << '\n';

	d = Date(2012, Date::feb, 29);
	d.add_year(5);
	cout << "4. " << d << " = " << Date(2017, Date::feb, 28) << '\n';

	cout << '\n';
}

void test_week_of_year() {
	cout << "test_week_of_year()...\n";

	Date d;

	d = Date(2010, Date::jan, 1);
	cout << "1. " << week_of_year(d) << " = 1\n";

	d = Date(2010, Date::jan, 7);
	cout << "2. " << week_of_year(d) << " = 1\n";

	d = Date(2010, Date::jan, 8);
	cout << "3. " << week_of_year(d) << " = 2\n";

	d = Date(2010, Date::jan, 14);
	cout << "4. " << week_of_year(d) << " = 2\n";

	d = Date(2010, Date::jan, 15);
	cout << "5. " << week_of_year(d) << " = 3\n";

	d = Date(2010, Date::jan, 29);
	cout << "6. " << week_of_year(d) << " = 5\n";

	d = Date(2010, Date::feb, 4);
	cout << "7. " << week_of_year(d) << " = 5\n";

	d = Date(2010, Date::feb, 5);
	cout << "8. " << week_of_year(d) << " = 6\n";

	d = Date(2010, Date::mar, 4);
	cout << "9. " << week_of_year(d) << " = 9\n";

	d = Date(2012, Date::mar, 4);
	cout << "10. " << week_of_year(d) << " = 10\n";

	d = Date(2010, Date::dec, 31);
	cout << "11. " << week_of_year(d) << " = 53\n";

	d = Date(2012, Date::dec, 31);
	cout << "12. " << week_of_year(d) << " = 53\n";

	cout << '\n';
}

void test_day_of_week() {
	cout << "test_day_of_week()...\n";

	Date d;

	d = Date(2010, Date::jan, 1);
	cout << "1. " << day_of_week(d) << " = 0\n";

	d = Date(2010, Date::jan, 7);
	cout << "2. " << day_of_week(d) << " = 6\n";

	d = Date(2010, Date::jan, 8);
	cout << "3. " << day_of_week(d) << " = 0\n";

	d = Date(2010, Date::jan, 10);
	cout << "4. " << day_of_week(d) << " = 2\n";

	d = Date(2010, Date::mar, 4);
	cout << "5. " << day_of_week(d) << " = 6\n";

	d = Date(2012, Date::mar, 4);
	cout << "6. " << day_of_week(d) << " = 0\n";

	cout << '\n';
}

void test_next_Sunday() {
	cout << "test_next_Sunday()...\n";

	Date d;

	d = Date(2010, Date::jan, 1);
	cout << "1. " << next_Sunday(d) << " = " << Date(2010, Date::jan, 8) << '\n';

	d = Date(2010, Date::jan, 4);
	cout << "2. " << next_Sunday(d) << " = " << Date(2010, Date::jan, 8) << '\n';

	d = Date(2010, Date::jan, 28);
	cout << "3. " << next_Sunday(d) << " = " << Date(2010, Date::jan, 29) << '\n';

	d = Date(2010, Date::jan, 30);
	cout << "4. " << next_Sunday(d) << " = " << Date(2010, Date::feb, 5) << '\n';

	d = Date(2010, Date::dec, 31);
	cout << "5. " << next_Sunday(d) << " = " << Date(2011, Date::jan, 1) << '\n';

	d = Date(2010, Date::dec, 24);
	cout << "6. " << next_Sunday(d) << " = " << Date(2010, Date::dec, 31) << '\n';

	cout << '\n';
}

void test_next_workday() {
	cout << "test_next_workday()...\n";

	Date d;

	d = Date(2010, Date::jan, 1);
	cout << "1. " << next_workday(d) << " = " << Date(2010, Date::jan, 2) << '\n';

	d = Date(2010, Date::jan, 2);
	cout << "2. " << next_workday(d) << " = " << Date(2010, Date::jan, 3) << '\n';

	d = Date(2010, Date::jan, 5);
	cout << "3. " << next_workday(d) << " = " << Date(2010, Date::jan, 6) << '\n';

	d = Date(2010, Date::jan, 6);
	cout << "4. " << next_workday(d) << " = " << Date(2010, Date::jan, 9) << '\n';

	d = Date(2010, Date::dec, 28);
	cout << "5. " << next_workday(d) << " = " << Date(2010, Date::dec, 29) << '\n';

	d = Date(2010, Date::dec, 29);
	cout << "6. " << next_workday(d) << " = " << Date(2011, Date::jan, 2) << '\n';

	cout << '\n';
}
