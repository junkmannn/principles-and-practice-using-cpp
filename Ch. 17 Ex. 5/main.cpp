#include <iostream>

const char* findx(const char* s, const char* x);

int main() {
    char* s = "lmao kek lel jej pepe jej";
    char* x = " ";

    const char* res = findx(s, x);
    if (res != nullptr)
        std::cout << res << '\n';
    else
        std::cout << "Not found\n";

    return 0;
}

const char* findx(const char* s, const char* x) {
    int i = 0;
    int i2 = 0;
    while (s[i] != 0) {
        if (x[i2] == s[i]) {
            ++i2;
            if (x[i2] == 0)
                return &s[i-i2+1];
        }
        else {
            i2 = 0;
        }
        ++i;
    }
    return nullptr;
}
