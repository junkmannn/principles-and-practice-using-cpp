#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Rectangle Fl_Rectangle;

unsigned int to_rgba(int r, int g, int b);

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 7");

	const int size = 30;
	const int lines = 6;
	const int columns = 8;

	unsigned int colors[lines][columns];
	colors[0][0] = to_rgba(255, 128, 128);
	colors[0][1] = to_rgba(255, 255, 128);
	colors[0][2] = to_rgba(128, 255, 128);
	colors[0][3] = to_rgba(0, 255, 128);
	colors[0][4] = to_rgba(128, 255, 255);
	colors[0][5] = to_rgba(0, 128, 255);
	colors[0][6] = to_rgba(255, 128, 192);
	colors[0][7] = to_rgba(255, 128, 255);
	colors[1][0] = to_rgba(255, 0, 0);
	colors[1][1] = to_rgba(255, 255, 0);
	colors[1][2] = to_rgba(128, 255, 0);
	colors[1][3] = to_rgba(0, 255, 64);
	colors[1][4] = to_rgba(0, 255, 255);
	colors[1][5] = to_rgba(0, 128, 192);
	colors[1][6] = to_rgba(128, 128, 192);
	colors[1][7] = to_rgba(255, 0, 255);
	colors[2][0] = to_rgba(128, 64, 64);
	colors[2][1] = to_rgba(255, 128, 64);
	colors[2][2] = to_rgba(0, 255, 0);
	colors[2][3] = to_rgba(0, 128, 128);
	colors[2][4] = to_rgba(0, 64, 128);
	colors[2][5] = to_rgba(128, 128, 255);
	colors[2][6] = to_rgba(128, 0, 64);
	colors[2][7] = to_rgba(255, 0, 128);
	colors[3][0] = to_rgba(128, 0, 0);
	colors[3][1] = to_rgba(255, 128, 0);
	colors[3][2] = to_rgba(0, 128, 0);
	colors[3][3] = to_rgba(0, 128, 64);
	colors[3][4] = to_rgba(0, 0, 255);
	colors[3][5] = to_rgba(0, 0, 160);
	colors[3][6] = to_rgba(128, 0, 128);
	colors[3][7] = to_rgba(128, 0, 255);
	colors[4][0] = to_rgba(64, 0, 0);
	colors[4][1] = to_rgba(128, 64, 0);
	colors[4][2] = to_rgba(0, 64, 0);
	colors[4][3] = to_rgba(0, 64, 64);
	colors[4][4] = to_rgba(0, 0, 128);
	colors[4][5] = to_rgba(0, 0, 64);
	colors[4][6] = to_rgba(64, 0, 64);
	colors[4][7] = to_rgba(64, 0, 128);
	colors[5][0] = to_rgba(0, 0, 0);
	colors[5][1] = to_rgba(128, 128, 0);
	colors[5][2] = to_rgba(128, 128, 64);
	colors[5][3] = to_rgba(128, 128, 128);
	colors[5][4] = to_rgba(64, 128, 128);
	colors[5][5] = to_rgba(192, 192, 192);
	colors[5][6] = to_rgba(64, 0, 64);
	colors[5][7] = to_rgba(255, 255, 255);

	Fl_Rectangle* palette[lines][columns];
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j) {
			palette[i][j] = new Fl_Rectangle(Point(j*size, i*size), size, size);
			Fl_Rectangle* color = palette[i][j];
			color->set_color(Color::white);
			color->set_fill_color(colors[i][j]);
			win.attach(*color);
		}
	}

	win.wait_for_button(); // display!
}

unsigned int to_rgba(int r, int g, int b) {
	int rgba = 0;
	rgba |= r << 24;
	rgba |= g << 16;
	rgba |= b << 8;
	return rgba;
}
