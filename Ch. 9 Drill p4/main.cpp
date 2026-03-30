#include "../std_lib_facilities.h"
#include "date.h"

int main() {
	try {
		Date today(1978, Date::jun, 25);
		cout << "Today: " << today << '\n';
		Date tomorrow(today);
		tomorrow.add_day(1);
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
