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
	Button color_menu_button;
	Menu linestyle_menu;
	Button linestyle_menu_button;

	void change_color(Color c);
	void change_linestyle(Line_style ls);

	void hide_color_menu();
	void hide_linestyle_menu();


	// actions invoked by callbacks:
	// -----------------------------------------------
	void color_red_pressed();
	void color_blue_pressed();
	void color_black_pressed();
	void color_menu_pressed();

	void linestyle_dash_pressed();
	void linestyle_dashdot_pressed();
	void linestyle_dashdotdot_pressed();
	void linestyle_dot_pressed();
	void linestyle_solid_pressed();
	void linestyle_menu_pressed();

	void next();
	void quit();
	// -----------------------------------------------


	// callback functions:
	// -----------------------------------------------
	static void cb_color_red(Address, Address);
	static void cb_color_blue(Address, Address);
	static void cb_color_black(Address, Address);
	static void cb_color_menu(Address, Address);

	static void cb_linestyle_dash(Address, Address);
	static void cb_linestyle_dashdot(Address, Address);
	static void cb_linestyle_dashdotdot(Address, Address);
	static void cb_linestyle_dot(Address, Address);
	static void cb_linestyle_solid(Address, Address);
	static void cb_linestyle_menu(Address, Address);

	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
	// -----------------------------------------------
};

}

#endif
