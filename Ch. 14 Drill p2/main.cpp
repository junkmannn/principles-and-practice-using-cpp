#include <iostream>

using namespace std;

class B1 {
public:
	virtual void vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
private:

};

class D1 : public B1 {
public:
	virtual void vf() { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
private:

};

void keep_window_open();

int main() {
	B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	B1& b1_ref = d1;
	b1_ref.vf();
	b1_ref.f();

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
