#define _USE_MATH_DEFINES

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
#include <string>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Ellipse Fl_Ellipse;

int main() {
	const int win_width = 700;
	const int win_height = 700;
	Simple_window win(Point(100, 100), win_width, win_height, "Ch. 13 Ex. 11");

	Axis xa(Axis::x, Point(0,win_height/2), win_width, 10);
	Axis ya(Axis::y, Point(win_width/2,win_height), win_height, 10);

	int a = 300;
	int b = 200;
	Fl_Ellipse ellipse(Point(win_width/2, win_height/2), a, b);
	double x = a*cos(M_PI_4);
	double y = b*sin(M_PI_4);

	Mark focus1(Point(ellipse.focus1().x, ellipse.focus1().y), 'x');
	Mark focus2(Point(ellipse.focus2().x, ellipse.focus2().y), 'x');
	Mark pt(Point(win_width/2+x, win_height/2-y), 'o');

	Line f1_to_pt(Point(ellipse.focus1().x, ellipse.focus1().y), Point(win_width/2+x, win_height/2-y));
	Line f2_to_pt(Point(ellipse.focus2().x, ellipse.focus2().y), Point(win_width/2+x, win_height/2-y));

	win.attach(ellipse);
	win.attach(xa);
	win.attach(ya);
	win.attach(focus1);
	win.attach(focus2);
	win.attach(pt);
	win.attach(f1_to_pt);
	win.attach(f2_to_pt);

	// tests
	Circle ca(Point(win_width/2, win_height/2), a);
	ca.set_color(Color::red);
	win.attach(ca);
	Circle cb(Point(win_width/2, win_height/2), b);
	cb.set_color(Color::blue);
	win.attach(cb);
	double ca_x = a*cos(M_PI_4);
	double ca_y = a*sin(M_PI_4);
	Mark ma(Point(win_width/2+ca_x, win_height/2-ca_y), 'x');
	ma.set_color(Color::red);
	win.attach(ma);
	double cb_x = b*cos(M_PI_4);
	double cb_y = b*sin(M_PI_4);
	Mark mb(Point(win_width/2+cb_x, win_height/2-cb_y), 'x');
	mb.set_color(Color::blue);
	win.attach(mb);

	win.wait_for_button(); // display!
}
