#include <vector>
#include <iostream>

template<typename T, typename U>
T sum_mult_vec(const std::vector<T>& vt, const std::vector<U>& vu);

int main() {
    std::vector<int> vt = { 0, 1, 2, 3, 4 };
    std::vector<int> vu = { 5, 6, 7, 8, 9 };
    int sum = sum_mult_vec(vt, vu);
    std::cout << "sum = " << sum << '\n';

    std::vector<double> vt2 = { 5.2, 6.7, 22.8, 44.0, 12.4 };
    std::vector<int> vu2 = { 73, 2, -4, 4, -5 };
    double sum2 = sum_mult_vec(vt2, vu2);
    std::cout << "sum2 = " << sum2 << '\n';

    return 0;
}

template<typename T, typename U>
T sum_mult_vec(const std::vector<T>& vt, const std::vector<U>& vu) {
    T sum = 0;
    for (int i = 0, sz = vt.size(); i < sz; ++i)
        sum += vt[i] * vu[i];
    return sum;
}
