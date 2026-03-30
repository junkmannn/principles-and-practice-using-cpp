#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Ellipse Fl_Ellipse;

Point n(const Circle& c);
Point s(const Circle& c);
Point e(const Circle& c);
Point w(const Circle& c);
Point center(const Circle& c);
Point ne(const Circle& c);
Point se(const Circle& c);
Point sw(const Circle& c);
Point nw(const Circle& c);

Point n(const Fl_Ellipse& e);
Point s(const Fl_Ellipse& e);
Point e(const Fl_Ellipse& e);
Point w(const Fl_Ellipse& e);
Point center(const Fl_Ellipse& e);
Point ne(const Fl_Ellipse& e);
Point se(const Fl_Ellipse& e);
Point sw(const Fl_Ellipse& e);
Point nw(const Fl_Ellipse& e);

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 5");

	Point p;

	Circle circle(Point(75,100), 50);
	cout << "Circle\n";
	p = n(circle);
	cout << "N = (" << p.x << ',' << p.y << ")\n";
	p = s(circle);
	cout << "S = (" << p.x << ',' << p.y << ")\n";
	p = e(circle);
	cout << "E = (" << p.x << ',' << p.y << ")\n";
	p = w(circle);
	cout << "W = (" << p.x << ',' << p.y << ")\n";
	p = center(circle);
	cout << "Center = (" << p.x << ',' << p.y << ")\n";
	p = ne(circle);
	cout << "NE = (" << p.x << ',' << p.y << ")\n";
	p = se(circle);
	cout << "SE = (" << p.x << ',' << p.y << ")\n";
	p = sw(circle);
	cout << "SW = (" << p.x << ',' << p.y << ")\n";
	p = nw(circle);
	cout << "NW = (" << p.x << ',' << p.y << ")\n";
	cout << '\n';
	win.attach(circle);

	Fl_Ellipse ellipse(Point(300,200), 100, 50);
	cout << "Ellipse\n";
	p = n(ellipse);
	cout << "N = (" << p.x << ',' << p.y << ")\n";
	p = s(ellipse);
	cout << "S = (" << p.x << ',' << p.y << ")\n";
	p = e(ellipse);
	cout << "E = (" << p.x << ',' << p.y << ")\n";
	p = w(ellipse);
	cout << "W = (" << p.x << ',' << p.y << ")\n";
	p = center(ellipse);
	cout << "Center = (" << p.x << ',' << p.y << ")\n";
	p = ne(ellipse);
	cout << "NE = (" << p.x << ',' << p.y << ")\n";
	p = se(ellipse);
	cout << "SE = (" << p.x << ',' << p.y << ")\n";
	p = sw(ellipse);
	cout << "SW = (" << p.x << ',' << p.y << ")\n";
	p = nw(ellipse);
	cout << "NW = (" << p.x << ',' << p.y << ")\n";
	cout << '\n';
	win.attach(ellipse);

	win.wait_for_button(); // display!
}

Point n(const Circle& c) {
	return Point(c.point(0).x + c.radius(), c.point(0).y);
}

Point s(const Circle& c) {
	return Point(c.point(0).x + c.radius(), c.point(0).y + 2*c.radius());
}

Point e(const Circle& c) {
	return Point(c.point(0).x + 2*c.radius(), c.point(0).y + c.radius());
}

Point w(const Circle& c) {
	return Point(c.point(0).x, c.point(0).y + c.radius());
}

Point center(const Circle& c) {
	return Point(c.point(0).x + c.radius(), c.point(0).y + c.radius());
}

Point ne(const Circle& c) {
	return Point(c.point(0).x + 2*c.radius(), c.point(0).y);
}

Point se(const Circle& c) {
	return Point(c.point(0).x + 2*c.radius(), c.point(0).y + 2*c.radius());
}

Point sw(const Circle& c) {
	return Point(c.point(0).x, c.point(0).y + 2*c.radius());
}

Point nw(const Circle& c) {
	return Point(c.point(0).x, c.point(0).y);
}

Point n(const Fl_Ellipse& e) {
	return Point(e.point(0).x + e.major(), e.point(0).y);
}

Point s(const Fl_Ellipse& e) {
	return Point(e.point(0).x + e.major(), e.point(0).y + 2*e.minor());
}

Point e(const Fl_Ellipse& e) {
	return Point(e.point(0).x + 2*e.major(), e.point(0).y + e.minor());
}

Point w(const Fl_Ellipse& e) {
	return Point(e.point(0).x, e.point(0).y + e.minor());
}

Point center(const Fl_Ellipse& e) {
	return Point(e.point(0).x + e.major(), e.point(0).y + e.minor());
}

Point ne(const Fl_Ellipse& e) {
	return Point(e.point(0).x + 2*e.major(), e.point(0).y);
}

Point se(const Fl_Ellipse& e) {
	return Point(e.point(0).x + 2*e.major(), e.point(0).y + 2*e.minor());
}

Point sw(const Fl_Ellipse& e) {
	return Point(e.point(0).x, e.point(0).y + 2*e.minor());
}

Point nw(const Fl_Ellipse& e) {
	return Point(e.point(0).x, e.point(0).y);
}
