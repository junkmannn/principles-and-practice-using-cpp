
// class vector
// ----------------------------------------------------------------------------
class vector {
public:
    explicit vector(int s);
    ~vector();
    vector(const vector& arg); // copy constructor: define copy
    vector& operator=(const vector& a); // copy assignment
    double operator[](int n);
private:
    int sz;
    double* elem;
    void copy(const vector& arg); // copy elements from arg into *elem
};

vector::vector(int s) : sz(s), elem(new double[s]) { }

vector::~vector() { delete[] elem; }

vector::vector(const vector& arg) : sz(arg.sz), elem(new double[arg.sz]) {
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
    return *this; // return a self-reference (see 17.10)
}

double vector::operator[](int n) { return elem[n]; }

// copy elements [0:arg.sz-1]
void vector::copy(const vector& arg) {
    for (int i = 0; i < arg.sz; ++i)
        elem[i] = arg.elem[i];
}
// ----------------------------------------------------------------------------
// class vector


int main() {
    vector v(10);
    int x = v[2]; // fine
    // v[3] = x; // error: v[3] is not an lvalue

    return 0;
}
