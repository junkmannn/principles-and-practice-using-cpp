#include "date.h"

using namespace std;

void init_date(Date& dd, int y, int m, int d) {
	if (m < 1 || m > 12 || d < 1 || d > 31) throw Invalid();
	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n) {
	dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.y
			  << ',' << d.m
			  << ',' << d.d << ')';
}
