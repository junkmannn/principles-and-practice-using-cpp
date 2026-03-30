#ifndef BINARY_TREE_POLYGON_ARROW_H
#define BINARY_TREE_POLYGON_ARROW_H

#include "binary_tree_polygon.h"

namespace Graph_lib {

class Binary_tree_polygon_arrow : public Binary_tree_polygon {
public:
	enum Direction { UP, DOWN };

	Binary_tree_polygon_arrow() : arrow_direction(UP) { }
	Binary_tree_polygon_arrow
		(Point root, int node_radius, int node_sides, int dx, int dy, int lvls, Direction dir) :
		Binary_tree_polygon(root, node_radius, node_sides, dx, dy, lvls), arrow_direction(dir) { }

protected:
	virtual void draw_branches(const std::vector<std::pair<Point,Point>>& branches) const;

private:
	Direction arrow_direction;
};

}

#endif
