#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Rectangle Fl_Rectangle;

Point n(const Fl_Rectangle& r);
Point s(const Fl_Rectangle& r);
Point e(const Fl_Rectangle& r);
Point w(const Fl_Rectangle& r);
Point center(const Fl_Rectangle& r);
Point ne(const Fl_Rectangle& r);
Point se(const Fl_Rectangle& r);
Point sw(const Fl_Rectangle& r);
Point nw(const Fl_Rectangle& r);

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 4");

	Fl_Rectangle rect(Point(25,100), 100, 50);

	// cout << '(' << rect.point(0).x << ',' << rect.point(0).y << ")\n";
	// cout << rect.width() << 'x' << rect.height() << '\n';

	Point p = n(rect);
	cout << "N = (" << p.x << ',' << p.y << ")\n";
	p = s(rect);
	cout << "S = (" << p.x << ',' << p.y << ")\n";
	p = e(rect);
	cout << "E = (" << p.x << ',' << p.y << ")\n";
	p = w(rect);
	cout << "W = (" << p.x << ',' << p.y << ")\n";
	p = center(rect);
	cout << "Center = (" << p.x << ',' << p.y << ")\n";
	p = ne(rect);
	cout << "NE = (" << p.x << ',' << p.y << ")\n";
	p = se(rect);
	cout << "SE = (" << p.x << ',' << p.y << ")\n";
	p = sw(rect);
	cout << "SW = (" << p.x << ',' << p.y << ")\n";
	p = nw(rect);
	cout << "NW = (" << p.x << ',' << p.y << ")\n";

	win.attach(rect);

	win.wait_for_button(); // display!
}

Point n(const Fl_Rectangle& r) {
	return Point(r.point(0).x + r.width()/2, r.point(0).y);
}

Point s(const Fl_Rectangle& r) {
	return Point(r.point(0).x + r.width()/2, r.point(0).y + r.height());
}

Point e(const Fl_Rectangle& r) {
	return Point(r.point(0).x + r.width(), r.point(0).y + r.height()/2);
}

Point w(const Fl_Rectangle& r) {
	return Point(r.point(0).x, r.point(0).y + r.height()/2);
}

Point center(const Fl_Rectangle& r) {
	return Point(r.point(0).x + r.width()/2, r.point(0).y + r.height()/2);
}

Point ne(const Fl_Rectangle& r) {
	return Point(r.point(0).x + r.width(), r.point(0).y);
}

Point se(const Fl_Rectangle& r) {
	return Point(r.point(0).x + r.width(), r.point(0).y + r.height());
}

Point sw(const Fl_Rectangle& r) {
	return Point(r.point(0).x, r.point(0).y + r.height());
}

Point nw(const Fl_Rectangle& r) {
	return Point(r.point(0).x, r.point(0).y);
}
