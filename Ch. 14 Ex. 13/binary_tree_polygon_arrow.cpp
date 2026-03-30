#include "binary_tree_polygon_arrow.h"
#include "arrow.h"

// debug and benchmark includes
#include <omp.h>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Graph_lib;

// 0.00033 (1.79x)
void Binary_tree_polygon_arrow::draw_branches(const std::vector<std::pair<Point,Point>>& branches) const {
	double start = omp_get_wtime();



	typedef Point Vector;

	if (!color().visibility()) return;

	fl_color(color().as_int());

	Point p1;
	Point p2;
	Point* from;
	Point* to; // head of the arrow
	if (arrow_direction == DOWN) {
		from = &p1;
		to = &p2;
	}
	else {
		from = &p2;
		to = &p1;
	}

	Arrow arrow;
	arrow.set_color(color());
	arrow.set_style(style());

	int node_radius = get_node_radius();
	int lvls = get_levels() - 1; // minus one!!
	int lvl_num_branches = 2;
	int branch_idx = 0;
	int branch_idx_max = 2;
	int dx = 0;
	int i = 0;
	int i2 = 0;

	while (true) {
		p1 = branches[branch_idx].first;
		p2 = branches[branch_idx].second;

		Vector v(p2.x-p1.x, p2.y-p1.y);
		double old_length = sqrt(pow(v.x,2)+pow(v.y,2));
		double new_length = old_length - node_radius;
		double scale = new_length/old_length;

		pair<Point,Point> lines[2];

		i2 = 0;
		while (true) {
			Point p1_bak = p1;

			v.x *= scale;
			v.y *= scale;

			p1.x = p2.x - v.x;
			p1.y = p2.y - v.y;
			p2.x = p1_bak.x + v.x;
			p2.y = p1_bak.y + v.y;

			arrow.set_p1(*from);
			arrow.set_p2(*to);
			arrow.draw();

			lines[i2] = make_pair(p1, p2);

			++branch_idx;
			++i2;
			if (i2 == 2) break;

			p1 = branches[branch_idx].first;
			p2 = branches[branch_idx].second;

			v = Vector(p2.x-p1.x, p2.y-p1.y);
		}

		int offset = 0;
		while (branch_idx < branch_idx_max) {
			offset += dx;

			for (i2 = 0; i2 < 2; ++i2) {
				pair<Point,Point> line = lines[i2];
				p1 = line.first;
				p2 = line.second;
				p1.x += offset;
				p2.x += offset;
				arrow.set_p1(*from);
				arrow.set_p2(*to);
				arrow.draw();
			}

			branch_idx += 2;
		}

		++i;
		if (i == lvls) break;

		dx = branches[branch_idx+2].first.x - branches[branch_idx].first.x;

		lvl_num_branches *= 2;
		branch_idx_max = branch_idx + lvl_num_branches;
	}



	double end = omp_get_wtime();
	double time = end - start;
	cout << fixed << setprecision(10) << time << '\n';
}

// 0.00059 (1.10x)
/*
void Binary_tree_polygon_arrow::draw_branches(const std::vector<std::pair<Point,Point>>& branches) const {
	double start = omp_get_wtime();



	typedef Point Vector;

	if (!color().visibility()) return;

	fl_color(color().as_int());

	Point p1;
	Point p2;
	Point* from;
	Point* to; // head of the arrow
	if (arrow_direction == DOWN) {
		from = &p1;
		to = &p2;
	}
	else {
		from = &p2;
		to = &p1;
	}

	Arrow arrow;
	arrow.set_color(color());
	arrow.set_style(style());

	int node_radius = get_node_radius();
	int lvls = get_levels() - 1; // minus one!!
	int lvl_num_branches = 1;
	int branch_idx = 0;
	int branch_idx_max = 0;

	for (int i = 0; i < lvls; ++i) {
		lvl_num_branches *= 2;
		branch_idx_max = branch_idx + lvl_num_branches;

		p1 = branches[branch_idx].first;
		p2 = branches[branch_idx].second;

		Vector v(p2.x-p1.x, p2.y-p1.y);
		double old_length = sqrt(pow(v.x,2)+pow(v.y,2));
		double new_length = old_length - node_radius;
		double scale = new_length/old_length;

		while (true) {
			Point p1_bak = p1;

			v.x *= scale;
			v.y *= scale;

			p1.x = p2.x - v.x;
			p1.y = p2.y - v.y;
			p2.x = p1_bak.x + v.x;
			p2.y = p1_bak.y + v.y;

			arrow.set_p1(*from);
			arrow.set_p2(*to);
			// arrow.draw();

			++branch_idx;
			if (branch_idx == branch_idx_max) break;

			p1 = branches[branch_idx].first;
			p2 = branches[branch_idx].second;

			v = Vector(p2.x-p1.x, p2.y-p1.y);
		}


	}



	double end = omp_get_wtime();
	double time = end - start;
	cout << fixed << setprecision(10) << time << '\n';
}
*/

