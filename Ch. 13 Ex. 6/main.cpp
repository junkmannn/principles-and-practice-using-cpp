#include "Simple_window.h"
#include "Graph.h"
#include "textbox.h"
#include "arrow.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 6");

	Textbox window(Point(75,25), "Window");
	Textbox linestyle(Point(175,25), "Line_style");
	Textbox color(Point(300,25), "Color");
	Textbox simplewindow(Point(50,90), "Simple_window");
	Textbox shape(Point(200,75), "Shape");
	Textbox point(Point(325,85), "Point");
	Textbox line(Point(30,175), "Line");
	Textbox lines(Point(80,175), "Lines");
	Textbox polygon(Point(140,175), "Polygon");
	Textbox axis(Point(220,175), "Axis");
	Textbox rectangle(Point(275,175), "Rectangle");
	Textbox text(Point(365,175), "Text");
	Textbox image(Point(420,175), "Image");

	Arrow simplewindow_to_window(Point(105, 90), Point(105, 47));
	Arrow line_to_shape(Point(45, 175), Point(205, 98));
	Arrow lines_to_shape(Point(100, 175), Point(212, 98));
	Arrow polygon_to_shape(Point(170, 175), Point(219, 98));
	Arrow axis_to_shape(Point(240, 175), Point(226, 98));
	Arrow rectangle_to_shape(Point(315, 175), Point(233, 98));
	Arrow text_to_shape(Point(385, 175), Point(240, 98));
	Arrow image_to_shape(Point(440, 175), Point(247, 98));

	win.attach(window);
	win.attach(linestyle);
	win.attach(color);
	win.attach(simplewindow);
	win.attach(shape);
	win.attach(point);
	win.attach(line);
	win.attach(lines);
	win.attach(polygon);
	win.attach(axis);
	win.attach(rectangle);
	win.attach(text);
	win.attach(image);

	win.attach(simplewindow_to_window);
	win.attach(line_to_shape);
	win.attach(lines_to_shape);
	win.attach(polygon_to_shape);
	win.attach(axis_to_shape);
	win.attach(rectangle_to_shape);
	win.attach(text_to_shape);
	win.attach(image_to_shape);

	win.wait_for_button(); // display!
}
