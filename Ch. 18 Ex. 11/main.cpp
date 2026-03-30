#include "skip_list.h"
#include <cstdlib> // srand(), rand()
#include <ctime> // time()
#include <assert.h> // assert()
#include <utility> // std::move()
#include <string>
#include <vector>

struct Test {
    Test(int i) : p(new int(i)) { }
    Test(const Test& t) : p(new int(*t.p)) { }
    Test(Test&& t) : p(t.p) {
        t.p = 0;
    }
    ~Test() {
        delete p;
    }
    bool operator<(const Test& t) {
        return *p < *t.p;
    }
    bool operator>(const Test& t) {
        return *p > *t.p;
    }
    bool operator==(const Test& t) {
        return *p == *t.p;
    }

    int* p;
};

void run_tests();
void default_constructor_test();
void copy_constructor_test();
void move_constructor_test();
void destructor_test();
void copy_assignment_test();
void move_assignment_test();
void insert_test();
void remove_test();
void remove_all_test();
void contains_test();
void rng_test();
void other_tests();

int main() {
    srand(time(NULL));

    run_tests();

    return 0;
}

void run_tests() {
    // default_constructor_test(); // OK
    // copy_constructor_test(); // OK
    // move_constructor_test(); // OK
    // destructor_test(); // OK
    // copy_assignment_test(); // OK
    // move_assignment_test(); // OK
    // remove_all_test(); // OK
    // insert_test(); // OK
    // remove_test(); // OK
    // contains_test(); // OK
    // rng_test(); // OK
    other_tests(); // OK
}

void default_constructor_test() {
    Skip_list<int> sl;
}

void copy_constructor_test() {
    Skip_list<int> sl;
    Skip_list<int> sl2(sl);
    sl.insert(1);
    sl.insert(2);
    sl.insert(3);
    assert(sl2.contains(1) == false);
    assert(sl2.contains(2) == false);
    assert(sl2.contains(3) == false);
    sl2.insert(4);
    sl2.insert(5);
    sl2.insert(6);
    assert(sl.contains(4) == false);
    assert(sl.contains(5) == false);
    assert(sl.contains(6) == false);
}

void move_constructor_test() {
    Skip_list<int> sl;
    Skip_list<int> sl2(std::move(sl));
    sl2.insert(5);
    assert(sl2.contains(5) == true);
    assert(sl.contains(5) == false);
    Skip_list<int> sl3(std::move(sl2));
    assert(sl2.contains(5) == false);
    assert(sl.contains(5) == false);
    assert(sl3.contains(5) == true);
    sl3.insert(2);
    sl3.insert(7);
    assert(sl2.contains(2) == false);
    assert(sl2.contains(7) == false);
}

void destructor_test() {
    Skip_list<int> sl;
    for (int i = 0; i < 250000; ++i) {
        int random = rand() % 1000000;
        sl.insert(random);
    }
}

void copy_assignment_test() {
    Skip_list<int> sl;
    sl = sl;
    Skip_list<int> sl2;
    sl2 = sl;
    sl.insert(1);
    assert(sl2.contains(1) == false);
    sl.insert(2);
    sl.insert(-43);
    sl.insert(1784);
    sl2 = sl;
}

void move_assignment_test() {
    Skip_list<int> sl;
    sl = std::move(sl);
    sl.insert(1);
    sl.insert(2);
    Skip_list<int> sl2;
    sl2 = std::move(sl);
}

void insert_test() {
    /*
    Skip_list<int> sl;
    assert(sl.insert(0, 2) == true);
    assert(sl.insert(0, 2) == false);
    assert(sl.insert(1, 3) == true);
    assert(sl.insert(1, 3) == false);
    assert(sl.insert(3, 1) == true);
    assert(sl.insert(2, 1) == true);
    assert(sl.insert(2, 1) == false);
    assert(sl.insert(3, 1) == false);
    assert(sl.insert(-1, 5) == true);
    */
}

void remove_test() {
    /*
    Skip_list<int> sl;
    sl.insert(0, 1);
    assert(sl.remove(0) == true);
    assert(sl.remove(0) == false);
    sl.insert(0, 3);
    assert(sl.remove(0) == true);
    sl.insert(0, 3);
    sl.insert(1, 2);
    sl.insert(2, 3);
    assert(sl.remove(1) == true);
    assert(sl.remove(1) == false);
    assert(sl.remove(-1) == false);
    assert(sl.remove(2) == true);
    assert(sl.remove(0) == true);
    */
}

void remove_all_test() {
    Skip_list<int> sl;
    sl.remove_all();
    sl.insert(1);
    sl.remove_all();
    sl.insert(3);
    sl.remove_all();
    sl.insert(3);
    sl.insert(2);
    sl.insert(1);
    sl.insert(4);
    sl.remove_all();
}

void contains_test() {
    /*
    Skip_list<int> sl;
    assert(sl.contains(10) == false);
    sl.insert(10, 5);
    assert(sl.contains(10) == true);
    sl.insert(0, 2);
    assert(sl.contains(1) == false);
    assert(sl.contains(0) == true);
    sl.remove(0);
    assert(sl.contains(1) == false);
    sl.insert(1, 3);
    sl.insert(3, 2);
    sl.insert(2, 1);
    assert(sl.contains(2) == true);
    sl.remove(1);
    assert(sl.contains(2) == true);
    assert(sl.contains(1) == false);
    */
}

void rng_test() {
    Skip_list<int> sl;
    for (int i = 0; i < 1000000; ++i) {
        sl.insert(i);
    }
}

void other_tests() {
    // check if the move insertion is working correctly
    /*
    Skip_list<std::string> sl;
    std::string s = "kek";
    sl.insert(s);
    std::string s2 = "jej";
    sl.insert(std::move(s2));
    */

    Skip_list<Test> sl2;
    // Test t(3);
    // sl2.insert(t);
    Test t2(4);
    sl2.insert(std::move(t2));

    /*
    std::vector<Test> v;
    Test t3(5);
    v.push_back(std::move(t3));
    */

    int i = 0;
}
