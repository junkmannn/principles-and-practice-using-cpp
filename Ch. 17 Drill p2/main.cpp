#include <iostream>
#include <vector>

void print_array(std::ostream& os, int* a, int n);

int main() {
    // 1. Allocate an int, initialize it to 7, and assign its address to a variable p1
    int* p1 = new int(7);

    // 2. Print out the value of p1 and of the int it points to
    std::cout << "p1 points to an integer of value " << *p1 << " located at " << p1 << '\n';

    // 3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and
    // assign its address to a variable p2
    int* p2 = new int[7];
    p2[0] = 1;
    for (int i = 1; i < 7; ++i)
        p2[i] = p2[i-1] * 2;

    // 4. Print out the value of p2 and of the array it points to
    std::cout << "p2 points to an array of integers located at " << p2 << " which contains "
                 "the following values:\n";
    print_array(std::cout, p2, 7);

    // 5. Declare an int* called p3 and initialize it with p2
    int* p3 = p2;

    // 6. Assign p1 to p2
    p2 = p1;

    // 7. Assign p3 to p2
    p2 = p3;

    // 8. Print out the values of p1 and p2 and of what they point to
    std::cout << "p1 points to an integer of value " << *p1 << " located at " << p1 << '\n';
    std::cout << "p2 points to an array of integers located at " << p2 << " which contains "
                 "the following values:\n";
    print_array(std::cout, p2, 7);

    // 9. Deallocate all the memory you allocated from the free store
    delete p1;
    delete[] p2;

    // 10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and
    // assign its address to a variable p1
    p1 = new int[10];
    p1[0] = 1;
    for (int i = 1; i < 10; ++i)
        p1[i] = p1[i-1] * 2;

    // 11. Allocate an array of ten ints, and assign its address to a variable p2
    p2 = new int[10];

    // 12. Copy the values from the array pointed by p1 into the array pointed by p2
    for (int i = 0; i < 10; ++i)
        p2[i] = p1[i];
    for (int i = 0; i < 10; ++i)
        std::cout << p2[i] << ' ';
    std::cout << '\n';
    delete[] p1;
    delete[] p2;

    // 13. Repeat 10-12 using a vector rather than an array
    std::vector<int> v1(10);
    v1[0] = 1;
    for (int i = 1, sz = v1.size(); i < sz; ++i)
        v1[i] = v1[i-1] * 2;
    std::vector<int> v2(10);
    v2 = v1;
    for (int i = 0, sz = v2.size(); i < sz; ++i)
        std::cout << v2[i] << ' ';
    std::cout << '\n';

    return 0;
}

void print_array(std::ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i)
        os << a[i] << ' ';
    os << '\n';
}
