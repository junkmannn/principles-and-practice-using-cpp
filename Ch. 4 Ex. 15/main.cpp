#include "../std_lib_facilities.h"

bool is_prime(int number);

vector<int> primes;

int main() {
	cout << "This program will find the first n primes\nn = ";
	int n = 0;
	cin >> n;
	if (n < 1) {
		simple_error("n's value must be greater 0");
	}
	else {
		primes.push_back(2);
		int i = 3;
		while (primes.size() < n) {
			if (is_prime(i)) primes.push_back(i);
			++i;
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