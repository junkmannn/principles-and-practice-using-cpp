#include "myexceptions.h"

Calculator_error::Calculator_error(const std::string& what_arg) : std::runtime_error(what_arg) { }
Calculator_error::Calculator_error(const char* what_arg) : std::runtime_error(what_arg) { }
