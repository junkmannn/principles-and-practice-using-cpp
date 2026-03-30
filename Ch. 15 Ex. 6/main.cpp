#include "Simple_window.h"
#include "Graph.h"
#include "bar_graph.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100,100), 600, 400, "Ch. 15 Ex. 6");

	Point graph_origin(50, 350);

	// set data
	vector<double> data;
	data.push_back(25.0);
	data.push_back(50.0);
	data.push_back(75.0);
	data.push_back(100.0);

	// draw graph
	int bar_width = 80;
	int bar_spacing = 20;
	double graph_scale = 2.0;
	Bar_graph graph;
	graph.set_data(&data);
	graph.set_graph_origin(graph_origin);
	graph.set_bar_width(bar_width);
	graph.set_bar_spacing(bar_spacing);
	graph.set_bar_scale(graph_scale);
	graph.set_fill_color(Color::red);
	win.attach(graph);

	// draw x-axis
	int xa_length = data.size()*bar_width + (data.size()+1)*bar_spacing;
	Axis xa(Axis::x, graph_origin, xa_length, 0);
	win.attach(xa);

	// draw y-axis
	double ya_max = 150.0;
	int ya_length = int(ya_max*graph_scale);
	Axis ya(Axis::y, graph_origin, ya_length, 2);
	win.attach(ya);

	// labels
	Point ya_max_lbl_pos(graph_origin);
	ya_max_lbl_pos.x -= 40;
	ya_max_lbl_pos.y -= ya_length - 5;
	Text ya_max_lbl(ya_max_lbl_pos, to_string(int(ya_max)));
	win.attach(ya_max_lbl);

	win.wait_for_button(); // display!
}
