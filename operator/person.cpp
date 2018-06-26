#include "person.h"

cPerson::cPerson(string n, int a, char g) {
	name = n;
	age = a;
	gender = g;
	return;
}

cPerson::cPerson() {
	name = "";
	age = 0;
	gender = '*';
}

cPerson::~cPerson() {
	return;
}

void cPerson::Show() {
	cout << "Name:" << name << ", Age:" << age << ", Gender:" << gender << endl;
}