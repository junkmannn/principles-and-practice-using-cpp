#include "myexceptions.h"

Syntax_error::Syntax_error(const std::string& what_arg) : std::runtime_error(what_arg) { }
Syntax_error::Syntax_error(const char* what_arg) : std::runtime_error(what_arg) { }

/*
Undefinied_name::Undefinied_name(const std::string& what_arg) : std::runtime_error(what_arg) { }
Undefinied_name::Undefinied_name(const char* what_arg) : std::runtime_error(what_arg) { }
*/
