#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"
#include <vector>
#include <cmath>

namespace Graph_lib {

class Binary_tree : public Shape {
public:
	Binary_tree() : node_width(0), node_height(0), dx(0), dy(0), levels(0) { add(Point()); }
	Binary_tree(Point root, int node_width, int node_height, int dx, int dy, int lvls) :
		node_width(node_width), node_height(node_height), dx(dx), dy(dy), levels(lvls) { add(root); }

	Point get_pos() const { return point(0); }
	void set_pos(Point p) { set_point(0, p); }

	int get_dx() const { return dx; }
	void set_dx(int i) { dx = i; }

	int get_dy() const { return dy; }
	void set_dy(int i) { dy = i; }

	int get_levels() const { return levels; }
	void set_levels(int i) { levels = i; }

	int number_of_nodes() const { return (int)pow(2.0, (double)levels) - 1; }

protected:
	int get_node_width() const { return node_width; }
	void set_node_width(int i) { node_width = i; }

	int get_node_height() const { return node_height; }
	void set_node_height(int i) { node_height = i; }

	virtual void draw_lines() const;

	virtual void draw_nodes(const std::vector<Point>& nodes) const = 0;
	virtual void draw_branches(const std::vector<std::pair<Point,Point>>& branches) const;

private:
	int node_width;
	int node_height;
	int dx;
	int dy;
	int levels;
};

}

#endif
