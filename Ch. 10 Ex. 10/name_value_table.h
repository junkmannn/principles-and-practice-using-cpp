#ifndef NAME_VALUE_TABLE_H
#define NAME_VALUE_TABLE_H

#include <unordered_map>
#include "name_value.h"

class Name_value_table {
public:
	Name_value_table();

	// Get the corresponding name and value pair from the table
	// Return false if the name is not defined
	bool get(const std::string& name, Name_value*& name_value);
	// Add a new name and value pair to the table
	// Return false if the name is already defined
	bool add(const Name_value& name_value);

private:
	std::unordered_map<std::string, Name_value> table;
};

#endif
