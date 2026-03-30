#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <random>

template<typename T>
class Skip_list {
public:
    // Constructors
    Skip_list();
    Skip_list(const Skip_list& list);
    Skip_list(Skip_list&& list);

    // Destructor
    ~Skip_list();

    // Assignment operators
    Skip_list& operator=(const Skip_list& list);
    Skip_list& operator=(Skip_list&& list);

    // Operations
    bool insert(const T& value);
    bool insert(T&& value);
    bool remove(const T& value);
    void remove_all();
    bool contains(const T& value) const;

private:
    // Data types
    // ------------------------------------------------------------------------
    struct Skip_list_node {
        Skip_list_node();
        Skip_list_node* right;
        Skip_list_node* down;
        T* value;
    };
    // ------------------------------------------------------------------------

    // Member variables
    Skip_list_node* top_lvl_header;
    Skip_list_node* bottom_lvl_header;

    // Member functions
    void copy(const Skip_list& list);
    Skip_list_node* search(const T& value) const;
    int search(const T& value, Skip_list_node** arr) const;
    bool insert_impl(const T& value, bool move);

    // Static member functions
    static int random_level();
    static void insert_node(Skip_list_node* old_left, Skip_list_node* new_right);
    static void remove_node(Skip_list_node* node, Skip_list_node* left);
    static Skip_list_node* promote_node(Skip_list_node* node);
};

// struct Skip_list<T>::Skip_list_node implementation
// ----------------------------------------------------------------------------
template<typename T>
Skip_list<T>::Skip_list_node::Skip_list_node() :
    right(0), down(0), value(0) { }
// ----------------------------------------------------------------------------

// class Skip_list<T> implementation
// ----------------------------------------------------------------------------
template<typename T>
Skip_list<T>::Skip_list() :
    top_lvl_header(new Skip_list_node), bottom_lvl_header(top_lvl_header) { }

template<typename T>
Skip_list<T>::Skip_list(const Skip_list& list) :
    top_lvl_header(new Skip_list_node), bottom_lvl_header(top_lvl_header) {
    copy(list);
}

template<typename T>
Skip_list<T>::Skip_list(Skip_list&& list) :
    top_lvl_header(list.top_lvl_header), bottom_lvl_header(list.bottom_lvl_header) {
    list.top_lvl_header = new Skip_list_node;
    list.bottom_lvl_header = list.top_lvl_header;
}

template<typename T>
Skip_list<T>::~Skip_list() {
    remove_all();
    delete top_lvl_header;
}

template<typename T>
typename Skip_list<T>::Skip_list& Skip_list<T>::operator=(const Skip_list& list) {
    if (this == &list)
        return *this;
    remove_all();
    copy(list);
    return *this;
}

template<typename T>
typename Skip_list<T>::Skip_list& Skip_list<T>::operator=(Skip_list&& list) {
    if (this == &list)
        return *this;
    remove_all();
    Skip_list_node* tmp = top_lvl_header;
    top_lvl_header = list.top_lvl_header;
    bottom_lvl_header = list.bottom_lvl_header;
    list.top_lvl_header = tmp;
    list.bottom_lvl_header = list.top_lvl_header;
    return *this;
}

template<typename T>
bool Skip_list<T>::insert(const T& value) {
    return insert_impl(value, false);
}

template<typename T>
bool Skip_list<T>::insert(T&& value) {
    return insert_impl(value, true);
}

template<typename T>
bool Skip_list<T>::remove(const T& value) {
    Skip_list_node* route[32];
    int i;

    // Search for the value
    i = search(value, route)-1;

    // Check if it exists
    if (!route[i]->right || *route[i]->right->value != value)
        return false;

    // Remove it from all levels
    T* value_addr = route[i]->right->value;
    delete route[i]->right->value;
    do {
        remove_node(route[i]->right, route[i]);
        --i;
    }
    while (i >= 0 && route[i]->right->value == value_addr);

    // Adjust the list's height if needed
    while (!top_lvl_header->right && top_lvl_header->down) {
        Skip_list_node* new_header = top_lvl_header->down;
        delete top_lvl_header;
        top_lvl_header = new_header;
    }

    return true;
}

