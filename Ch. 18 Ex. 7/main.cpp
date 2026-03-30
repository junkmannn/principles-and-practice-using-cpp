#include <iostream>

int my_strlen(const char* s);
char* cat_sep(const char* s1, const char* s2, const char* sep);

int main() {
    char* s;

    s = cat_sep("Niels", "Bohr", ".");
    std::cout << s << '\n';
    delete[] s;

    s = cat_sep("pepe", "meme", "_xD_");
    std::cout << s << '\n';
    delete[] s;

    s = cat_sep("jej", "lmaonub", "______");
    std::cout << s << '\n';
    delete[] s;

    s = cat_sep("", "", "");
    std::cout << s << '\n';
    delete[] s;

    s = cat_sep("", "", "x");
    std::cout << s << '\n';
    delete[] s;
}

int my_strlen(const char* s) {
    int len = 0;
    while (s[len] != 0)
        ++len;
    return len;
}

char* cat_sep(const char* s1, const char* s2, const char* sep) {
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);
    int sep_len = my_strlen(sep);

    char* cat = new char[s1_len+s2_len+sep_len+1];
    char* p = cat;
    int i;

    for (i = 0; i < s1_len; ++i, ++p)
        *p = s1[i];
    for (i = 0; i < sep_len; ++i, ++p)
        *p = sep[i];
    for (i = 0; i <= s2_len; ++i, ++p)
        *p = s2[i];

    return cat;
}