// 0.00065 (13.23x)
/*
void Binary_tree_polygon_arrow::draw_branches(const std::vector<std::pair<Point,Point>>& branches) const {
	double start = omp_get_wtime();



	typedef Point Vector;

	if (!color().visibility()) return;

	fl_color(color().as_int());

	Point p1;
	Point p2;
	Point* from;
	Point* to; // head of the arrow
	if (arrow_direction == DOWN) {
		from = &p1;
		to = &p2;
	}
	else {
		from = &p2;
		to = &p1;
	}

	Arrow arrow;
	arrow.set_color(color());
	arrow.set_style(style());

	int node_radius = get_node_radius();
	int lvls = get_levels() - 1; // minus one!!
	int lvl_num_branches = 1;
	int branch_idx = 0;
	int branch_idx_max = 0;

	for (int i = 0; i < lvls; ++i) {
		lvl_num_branches *= 2;
		branch_idx_max = branch_idx + lvl_num_branches;

		p1 = branches[branch_idx].first;
		p2 = branches[branch_idx].second;

		Vector v(p2.x-p1.x, p2.y-p1.y);
		double old_length = sqrt(pow(v.x,2)+pow(v.y,2));
		double new_length = old_length - node_radius;
		double scale = new_length/old_length;

		for (; branch_idx != branch_idx_max; ++branch_idx) {
			p1 = branches[branch_idx].first;
			p2 = branches[branch_idx].second;
			Point p1_bak = p1;

			v = Vector(p2.x-p1.x, p2.y-p1.y);
			v.x *= scale;
			v.y *= scale;

			p1.x = p2.x - v.x;
			p1.y = p2.y - v.y;
			p2.x = p1_bak.x + v.x;
			p2.y = p1_bak.y + v.y;

			arrow.set_p1(*from);
			arrow.set_p2(*to);
			// arrow.draw();
		}
	}



	double end = omp_get_wtime();
	double time = end - start;
	cout << fixed << setprecision(10) << time << '\n';
}
*/

// 0.0086
/*
void Binary_tree_polygon_arrow::draw_branches(const std::vector<std::pair<Point,Point>>& branches) const {
	double start = omp_get_wtime();



	typedef Point Vector;

	if (!color().visibility()) return;

	fl_color(color().as_int());

	Point p1;
	Point p2;
	Point* from;
	Point* to; // head of the arrow
	if (arrow_direction == DOWN) {
		from = &p1;
		to = &p2;
	}
	else {
		from = &p2;
		to = &p1;
	}

	Arrow arrow;
	arrow.set_color(color());
	arrow.set_style(style());

	int node_radius = get_node_radius();
	int num_branches = number_of_nodes() - 1;

	for (int i = 0; i < num_branches; ++i) {
		p1 = branches[i].first;
		p2 = branches[i].second;
		Point p1_bak = p1;

		typedef Point Vector;
		Vector v(p2.x-p1.x, p2.y-p1.y);
		double old_length = sqrt(pow(v.x,2)+pow(v.y,2));
		double new_length = old_length - node_radius;
		v.x *= new_length/old_length;
		v.y *= new_length/old_length;

		p1.x = p2.x - v.x;
		p1.y = p2.y - v.y;
		p2.x = p1_bak.x + v.x;
		p2.y = p1_bak.y + v.y;

		arrow.set_p1(*from);
		arrow.set_p2(*to);
		arrow.draw();
	}



	double end = omp_get_wtime();
	double time = end - start;
	cout << fixed << setprecision(10) << time << '\n';
}
*/
