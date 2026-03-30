#include <iostream>

// class Number<T>
// ----------------------------------------------------------------------------
template<typename T>
class Number {
public:
    Number();
    Number(const T& val);
    Number& operator=(const Number& a);

    template<typename T>
    friend Number<T> operator+(const Number<T>& a, const Number<T>& b);
    template<typename T>
    friend Number<T> operator-(const Number<T>& a, const Number<T>& b);
    template<typename T>
    friend Number<T> operator*(const Number<T>& a, const Number<T>& b);
    template<typename T>
    friend Number<T> operator/(const Number<T>& a, const Number<T>& b);
    template<typename T>
    friend Number<T> operator%(const Number<T>& a, const Number<T>& b);
    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const Number<T>& a);
    template<typename T>
    friend std::istream& operator>>(std::istream& is, Number<T>& a);

private:
    T val;
};

template<typename T>
Number<T>::Number() : val(0) { }

template<typename T>
Number<T>::Number(const T& val) : val(val) { }

template<typename T>
Number<T>& Number<T>::operator=(const Number<T>& a) {
    val = a.val;
    return *this;
}

template<typename T>
Number<T> operator+(const Number<T>& a, const Number<T>& b) {
    return Number<T>(a.val + b.val);
}

template<typename T>
Number<T> operator-(const Number<T>& a, const Number<T>& b) {
    return Number<T>(a.val - b.val);
}

template<typename T>
Number<T> operator*(const Number<T>& a, const Number<T>& b) {
    return Number<T>(a.val * b.val);
}

template<typename T>
Number<T> operator/(const Number<T>& a, const Number<T>& b) {
    return Number<T>(a.val / b.val);
}

template<typename T>
Number<T> operator%(const Number<T>& a, const Number<T>& b) {
    return Number<T>(a.val % b.val);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Number<T>& a) {
    return os << a.val;
}

template<typename T>
std::istream& operator>>(std::istream& is, Number<T>& a) {
    return is >> a.val;
}
// ----------------------------------------------------------------------------

int main() {
    // testing Number<int>
    // ------------------------------------------------------------------------
    Number<int> i = 12;
    std::cout << "i = " << i << '\n';

    Number<int> i2 = 6;
    std::cout << "i2 = " << i2 << '\n';

    Number<int> i_plus_i2 = i + i2;
    std::cout << "i_plus_i2 = " << i_plus_i2 << '\n';

    Number<int> i_minus_i2 = i - i2;
    std::cout << "i_minus_i2 = " << i_minus_i2 << '\n';

    Number<int> i_mult_i2 = i * i2;
    std::cout << "i_mult_i2 = " << i_mult_i2 << '\n';

    Number<int> i_div_i2 = i / i2;
    std::cout << "i_div_i2 = " << i_div_i2 << '\n';

    Number<int> i_mod_i2 = i % i2;
    std::cout << "i_mod_i2 = " << i_mod_i2 << '\n';

    Number<int> i3;
    std::cin >> i3;
    std::cout << "i3 = " << i3 << '\n';
    // ------------------------------------------------------------------------

    // testing Number<double>
    // ------------------------------------------------------------------------
    Number<double> d = 62.4;
    std::cout << "d = " << d << '\n';

    Number<double> d2 = 6.9;
    std::cout << "d2 = " << d2 << '\n';

    Number<double> d_plus_d2 = d + d2;
    std::cout << "d_plus_d2 = " << d_plus_d2 << '\n';

    Number<double> d_minus_d2 = d - d2;
    std::cout << "d_minus_d2 = " << d_minus_d2 << '\n';

    Number<double> d_mult_d2 = d * d2;
    std::cout << "d_mult_d2 = " << d_mult_d2 << '\n';

    Number<double> d_div_d2 = d / d2;
    std::cout << "d_div_d2 = " << d_div_d2 << '\n';

    // doesn't work
    // Number<double> d_mod_d2 = d % d2;
    // std::cout << "d_mod_d2 = " << d_mod_d2 << '\n';

    Number<double> d3;
    std::cin >> d3;
    std::cout << "d3 = " << d3 << '\n';
    // ------------------------------------------------------------------------

    return 0;
}
