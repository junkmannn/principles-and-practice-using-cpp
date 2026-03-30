#include "Simple_window.h"
#include "Graph.h"
#include "binary_tree_polygon_arrow.h"

using namespace std;
using namespace Graph_lib;

typedef Binary_tree_polygon_arrow Btpa;

int main() {
	Simple_window win(Point(1280, 70), 1280, 1370, "Ch. 14 Ex. 13");

	Btpa bt(Point(640, 50)/*root*/, 20/*radius*/, 5/*sides*/, 50/*dx*/, 25/*dy*/, 1/*levels*/, Btpa::UP/*direction*/);

	win.attach(bt);

	win.wait_for_button(); // display!

	bt.move(30, 30);
	win.wait_for_button();

	bt.set_dx(70);
	win.wait_for_button();

	bt.set_dy(50);
	win.wait_for_button();

	bt.set_levels(4);
	win.wait_for_button();

	bt.set_node_radius(30);
	win.wait_for_button();

	bt.set_color(Color::cyan);
	bt.set_fill_color(Color::white);
	bt.set_style(Line_style::solid);
	win.wait_for_button();
}
