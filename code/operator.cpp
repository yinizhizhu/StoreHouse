#include <iostream>  

using namespace std;

class node {
public:
	int x, y;
	node() : x(0), y(0) {}
	node(int a, int b) : x(a), y(b) {}
	node& operator+=(const node& a) {
		x += a.x;
		y += a.y;
		return *this;
	}
	node operator+(const node& a) {
		node tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}
	bool operator==(const node& a) {
		if (x == a.x && y == a.y)
			return true;
		return false;
	}
	void operator=(const node& a) {
		x = a.x;
		y = a.y;
	}
	void show() {
		cout << x << ", " << y << endl;
	}
};

node direction[4] = {
	node(0, -1),	//up
	node(0, 1),		//down
	node(-1, 0),	//left
	node(1, 0)		//right
};

int main() {
	node head(0, 0), tail(5, 5);
	head.show();
	head = tail;
	head.show();
	head += tail;
	head.show();
	head = head + tail;
	head.show();
	return 0;
}