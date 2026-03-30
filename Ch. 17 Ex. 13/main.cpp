#include <iostream>
#include <string>

struct God {
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
    God(std::string name, std::string mythology, std::string vehicle, std::string weapon) :
        name(name), mythology(mythology), vehicle(vehicle), weapon(weapon) { }
};

struct Link {
    God value;
    Link* prev;
    Link* succ;
    Link(const God& v, Link* p=0, Link* s=0) :
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
Link* find(Link* p, const God& s);

// move n positions in list
// return nullptr for "not found"
// positive n moves forward, negative backward
Link* advance(Link* p, int n);

Link* add_ordered(Link* p, const God& s);

void print_all(Link* p);

int main() {
    Link* gods = new Link(God("Zeus", "Greek", "", "Lightning"));
    gods = insert(gods, new Link(God("H", "Greek", "", "")));
    gods = insert(gods, new Link(God("Poseidon", "Greek", "", "Trident")));
    gods = insert(gods, new Link(God("Z", "Norse", "", "")));
    gods = insert(gods, new Link(God("Odin", "Norse", "Eight-legged flying horse called Sleipner", "")));
    gods = insert(gods, new Link(God("Thor", "Norse", "", "Hammer")));
    gods = insert(gods, new Link(God("A", "Roman", "", "")));
    gods = insert(gods, new Link(God("Mars", "Roman", "", "Spear")));
    gods = insert(gods, new Link(God("Jupiter", "Roman", "", "Thunder")));
    std::cout << "gods\n";
    print_all(gods);
    std::cout << '\n';

    Link* greek_gods = nullptr;
    Link* norse_gods = nullptr;
    Link* roman_gods = nullptr;
    while (gods != nullptr) {
        erase(gods);
        std::string& myth = gods->value.mythology;
        if (myth == "Greek")
            greek_gods = add_ordered(greek_gods, gods->value);
        else if (myth == "Norse")
            norse_gods = add_ordered(norse_gods, gods->value);
        else if (myth == "Roman")
            roman_gods = add_ordered(roman_gods, gods->value);
        gods = gods->succ;
    }

    std::cout << "greek_gods\n";
    print_all(greek_gods);
    std::cout << '\n';
    std::cout << "norse_gods\n";
    print_all(norse_gods);
    std::cout << '\n';
    std::cout << "roman_gods\n";
    print_all(roman_gods);
    std::cout << '\n';
    std::cout << "gods\n";
    print_all(gods); // should be empty
    std::cout << '\n';

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

Link* find(Link* p, const God& s) {
    while (p != nullptr) {
        God& god = p->value;
        if (&god == &s ||
            (god.mythology == s.mythology &&
             god.name == s.name &&
             god.vehicle == s.vehicle &&
             god.weapon == s.weapon)) {
            return p;
        }
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

Link* add_ordered(Link* p, const God& s) {
    if (p != nullptr) {
        if (s.name < p->value.name)
            return insert(p, new Link(s));
    }
    else {
        return new Link(s);
    }

    Link* pp = p;
    while (true) {
        if (pp->succ == nullptr)
            break;
        pp = pp->succ;
        if (s.name < pp->value.name) {
            insert(pp, new Link(s));
            return p;
        }
    }

    add(pp, new Link(s));

    return p;
}

void print_all(Link* p) {
    std::cout << "{\n";
    while (p != nullptr) {
        God& god = p->value;
        std::cout << "\tName: " << god.name << ", "
                     "Mythology: " << god.mythology << ", "
                     "Vehicle: " << god.vehicle << ", "
                     "Weapon: " << god.weapon << '\n';
        p = p->succ;
    }
    std::cout << "}\n";
}
