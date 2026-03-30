#include "../std_lib_facilities.h"

int main() {
	cout << "How many pennies do you have? ";
	int pennies;
	cin >> pennies;

	cout << "How many nickels do you have? ";
	int nickels;
	cin >> nickels;

	cout << "How many dimes do you have? ";
	int dimes;
	cin >> dimes;

	cout << "How many quarters do you have? ";
	int quarters;
	cin >> quarters;

	cout << "How many half dollars do you have? ";
	int half_dollars;
	cin >> half_dollars;

	cout << "How many one dollars do you have? ";
	int one_dollars;
	cin >> one_dollars;

	if (pennies > 1) cout << "You have " << pennies << " pennies\n";
	else cout << "You have " << pennies << " penny\n";

	if (nickels > 1) cout << "You have " << nickels << " nickels\n";
	else cout << "You have " << nickels << " nickel\n";

	if (dimes > 1) cout << "You have " << dimes << " dimes\n";
	else cout << "You have " << dimes << " dime\n";

	if (quarters > 1) cout << "You have " << quarters << " quarters\n";
	else cout << "You have " << quarters << " quarter\n";

	if (half_dollars > 1) cout << "You have " << half_dollars << " half dollars\n";
	else cout << "You have " << half_dollars << " half dollar\n";

	if (one_dollars > 1) cout << "You have " << one_dollars << " one dollars\n";
	else cout << "You have " << one_dollars << " one dollar\n";

	double total = (pennies * 1 + nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + one_dollars * 100) / 100.0;
	cout << "The value of all your coins is $" << total << '\n';

	keep_window_open();
	return 0;
}