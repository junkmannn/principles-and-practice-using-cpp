#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"
#include <vector>
#include <cmath>

namespace Graph_lib {

class Binary_tree : public Shape {
public:
	Binary_tree() : node_radius(0), dx(0), dy(0), levels(0) { add(Point()); }
	Binary_tree(Point pos, int node_radius, int dx, int dy, int lvls) :
		node_radius(node_radius), dx(dx), dy(dy), levels(lvls) { add(pos); }

	Point get_pos() const { return point(0); }
	void set_pos(Point p) { set_point(0, p); }

	int get_node_radius() const { return node_radius; }
	void set_node_radius(int i) { node_radius = i; }

	int get_dx() const { return dx; }
	void set_dx(int i) { dx = i; }

	int get_dy() const { return dy; }
	void set_dy(int i) { dy = i; }

	int get_levels() const { return levels; }
	void set_levels(int i) { levels = i; }

	int number_of_nodes() const { return pow(2.0, (double)levels) - 1; }

protected:
	virtual void draw_lines() const;

private:
	int node_radius;
	int dx;
	int dy;
	int levels;
};

}

#endif
