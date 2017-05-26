#include "list.cpp"

int main() {
	_list<int> l;
	for (int i = 0; i < 6; i++) {
		cout << "Push: " << i << endl;
		l.push(i);
		l.show();
	}
	for (int i = 0; i < 7; i++) {
		cout << "Pop: ";
		l.pop();
		l.show();
	}
}