#include <iostream>

char* strdupp(const char* s);

int main() {
    char* s = "Hello, World!";
    char* dup = strdupp(s);
    std::cout << dup << '\n';
    delete[] dup;

    return 0;
}

char* strdupp(const char* s) {
    // get string length (including '\0')
    int len = 0;
    while (s[len++] != 0);

    // do the copying
    char* dup = new char[len];
    for (int i = 0; i < len; ++i)
        dup[i] = s[i];

    return dup;
}
