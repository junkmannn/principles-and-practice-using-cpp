#include <iostream>

// class Int
// ----------------------------------------------------------------------------
class Int {
public:
    Int();
    Int(int val);
    Int& operator=(const Int& a);
    friend Int operator+(const Int& a, const Int& b);
    friend Int operator-(const Int& a, const Int& b);
    friend Int operator*(const Int& a, const Int& b);
    friend Int operator/(const Int& a, const Int& b);
    friend std::ostream& operator<<(std::ostream& os, const Int& a);
    friend std::istream& operator>>(std::istream& is, Int& a);

private:
    int val;
};

Int::Int() : val(0) { }

Int::Int(int val) : val(val) { }

Int& Int::operator=(const Int& a) {
    val = a.val;
    return *this;
}

Int operator+(const Int& a, const Int& b) {
    return Int(a.val + b.val);
}

Int operator-(const Int& a, const Int& b) {
    return Int(a.val - b.val);
}

Int operator*(const Int& a, const Int& b) {
    return Int(a.val * b.val);
}

Int operator/(const Int& a, const Int& b) {
    return Int(a.val / b.val);
}

std::ostream& operator<<(std::ostream& os, const Int& a) {
    return os << a.val;
}

std::istream& operator>>(std::istream& is, Int& a) {
    return is >> a.val;
}
// ----------------------------------------------------------------------------

int main() {
    Int i = 12;
    std::cout << "i = " << i << '\n';

    Int i2 = 6;
    std::cout << "i2 = " << i2 << '\n';

    Int i_plus_i2 = i + i2;
    std::cout << "i_plus_i2 = " << i_plus_i2 << '\n';

    Int i_minus_i2 = i - i2;
    std::cout << "i_minus_i2 = " << i_minus_i2 << '\n';

    Int i_mult_i2 = i * i2;
    std::cout << "i_mult_i2 = " << i_mult_i2 << '\n';

    Int i_div_i2 = i / i2;
    std::cout << "i_div_i2 = " << i_div_i2 << '\n';

    Int i3;
    std::cin >> i3;
    std::cout << "i3 = " << i3 << '\n';

    return 0;
}
