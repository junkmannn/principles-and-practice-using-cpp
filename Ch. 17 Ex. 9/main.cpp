#include <iostream>

int* stack_test();

int main() {
    int i = 0;
    if (stack_test() > &i)
        std::cout << "The stack grows up\n";
    else
        std::cout << "The stack grows down\n";

    char* c = new char(0);
    char* c2 = new char(0);
    if (c2 > c)
        std::cout << "The heap grows up\n";
    else
        std::cout << "The heap grows down\n";
    delete c;
    delete c2;

    return 0;
}

int* stack_test() {
    int i = 0;
    return &i;
}
