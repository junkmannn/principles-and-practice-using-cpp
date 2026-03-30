#ifndef LINES_WINDOW_H
#define LINES_WINDOW_H

#include "Window.h"
#include "GUI.h"
#include "Graph.h"
#include <string>

namespace Graph_lib {

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const std::string& title);
private:
	// data:
	Open_polyline lines;

	// widgets:
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;

	void change(Color c) { lines.set_color(c); }

	void hide_menu() { color_menu.hide(); menu_button.show(); }

	// actions invoked by callbacks:
	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void next();
	void quit();

	// callback functions:
	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
};

}

#endif
