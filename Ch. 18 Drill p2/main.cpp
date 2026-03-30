#include <iostream>
#include <vector>

// 1. Define a global vector<int> gv; initialize
//    it with ten ints, 1, 2, 4, 8, 16, etc.
std::vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

// 2. Define a function f() taking a vector<int> argument.
void f(std::vector<int> vec);

// 4. In main():
int main() {
    // 4a. Call f() with gv as its argument.
    f(gv);

    // 4b. Define a vector<int> vv, and initialize
    //     it with the first ten factorial values
    //     (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    std::vector<int> vv = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };

    // 4c. Call f() with vv as its argument.
    f(vv);

    return 0;
}

// 3. In f()
void f(std::vector<int> vec) {
    // 3a. Define a local vector<int> lv with the same
    //     number of elements as the argument vector.
    std::vector<int> lv(vec.size());

    // 3b. Copy the values from gv into lv.
    lv = gv;

    // 3c. Print out the lements of lv.
    std::cout << "The vector lv contains the values:\n";
    for (int i = 0, sz = lv.size(); i < sz; ++i)
       std::cout << lv[i] << '\n';
    std::cout << '\n';

    // 3d. Define a local vector<int> lv2; initialize it
    //     to be a copy of the argument vector.
    std::vector<int> lv2 = vec;

    // 3e. Print out the lements of lv2.
    std::cout << "The vector lv2 contains the values:\n";
    for (int i = 0, sz = lv2.size(); i < sz; ++i)
       std::cout << lv2[i] << '\n';
    std::cout << '\n';
}
