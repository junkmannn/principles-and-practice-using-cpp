#include <string>
#include <iostream>
#include "file_utils.h"

using namespace std;

inline void keep_window_open();

int main() {
	cout << "Please enter the name of the files (2) you would like to concatenate and the output file name.\n";
	string ifname1, ifname2, ofname;
	cin >> ifname1 >> ifname2 >> ofname;

	int i = 0;

	try {
		if (ifname1 == ifname2) {
			if (ifname1 == ofname) {
				File_utils::concatenate_self_overwrite(ifname1);
			}
			else {
				File_utils::concatenate_self(ifname1, ofname);
			}
		}
		else if (ifname1 == ofname) {
			File_utils::concatenate_overwrite(ifname1, ifname2);
		}
		else if (ifname2 == ofname) {
			File_utils::concatenate_overwrite(ifname2, ifname1);
		}
		else {
			File_utils::concatenate(ifname1, ifname2, ofname);
		}
	}
	catch (ios_base::failure &e) {
		cerr << "An unexpected error occurred while reading/writing file.\n";
	}
	catch (runtime_error &e) {
		cerr << e.what() << '\n';
	}

	keep_window_open();

	return 0;
}

inline void keep_window_open() {
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
}
