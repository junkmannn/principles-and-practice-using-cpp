#include "date.h"

using namespace std;

/*
Year::Year(int y) : y(y) {
	if (y < min || y > max) throw Invalid();
}
*/

Date::Date() : y(default_date().y), m(default_date().m), d(default_date().d) { };

Date::Date(int y, Month m, int d) : y(y), m(m), d(d) {
	if (!check()) throw Invalid();
}

void Date::add_day(int n) {
	d += n;
}

bool Date::check() {
	return !(d < 1 || d > 31);
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}

const Date& default_date() {
	static Date dd(2001, Date::jan, 1);
	return dd;
}
