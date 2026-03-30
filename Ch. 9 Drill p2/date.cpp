#include "date.h"

using namespace std;

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {
	if (m < 1 || m > 12 || d < 1 || d > 31) throw Invalid();
}

void Date::add_day(int n) {
	d += n;
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')';
}
