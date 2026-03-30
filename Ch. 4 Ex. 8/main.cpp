#include "../std_lib_facilities.h"
#include <stdint.h>

int main() {
	vector<uint64_t> steps;
	steps.push_back(1000);
	steps.push_back(1000000);
	steps.push_back(1000000000);
	steps.push_back(9223372036854775807);

	uint32_t current_step = 0;
	uint64_t current_square = 1;
	uint64_t total_grains = 1;
	for (int i = 1; i <= 64; ++i) {
		while (total_grains >= steps[current_step]) {
			cout << "Minimum squares needed for " << steps[current_step] << " grains of rice is " << i << " (" << total_grains << ")\n";
			++current_step;
			if (!(current_step < steps.size())) goto done;
		}
		current_square *= 2;
		total_grains += current_square;
	}
	done:

	keep_window_open();

	return 0;
}