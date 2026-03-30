#include "binary_tree_circle.h"

using namespace std;
using namespace Graph_lib;

void Binary_tree_circle::draw_nodes(const std::vector<Point>& nodes) const {
	/*
	int node_idx = 0;
	int num_nodes = number_of_nodes();
	int node_diameter = node_radius * 2;
	Point p;

	if (color().visibility()) {
		fl_color(color().as_int());

		for (node_idx = 0; node_idx < num_nodes; ++node_idx) {
			p = nodes[node_idx];
			fl_arc(p.x-node_radius, p.y-node_radius, node_diameter, node_diameter, 0.0, 360.0);
		}
	}

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		for (node_idx = 0; node_idx < num_nodes; ++node_idx) {
			p = nodes[node_idx];
			fl_pie(p.x-node_radius, p.y-node_radius, node_diameter-1, node_diameter-1, 0.0, 360.0);
		}
	}
	*/

	int num_nodes = number_of_nodes();

	Circle c(Point(0,0), node_radius);
	c.set_color(color());
	c.set_fill_color(fill_color());
	c.set_style(style());
	for (int i = 0; i < num_nodes; ++i) {
		c.set_center(nodes[i]);
		c.draw();
	}
}
