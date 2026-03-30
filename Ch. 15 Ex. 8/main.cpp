#include "Simple_window.h"
#include "Graph.h"
#include "people_height.h"
#include "point_graph.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
using namespace Graph_lib;

const int SUCCESS = 0;
const int FILE_NOT_FOUND = 1;
const int MALFORMED_FILE = 2;

int read_data(const string& filename, vector<People_height>& v);

int main() {
	cout << "Enter file name: ";
	string filename;
	getline(cin, filename);
	if (!cin) return 0;

	vector<People_height> data;
	int code = read_data(filename, data);
	// int code = read_data("data.txt", data);
	switch (code) {
	case FILE_NOT_FOUND:
		cerr << "error: file not found\n";
		return 1;
	case MALFORMED_FILE:
		cerr << "error: malformed file\n";
		return 2;
	}

	Simple_window win(Point(100,100), 600, 400, "Ch. 15 Ex. 8");

	const Point graph_origin(100, 300);

	Point_graph<People_height> graph;
	graph.set_origin(graph_origin);
	graph.set_data(&data);
	graph.set_xrange(150.0, 200.0);
	graph.set_yrange(0.0, 25.0);
	graph.set_xscale(8.0);
	graph.set_yscale(8.0);
	graph.set_xstart(150.0);
	graph.set_ystart(0.0);
	graph.set_point_size(3);
	win.attach(graph);

	Point graph_title_pos(graph_origin);
	graph_title_pos.x += 70;
	graph_title_pos.y -= 250;
	Text graph_title(graph_title_pos, "Height distribution of people in a group");
	graph_title.set_font_size(16);
	win.attach(graph_title);

	const int ya_length =
		int((graph.get_yrange_max()-graph.get_yrange_min())*graph.get_yscale());
	Axis ya(Axis::y, graph_origin, ya_length, 5);
	win.attach(ya);

	Point ya_lbl_pos(graph_origin);
	ya_lbl_pos.x -= 90;
	ya_lbl_pos.y -= ya_length/2 - 5;
	Text ya_lbl(ya_lbl_pos, "Count");
	win.attach(ya_lbl);

	Point ya_min_lbl_pos(graph_origin);
	ya_min_lbl_pos.x -= 20;
	ya_min_lbl_pos.y += 0;
	Text ya_min_lbl(ya_min_lbl_pos, to_string((int)graph.get_yrange_min()));
	win.attach(ya_min_lbl);

	Point ya_max_lbl_pos(graph_origin);
	ya_max_lbl_pos.x -= 25;
	ya_max_lbl_pos.y -= ya_length - 10;
	Text ya_max_lbl(ya_max_lbl_pos, to_string((int)graph.get_yrange_max()));
	win.attach(ya_max_lbl);

	const int xa_length =
		int((graph.get_xrange_max()-graph.get_xrange_min())*graph.get_xscale());
	Axis xa(Axis::x, graph_origin, xa_length, 5);
	win.attach(xa);

	Point xa_lbl_pos(graph_origin);
	xa_lbl_pos.x += xa_length/2 - 35;
	xa_lbl_pos.y += 50;
	Text xa_lbl(xa_lbl_pos, "Height (cm)");
	win.attach(xa_lbl);

	Point xa_min_lbl_pos(graph_origin);
	xa_min_lbl_pos.x += 0;
	xa_min_lbl_pos.y += 20;
	Text xa_min_lbl(xa_min_lbl_pos, to_string((int)graph.get_xrange_min()));
	win.attach(xa_min_lbl);

	Point xa_max_lbl_pos(graph_origin);
	xa_max_lbl_pos.x += xa_length - 25;
	xa_max_lbl_pos.y += 20;
	Text xa_max_lbl(xa_max_lbl_pos, to_string((int)graph.get_xrange_max()));
	win.attach(xa_max_lbl);

	win.wait_for_button(); // display!

	// tests...
	/*
	graph.set_color(Color::red);

	win.wait_for_button(); // display!

	graph.set_xrange(100.0, 200.0);
	graph.set_xstart(100.0);
	graph.set_xscale(4.0);

	win.wait_for_button(); // display!

	graph.set_yrange(2.0, 27.0);

	win.wait_for_button(); // display!

	graph.set_ystart(2.0);

	win.wait_for_button(); // display!

	graph.set_point_size(1);

	win.wait_for_button(); // display!
	*/

	return 0;
}

int read_data(const string& filename, vector<People_height>& v) {
	ifstream ifs(filename);

	if (!ifs) return FILE_NOT_FOUND;

	string entry;
	while (getline(ifs, entry)) {
		istringstream iss(entry);

		if ((iss>>ws).eof()) continue; // ignore empty lines

		int height = 0;
		int num_people = 0;

		if ((iss>>height).fail() ||
			(iss>>ws).eof() ||
			(iss>>num_people).fail() ||
			!(iss>>ws).eof()) {
			return MALFORMED_FILE;
		}

		v.push_back(People_height(height,num_people));
	}

	return SUCCESS;
}
