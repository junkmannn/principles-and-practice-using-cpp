#include "Simple_window.h"
#include "Graph.h"
#include "star.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 900, 680, "Ch. 13 Ex. 19");

	Star star1(Point(120,120), 5, 2, 100);
	win.attach(star1);

	Star star2(Point(340,120), 6, 2, 100);
	win.attach(star2);

	Star star3(Point(560,120), 7, 2, 100);
	win.attach(star3);

	Star star4(Point(780,120), 7, 3, 100);
	win.attach(star4);

	Star star5(Point(120,340), 8, 2, 100);
	win.attach(star5);

	Star star6(Point(340,340), 8, 3, 100);
	win.attach(star6);

	Star star7(Point(560,340), 9, 2, 100);
	win.attach(star7);

	Star star8(Point(780,340), 9, 3, 100);
	win.attach(star8);

	Star star9(Point(120,560), 9, 4, 100);
	win.attach(star9);

	Star star10(Point(340,560), 10, 3, 100);
	win.attach(star10);

	Star star11(Point(560,560), 12, 5, 100);
	win.attach(star11);

	win.wait_for_button(); // display!
}
