#pragma once
#ifndef LIST_H
#define LIST_H
#define HEAD
#include <iostream>

using namespace std;

template<typename keyType>
class _list {
private:
	typedef struct node {
		keyType k;
		node* next;
		node(keyType key = 0) : k(key), next(NULL) {}
	} NODE, *PNODE;
	PNODE head;
public:
	_list();
	~_list();
	void push(keyType k);
	void pop();
	void show();
};

#endif
