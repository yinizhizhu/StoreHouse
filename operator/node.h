#pragma once

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "person.h"

using namespace std;

typedef class cNode{
public:
	cNode(cPerson p);
	~cNode();
	cPerson data;
	cPerson GetData();
	cNode *next;
}NODE, *PNODE;

#endif // !NODE_H
