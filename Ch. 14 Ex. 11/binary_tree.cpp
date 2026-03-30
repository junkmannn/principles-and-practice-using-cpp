#include "binary_tree.h"

using namespace std;
using namespace Graph_lib;

void Binary_tree::draw_lines() const {
	if (levels == 0 || (!color().visibility() && !fill_color().visibility())) {
		return; // nothing to draw here
	}

	if (levels == 1) {
		Circle(point(0), node_radius, color(), fill_color(), style()).draw();
		return;
	}

	// center point of the root node
	Point root = point(0);
	int node_diameter = 2 * node_radius;

	// total number of nodes
	int num_nodes = number_of_nodes();
	vector<Point> nodes(num_nodes);
	int node_idx = num_nodes - 1;

	// total number of branches
	int num_branches = num_nodes - 1;
	vector<pair<Point,Point>> branches(num_branches);
	int branch_idx = num_branches - 1;

	// range [0, levels-1] aka [top, bottom]
	int lvl = levels - 1;
	// number of nodes on some level
	int lvl_num_nodes = (num_nodes + 1) / 2;

	// dx between circles (center points) on some level
	int lvl_dx = dx + node_diameter;
	// length of the bounding box of all the nodes on some level
	int lvl_length = node_diameter*lvl_num_nodes + dx*(lvl_num_nodes-1);
	// x coordinate (center point) of some node on some level
	int lvl_x = root.x + lvl_length/2 - node_radius;
	// x coordinate (center point) of the last node on some level
	int lvl_x2 = lvl_x;
	// x coordinate (center point) of the second-to-last node on some level
	int lvl_x3 = lvl_x - lvl_dx;

	// dy between circles (center points) on some level - always the same
	const int lvl_dy = dy + node_diameter;
	// height of the bounding box of all the nodes on some level - always the same
	const int lvl_height = dy*lvl + node_diameter*lvl;
	// y coordinate (center point) of some node on some level
	int lvl_y = root.y + lvl_height;

	// we start from the bottom of the binary tree...
	for (int i = 0; i < lvl_num_nodes; ++i) {
		nodes[node_idx] = Point(lvl_x, lvl_y);
		--node_idx;
		lvl_x -= lvl_dx;
	}

	// ...and go towards the top (root) while adding the branches
	for (--lvl; lvl >= 1; --lvl) {
		lvl_num_nodes /= 2;
		lvl_x = (lvl_x2 + lvl_x3) / 2;
		lvl_length -= (lvl_x2 - lvl_x) * 2;
		lvl_dx = (lvl_length - node_diameter*lvl_num_nodes) / (lvl_num_nodes - 1) + node_diameter;
		lvl_x2 = lvl_x;
		lvl_x3 = lvl_x - lvl_dx;
		lvl_y -= lvl_dy;

		for (int i = 0; i < lvl_num_nodes; ++i) {
			Point p1(lvl_x, lvl_y);
			nodes[node_idx] = p1;
			--node_idx;
			branches[branch_idx] = make_pair(p1, nodes[branch_idx+1]);
			--branch_idx;
			branches[branch_idx] = make_pair(p1, nodes[branch_idx+1]);
			--branch_idx;
			lvl_x -= lvl_dx;
		}
	}

	nodes[node_idx] = root;
	branches[branch_idx] = make_pair(root, nodes[branch_idx+1]);
	--branch_idx;
	branches[branch_idx] = make_pair(root, nodes[branch_idx+1]);


	// draw...
	if (color().visibility()) {
		fl_color(color().as_int());

		for (branch_idx = 0; branch_idx < num_branches; ++branch_idx) {
			Point p1 = branches[branch_idx].first;
			Point p2 = branches[branch_idx].second;
			fl_line(p1.x, p1.y, p2.x, p2.y);
		}

		for (node_idx = 0; node_idx < num_nodes; ++node_idx) {
			Point p = nodes[node_idx];
			fl_arc(p.x-node_radius, p.y-node_radius, node_diameter, node_diameter, 0.0, 360.0);
		}
	}

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		for (node_idx = 0; node_idx < num_nodes; ++node_idx) {
			Point p = nodes[node_idx];
			fl_pie(p.x-node_radius, p.y-node_radius, node_diameter-1, node_diameter-1, 0.0, 360.0);
		}
	}
}
