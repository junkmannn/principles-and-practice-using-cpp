#include "../std_lib_facilities.h"

int main() {
	// 0 = prime
	// 1 = not prime
	vector<int> primes(100+1); // [0,100]

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

	cout << "Primes from 1 to 100\n";
	for (int i = 0; i < primes.size(); ++i) {
		if (primes[i] == 0) {
			cout << i << '\n';
		}
	}

	keep_window_open();

	return 0;
}