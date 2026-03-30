#include <string>
#include <iostream>

class Link {
public:
    std::string value;

    Link(const std::string& v, Link* p=0, Link* s=0) :
        value(v), prev(p), succ(s) { }

    Link* insert(Link* n);            // insert n before this object
    Link* add(Link* n);               // insert n after this object
    Link* erase();                    // remove this object from list
    Link* find(const std::string& s); // find s in list
    const Link* find(const std::string& s) const; // find s in const list (see 18.4.1)

    Link* advance(int n) const; // move n positions in list

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) {
    if (n == nullptr) // nothing to insert
        return this;
    n->succ = this; // this object comes after n
    if (prev != nullptr)
        prev->succ = n;
    n->prev = prev; // this object's predecessor becomes n's predecessor
    prev = n;       // n becomes this object's predecessor
    return n;
}

Link* Link::add(Link* n) {
    Link* l = n->insert(this);
    return l==this ? n : this;
}

Link* Link::erase() {
    if (succ != nullptr)
        succ->prev = prev;
    if (prev != nullptr)
        prev->succ = succ;
    return succ;
}

Link* Link::find(const std::string& s) {
    Link* p = this;
    while (p != nullptr) {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

const Link* Link::find(const std::string& s) const {
    const Link* p = this;
    while (p != nullptr) {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

Link* Link::advance(int n) const {
    const Link* p = this;
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
    return (Link*)p;
}

void print_all(Link* p);

int main() {
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));

    Link* p = greek_gods->find("Mars");
    if (p != nullptr)
        p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if (p2 != nullptr) {
        if (p2 == norse_gods)
            norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    std::cout << '\n';

    print_all(greek_gods);
    std::cout << '\n';

    // add function test
    /*
    Link* norse_gods = new Link("Freia");
    Link* norse_gods_bak = norse_gods;
    norse_gods = norse_gods->add(new Link("Zeus"));
    norse_gods = norse_gods->add(new Link("Odin"));
    norse_gods = norse_gods->add(new Link("Thor"));
    print_all(norse_gods_bak); // should print { Freia, Zeus, Odin, Thor }
    std::cout << '\n';
    */

    return 0;
}

void print_all(Link* p) {
    std::cout << "{ ";
    while (p != nullptr) {
        std::cout << p->value;
        p = p->next();
        if (p != nullptr)
            std::cout << ", ";
    }
    std::cout << " }";
}
