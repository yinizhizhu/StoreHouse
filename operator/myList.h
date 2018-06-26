#pragma once

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "node.h"

using namespace std;

class cList{
public:
	cList();
	~cList();
	PNODE pHead, pCur;
	void operator+=(const cPerson& p);
	friend bool operator++(cList&op, int);
	PNODE operator[] (string n);
	void SetCurToHead();
	void ShowCurData();
};

#endif // !MYLIST_H
