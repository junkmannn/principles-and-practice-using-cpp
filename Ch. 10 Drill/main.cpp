#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Point {
	Point(int x, int y) : x(x), y(y) { }
	int x;
	int y;
};

bool input_points(vector<Point>& pts);
void print_points(vector<Point>& pts);
bool write_to_file(vector<Point>& pts);
bool read_from_file(vector<Point>& pts);
bool compare_points(vector<Point>& pts1, vector<Point>& pts2);
void keep_window_open();

int main() {
	vector<Point> original_points;

	if (input_points(original_points)) {
		cout << "original_points:\n";
		print_points(original_points);

		if (!write_to_file(original_points)) {
			cout << "Can't open file for writing.\n";
			keep_window_open();
			return 0;
		}

		vector<Point> processed_points;
		if (!read_from_file(processed_points)) {
			cout << "Can't open file for reading.\n";
			keep_window_open();
			return 0;
		}

		cout << "processed_points:\n";
		print_points(processed_points);

		if (compare_points(original_points, processed_points)) {
			cout << "OK!\n";
		}
		else {
			cout << "Scomething's wrong!\n";
		}
	}

	cin.clear();
	keep_window_open();

	return 0;
}

bool input_points(vector<Point>& pts) {
	cout << "Please enter seven (x,y) pairs.\n";

	for (int i = 0; i < 7; ++i) {
		int x, y;
		if (cin >> x >> y) pts.push_back(Point(x, y));
		else return false;
	}

	return true;
}

void print_points(vector<Point>& pts) {
	for (int i = 0, size = pts.size(); i < size; ++i) {
		Point& pt = pts[i];
		cout << i+1 << ". (" << pt.x << ',' << pt.y << ")\n";
	}
}

bool write_to_file(vector<Point>& pts) {
	ofstream ost("mydata.txt");
	if (!ost) return false;

	for (int i = 0, size = pts.size(); i < size; ++i) {
		Point& pt = pts[i];
		ost << pt.x << ' ' << pt.y << '\n';
	}

	return true;
}

bool read_from_file(vector<Point>& pts) {
	ifstream ist("mydata.txt");
	if (!ist) return false;

	int x, y;
	while (ist >> x >> y) {
		pts.push_back(Point(x, y));
	}

	return true;
}

bool compare_points(vector<Point>& pts1, vector<Point>& pts2) {
	int size = pts1.size();

	if (size != pts2.size()) return false;

	for (int i = 0; i < size; ++i) {
		Point& pt1 = pts1[i];
		Point& pt2 = pts2[i];
		if (pt1.x != pt2.x || pt1.y != pt2.y) return false;
	}

	return true;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}