template<typename T>
void Skip_list<T>::remove_all() {
    Skip_list_node* cur_node;

    cur_node = bottom_lvl_header->right;
    while (cur_node) {
        Skip_list_node* right_node = cur_node->right;
        delete cur_node->value;
        delete cur_node;
        cur_node = right_node;
    }

    while (top_lvl_header != bottom_lvl_header) {
        Skip_list_node* down_node = top_lvl_header->down;
        cur_node = top_lvl_header;
        do {
            Skip_list_node* right_node = cur_node->right;
            delete cur_node;
            cur_node = right_node;
        }
        while (cur_node);
        top_lvl_header = down_node;
    }

    top_lvl_header->right = 0;
}

template<typename T>
bool Skip_list<T>::contains(const T& value) const {
    Skip_list_node* node = search(value);
    return node->right && *node->right->value == value;
}

template<typename T>
void Skip_list<T>::copy(const Skip_list& list) {
    Skip_list_node* cur_node = list.bottom_lvl_header;
    while (cur_node = cur_node->right)
        insert(*cur_node->value);
}

template<typename T>
typename Skip_list<T>::Skip_list_node* Skip_list<T>::search(const T& value) const {
    Skip_list_node* cur_node = top_lvl_header;
    bool search = true;
    while (search) {
        if (cur_node->right && *cur_node->right->value < value)
            cur_node = cur_node->right;
        else if (cur_node->down)
            cur_node = cur_node->down;
        else
            search = false;
    }
    return cur_node;
}

template<typename T>
int Skip_list<T>::search(const T& value, Skip_list_node** arr) const {
    int i = 0;
    Skip_list_node* cur_node = top_lvl_header;
    bool search = true;
    while (search) {
        if (cur_node->right && *cur_node->right->value < value) {
            cur_node = cur_node->right;
        }
        else if (cur_node->down) {
            arr[i] = cur_node;
            cur_node = cur_node->down;
            ++i;
        }
        else {
            search = false;
        }
    }
    arr[i] = cur_node;
    return i+1;
}

template<typename T>
bool Skip_list<T>::insert_impl(const T& value, bool move) {
    Skip_list_node* route[32];
    int i;
    int num_levels;
    Skip_list_node* new_node;

    // Search where to insert the value
    num_levels = search(value, route);
    i = num_levels-1;

    // Check if it is a duplicate
    if (route[i]->right && *route[i]->right->value == value)
        return false;

    // Insert it
    new_node = new Skip_list_node;
    if (move)
        new_node->value = new T(std::move(const_cast<T&>(value)));
    else
        new_node->value = new T(value);
    insert_node(route[i], new_node);

    // Promote it and adjust the list's height if needed
    int num_rand_levels = random_level();
    int max = (num_rand_levels <= num_levels) ? num_rand_levels : num_levels;
    int x;
    for (x = 1; x < max; ++x) {
        --i;
        new_node = promote_node(new_node);
        insert_node(route[i], new_node);
    }
    if (num_rand_levels <= num_levels)
        return true;
    for (x = 0; x < num_rand_levels-num_levels; ++x) {
        top_lvl_header = promote_node(top_lvl_header);
        new_node = promote_node(new_node);
        insert_node(top_lvl_header, new_node);
    }

    return true;
}

template<typename T>
int Skip_list<T>::random_level() {
    static thread_local std::mt19937 rng;
    int num_rand_levels = 1;
    while ((rng() & 1) == 0)
        ++num_rand_levels;
    return num_rand_levels;
}

template<typename T>
void Skip_list<T>::insert_node(Skip_list_node* old_left, Skip_list_node* new_right) {
    Skip_list_node* old_right = old_left->right;
    old_left->right = new_right;
    new_right->right = old_right;
}

template<typename T>
void Skip_list<T>::remove_node(Skip_list_node* node, Skip_list_node* left) {
    left->right = node->right;
    delete node;
}

template<typename T>
typename Skip_list<T>::Skip_list_node* Skip_list<T>::promote_node(Skip_list_node* node) {
    Skip_list_node* promoted = new Skip_list_node;
    promoted->value = node->value;
    promoted->down = node;
    return promoted;
}
// ----------------------------------------------------------------------------
// class Skip_list<T> implementation

#endif
