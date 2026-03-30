#include "lines_window.h"
#include <sstream>

using namespace Graph_lib;
using namespace std;

Lines_window::Lines_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next),
	quit_button(Point(x_max()-70,0), 60, 20, "Quit", cb_quit),
	next_x(Point(x_max()-310,0), 50, 20, "next x:"),
	next_y(Point(x_max()-210,0), 50, 20, "next y:"),
	xy_out(Point(100,0), 100, 20, "current (x,y):"),
	color_menu(Point(x_max()-80,30), 70, 20, Menu::vertical, "color"),
	color_menu_button(Point(x_max()-90,30), 80, 20, "color menu", cb_color_menu),
	linestyle_menu(Point(x_max()-105,100), 95, 20, Menu::vertical, "linestyle"),
	linestyle_menu_button(Point(x_max()-105,100), 95, 20, "linestyle menu", cb_linestyle_menu) {

	attach(next_button);
	attach(quit_button);
	attach(color_menu_button);
	attach(linestyle_menu_button);
	attach(next_x);
	attach(next_y);
	attach(lines);

	attach(xy_out);
	xy_out.put("no point");

	color_menu.attach(new Button(Point(0,0), 0, 0, "red", cb_color_red));
	color_menu.attach(new Button(Point(0,0), 0, 0, "blue", cb_color_blue));
	color_menu.attach(new Button(Point(0,0), 0, 0, "black", cb_color_black));
	attach(color_menu);
	color_menu.hide();

	linestyle_menu.attach(new Button(Point(0,0), 0, 0, "dash", cb_linestyle_dash));
	linestyle_menu.attach(new Button(Point(0,0), 0, 0, "dashdot", cb_linestyle_dashdot));
	linestyle_menu.attach(new Button(Point(0,0), 0, 0, "dashdotdot", cb_linestyle_dashdotdot));
	linestyle_menu.attach(new Button(Point(0,0), 0, 0, "dot", cb_linestyle_dot));
	linestyle_menu.attach(new Button(Point(0,0), 0, 0, "solid", cb_linestyle_solid));
	attach(linestyle_menu);
	linestyle_menu.hide();
}

void Lines_window::change_color(Color c) {
	lines.set_color(c);
}

void Lines_window::change_linestyle(Line_style ls) {
	lines.set_style(ls);
}

void Lines_window::hide_color_menu() {
	color_menu.hide();
	color_menu_button.show();
}

void Lines_window::hide_linestyle_menu() {
	linestyle_menu.hide();
	linestyle_menu_button.show();
}

void Lines_window::color_red_pressed() {
	change_color(Color::red);
	hide_color_menu();
}

void Lines_window::color_blue_pressed() {
	change_color(Color::blue);
	hide_color_menu();
}

void Lines_window::color_black_pressed() {
	change_color(Color::black);
	hide_color_menu();
}

void Lines_window::color_menu_pressed() {
	color_menu_button.hide();
	color_menu.show();
}

void Lines_window::linestyle_dash_pressed() {
	change_linestyle(Line_style::dash);
	hide_linestyle_menu();
}

void Lines_window::linestyle_dashdot_pressed() {
	change_linestyle(Line_style::dashdot);
	hide_linestyle_menu();
}

void Lines_window::linestyle_dashdotdot_pressed() {
	change_linestyle(Line_style::dashdotdot);
	hide_linestyle_menu();
}

void Lines_window::linestyle_dot_pressed() {
	change_linestyle(Line_style::dot);
	hide_linestyle_menu();
}

void Lines_window::linestyle_solid_pressed() {
	change_linestyle(Line_style::solid);
	hide_linestyle_menu();
}

void Lines_window::linestyle_menu_pressed() {
	linestyle_menu_button.hide();
	linestyle_menu.show();
}

void Lines_window::quit() {
	hide(); // curious FLTK idiom to delete window
}

void Lines_window::next() {
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point(x,y));

	// update current position readout:
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

void Lines_window::cb_color_red(Address, Address pw) {
	reference_to<Lines_window>(pw).color_red_pressed();
}

void Lines_window::cb_color_blue(Address, Address pw) {
	reference_to<Lines_window>(pw).color_blue_pressed();
}

void Lines_window::cb_color_black(Address, Address pw) {
	reference_to<Lines_window>(pw).color_black_pressed();
}

void Lines_window::cb_color_menu(Address, Address pw) {
	reference_to<Lines_window>(pw).color_menu_pressed();
}

void Lines_window::cb_linestyle_dash(Address, Address pw) {
	reference_to<Lines_window>(pw).linestyle_dash_pressed();
}

void Lines_window::cb_linestyle_dashdot(Address, Address pw) {
	reference_to<Lines_window>(pw).linestyle_dashdot_pressed();
}

void Lines_window::cb_linestyle_dashdotdot(Address, Address pw) {
	reference_to<Lines_window>(pw).linestyle_dashdotdot_pressed();
}

void Lines_window::cb_linestyle_dot(Address, Address pw) {
	reference_to<Lines_window>(pw).linestyle_dot_pressed();
}

void Lines_window::cb_linestyle_solid(Address, Address pw) {
	reference_to<Lines_window>(pw).linestyle_solid_pressed();
}

void Lines_window::cb_linestyle_menu(Address, Address pw) {
	reference_to<Lines_window>(pw).linestyle_menu_pressed();
}

void Lines_window::cb_quit(Address, Address pw) { // "the usual"
	reference_to<Lines_window>(pw).quit();
}

void Lines_window::cb_next(Address, Address pw) { // "the usual"
	reference_to<Lines_window>(pw).next();
}
