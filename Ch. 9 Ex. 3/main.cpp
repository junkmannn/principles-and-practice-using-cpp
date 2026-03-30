#include "Name_pairs.h"
#include "../std_lib_facilities.h"

int main() {
	cout << "np1\n";
	Name_pairs np1;
	np1.read_names();
	np1.read_ages();
	np1.sort();
	cout << np1;

	cout << "np2\n";
	Name_pairs np2;
	np2.read_names();
	np2.read_ages();
	np2.sort();
	cout << np2;

	cout << "np1==np2 " << (np1==np2) << "\n";
	cout << "np1!=np2 " << (np1!=np2) << "\n";

	keep_window_open();

	return 0;
}