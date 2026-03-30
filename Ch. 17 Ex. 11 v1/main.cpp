#include <iostream>
#include <string>

struct Link {
    std::string value;
    Link* prev;
    Link* succ;
    Link(const std::string& v, Link* p=0, Link* s=0) :
        value(v), prev(p), succ(s) { }
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

    Link* p = find(norse_gods, "Zeus");
    if (p != nullptr) {
        if (p == norse_gods)
            norse_gods = p->succ;
        erase(p);
        greek_gods = insert(greek_gods, p);
    }

    print_all(norse_gods);
    std::cout << '\n';

    print_all(greek_gods);
    std::cout << '\n';

    // add function test
    /*
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
    n->succ = p; // p comes after n
    if (p->prev != nullptr)
        p->prev->succ = n;
    n->prev = p->prev; // p's predecessor becomes n's predecessor
    p->prev = n;
    return n;
}

Link* add(Link* p, Link* n) {
    Link* l = insert(n, p);
    return l==p ? n : p;
}

Link* erase(Link* p) {
    if (p == nullptr)
        return nullptr;
    if (p->succ != nullptr)
        p->succ->prev = p->prev;
    if (p->prev != nullptr)
        p->prev->succ = p->succ;
    return p->succ;
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
    if (n > 0) {
        do {
            if (p->succ == nullptr)
                return nullptr;
            p = p->succ;
            --n;
        }
        while (n != 0);
    }
    else if (n < 0) {
        do {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev;
            ++n;
        }
        while (n != 0);
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
