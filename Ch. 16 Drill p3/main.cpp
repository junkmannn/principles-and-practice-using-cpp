#include "lines_window.h"
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Lines_window win(Point(100,100), 600, 400, "Ch. 16 Drill p3");
	return gui_main();
}
