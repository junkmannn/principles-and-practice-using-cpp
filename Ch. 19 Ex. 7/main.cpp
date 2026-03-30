#include <vector>
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

template<typename T>
T sum_mult_vec(const std::vector<T>& v1, const std::vector<T>& v2);

int main() {
    std::vector<Number<int>> vt = { 0, 1, 2, 3, 4 };
    std::vector<Number<int>> vu = { 5, 6, 7, 8, 9 };
    Number<int> sum = sum_mult_vec(vt, vu);
    std::cout << "sum = " << sum << '\n';

    std::vector<Number<double>> vt2 = { 5.2, 6.7, 22.8, 44.0, 12.4 };
    std::vector<Number<double>> vu2 = { 73.0, 2.0, -4.0, 4.0, -5.0 };
    Number<double> sum2 = sum_mult_vec(vt2, vu2);
    std::cout << "sum2 = " << sum2 << '\n';

    return 0;
}

template<typename T>
T sum_mult_vec(const std::vector<T>& v1, const std::vector<T>& v2) {
    T sum = 0;
    for (int i = 0, sz = v1.size(); i < sz; ++i)
        sum = sum + v1[i]*v2[i];
    return sum;
}
