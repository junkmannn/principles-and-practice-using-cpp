#include <iostream>
#include <string>
#include <stdexcept>

struct Link {
    std::string value;
    Link* succ;
    Link(const std::string& v, Link* s=nullptr) :
        value(v), succ(s) { }
};

// insert n before p
// return n
Link* insert(Link* p, Link* n);

// insert n after p
// return n
Link* add(Link* p, Link* n);

// remove *p from list
// return p's successor
Link* erase(Link* p);

// find s in list
// return nullptr for "not found"
Link* find(Link* p, const std::string& s);

// move n positions in list
// return nullptr for "not found"
// positive n moves forward, negative backward
Link* advance(Link* p, int n);

void print_all(Link* p);

int main() {
    Link* norse_gods = new Link("Thor");
    norse_gods = insert(norse_gods, new Link("Odin"));
    norse_gods = insert(norse_gods, new Link("Zeus"));
    norse_gods = insert(norse_gods, new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = insert(greek_gods, new Link("Athena"));
    greek_gods = insert(greek_gods, new Link("Mars"));
    greek_gods = insert(greek_gods, new Link("Poseidon"));

    print_all(norse_gods);
    std::cout << '\n';

    print_all(greek_gods);
    std::cout << '\n';

    /*
    // add function test
    Link* norse_gods = new Link("Freia");
    Link* norse_gods_bak = norse_gods;
    norse_gods = add(norse_gods, new Link("Zeus"));
    norse_gods = add(norse_gods, new Link("Odin"));
    norse_gods = add(norse_gods, new Link("Thor"));
    print_all(norse_gods_bak); // should print { Freia, Zeus, Odin, Thor }
    std::cout << '\n';
    */

    return 0;
}

Link* insert(Link* p, Link* n) {
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;

    std::string pval = std::move(p->value);
    n->succ = p->succ;
    p->value = std::move(n->value);
    p->succ = n;
    n->value = std::move(pval);

    return p;
}

Link* add(Link* p, Link* n) {
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;

    p->succ = n;

    return n;
}

Link* erase(Link* p) {
    // impossible to implement for all cases
    return nullptr;
}

Link* find(Link* p, const std::string& s) {
    while (p != nullptr) {
        if (p->value == s)
            return p;
        p = p->succ;
    }

    return nullptr;
}

Link* advance(Link* p, int n) {
    if (p == nullptr)
        return nullptr;

    if (n < 0)
        throw std::invalid_argument("can only advance forward in a singly-linked list");

    while (n != 0) {
        if (p->succ == nullptr)
            return nullptr;
        p = p->succ;
        --n;
    }

    return p;
}

void print_all(Link* p) {
    std::cout << "{ ";

    while (p != nullptr) {
        std::cout << p->value;
        p = p->succ;
        if (p != nullptr)
            std::cout << ", ";
    }

    std::cout << " }";
}
