#include "../std_lib_facilities.h"

bool is_prime(int number);

vector<int> primes;

int main() {
	cout << "Primes from 1 to max\nmax = ";
	int max = 0;
	cin >> max;
	if (max < 2) {
		simple_error("max's value must be greater or equal to 2");
	}
	else {
		primes.push_back(2);
		for (int i = 3; i <= max; ++i) {
			if (is_prime(i)) primes.push_back(i);
		}
		for (int i = 0; i < primes.size(); ++i) {
			cout << primes[i] << '\n';
		}
	}

	keep_window_open();

	return 0;
}

bool is_prime(int number) {
	for (int i = 0; i < primes.size(); ++i) {
		if (number % primes[i] == 0) return false;
	}
	return true;
}