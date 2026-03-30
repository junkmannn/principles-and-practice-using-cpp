#include "Name_pairs.h"
#include "../std_lib_facilities.h"

int main() {
	Name_pairs np;
	np.read_names();
	np.read_ages();
	np.sort();
	np.print();

	keep_window_open();

	return 0;
}