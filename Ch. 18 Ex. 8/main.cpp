#include <iostream>
#include <string>

// std::string version
bool is_palindrome(const std::string& s);

// array version using subscript
bool is_palindrome(const char* s, int n);

// array version using pointers
bool is_palindrome(const char* first, const char* last);

std::istream& read_word(std::istream& is, char* buffer, int max);

int main() {
    const int max = 128;
    char s[max];
    while (read_word(std::cin, s, max)) {
        std::cout << "Is \"" << s << "\" a palindrome?\n";

        std::cout << "bool is_palindrome(const std::string& s)\n";
        if (is_palindrome(std::string(s)))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";

        std::cout << "bool is_palindrome(const char* s, int n)\n";
        if (is_palindrome(s, strlen(s)))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";

        std::cout << "bool is_palindrome(const char* first, const char* last)\n";
        if (is_palindrome(&s[0], &s[strlen(s)-1]))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}

bool is_palindrome(const std::string& s) {
    /*
    int first = 0;           // index of first letter
    int last = s.length()-1; // index of the last letter
    while (first < last) { // we haven't reached the middle
        if (s[first] != s[last])
            return false;
        ++first; // move forward
        --last;  // move backward
    }
    return true;
    */

    int s_len = s.length();
    std::string backwards;
    backwards.resize(s_len);
    for (int i = s_len-1, i2 = 0; i >= 0; --i, ++i2)
        backwards[i] = s[i2];
    return backwards == s;
}

// s points to the first character of an array of character
bool is_palindrome(const char* s, int n) {
    /*
    int first = 0;  // index of first letter
    int last = n-1; // index of last letter
    while (first < last) { // we haven't reached the middle
        if (s[first] != s[last])
            return false;
        ++first; // move forward
        --last;  // move backward
    }
    return true;
    */

    char* backwards = new char[n];
    int i;
    int i2;
    bool res = true;
    for (i = n-1, i2 = 0; i >= 0; --i, ++i2)
        backwards[i] = s[i2];
    for (i = 0; i < n; ++i) {
        if (backwards[i] != s[i]) {
            res = false;
            break;
        }
    }
    delete[] backwards;
    return res;
}

// first points to the first letter, last to the last letter
bool is_palindrome(const char* first, const char* last) {
    /*
    while (first < last) { // we haven't reached the middle
        if (*first != *last)
            return false;
        ++first; // move forward
        --last;  // move backward
    }
    return true;
    */

    int len = last-first+1;
    char* backwards = new char[len];
    char* p1;
    const char* p2;
    bool res = true;
    for (p1 = backwards+len-1, p2 = first; p2 <= last; --p1, ++p2)
        *p1 = *p2;
    for (p1 = backwards, p2 = first; p2 <= last; ++p1, ++p2) {
        if (*p1 != *p2) {
            res = false;
            break;
        }
    }
    delete[] backwards;
    return res;
}

// read at most max-1 characters from is into buffer
std::istream& read_word(std::istream& is, char* buffer, int max) {
    is.width(max); // read at most max-1 characters in the next >>
    is >> buffer;  // read whitespace-terminated word
                   // add zero after the last character read into buffer
    return is;
}
