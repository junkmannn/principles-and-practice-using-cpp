#ifndef GROUP_H
#define GROUP_H

#include "Graph.h"
#include <vector>

namespace Graph_lib {

class Group {
public:
	Group();
	Group(const Group& g) = delete;
	Group& operator=(const Group& g) = delete;

	void add(Shape& s);
	bool remove(Shape& s);
	void remove_all();
	Shape& get(int i) const;
	Shape& operator[](int i);
	int number_of_shapes() const;
	void set_color(Color c);
	void set_fill_color(Color c);
	void set_style(Line_style ls);
	void move(int dx, int dy);

private:
	std::vector<Shape*> shapes;
};

}

#endif
