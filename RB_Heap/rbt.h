#ifndef RBT_H
#define RBT_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "heap.h"

using namespace std;

class rbTree {
private:
	JOBP root;
	heap minh;
	int counter;
public:
	rbTree();
	~rbTree();
	void processor();
	int strTInt(string& str);
	void insert(int id, int t_t);
	void printJob(int id);
	void printJob(int id1, int id2);
	void mOrder(JOBP t, int id1, int id2);
	void nextJob(int id);
	void preJob(int id);
	void null();

	JOBP findRB(int id);
	JOBP findPre(int id);
	JOBP findNext(int id);
	void insertRBNode(int id, int t_t);
	void insertFixUp(JOBP tmp);
	void leftRotate(JOBP tmp);
	void rightRotate(JOBP tmp);
	void deleteFixUp(JOBP tmp);
	void deleteRBNode(int id);
	void deleteNoOrOneChildNode(JOBP pre, JOBP cur);
};

#endif