#ifndef NAME_VALUE_H
#define NAME_VALUE_H

#include <string>

class Name_value {
public:
	// Create a name and value pair
	Name_value(const std::string& name, double value, bool constant);

	const std::string& get_name() const;
	double get_value() const;
	bool is_constant() const;

	// Only for variables
	void set_value(double new_value);

private:
	std::string name;
	double value;
	bool constant;
};

#endif
