#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "EK");

	Text txt(Point(185, 90), "EK");
	txt.set_font_size(24);
	Image img(Point(100, 100), "ek.jpg");

	win.attach(txt);
	win.attach(img);

	win.wait_for_button(); // display!
}
