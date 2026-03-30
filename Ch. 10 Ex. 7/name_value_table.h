#ifndef NAME_VALUE_TABLE_H
#define NAME_VALUE_TABLE_H

#include <unordered_map>
#include "name_value.h"

class Name_value_table {
public:
	Name_value_table();

	bool get(const std::string& name, Name_value*& name_value);
	bool add(const Name_value& name_value);

private:
	std::unordered_map<std::string, Name_value> table;
};

#endif
