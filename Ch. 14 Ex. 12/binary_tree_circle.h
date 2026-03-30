#ifndef BINARY_TREE_CIRCLE_H
#define BINARY_TREE_CIRCLE_H

#include "binary_tree.h"

namespace Graph_lib {

class Binary_tree_circle : public Binary_tree {
public:
	Binary_tree_circle() : node_radius(0) { }
	Binary_tree_circle(Point root, int node_radius, int dx, int dy, int lvls) :
		Binary_tree(root, node_radius*2, node_radius*2, dx, dy, lvls), node_radius(node_radius) { }

	int get_node_radius() const { return node_radius; }
	void set_node_radius(int i) { node_radius = i; set_node_width(i*2); set_node_height(i*2); }

protected:
	virtual void draw_nodes(const std::vector<Point>& nodes) const;

private:
	int node_radius;
};

}

#endif
