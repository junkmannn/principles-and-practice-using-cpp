#include <iostream>

using namespace std;

int main() {
    cout << "Integer types:\n";
    cout << "the size of char is " << sizeof(char) << '\n';
    cout << "the size of short is " << sizeof(short) << '\n';
    cout << "the size of int is " << sizeof(int) << '\n';
    cout << "the size of long is " << sizeof(long) << '\n';
    cout << "the size of long long is " << sizeof(long long) << '\n';

    cout << "\nFloating-point types:\n";
    cout << "the size of float is " << sizeof(float) << '\n';
    cout << "the size of float is " << sizeof(double) << '\n';
    cout << "the size of long double is " << sizeof(long double) << '\n';

    cout << "\nBoolean type:\n";
    cout << "the size of bool is " << sizeof(bool) << '\n';

    cout << "\nCharacter types:\n";
    cout << "the size of char is " << sizeof(char) << '\n';
    cout << "the size of wchar_t is " << sizeof(wchar_t) << '\n';

    return 0;
}
