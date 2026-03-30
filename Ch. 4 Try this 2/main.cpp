#include "../std_lib_facilities.h"

int main() {
	const double yen_to_dollar = 0.0082;
	const double yuan_to_dollar = 0.16;
	const double euro_to_dollar = 1.12;
	const double krone_to_dollar = 0.15;
	const double pound_to_dollar = 1.57;
	double amount = 0;
	char currency = ' ';

	cout << "Please enter an amount of money followed by its currency.\nSupported currencies are yen(y), yuan(u), euros(e), kroner(k) and pounds(p).\n";

	cin >> amount >> currency;

	switch (currency) {
		case 'y':
			cout << amount << " yen == " << amount*yen_to_dollar << " dollars\n";
			break;
		case 'u':
			cout << amount << " yuan == " << amount*yuan_to_dollar << " dollars\n";
			break;
		case 'e':
			cout << amount << " euros == " << amount*euro_to_dollar << " dollars\n";
			break;
		case 'k':
			cout << amount << " kroner == " << amount*krone_to_dollar << " dollars\n";
			break;
		case 'p':
			cout << amount << " pounds == " << amount*pound_to_dollar << " dollars\n";
			break;
		default:
			cout << "Sorry, I don't know a currency called '" << currency << "'\n";
			break;
	}

	keep_window_open();

	return 0;
}