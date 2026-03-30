#include "../std_lib_facilities.h"

int main() {
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;
	cout << "\nDear " << first_name << ",\n\n"
		 << "How are you? I am fine. I miss you.\n\n";

	cout << "Enter the name of another friend:\n";
	string friend_name;
	cin >> friend_name;
	cout << "\nHave you seen " << friend_name << " lately?\n\n";

	cout << "Enter an 'm' if the friend is male or an 'f' if the friend is female:\n";
	char friend_sex = 0;
	cin >> friend_sex;
	if (friend_sex == 'm') {
		cout << "\nIf you see " << friend_name << " please ask him to call me.\n\n";
	}
	else if (friend_sex == 'f') {
		cout << "\nIf you see " << friend_name << " please ask her to call me.\n\n";
	}

	cout << "Enter the age of the recipient:\n";
	int age;
	cin >> age;
	if (age <= 0) {
		simple_error("you're kidding!\n");
	}
	else if (age >= 110) {
		simple_error("you're kidding!\n");
	}
	cout << "\nI hear you just had a birthday and you are " << age << " years old. ";
	if (age < 12) {
		cout << "Next year you will be " << age + 1 << ".\n\n";
	}
	else if (age == 17) {
		cout << "Next year you will be able to vote.\n\n";
	}
	else if (age > 70) {
		cout << "I hope you are enjoying retirement.\n\n";
	}

	cout << "Yours sincerely,\n\n\nAdrian\n\n";

	keep_window_open();
	return 0;
}