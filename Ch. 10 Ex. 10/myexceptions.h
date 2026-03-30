#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <stdexcept>
#include <string>

// Exception used to report an error with the calculator
class Calculator_error : public std::runtime_error {
public:
	Calculator_error(const std::string& what_arg);
	Calculator_error(const char* what_arg);
};

#endif
