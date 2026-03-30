#include <iostream>

using namespace std;

void keep_window_open();

int main() {
	int birthyear = 1995;
	cout << "Birth year:\n" << dec << birthyear << " (dec)\t" << hex << birthyear << " (hex)\t" << oct << birthyear << " (oct)\n";

	int age = 20;
	cout << "Age:\n" << dec << age << " (dec)\t" << hex << age << " (hex)\t" << oct << age << " (oct)\n";

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
