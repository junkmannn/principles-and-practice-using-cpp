#include "Simple_window.h"
#include "smiley.h"
#include "frowny.h"
#include "smiley_hat.h"
#include "frowny_hat.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 1000, 1000, "Ch. 14 Ex. 1");

	Smiley smiley(Point(200,200), 100);
	smiley.set_color(Color::blue);
	smiley.set_fill_color(Color::white);
	smiley.set_style(Line_style::dot);
	win.attach(smiley);

	Frowny frowny(Point(600,200), 100);
	frowny.set_color(Color::red);
	frowny.set_fill_color(Color::black);
	win.attach(frowny);

	Smiley_hat smiley_hat(Point(200,600), 100);
	smiley_hat.set_color(Color::blue);
	smiley_hat.set_fill_color(Color::white);
	win.attach(smiley_hat);

	Frowny_hat frowny_hat(Point(600,600), 150);
	frowny_hat.set_color(Color::red);
	frowny_hat.set_fill_color(Color::black);
	win.attach(frowny_hat);

	win.wait_for_button(); // display!

	smiley.set_center(Point(201,201));
	win.attach(smiley);

	win.wait_for_button();
}
