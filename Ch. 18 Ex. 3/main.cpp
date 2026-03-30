#include <iostream>

int strcmp(const char* s1, const char* s2);

int main() {
    char* s1 = "";
    char* s2 = "";
    std::cout << strcmp(s1, s2) << " should be 0\n";

    char* s3 = "a";
    char* s4 = "b";
    std::cout << strcmp(s3, s4) << " should be -1\n";
    std::cout << strcmp(s4, s3) << " should be 1\n";

    char* s5 = "aa";
    char* s6 = "a";
    std::cout << strcmp(s5, s6) << " should be 1\n";
    std::cout << strcmp(s6, s5) << " should be -1\n";

    char* s7 = "aa";
    char* s8 = "b";
    std::cout << strcmp(s7, s8) << " should be -1\n";
    std::cout << strcmp(s8, s7) << " should be 1\n";

    return 0;
}

int strcmp(const char* s1, const char* s2) {
    while (true) {
        if (!*s1) {
            if (!*s2)
                return 0;
            return -1;
        }
        if (*s1 != *s2) {
            if (!*s2 || *s2 < *s1)
                return 1;
            return -1;
        }
        ++s1;
        ++s2;
    }
}
