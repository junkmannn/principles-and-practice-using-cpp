#include "binary_tree_polygon.h"
#include "regular_polygon.h"

using namespace std;
using namespace Graph_lib;

void Binary_tree_polygon::draw_nodes(const std::vector<Point>& nodes) const {
	int num_nodes = number_of_nodes();

	Regular_polygon rp(Point(0,0), node_radius, node_sides);
	rp.set_color(color());
	rp.set_fill_color(fill_color());
	rp.set_style(style());
	for (int i = 0; i < num_nodes; ++i) {
		rp.set_center(nodes[i]);
		rp.draw();
	}
}
