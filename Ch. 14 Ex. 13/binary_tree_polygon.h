#ifndef BINARY_TREE_POLYGON_H
#define BINARY_TREE_POLYGON_H

#include "binary_tree.h"

namespace Graph_lib {

class Binary_tree_polygon : public Binary_tree {
public:
	Binary_tree_polygon() : node_radius(0), node_sides(0) { }
	Binary_tree_polygon(Point root, int node_radius, int node_sides, int dx, int dy, int lvls) :
		Binary_tree(root, node_radius*2, node_radius*2, dx, dy, lvls),
		node_radius(node_radius), node_sides(node_sides) { }

	int get_node_radius() const { return node_radius; }
	void set_node_radius(int i) { node_radius = i; set_node_width(i*2); set_node_height(i*2); }

	int get_node_sides() const { return node_sides; }
	void set_node_sides(int i) { node_sides = i; }

protected:
	virtual void draw_nodes(const std::vector<Point>& nodes) const;

private:
	int node_radius;
	int node_sides;
};

}

#endif
