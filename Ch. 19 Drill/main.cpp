#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// template<class T> struct S
// ----------------------------------------------------------------------------

// 1. Define template<class T> struct S { T val; };.
template<class T>
struct S {
    // 2. Add a constructor, so that you can initialize it with a T.
    S(T t);
    // 5. Add a function template get() that returns a reference to val.
    T& get();
    // 11. Provide const and non-const versions of get().
    const T& get() const;
    // 9. Add a set() function template so that you can change val.
    // void set(const T& newval);
    // 10. Replace set() with an S<T>::operator=(const T&).
    //     Hint: Much simpler than 19.2.5.
    void operator=(const T& newval);

private:
    // 7. Make val private.
    T val;
};

template<class T>
S<T>::S(T t) : val(t) { }

// 6. Put the definition of get() outside the class.
template<class T>
T& S<T>::get() {
    return val;
}

template<class T>
const T& S<T>::get() const {
    return val;
}

/*
template<class T>
void S<T>::set(const T& newval) {
    val = newval;
}
*/

template<class T>
void S<T>::operator=(const T& newval) {
    val = newval;
}

// ----------------------------------------------------------------------------

// 12. Define a function template<class T> read_val(T& v) that
//     reads from cin into v.
template<class T>
void read_val(T& v);

// 14. Bonus: Define input and output operators (>> and <<) for vector<T>s.
//            For both input and output use a { val, val, val } format.
//            That will allow read_val() to also handle the S<vector<int>>
//            variable.
template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
template<class T>
std::istream& operator>>(std::istream& is, std::vector<T>& v);

int main() {
    // 3. Define variables of types S<int>, S<char>, S<double>,
    //    S<string>, and S<vector<int>>; initialize them with
    //    values of your choice.
    S<int> s_int(31);
    S<char> s_char('k');
    S<double> s_double(3.7);
    S<std::string> s_string("jej");
    S<std::vector<int>> s_vector({ });

    // 4. Read those values and print them.
    // 8. Do 4 again using get().
    // 13. Use read_val() to read into each of the variables from 3 except the
    //     S<vector<int>> variable.
    read_val(s_int.get());
    read_val(s_char.get());
    read_val(s_double.get());
    read_val(s_string.get());
    read_val(s_vector.get());
    std::cout << "s_int contains " << s_int.get() << '\n';
    std::cout << "s_char contains " << s_char.get() << '\n';
    std::cout << "s_double contains " << s_double.get() << '\n';
    std::cout << "s_string contains " << s_string.get() << '\n';
    std::cout << "s_vector contains " << s_vector.get() << '\n';

    return 0;
}

template<class T>
void read_val(T& v) {
    std::cin >> v;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    int v_sz = v.size();

    if (!v_sz)
        return os << "{ }";

    std::ostringstream oss;
    oss << "{ ";
    for (int i = 0; i < v_sz; ++i)
        oss << v[i] << ", ";
    std::string str = oss.str();
    int str_sz = str.size();
    str[str_sz-2] = ' ';
    str[str_sz-1] = '}';

    return os << str;
}

template<class T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    std::ios::iostate except_iostate_bak = is.exceptions();

    try {
        is.exceptions(std::ios::failbit | std::ios::badbit);

        char c;
        bool read = true;

        is >> c;
        if (c != '{')
            is.setstate(std::ios::failbit);

        is >> c;
        if (c == '}')
            read = false;
        else
            is.unget();

        while (read) {
            T var;
            is >> var;
            v.push_back(var);

            is >> c;
            if (c == '}')
                read = false;
            else if (c != ',')
                is.setstate(std::ios::failbit);
        }
    }
    catch (std::ios::failure& e) { }

    is.exceptions(except_iostate_bak);

    return is;
}
