#include <iostream>

int main() {
    char* s = new char[8];
    int i = 0;
    while (std::cin.get(s[i]) && s[i] != '!')
        ++i;
    s[i] = 0;

    std::cout << s << '\n';

    return 0;
}
