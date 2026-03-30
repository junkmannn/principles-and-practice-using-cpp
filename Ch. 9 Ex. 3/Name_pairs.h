#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H

#include <vector>
#include <string>

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void sort();
	std::vector<std::string> get_name() const;
	std::vector<double> get_age() const;
private:
	static const int UNDEFINED_AGE = -1;
	std::vector<std::string> name;
	std::vector<double> age;
};

bool operator==(const Name_pairs& a, const Name_pairs& b);
bool operator!=(const Name_pairs& a, const Name_pairs& b);
std::ostream& operator<<(std::ostream& os, const Name_pairs& a);

#endif
