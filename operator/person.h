#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class cPerson{
public:
	cPerson(string n, int a, char g);
	cPerson();
	~cPerson();
	void Show();
	string name;
	int age;
	char gender;
};

#endif // !PERSON_H
