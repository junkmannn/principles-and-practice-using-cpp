#include "../std_lib_facilities.h"
#include "date.h"

int main() {
	try {
		Date today;
		init_date(today, 1978, 6, 25);
		cout << "Today: " << today << '\n';
		Date tomorrow(today);
		add_day(tomorrow, 1);
		cout << "Tomorrow: " << tomorrow << '\n';
		keep_window_open();
		return 0;
	}
	catch (Invalid &e) {
		cout << "invalid date\n";
		keep_window_open();
		return 1;
	}
}
