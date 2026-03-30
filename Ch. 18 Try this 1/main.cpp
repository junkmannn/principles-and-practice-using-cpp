#include <iostream>
#include <string>
#include <vector>

struct X {
    int val;

    void out(const std::string& s, int nv) {
        std::cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    // default constructor
    X() {
        out("X()", 0);
        val = 0;
    }

    X(int v) {
        out("X(int)", v);
        val = v;
    }

    // copy constructor
    X(const X& x) {
        out("X(X&)", x.val);
        val = x.val;
    }

    // copy assigment
    X& operator=(const X& a) {
        out("X::operator=()", a.val);
        val = a.val;
        return *this;
    }

    // destructor
    ~X() {
        out("~X()", 0);
    }
};

X glob(2);

X copy(X a) {
    return a;
}

X copy2(X a) {
    X aa = a;
    return aa;
}

X& ref_to(X& a) {
    return a;
}

X* make(int i) {
    X a(i);
    return new X(a);
}

struct XX {
    X a;
    X b;
};

int main() {
    X loc(4); // local variable
    X loc2 = loc;
    loc = X(5);
    loc2 = copy(loc);
    loc2 = copy2(loc);
    X loc3(6);
    X& r = ref_to(loc);
    delete make(7);
    delete make(8);
    std::vector<X> v(4);
    XX loc4;
    X* p = new X(9); // an X on the free store
    delete p;
    X* pp = new X[5];
    delete[] pp;
}
