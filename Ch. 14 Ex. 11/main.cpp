#include "Simple_window.h"
#include "Graph.h"
#include "binary_tree.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(1280, 70), 1280, 1370, "Ch. 14 Ex. 11");

	Binary_tree bt(Point(640, 50)/*root*/, 20/*radius*/, 50/*dx*/, 25/*dy*/, 1/*levels*/);

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
