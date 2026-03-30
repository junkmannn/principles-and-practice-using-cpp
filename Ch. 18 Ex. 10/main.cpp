#include <iostream>
#include <cctype>

std::istream& read_word_A(std::istream& is, char* buffer, int max, bool& overflow);
std::istream& read_word_B(std::istream& is, char*& buffer);

int main() {
    // Version A
    /*
    const int max = 4;
    char s[max];
    bool overflow;
    while (read_word_A(std::cin, s, max, overflow)) {
        if (overflow)
            std::cout << "overflow\n";
        std::cout << s << '\n';
    }
    */

    // Version B
    char* s = nullptr;
    while (read_word_B(std::cin, s)) {
        std::cout << s << '\n';
        delete[] s;
    }
}

std::istream& read_word_A(std::istream& is, char* buffer, int max, bool& overflow) {
    char c;
    while (is.get(c) && isspace(c)); // ignore whitespaces
    if (!is)
        return is;
    is.unget();
    int i = 0;
    while (i < max && is.get(c) && !isspace(c)) { // read word
        buffer[i] = c;
        ++i;
    }
    if (!is)
        return is;
    is.unget();
    if (i == max) { // overflow
        buffer[i-1] = 0;
        overflow = true;
        while (is.get(c) && !isspace(c)); // ignore the rest of the word
        if (!is)
            return is;
        is.unget();
    }
    else {
        buffer[i] = 0;
        overflow = false;
    }
    return is;
}

std::istream& read_word_B(std::istream& is, char*& buffer) {
    std::ios::iostate exceptions_bak = is.exceptions();
    is.exceptions(std::ios::failbit | std::ios::badbit);
    try {
        buffer = nullptr;
        char c;
        while (is.get(c) && isspace(c)); // ignore whitespaces
        is.unget();
        int i = 0;
        int buf_sz = 64; // initial buffer size
        buffer = new char[buf_sz];
        while (is.get(c) && !isspace(c)) { // read word
            if (i == buf_sz) { // buffer is full
                int newsize = buf_sz*2;
                char* newbuf = new char[newsize];
                memcpy(newbuf, buffer, buf_sz);
                delete[] buffer;
                buf_sz = newsize;
                buffer = newbuf;
            }
            buffer[i] = c;
            ++i;
        }
        is.unget();
        buffer[i] = 0;
    }
    catch (std::ios::failure &e) {
        delete[] buffer;
    }
    is.exceptions(exceptions_bak);
    return is;
}
