#ifndef LINES_WINDOW_H
#define LINES_WINDOW_H

#include "Window.h"
#include "GUI.h"
#include "Graph.h"
#include <string>

namespace Graph_lib {

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const std::string& title);
	Open_polyline lines;
private:
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	static void cb_next(Address, Address);
	void next();
	static void cb_quit(Address, Address);
	void quit();
};

}

#endif
