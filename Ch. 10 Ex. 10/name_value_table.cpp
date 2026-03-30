#include "name_value_table.h"

using namespace std;

Name_value_table::Name_value_table() : table() { }

bool Name_value_table::get(const std::string& name, Name_value*& name_value) {
	if (table.count(name) == 0) return false;
	name_value = &table.at(name);
	return true;
}

bool Name_value_table::add(const Name_value& name_value) {
	size_t sz = table.size(); // size before insert
	table.insert({ name_value.get_name(), name_value });
	return (table.size() > sz); // if size didn't change, means element was not added
}
