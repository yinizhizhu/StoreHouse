#include <iostream>

using namespace std;

class Base {
public:Base(){}
public:
	virtual void print() { cout << "Base\n"; }
	//virtual void print() = 0 { cout << "Base\n"; }//the class which contains pure virtual funciton must not be the instance
};

class Derived :public Base {
public:Derived(){}
public:
	void print(){ cout << "Derived\n"; }
};

int main() {
	Base a;
	a.print();
	Base *b = new Derived();
	b->print();
	Derived point;
	point.print();

}