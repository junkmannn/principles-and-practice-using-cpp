#include <iostream>
#include <string>

std::string cat_dot(const std::string& s1, const std::string& s2);

int main() {
    std::cout << cat_dot("Niels", "Bohr") << '\n';
}

std::string cat_dot(const std::string& s1, const std::string& s2) {
    return s1 + '.' + s2;
}
