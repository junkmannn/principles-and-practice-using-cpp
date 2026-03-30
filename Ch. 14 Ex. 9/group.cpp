#include "group.h"

using namespace std;
using namespace Graph_lib;

Group::Group() {

}

void Group::add(Shape& s) {
	shapes.push_back(&s);
}

bool Group::remove(Shape& s) {
	for (size_t i = 0, size = shapes.size(); i < size; ++i) {
		if (shapes[i] == &s) {
			shapes.erase(shapes.begin() + i);
			return true;
		}
	}
	return false;
}

void Group::remove_all() {
	shapes.clear();
}

Shape& Group::get(int i) const {
	return *shapes[i];
}

Shape& Group::operator[](int i) {
	return get(i);
}

int Group::number_of_shapes() const {
	return shapes.size();
}

void Group::set_color(Color c) {
	for (size_t i = 0, size = shapes.size(); i < size; ++i) {
		shapes[i]->set_color(c);
	}
}

void Group::set_fill_color(Color c) {
	for (size_t i = 0, size = shapes.size(); i < size; ++i) {
		shapes[i]->set_fill_color(c);
	}
}

void Group::set_style(Line_style ls) {
	for (size_t i = 0, size = shapes.size(); i < size; ++i) {
		shapes[i]->set_style(ls);
	}
}

void Group::move(int dx, int dy) {
	for (size_t i = 0, size = shapes.size(); i < size; ++i) {
		shapes[i]->move(dx, dy);
	}
}
