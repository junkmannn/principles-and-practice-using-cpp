#include <iostream>

using namespace std;

int fac_recursive(int n);
int fac_iterative(int n);
void keep_window_open();

int main() {
	cout << "Recursive:\n";
	for (int i = 0; i <= 12; ++i) {
		cout << i << "! = " << fac_recursive(i) << '\n';
	}

	cout << "\nIterative:\n";
	for (int i = 0; i <= 12; ++i) {
		cout << i << "! = " << fac_iterative(i) << '\n';
	}

	keep_window_open();

	return 0;
}

int fac_recursive(int n) {
	return (n > 1) ? n*fac_recursive(n-1) : 1;
}

int fac_iterative(int n) {
	int ret = 1;
	for (; n > 1; --n) ret *= n;
	return ret;
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
