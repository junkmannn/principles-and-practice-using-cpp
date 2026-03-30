#include "../std_lib_facilities.h"

int main() {
	cout << "Primes from 1 to max\nmax = ";
	int max = 0;
	cin >> max;
	if (max < 2) {
		simple_error("max's value must be greater or equal to 2");
	}
	else {
		// 0 = prime
		// 1 = not prime
		vector<int> primes(max+1); // [0,max]

		// we already know that 0 and 1 are not prime numbers
		primes[0] = 1;
		primes[1] = 1;

		for (int i = 2; i < primes.size(); ++i) {
			if (primes[i] == 0) {
				for (int j = i+i; j < primes.size(); j+=i) {
					primes[j] = 1;
				}
			}
		}

		cout << "Primes from 1 to " << max << '\n';
		for (int i = 0; i < primes.size(); ++i) {
			if (primes[i] == 0) {
				cout << i << '\n';
			}
		}
	}

	keep_window_open();

	return 0;
}