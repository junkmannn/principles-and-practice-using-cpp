#include <iostream>
#include <stdexcept>

// class auto_ptr<T>
// ----------------------------------------------------------------------------
template<typename T>
class auto_ptr {
public:
    auto_ptr(T* ptr);
    ~auto_ptr();
    T* release();
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;

private:
    T* ptr;
};

template<typename T>
auto_ptr<T>::auto_ptr(T* ptr) : ptr(ptr) { }

template<typename T>
auto_ptr<T>::~auto_ptr() { delete ptr; }

template<typename T>
T* auto_ptr<T>::release() {
    T* tmp = ptr;
    ptr = 0;
    return tmp;
}

template<typename T>
T& auto_ptr<T>::operator*() {
    return *ptr;
}

template<typename T>
const T& auto_ptr<T>::operator*() const {
    return *ptr;
}

template<typename T>
T* auto_ptr<T>::operator->() {
    return ptr;
}

template<typename T>
const T* auto_ptr<T>::operator->() const {
    return ptr;
}
// ----------------------------------------------------------------------------

int* test();
void test2();
int* test3();
void test4();

int main() {
    int* ptr;

    ptr = test();
    std::cout << *ptr << " = " << 6 << '\n';
    delete ptr;

    test2();

    try {
        ptr = test3();
    }
    catch (...) {

    }

    test4();

    return 0;
}

int* test() {
    auto_ptr<int> ptr = new int(6);
    return ptr.release();
}

void test2() {
    auto_ptr<int> ptr = new int(23);
}

int* test3() {
    auto_ptr<int> ptr = new int(50);
    throw std::runtime_error("");
    return ptr.release();
}

void test4() {
    auto_ptr<int> ptr = new int(6);
    *ptr = 9;
    std::cout << *ptr << '\n';

    const auto_ptr<int> ptr2 = new int(67);
    // *ptr2 = 10; // doesn't work! perfect
    std::cout << *ptr2 << '\n';

    struct S {
        int a;
        int b;
    };

    auto_ptr<S> ptr3 = new S;
    ptr3->a = 4;
    ptr3->b = 9;
    std::cout << ptr3->a << ", " << ptr3->b << '\n';

    const auto_ptr<S> ptr4 = new S;
    // ptr4->a = 7; // doesn't work! perfect!
    std::cout << ptr4->a << ", " << ptr4->b << '\n';
}
