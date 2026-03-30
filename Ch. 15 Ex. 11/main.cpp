#include "Simple_window.h"
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100,100), 600, 400, "Ch. 15 Ex. 11");

	// code here

	win.wait_for_button(); // display!
}
