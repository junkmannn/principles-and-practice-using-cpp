#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 4");

	Graph_lib::Rectangle* rects[9];
	// vector<Graph_lib::Rectangle> rects(9);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int index = i*3 + j;
			rects[index] = new Graph_lib::Rectangle(Point(i*30, j*30), 30, 30);
			rects[index]->set_fill_color(index%2 == 0 ? Color::white : Color::red);
			win.attach(*rects[index]);

			/*
			int index = i*3 + j;
			rects[index] = Graph_lib::Rectangle(Point(i*30, j*30), 30, 30);
			rects[index].set_fill_color(index%2 == 0 ? Color::white : Color::red);
			win.attach(rects[index]);
			*/
		}
	}

	win.wait_for_button(); // display!
}
