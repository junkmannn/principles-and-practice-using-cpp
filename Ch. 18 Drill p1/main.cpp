#include <iostream>

// 1. Define a global int array ga of ten ints
//    initialized to 1, 2, 4, 8, 16, etc.
int ga[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

// 2. Define a function f() taking an int array
//    argument and an int argument indicating
//    the number of elements in the array.
void f(int* arr, int arr_size);

// 4. In main():
int main() {
    // 4a. Call f() with ga as its argument.
    f(ga, sizeof(ga)/sizeof(int));

    // 4b. Define an array aa with ten elements, and initialize
    //     it with the first ten factorial values
    //     (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    int aa[] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };

    // 4c. Call f() with aa as its argument.
    f(aa, sizeof(aa)/sizeof(int));

    return 0;
}

// 3. in f():
void f(int* arr, int arr_size) {
    // 3a. Define a local int array la of ten ints.
    int la[10];
    int la_sz = sizeof(la)/sizeof(int);

    // 3b. Copy the values from ga into la.
    for (int i = 0; i < la_sz; ++i)
        la[i] = ga[i];

    // 3c. Print out the elements of la.
    std::cout << "The array la contains the values:\n";
    for (int i = 0; i < la_sz; ++i)
        std::cout << la[i] << '\n';
    std::cout << '\n';

    // 3d. Define a pointer p to int and initialize it
    //    with an array allocated on the free store with
    //    the same number of elements as the argument array.
    int* p = new int[arr_size];

    // 3e. Copy the values from the argument array into
    //     the free-store array.
    for (int i = 0; i < arr_size; ++i)
        p[i] = arr[i];

    // 3f. Print out the elements of the free-store array.
    std::cout << "The array p contains the values:\n";
    for (int i = 0; i < arr_size; ++i)
        std::cout << p[i] << '\n';
    std::cout << '\n';

    // 3g. Deallocate the free-store array.
    delete[] p;
}
