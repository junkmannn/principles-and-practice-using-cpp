#include <iostream>
#include <stdexcept>

// class vector
// ----------------------------------------------------------------------------
class vector {
public:
    explicit vector(int s);
    vector(const vector& arg); // copy constructor: define copy
    vector& operator=(const vector& a); // copy assignment
    ~vector();
    double& operator[](int n); // for non-const vectors
    const double& operator[](int n) const; // for const vectors
    int size() const;
    int capacity() const;
    void reserve(int newalloc);
    void resize(int newsize);

private:
    int sz;       // number of elements
    double* elem; // address of first element
    int space;    // number of elements plus "free store"/"slots"
                  // for new elements ("the current allocation")

    void copy(const vector& arg); // copy elements from arg into *elem
};

vector::vector(int s) {
    if (s < 0)
        throw std::invalid_argument("size must be greater or equal to 0");
    sz = s;
    space = sz;
    elem = new double[sz];
}

vector::vector(const vector& arg) : sz(arg.sz), space(sz), elem(new double[sz]) {
    copy(arg);
}

// make this vector a copy of a
vector& vector::operator=(const vector& a) {
    double* p = new double[a.sz]; // allocate new space
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i]; // copy elements
    delete[] elem; // deallocate old space
    elem = p; // now we can reset elem
    sz = a.sz;
    space = sz;
    return *this; // return a self-reference (see 17.10)
}

vector::~vector() { delete[] elem; }

double& vector::operator[](int n) { return elem[n]; }

const double& vector::operator[](int n) const { return elem[n]; }

int vector::size() const { return sz; }

int vector::capacity() const { return space; }

void vector::reserve(int newalloc) {
    if (newalloc <= space)            // never decrease allocation
        return;
    double* p = new double[newalloc]; // allocate new space
    for (int i = 0; i < sz; ++i)      // copy old elements
        p[i] = elem[i];
    delete[] elem;                    // deallocate old space
    elem = p;
    space = newalloc;
}

// make the vector have newsize elements
// initialize each new element with the default value 0.0
void vector::resize(int newsize) {
    if (newsize < 0)
        return;
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        elem[i] = 0.0; // initialize new elements
    sz = newsize;
}

// copy elements [0:arg.sz-1]
void vector::copy(const vector& arg) {
    for (int i = 0; i < arg.sz; ++i)
        elem[i] = arg.elem[i];
}
// ----------------------------------------------------------------------------
// class vector


int main() {
    vector vec(30);
    std::cout << "size() = " << vec.size() << '\n';
    std::cout << "capacity() = " << vec.capacity() << '\n';
    vec[0] = 35.6;
    std::cout << "vec[0] = " << vec[0] << '\n';
    // vec[30] = 0.33; // error; OK
    vec.resize(31);
    std::cout << "size() = " << vec.size() << '\n';
    std::cout << "capacity() = " << vec.capacity() << '\n';
    vec[30] = 0.33; // no error; OK
    std::cout << "vec[30] = " << vec[30] << '\n';
    vec.reserve(-5);
    std::cout << "size() = " << vec.size() << '\n';
    std::cout << "capacity() = " << vec.capacity() << '\n';
    vec.reserve(100);
    std::cout << "size() = " << vec.size() << '\n';
    std::cout << "capacity() = " << vec.capacity() << '\n';
    vec.resize(-5);
    std::cout << "size() = " << vec.size() << '\n';
    std::cout << "capacity() = " << vec.capacity() << '\n';

    // vector vec2(-1); // throws std::invalid_argument; OK

    return 0;
}
