#include "../std_lib_facilities.h"

bool is_prime(int number);

vector<int> primes;

int main() {
	primes.push_back(2);

	for (int i = 3; i <= 100; ++i) {
		if (is_prime(i)) primes.push_back(i);
	}

	cout << "Primes from 1 to 100\n";
	for (int i = 0; i < primes.size(); ++i) {
		cout << primes[i] << '\n';
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