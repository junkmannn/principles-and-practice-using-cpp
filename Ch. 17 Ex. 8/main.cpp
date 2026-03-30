#include <iostream>
#include <string>

int main() {
    std::string s;
    char c;
    while (std::cin.get(c) && c != '!')
        s += c;

    std::cout << s << '\n';

    return 0;
}
