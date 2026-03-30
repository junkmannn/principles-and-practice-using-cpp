#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <time.h>
#include <iostream>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Rectangle Fl_Rectangle;

int main() {
	// 1. make 800x1000 window
	Simple_window win(Point(100, 100), 800, 1000, "Ch. 13 Drill");

	// 2. draw grid
	const int SQUARE_SIZE = 100;
	Lines grid;
	for (int i = 0; i <= 8; ++i) {
		int tmp = i*SQUARE_SIZE;
		grid.add(Point(tmp, 0), Point(tmp, 800));
		grid.add(Point(0, tmp), Point(800, tmp));
	}
	win.attach(grid);

	// 3. add red rectangles on the diagonal starting from top left
	Fl_Rectangle* red_squares[8];
	for (int i = 0; i < 8; ++i) {
		red_squares[i] = new Fl_Rectangle(Point(i*SQUARE_SIZE, i*SQUARE_SIZE), SQUARE_SIZE, SQUARE_SIZE);
		red_squares[i]->set_fill_color(Color::red);
		win.attach(*red_squares[i]);
	}

	// 4. add three 200x200 images
	Image* imgs[3];
	imgs[0] = new Image(Point(2*SQUARE_SIZE, 0), "ek.jpg");
	win.attach(*imgs[0]);
	imgs[1] = new Image(Point(0, 2*SQUARE_SIZE), "ek.jpg");
	win.attach(*imgs[1]);
	imgs[2] = new Image(Point(2*SQUARE_SIZE, 5*SQUARE_SIZE), "ek.jpg");
	win.attach(*imgs[2]);

	// 5. add one 100x100 image and move it around
	srand(time(NULL));
	int x = 0;
	int y = 0;
	Image* smiley = new Image(Point(x, y), "smiley.jpg");
	win.attach(*smiley);
	win.wait_for_button(); // display!
	while (1) {
		smiley->move(-x, -y);
		x = (rand() % 8) * SQUARE_SIZE;
		y = (rand() % 8) * SQUARE_SIZE;
		smiley->move(x, y);
		win.wait_for_button(); // display!
	}
}
