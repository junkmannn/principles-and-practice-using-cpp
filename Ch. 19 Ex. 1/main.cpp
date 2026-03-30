#include <vector>
#include <iostream>

template<typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2);

int main() {
    std::vector<double> v1 = { 1.0, 2.4, 66.3, 23.4, 0.2 };
    std::vector<double> v2 = { 42.5, 88.1, 1.4, 4.7, 9.2 };
    f(v1, v2);
    for (double d : v1)
        std::cout << d << '\n';

    return 0;
}

template<typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2) {
    for (int i = 0, sz = v1.size(); i < sz; ++i)
        v1[i] += v2[i];
}
