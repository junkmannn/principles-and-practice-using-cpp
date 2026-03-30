#include <iostream>
#include <string>

std::string cat_sep(
    const std::string& s1, const std::string& s2, const std::string& sep
);

int main() {
    std::cout << cat_sep("Niels", "Bohr", ".") << '\n';
    std::cout << cat_sep("pepe", "meme", "_xD_") << '\n';
}

std::string cat_sep(
    const std::string& s1, const std::string& s2, const std::string& sep
) {
    return s1 + sep + s2;
}
