#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Rectangle Fl_Rectangle;

int main() {
	Simple_window win(Point(100, 100), 700, 650, "Ch. 12 Ex. 10");

	const int fltk_headers_x = 350;
	const int fltk_headers_y = 40;

	const int fltk_code_x = 550;
	const int fltk_code_y = 90;

	const int point_h_x = 60;
	const int point_h_y = 100;

	const int graph_h_x = 60;
	const int graph_h_y = 225;

	const int window_h_x = 330;
	const int window_h_y = 175;

	const int gui_h_x = 475;
	const int gui_h_y = 275;

	const int simple_window_h_x = 275;
	const int simple_window_h_y = 400;

	const int ch12_cpp_x = 150;
	const int ch12_cpp_y = 525;

	const int graph_cpp_x = 35;
	const int graph_cpp_y = 390;

	const int window_cpp_x = 200;
	const int window_cpp_y = 330;

	const int gui_cpp_x = 500;
	const int gui_cpp_y = 380;

	// links
	// -------------------------------------------------------------------------------------
	Line fltk_code_to_headers(Point(fltk_code_x, fltk_code_y+23), Point(fltk_headers_x+125, fltk_headers_y+30));
	win.attach(fltk_code_to_headers);

	Line graph_h_to_fltk_headers(Point(graph_h_x+70, graph_h_y+5), Point(fltk_headers_x+25, fltk_headers_y+55));
	win.attach(graph_h_to_fltk_headers);
	Line graph_to_point_h(Point(graph_h_x+70, graph_h_y+5), Point(point_h_x+65, point_h_y+30));
	win.attach(graph_to_point_h);

	Line window_h_to_fltk_headers(Point(window_h_x+72, window_h_y+5), Point(fltk_headers_x+68, fltk_headers_y+55));
	win.attach(window_h_to_fltk_headers);
	Line window_to_point_h(Point(window_h_x+10, window_h_y+5), Point(point_h_x+90, point_h_y+30));
	win.attach(window_to_point_h);

	Line gui_h_to_fltk_headers(Point(gui_h_x+90, gui_h_y+5), Point(fltk_headers_x+90, fltk_headers_y+55));
	win.attach(gui_h_to_fltk_headers);
	Line gui_to_window_h(Point(gui_h_x+90, gui_h_y+5), Point(window_h_x+110, window_h_y+62));
	win.attach(gui_to_window_h);

	Line simple_window_to_window_h(Point(simple_window_h_x+140, simple_window_h_y+5), Point(window_h_x+70, window_h_y+62));
	win.attach(simple_window_to_window_h);
	Line simple_window_to_gui_h(Point(simple_window_h_x+140, simple_window_h_y+5), Point(gui_h_x+20, gui_h_y+62));
	win.attach(simple_window_to_gui_h);

	Line gui_cpp_to_gui_h(Point(gui_cpp_x+75, gui_cpp_y+5), Point(gui_h_x+80, gui_h_y+62));
	win.attach(gui_cpp_to_gui_h);

	Line window_cpp_to_window_h(Point(window_cpp_x+80, window_cpp_y+5), Point(window_h_x+45, window_h_y+62));
	win.attach(window_cpp_to_window_h);

	Line graph_cpp_to_graph_h(Point(graph_cpp_x+70, graph_cpp_y+5), Point(graph_h_x+65, graph_h_y+62));
	win.attach(graph_cpp_to_graph_h);

	Line ch12_cpp_to_graph_h(Point(ch12_cpp_x+100, ch12_cpp_y+5), Point(graph_h_x+70, graph_h_y+62));
	win.attach(ch12_cpp_to_graph_h);

	Line ch12_cpp_to_simple_window_h(Point(ch12_cpp_x+100, ch12_cpp_y+5), Point(simple_window_h_x+30, simple_window_h_y+62));
	win.attach(ch12_cpp_to_simple_window_h);
	// -------------------------------------------------------------------------------------

	// FLTK headers
	// -------------------------------------------------------------------------------------
	Fl_Rectangle fltk_headers_rect1(Point(fltk_headers_x, fltk_headers_y), 115, 45);
	fltk_headers_rect1.set_fill_color(Color::yellow);
	Fl_Rectangle fltk_headers_rect2(Point(fltk_headers_x+5, fltk_headers_y+5), 115, 45);
	fltk_headers_rect2.set_fill_color(Color::yellow);
	Fl_Rectangle fltk_headers_rect3(Point(fltk_headers_x+10, fltk_headers_y+10), 115, 45);
	fltk_headers_rect3.set_fill_color(Color::yellow);

	Text fltk_headers_inside_text(Point(fltk_headers_x+25, fltk_headers_y+28), "FLTK headers");
	fltk_headers_inside_text.set_font(Font::times);

	win.attach(fltk_headers_rect1);
	win.attach(fltk_headers_rect2);
	win.attach(fltk_headers_rect3);
	win.attach(fltk_headers_inside_text);
	// -------------------------------------------------------------------------------------

	// FLTK code
	// -------------------------------------------------------------------------------------
	Fl_Rectangle fltk_code_rect1(Point(fltk_code_x, fltk_code_y), 100, 45);
	fltk_code_rect1.set_fill_color(Color::yellow);
	Fl_Rectangle fltk_code_rect2(Point(fltk_code_x+5, fltk_code_y+5), 100, 45);
	fltk_code_rect2.set_fill_color(Color::yellow);
	Fl_Rectangle fltk_code_rect3(Point(fltk_code_x+10, fltk_code_y+10), 100, 45);
	fltk_code_rect3.set_fill_color(Color::yellow);

	Text fltk_code_inside_text(Point(fltk_code_x+25, fltk_code_y+28), "FLTK code");
	fltk_code_inside_text.set_font(Font::times);

	win.attach(fltk_code_rect1);
	win.attach(fltk_code_rect2);
	win.attach(fltk_code_rect3);
	win.attach(fltk_code_inside_text);
	// -------------------------------------------------------------------------------------

	// Point.h
	// -------------------------------------------------------------------------------------
	Text point_h_outside_text(Point(point_h_x, point_h_y), "Point.h");
	point_h_outside_text.set_font(Font::times_bold);

	Fl_Rectangle point_h_rect(Point(point_h_x, point_h_y + 5), 130, 30);
	point_h_rect.set_fill_color(Color::yellow);

	Text point_h_inside_text(Point(point_h_x+7, point_h_y+23), "struct Point { ... };");
	point_h_inside_text.set_font(Font::times_bold);

	win.attach(point_h_outside_text);
	win.attach(point_h_rect);
	win.attach(point_h_inside_text);
	// -------------------------------------------------------------------------------------

	// Graph.h
	// -------------------------------------------------------------------------------------
	Text graph_h_outside_text(Point(graph_h_x, graph_h_y), "Graph.h");
	graph_h_outside_text.set_font(Font::times_bold);

	Fl_Rectangle graph_h_rect(Point(graph_h_x, graph_h_y + 5), 140, 62);
	graph_h_rect.set_fill_color(Color::yellow);

	Text graph_h_inside_text1(Point(graph_h_x+7, graph_h_y+23),
		"// graphing interface:");
	graph_h_inside_text1.set_font(Font::times);
	Text graph_h_inside_text2(Point(graph_h_x+7, graph_h_y+40),
		"struct Shape { ... };");
	graph_h_inside_text2.set_font(Font::times_bold);
	Text graph_h_inside_text3(Point(graph_h_x+7, graph_h_y+57),
		"...");
	graph_h_inside_text3.set_font(Font::times);

	win.attach(graph_h_outside_text);
	win.attach(graph_h_rect);
	win.attach(graph_h_inside_text1);
	win.attach(graph_h_inside_text2);
	win.attach(graph_h_inside_text3);
	// -------------------------------------------------------------------------------------

	// Window.h
	// -------------------------------------------------------------------------------------
	Text window_h_outside_text(Point(window_h_x, window_h_y), "Window.h");
	window_h_outside_text.set_font(Font::times_bold);

	Fl_Rectangle window_h_rect(Point(window_h_x, window_h_y + 5), 145, 62);
	window_h_rect.set_fill_color(Color::yellow);

	Text window_h_inside_text1(Point(window_h_x+7, window_h_y+23),
		"// window interface:");
	window_h_inside_text1.set_font(Font::times);
	Text window_h_inside_text2(Point(window_h_x+7, window_h_y+40),
		"class Window { ... };");
	window_h_inside_text2.set_font(Font::times_bold);
	Text window_h_inside_text3(Point(window_h_x+7, window_h_y+57),
		"...");
	window_h_inside_text3.set_font(Font::times);

	win.attach(window_h_outside_text);
	win.attach(window_h_rect);
	win.attach(window_h_inside_text1);
	win.attach(window_h_inside_text2);
	win.attach(window_h_inside_text3);
	// -------------------------------------------------------------------------------------

	// GUI.h
	// -------------------------------------------------------------------------------------
	Text gui_h_outside_text(Point(gui_h_x, gui_h_y), "GUI.h");
	gui_h_outside_text.set_font(Font::times_bold);

	Fl_Rectangle gui_h_rect(Point(gui_h_x, gui_h_y + 5), 145, 62);
	gui_h_rect.set_fill_color(Color::yellow);

	Text gui_h_inside_text1(Point(gui_h_x+7, gui_h_y+23),
		"// GUI interface:");
	gui_h_inside_text1.set_font(Font::times);
	Text gui_h_inside_text2(Point(gui_h_x+7, gui_h_y+40),
		"struct In_box { ... };");
	gui_h_inside_text2.set_font(Font::times_bold);
	Text gui_h_inside_text3(Point(gui_h_x+7, gui_h_y+57),
		"...");
	gui_h_inside_text3.set_font(Font::times);

	win.attach(gui_h_outside_text);
	win.attach(gui_h_rect);
	win.attach(gui_h_inside_text1);
	win.attach(gui_h_inside_text2);
	win.attach(gui_h_inside_text3);
	// -------------------------------------------------------------------------------------

	// Simple_window.h
	// -------------------------------------------------------------------------------------
	Text simple_window_h_outside_text(Point(simple_window_h_x, simple_window_h_y), "Simple_window.h");
	simple_window_h_outside_text.set_font(Font::times_bold);

	Fl_Rectangle simple_window_h_rect(Point(simple_window_h_x, simple_window_h_y + 5), 185, 62);
	simple_window_h_rect.set_fill_color(Color::yellow);

	Text simple_window_h_inside_text1(Point(simple_window_h_x+7, simple_window_h_y+23),
		"// window interface:");
	simple_window_h_inside_text1.set_font(Font::times);
	Text simple_window_h_inside_text2(Point(simple_window_h_x+7, simple_window_h_y+40),
		"class Simple_window { ... };");
	simple_window_h_inside_text2.set_font(Font::times_bold);
	Text simple_window_h_inside_text3(Point(simple_window_h_x+7, simple_window_h_y+57),
		"...");
	simple_window_h_inside_text3.set_font(Font::times);

	win.attach(simple_window_h_outside_text);
	win.attach(simple_window_h_rect);
	win.attach(simple_window_h_inside_text1);
	win.attach(simple_window_h_inside_text2);
	win.attach(simple_window_h_inside_text3);
	// -------------------------------------------------------------------------------------

	// chapter12.cpp
	// -------------------------------------------------------------------------------------
	Text ch12_cpp_outside_text(Point(ch12_cpp_x, ch12_cpp_y), "chapter12.cpp");
	ch12_cpp_outside_text.set_font(Font::times_bold);

	Fl_Rectangle ch12_cpp_rect(Point(ch12_cpp_x, ch12_cpp_y + 5), 195, 62);
	ch12_cpp_rect.set_fill_color(Color::yellow);

	Text ch12_cpp_inside_text1(Point(ch12_cpp_x+7, ch12_cpp_y+23),
		"#include \"Graph.h\"");
	ch12_cpp_inside_text1.set_font(Font::times_bold);
	Text ch12_cpp_inside_text2(Point(ch12_cpp_x+7, ch12_cpp_y+40),
		"#include \"Simple_window.h\"");
	ch12_cpp_inside_text2.set_font(Font::times_bold);
	Text ch12_cpp_inside_text3(Point(ch12_cpp_x+7, ch12_cpp_y+57),
		"int main() { ... }");
	ch12_cpp_inside_text3.set_font(Font::times_bold);

	win.attach(ch12_cpp_outside_text);
	win.attach(ch12_cpp_rect);
	win.attach(ch12_cpp_inside_text1);
	win.attach(ch12_cpp_inside_text2);
	win.attach(ch12_cpp_inside_text3);
	// -------------------------------------------------------------------------------------

	// Graph.cpp
	// -------------------------------------------------------------------------------------
	Text graph_cpp_outside_text(Point(graph_cpp_x, graph_cpp_y), "Graph.cpp");
	graph_cpp_outside_text.set_font(Font::times_bold);

	Fl_Rectangle graph_cpp_rect(Point(graph_cpp_x, graph_cpp_y + 5), 85, 27);
	graph_cpp_rect.set_fill_color(Color::yellow);

	Text graph_cpp_inside_text(Point(graph_cpp_x+7, graph_cpp_y+23),
		"Graph code");
	graph_cpp_inside_text.set_font(Font::times_bold);

	win.attach(graph_cpp_outside_text);
	win.attach(graph_cpp_rect);
	win.attach(graph_cpp_inside_text);
	// -------------------------------------------------------------------------------------

	// window.cpp
	// -------------------------------------------------------------------------------------
	Text window_cpp_outside_text(Point(window_cpp_x, window_cpp_y), "window.cpp");
	window_cpp_outside_text.set_font(Font::times_bold);

	Fl_Rectangle window_cpp_rect(Point(window_cpp_x, window_cpp_y + 5), 95, 27);
	window_cpp_rect.set_fill_color(Color::yellow);

	Text window_cpp_inside_text(Point(window_cpp_x+7, window_cpp_y+23),
		"Window code");
	window_cpp_inside_text.set_font(Font::times_bold);

	win.attach(window_cpp_outside_text);
	win.attach(window_cpp_rect);
	win.attach(window_cpp_inside_text);
	// -------------------------------------------------------------------------------------

	// GUI.cpp
	// -------------------------------------------------------------------------------------
	Text gui_cpp_outside_text(Point(gui_cpp_x, gui_cpp_y), "GUI.cpp");
	gui_cpp_outside_text.set_font(Font::times_bold);

	Fl_Rectangle gui_cpp_rect(Point(gui_cpp_x, gui_cpp_y + 5), 95, 27);
	gui_cpp_rect.set_fill_color(Color::yellow);

	Text gui_cpp_inside_text(Point(gui_cpp_x+7, gui_cpp_y+23),
		"GUI code");
	gui_cpp_inside_text.set_font(Font::times_bold);

	win.attach(gui_cpp_outside_text);
	win.attach(gui_cpp_rect);
	win.attach(gui_cpp_inside_text);
	// -------------------------------------------------------------------------------------

	win.wait_for_button(); // display!
}
