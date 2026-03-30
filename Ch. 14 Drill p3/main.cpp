#include <iostream>

using namespace std;

class B1 {
public:
	virtual void vf() { cout << "B1::vf()\n"; }
	virtual void pvf() = 0;
	void f() { cout << "B1::f()\n"; }
private:

};

class D1 : public B1 {
public:
	virtual void vf() { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
private:

};

class D2 : public D1 {
public:
	virtual void pvf() { cout << "D2::pvf()\n"; }
private:

};

void keep_window_open();

int main() {
	D2 d2;

	d2.f();
	d2.vf();
	d2.pvf();

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
