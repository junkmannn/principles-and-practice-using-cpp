#include <iostream>
#include <vector>

template<class T1, class T2>
class Pair {
public:
    Pair(T1 first, T2 second);

    T1 first;
    T2 second;
};

template<class T1, class T2>
Pair<T1,T2>::Pair(T1 first, T2 second) : first(first), second(second) { }

class Symbol_table {
public:
    double get_value(const std::string& var);
    void set_value(const std::string& var, double val);
    bool is_declared(const std::string& var);
    double define_name(const std::string& var, double val);

private:
    std::vector<Pair<std::string, double>> symbols;
};

double Symbol_table::get_value(const std::string& var) {
    for (const auto& symbol : symbols) {
        if (symbol.first == var)
            return symbol.second;
    }
    throw std::runtime_error("get: undefined variable " + var);
}

void Symbol_table::set_value(const std::string& var, double val) {
    for (auto& symbol : symbols) {
        if (symbol.first == var) {
            symbol.second = val;
            return;
        }
    }
    throw std::runtime_error("set: undefined variable " + var);
}

bool Symbol_table::is_declared(const std::string& var) {
    for (const auto& symbol : symbols) {
        if (symbol.first == var)
            return true;
    }
    return false;
}

double Symbol_table::define_name(const std::string& var, double val) {
    if (is_declared(var))
        throw std::runtime_error(var + " already declared");
    symbols.push_back(Pair<std::string, double>(var, val));
    return val;
}

int main() {
    std::cout << std::boolalpha;

    Symbol_table st;

    try {
        st.get_value("kek");
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

    try {
        st.set_value("kek", 1335.6);;
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

    std::cout << st.is_declared("kek") << '\n';

    std::cout << st.define_name("kek", 88.0) << '\n';

    std::cout << st.get_value("kek") << '\n';

    st.set_value("kek", 136.4);

    std::cout << st.get_value("kek") << '\n';

    std::cout << st.is_declared("kek") << '\n';

    return 0;
}
