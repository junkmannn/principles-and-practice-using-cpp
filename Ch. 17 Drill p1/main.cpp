#include <iostream>
#include <vector>

// 4. Write a function print_array10(ostream& os, int* a) that prints
// out the values of a (assumed to have ten elements) to os
void print_array10(std::ostream& os, int* a);

// 7. Write a function print_array(ostream& os, int* a, int n) that
// prints out the values of a (assumed to have n elements) to os
void print_array(std::ostream& os, int* a, int n);

void print_vector(std::ostream& os, std::vector<int>& v);

int main () {
    // 1. Allocate an array of ten ints on the free store using new
    int* arr = new int[10];

    // 2. Print the values of the ten ints to cout
    for (int i = 0; i < 10; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    // 3. Deallocate the array (using delete[])
    delete[] arr;

    // 5. Allocate an array of ten ints on the free store; initialize it
    // with the values 100, 101, 102, etc.; and print out its values
    arr = new int[10];
    for (int i = 0; i < 10; ++i)
        arr[i] = 100+i;
    print_array10(std::cout, arr);
    delete[] arr;

    // 6. Allocate an array of 11 ints on the free store; initialize it
    // with the values 100, 101, 102, etc.; and print out its values
    arr = new int[11];
    for (int i = 0; i < 11; ++i)
        arr[i] = 100+i;
    std::cout << arr[0] << ' ';
    print_array10(std::cout, &arr[1]);
    delete[] arr;

    // 8. Allocate an array of 20 ints on the free store; initialize it
    // with the values 100, 101, 102, etc.; and print out its values
    arr = new int[20];
    for (int i = 0; i < 20; ++i)
        arr[i] = 100+i;
    print_array(std::cout, arr, 20);
    delete[] arr;

    // 9. Did you remember to delete the arrays? (If not, do it.)

    // 10. Do 5, 6, and 8 using a vector instead of an array and a
    // print_vector() instead of print_array()
    std::vector<int> vec;
    vec = std::vector<int>(10);
    for (int i = 0, sz = vec.size(); i < sz; ++i)
        vec[i] = 100+i;
    print_vector(std::cout, vec);
    vec = std::vector<int>(11);
    for (int i = 0, sz = vec.size(); i < sz; ++i)
        vec[i] = 100+i;
    print_vector(std::cout, vec);
    vec = std::vector<int>(20);
    for (int i = 0, sz = vec.size(); i < sz; ++i)
        vec[i] = 100+i;
    print_vector(std::cout, vec);
}

void print_array10(std::ostream& os, int* a) {
    for (int i = 0; i < 10; ++i)
        os << a[i] << ' ';
    os << '\n';
}

void print_array(std::ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i)
        os << a[i] << ' ';
    os << '\n';
}

void print_vector(std::ostream& os, std::vector<int>& v) {
    for (int i = 0, sz = v.size(); i < sz; ++i)
        os << v[i] << ' ';
    os << '\n';
}
