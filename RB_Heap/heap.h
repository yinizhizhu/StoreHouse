#ifndef HEAP_H
#define HEAP_H
#pragma once
#include <iostream>
#include "job.h"

using namespace std;

class heap {
private:
	int tail;
	JOBP container[N];
public:
	heap();
	~heap();
	int top(int &ext);
	int getT();
	void add(JOBP x);
	void modify(int i);
	void swap(int i, int j);
};

#endif