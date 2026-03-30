#include "Simple_window.h"
#include "Graph.h"
#include "right_triangle.h"
#include <string>

using namespace std;
using namespace Graph_lib;

unsigned int to_rgba(int r, int g, int b);

int main() {

	srand(0);

	const int win_width = 599;
	const int win_height = 399;
	Simple_window win(Point(100,100), win_width, win_height, "Ch. 13 Ex. 15");

	const int a = 25;
	const int b = 40;

	// how many triangles fit vertically + 1 to make sure it fills the whole screen
	const int lines = win_height/a + 1;
	const int columns = win_width/b + 1; // how many triangles fit horizontally

	Right_triangle* triangles1[lines][columns];
	Right_triangle* triangles2[lines][columns];
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j) {
			Right_triangle* triangle1 = new Right_triangle(Point(j*b+b,i*a), a, b, 180.0);
			triangle1->set_fill_color(to_rgba(rand()%256, rand()%256, rand()%256));
			triangle1->set_color(Color::invisible);
			Right_triangle* triangle2 = new Right_triangle(Point(j*b,i*a+a), a, b, 0.0);
			triangle2->set_fill_color(to_rgba(rand()%256, rand()%256, rand()%256));
			triangle2->set_color(Color::invisible);
			win.attach(*triangle1);
			win.attach(*triangle2);
			triangles1[i][j] = triangle1;
			triangles2[i][j] = triangle2;
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
