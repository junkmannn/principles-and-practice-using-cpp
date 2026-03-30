#include "Simple_window.h"
#include "Graph.h"
#include "textbox.h"
#include "group.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100,100), 1000, 500, "Ch. 14 Ex. 17");

	Group g;

	Textbox exception(Point(430, 200), "exception");

	Textbox runtime_error(Point(200,300), "runtime_error");
	Textbox logic_error(Point(660,300), "logic_error");

	Textbox range_error(Point(100,400), "range_error");
	Textbox overflow_error(Point(200,400), "overflow_error");
	Textbox underflow_error(Point(315,400), "underflow_error");
	Textbox domain_error(Point(475,400), "domain_error");
	Textbox invalid_argument(Point(585,400), "invalid_argument");
	Textbox length_error(Point(720,400), "length_error");
	Textbox out_of_range(Point(825,400), "out_of_range");

	Line line1(Point(240,300), Point(465,223)); // runtime_error to exception
	Line line2(Point(700,300), Point(465,223)); // logic_error to exception

	Line line3(Point(140,400), Point(240,323)); // range_error to runtime_error
	Line line4(Point(250,400), Point(240,323)); // overflow_error to runtime_error
	Line line5(Point(375,400), Point(240,323)); // underflow_error to runtime_error

	Line line6(Point(525,400), Point(700,323)); // domain_error to logic_error
	Line line7(Point(650,400), Point(700,323)); // invalid_argument to logic_error
	Line line8(Point(770,400), Point(700,323)); // length_error to logic_error
	Line line9(Point(880,400), Point(700,323)); // out_of_range to logic_error

	g.add(exception);
	g.add(logic_error);
	g.add(runtime_error);
	g.add(range_error);
	g.add(overflow_error);
	g.add(underflow_error);
	g.add(domain_error);
	g.add(invalid_argument);
	g.add(length_error);
	g.add(out_of_range);

	g.add(line1);
	g.add(line2);
	g.add(line3);
	g.add(line4);
	g.add(line5);
	g.add(line6);
	g.add(line7);
	g.add(line8);
	g.add(line9);

	win.attach(g);

	win.wait_for_button(); // display!

	g.set_color(Color::green);

	win.wait_for_button();

	g.set_fill_color(Color::black);

	win.wait_for_button();

	g.move(0, -100);

	win.wait_for_button();
}
