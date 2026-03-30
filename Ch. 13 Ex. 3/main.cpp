#include "Simple_window.h"
#include "Graph.h"
#include "arrow.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 3");

	Arrow arrow1(Point(100,100), Point(200,100)); // 0 degrees
	Arrow arrow2(Point(100,100), Point(100,0)); // 90 degrees
	Arrow arrow3(Point(100,100), Point(0,100)); // 180 degrees
	Arrow arrow4(Point(100,100), Point(100,200)); // 270 degrees


	Arrow arrow5(Point(100,100), Point(200,75));
	Arrow arrow6(Point(100,100), Point(0,75));
	Arrow arrow7(Point(100,100), Point(0,125));
	Arrow arrow8(Point(100,100), Point(200,125));

	win.attach(arrow1);
	win.attach(arrow5);

	win.wait_for_button(); // display!

	arrow5.move(40, 30);
	win.wait_for_button();

	arrow5.set_color(Color::red);
	win.wait_for_button();

	arrow5.set_p2(Point(0,0));
	win.wait_for_button();

}
