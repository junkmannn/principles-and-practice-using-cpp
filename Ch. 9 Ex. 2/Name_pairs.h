#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H

#include <vector>
#include <string>

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print();
	void sort();
private:
	static const int UNDEFINED_AGE = -1;
	std::vector<std::string> name;
	std::vector<double> age;
};

#endif
