#include "Simple_window.h"
#include "Graph.h"
#include "regular_polygon.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 675, 675, "Ch. 13 Ex. 10");

	Regular_polygon rp3s(Point(110,110), 100, 3);
	rp3s.set_color(Color::red);
	rp3s.set_fill_color(Color::black);
	win.attach(rp3s);
	Circle c3s(Point(110,110), 100);
	win.attach(c3s);
	Lines l3s;
	l3s.add(Point(10,110), Point(210,110));
	l3s.add(Point(110,10), Point(110,210));
	win.attach(l3s);
	Text t3s(Point(120, 100), "3");
	win.attach(t3s);

	Regular_polygon rp4s(Point(320,110), 100, 4);
	rp4s.set_color(Color::red);
	win.attach(rp4s);
	Circle c4s(Point(320,110), 100);
	win.attach(c4s);
	Lines l4s;
	l4s.add(Point(220,110), Point(420,110));
	l4s.add(Point(320,10), Point(320,210));
	win.attach(l4s);
	Text t4s(Point(330, 100), "4");
	win.attach(t4s);

	Regular_polygon rp5s(Point(530,110), 100, 5);
	rp5s.set_color(Color::red);
	win.attach(rp5s);
	Circle c5s(Point(530,110), 100);
	win.attach(c5s);
	Lines l5s;
	l5s.add(Point(430,110), Point(630,110));
	l5s.add(Point(530,10), Point(530,210));
	win.attach(l5s);
	Text t5s(Point(540, 100), "5");
	win.attach(t5s);

	Regular_polygon rp6s(Point(110,320), 100, 6);
	rp6s.set_color(Color::red);
	win.attach(rp6s);
	Circle c6s(Point(110,320), 100);
	win.attach(c6s);
	Lines l6s;
	l6s.add(Point(10,320), Point(210,320));
	l6s.add(Point(110,220), Point(110,420));
	win.attach(l6s);
	Text t6s(Point(120, 310), "6");
	win.attach(t6s);

	Regular_polygon rp7s(Point(320,320), 100, 7);
	rp7s.set_color(Color::red);
	win.attach(rp7s);
	Circle c7s(Point(320,320), 100);
	win.attach(c7s);
	Lines l7s;
	l7s.add(Point(220,320), Point(420,320));
	l7s.add(Point(320,220), Point(320,420));
	win.attach(l7s);
	Text t7s(Point(330, 310), "7");
	win.attach(t7s);

	Regular_polygon rp8s(Point(530,320), 100, 8);
	rp8s.set_color(Color::red);
	win.attach(rp8s);
	Circle c8s(Point(530,320), 100);
	win.attach(c8s);
	Lines l8s;
	l8s.add(Point(430,320), Point(630,320));
	l8s.add(Point(530,220), Point(530,420));
	win.attach(l8s);
	Text t8s(Point(540, 310), "8");
	win.attach(t8s);

	Regular_polygon rp9s(Point(110,530), 100, 9);
	rp9s.set_color(Color::red);
	win.attach(rp9s);
	Circle c9s(Point(110,530), 100);
	win.attach(c9s);
	Lines l9s;
	l9s.add(Point(10,530), Point(210,530));
	l9s.add(Point(110,430), Point(110,630));
	win.attach(l9s);
	Text t9s(Point(120, 520), "9");
	win.attach(t9s);

	Regular_polygon rp10s(Point(320,530), 100, 10);
	rp10s.set_color(Color::red);
	win.attach(rp10s);
	Circle c10s(Point(320,530), 100);
	win.attach(c10s);
	Lines l10s;
	l10s.add(Point(220,530), Point(420,530));
	l10s.add(Point(320,430), Point(320,630));
	win.attach(l10s);
	Text t10s(Point(330, 520), "10");
	win.attach(t10s);

	Regular_polygon rp11s(Point(530,530), 100, 11);
	rp11s.set_color(Color::red);
	win.attach(rp11s);
	Circle c11s(Point(530,530), 100);
	win.attach(c11s);
	Lines l11s;
	l11s.add(Point(430,530), Point(630,530));
	l11s.add(Point(530,430), Point(530,630));
	win.attach(l11s);
	Text t11s(Point(540, 520), "11");
	win.attach(t11s);

	win.wait_for_button(); // display!

	/*
	Simple_window win(Point(100, 100), 1300, 1300, "Ch. 13 Ex. 10");

	Regular_polygon rp(Point(650,650), 600, 100);
	win.attach(rp);

	win.wait_for_button();
	*/
}
