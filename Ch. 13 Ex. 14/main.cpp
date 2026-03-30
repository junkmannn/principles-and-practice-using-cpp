#include "Simple_window.h"
#include "Graph.h"
#include "right_triangle.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 14");

	const int ab = 150;
	double mini_hyp_tmp = sqrt(pow((double)ab, 2) + pow((double)ab, 2)) - ab; // just not to lose precision
	int mini_ab = (int)(sqrt(2)*mini_hyp_tmp / 2);
	int mini_hyp = (int)mini_hyp_tmp;

	Point pt = Point(300,250);
	Right_triangle t1(pt, ab, ab, 0.0);
	t1.set_fill_color(Color::red);
	t1.set_color(Color::invisible);

	pt.x += mini_ab;
	pt.y -= mini_ab;
	Right_triangle t2(pt, ab, ab, 45.0);
	t2.set_fill_color(Color::yellow);
	t2.set_color(Color::invisible);

	pt.y -= mini_hyp;
	Right_triangle t3(pt, ab, ab, 90.0);
	t3.set_fill_color(Color::blue);
	t3.set_color(Color::invisible);

	pt.x -= mini_ab;
	pt.y -= mini_ab;
	Right_triangle t4(pt, ab, ab, 135.0);
	t4.set_fill_color(Color::black);
	t4.set_color(Color::invisible);

	pt.x -= mini_hyp;
	Right_triangle t5(pt, ab, ab, 180.0);
	t5.set_fill_color(Color::cyan);
	t5.set_color(Color::invisible);

	pt.x -= mini_ab;
	pt.y += mini_ab;
	Right_triangle t6(pt, ab, ab, 225.0);
	t6.set_fill_color(Color::green);
	t6.set_color(Color::invisible);

	pt.y += mini_hyp;
	Right_triangle t7(pt, ab, ab, 270.0);
	t7.set_fill_color(Color::white);
	t7.set_color(Color::invisible);

	pt.x += mini_ab;
	pt.y += mini_ab;
	Right_triangle t8(pt, ab, ab, 315.0);
	t8.set_fill_color(Color::magenta);
	t8.set_color(Color::invisible);

	win.attach(t1);
	win.attach(t2);
	win.attach(t3);
	win.attach(t4);
	win.attach(t5);
	win.attach(t6);
	win.attach(t7);
	win.attach(t8);

	win.wait_for_button(); // display!
}
