#include "../std_lib_facilities.h"

int main() {
	const double yen_to_dollar = 0.0082;
	const double euro_to_dollar = 1.12;
	const double pound_to_dollar = 1.57;
	double amount = 0;
	char currency = ' ';
	cout << "Please enter an amount of money followed by its currency.\nSupported currencies are yen(y), euros(e) and pounds(p).\n";
	cin >> amount >> currency;

	if (currency == 'y') {
		cout << amount << " yen == " << amount*yen_to_dollar << " dollar\n";
	}
	else if (currency == 'e') {
		cout << amount << " euro == " << amount*euro_to_dollar << " dollar\n";
	}
	else if (currency == 'p') {
		cout << amount << " pound == " << amount*pound_to_dollar << " dollar\n";
	}
	else {
		cout << "Sorry, I don't know a currency called '" << currency << "'\n";
	}

	keep_window_open();

	return 0;
}