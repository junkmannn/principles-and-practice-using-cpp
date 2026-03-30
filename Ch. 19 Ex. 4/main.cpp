#include <string>
#include <iostream>

// struct Link<T>
// ----------------------------------------------------------------------------
template<typename T>
struct Link {
    Link(const T& v, Link* p=0, Link* s=0);

    template<typename T>
    friend Link<T>* insert_before(Link<T>* p, Link<T>* n);
    template<typename T>
    friend Link<T>* insert_after(Link<T>* p, Link<T>* n);
    template<typename T>
    friend Link<T>* insert_order(Link<T>* p, const T& v);
    template<typename T>
    friend Link<T>* erase(Link<T>* p);
    template<typename T>
    friend Link<T>* find(Link<T>* p, const T& v);
    template<typename T>
    friend Link<T>* advance(Link<T>* p, int n);

    T value;
    Link* prev;
    Link* succ;
};

template<typename T>
Link<T>::Link(const T& v, Link* p=0, Link* s=0) :
    value(v), prev(p), succ(s) { }

// insert n before p; return n
template<typename T>
Link<T>* insert_before(Link<T>* p, Link<T>* n) {
    if (!n)
        return p;
    if (!p)
        return n;
    n->succ = p; // p comes after n
    if (p->prev)
        p->prev->succ = n;
    n->prev = p->prev; // p's predecessor becomes n's predecessor
    p->prev = n;       // n becomes p's predecessor
    return n;
}

// insert n after p; return n
template<typename T>
Link<T>* insert_after(Link<T>* p, Link<T>* n) {
    if (!n)
        return p;
    if (!p)
        return n;
    n->prev = p;
    if (p->succ)
        p->succ->prev = n;
    n->succ = p->succ;
    p->succ = n;
    return n;
}

template<typename T>
Link<T>* insert_order(Link<T>* p, const T& v) {
    if (!p)
        return new Link<T>(v);

    Link<T>* pp = p;
    while (v > p->value && p->succ)
        p = p->succ;

    if (v > p->value)
        insert_after(p, new Link<T>(v));
    else if (p != pp)
        insert_before(p, new Link<T>(v));
    else
        pp = insert_before(p, new Link<T>(v));

    return pp;
}

// remove *p from list; return p's successor
template<typename T>
Link<T>* erase(Link<T>* p) {
    if (!p)
        return 0;
    if (p->succ)
        p->succ->prev = p->prev;
    if (p->prev)
        p->prev->succ = p->succ;
    return p->succ;
}

// find s in list; return 0 for "not found"
template<typename T>
Link<T>* find(Link<T>* p, const T& v) {
    while (p) {
        if (p->value == v)
            return p;
        p = p->succ;
    }
    return 0;
}

// move n positions in list
// return 0 for "not found"
// positive n moves forward, negative backward
template<typename T>
Link<T>* advance(Link<T>* p, int n) {
    if (!p)
        return 0;
    if (n > 0) {
        while (n--) {
            if (!p->succ)
                return 0;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (!p->prev)
                return 0;
            p = p->prev;
        }
    }
    return p;
}
// ----------------------------------------------------------------------------

// struct God
// ----------------------------------------------------------------------------
struct God {
    God(std::string name, std::string mythology,
        std::string vehicle, std::string weapon);
    friend bool operator==(const God& g1, const God& g2);
    friend bool operator<(const God& g1, const God& g2);
    friend bool operator>(const God& g1, const God& g2);
    friend std::ostream& operator<<(std::ostream& os, const God& g);

    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

God::God(std::string name, std::string mythology,
         std::string vehicle, std::string weapon) :
    name(name), mythology(mythology), vehicle(vehicle), weapon(weapon) { }

bool operator==(const God& g1, const God& g2) {
    return g1.name == g2.name;
}

bool operator<(const God& g1, const God& g2) {
    return g1.name < g2.name;
}

bool operator>(const God& g1, const God& g2) {
    return g1.name > g2.name;
}

std::ostream& operator<<(std::ostream& os, const God& g) {
    return os << "Name: " << g.name << ", "
                 "Mythology: " << g.mythology << ", "
                 "Vehicle: " << g.vehicle << ", "
                 "Weapon: " << g.weapon;
}
// ----------------------------------------------------------------------------

template<typename T>
void print_all(Link<T>* p);

int main() {
    Link<God>* gods = 0;
    gods = insert_before(
        gods, new Link<God>(God("Zeus", "Greek", "", "Lightning"))
    );
    gods = insert_before(
        gods, new Link<God>(God("H", "Greek", "", ""))
    );
    gods = insert_before(
        gods, new Link<God>(God("Poseidon", "Greek", "", "Trident"))
    );
    gods = insert_before(
        gods, new Link<God>(God("Z", "Norse", "", ""))
    );
    gods = insert_before(
        gods, new Link<God>(God("Odin", "Norse", "Eight-legged flying horse called Sleipner", ""))
    );
    gods = insert_before(
        gods, new Link<God>(God("Thor", "Norse", "", "Hammer"))
    );
    gods = insert_before(
        gods, new Link<God>(God("A", "Roman", "", ""))
    );
    gods = insert_before(
        gods, new Link<God>(God("Mars", "Roman", "", "Spear"))
    );
    gods = insert_before(
        gods, new Link<God>(God("Jupiter", "Roman", "", "Thunder"))
    );

    // print out gods
    std::cout << "gods\n";
    print_all(gods);
    std::cout << '\n';

    Link<God>* greek_gods = 0;
    Link<God>* norse_gods = 0;
    Link<God>* roman_gods = 0;
    while (gods) {
        erase(gods);
        std::string& myth = gods->value.mythology;
        if (myth == "Greek")
            greek_gods = insert_order(greek_gods, gods->value);
        else if (myth == "Norse")
            norse_gods = insert_order(norse_gods, gods->value);
        else if (myth == "Roman")
            roman_gods = insert_order(roman_gods, gods->value);
        gods = gods->succ;
    }

    // print out greek_gods, norse_gods and roman_gods
    std::cout << "greek_gods\n";
    print_all(greek_gods);
    std::cout << '\n';
    std::cout << "norse_gods\n";
    print_all(norse_gods);
    std::cout << '\n';
    std::cout << "roman_gods\n";
    print_all(roman_gods);
    std::cout << '\n';

    // print out gods; should now be empty
    std::cout << "gods\n";
    print_all(gods);
    std::cout << '\n';

    return 0;
}

template<typename T>
void print_all(Link<T>* p) {
    std::cout << "{\n";
    while (p) {
        std::cout << '\t' << p->value << '\n';
        p = p->succ;
    }
    std::cout << "}\n";
}
