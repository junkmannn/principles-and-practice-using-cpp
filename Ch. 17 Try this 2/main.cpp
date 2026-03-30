#include <iostream>

// class Member
// ----------------------------------------------------------------------------
class Member {
public:
    Member();
    ~Member();
    int* p;
};

Member::Member() : p(new int(13)) { }

Member::~Member() {
    std::cout << "Member's destructor called\n";
    delete p;
}
// ----------------------------------------------------------------------------

// class Base
// ----------------------------------------------------------------------------
class Base {
public:
    Base();
    virtual ~Base();
    virtual int add_members();
    Member mem1;
};

Base::Base() { }

Base::~Base() {
    std::cout << "Base's destructor called\n";
}

int Base::add_members() {
    return *mem1.p;
}
// ----------------------------------------------------------------------------

// class Derived
// ----------------------------------------------------------------------------
class Derived : public Base {
public:
    Derived();
    virtual ~Derived();
    virtual int add_members();
    Member mem2;
};

Derived::Derived() { }

Derived::~Derived() {
    std::cout << "Derived's destructor called\n";
}

int Derived::add_members() {
    return *mem1.p + *mem2.p;
}
// ----------------------------------------------------------------------------

int main() {
    Base* b = new Derived;
    std::cout << b->add_members() << '\n';
    delete b;

    return 0;
}
