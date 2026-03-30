#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <stdexcept>
#include <string>

class Syntax_error : public std::runtime_error {
public:
	Syntax_error(const std::string& what_arg);
	Syntax_error(const char* what_arg);
};

/*
class Undefinied_name : public std::runtime_error {
public:
	Undefinied_name(const std::string& what_arg);
	Undefinied_name(const char* what_arg);
};
*/

#endif
