#include <iostream>

void to_lower(char* s);

int main() {
    char s[] = "Hello, World!";
    to_lower(s);
    std::cout << s << '\n';
    return 0;
}

void to_lower(char* s) {
    int i = 0;
    char* c;
    while (*(c=&s[i]) != 0) {
        if (*c >= 65 && *c <= 90)
            *c += 32;
        ++i;
    }
}
