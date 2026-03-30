#include "Simple_window.h"
#include "Graph.h"
#include "star.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 900, 680, "Ch. 13 Ex. 19");

	Star star1(Point(120,120), 5, 2, 100);
	star1.set_color(Color::white);
	star1.set_fill_color(Color::black);
	win.attach(star1);

	Star star2(Point(340,120), 6, 2, 100);
	star2.set_color(Color::white);
	star2.set_fill_color(Color::black);
	win.attach(star2);

	Star star3(Point(560,120), 7, 2, 100);
	star3.set_color(Color::white);
	star3.set_fill_color(Color::black);
	win.attach(star3);

	Star star4(Point(780,120), 7, 3, 100);
	star4.set_color(Color::white);
	star4.set_fill_color(Color::black);
	win.attach(star4);

	Star star5(Point(120,340), 8, 2, 100);
	star5.set_color(Color::white);
	star5.set_fill_color(Color::black);
	win.attach(star5);

	Star star6(Point(340,340), 8, 3, 100);
	star6.set_color(Color::white);
	star6.set_fill_color(Color::black);
	win.attach(star6);

	Star star7(Point(560,340), 9, 2, 100);
	star7.set_color(Color::white);
	star7.set_fill_color(Color::black);
	win.attach(star7);

	Star star8(Point(780,340), 9, 3, 100);
	star8.set_color(Color::white);
	star8.set_fill_color(Color::black);
	win.attach(star8);

	Star star9(Point(120,560), 9, 4, 100);
	star9.set_color(Color::white);
	star9.set_fill_color(Color::black);
	win.attach(star9);

	Star star10(Point(340,560), 10, 3, 100);
	star10.set_color(Color::white);
	star10.set_fill_color(Color::black);
	win.attach(star10);

	Star star11(Point(560,560), 12, 5, 100);
	star11.set_color(Color::white);
	star11.set_fill_color(Color::black);
	win.attach(star11);

	win.wait_for_button(); // display!
}
