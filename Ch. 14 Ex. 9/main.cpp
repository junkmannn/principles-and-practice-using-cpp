#include "Simple_window.h"
#include "Graph.h"
#include "group.h"
#include <iostream>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 14 Ex. 9");

	Group g;
	Circle c(Point(10,10), 100);
	Graph_lib::Rectangle r(Point(110,110), 50, 75);

	g.add(c);
	g.add(r);
	win.attach(g);
	win.wait_for_button();

	win.detach(g);
	win.wait_for_button();

	win.attach(g);
	win.wait_for_button();

	g.set_color(Color::cyan);
	win.wait_for_button();

	g.set_fill_color(Color::black);
	win.wait_for_button();

	g.set_style(Line_style(Line_style::solid, 5));
	win.wait_for_button();

	g.move(100, 100);
	win.wait_for_button();

	c.set_fill_color(Color::red);
	r.set_fill_color(Color::black);
	win.wait_for_button();

	g.move(100, 100);
	Circle& c2 = (Circle&)g.get(0); // should refer to c
	c2.set_color(Color::magenta);
	Graph_lib::Rectangle& r2 = (Graph_lib::Rectangle&)g.get(1); // should refer to r
	r2.set_color(Color::white);
	win.wait_for_button();

	cout << g.remove(c2) << '\n'; // should be true (1)
	cout << g.number_of_shapes() << '\n'; // should be 1
	win.wait_for_button();

	cout << g.remove(c2) << '\n'; // should be false (0)
	cout << g.number_of_shapes() << '\n'; // should still be 1
	win.wait_for_button();

	g.move(0, -100); // only the rectangle should move
	win.wait_for_button();

	g.remove_all();
	cout << g.number_of_shapes() << '\n'; // should be 0

	win.wait_for_button();
}
