#include "node.h"

cNode::cNode(cPerson p) {
	data.name = p.name;
	data.age = p.age;
	data.gender = p.gender;
	return;
}

cNode::~cNode() {
	return;
}

cPerson cNode::GetData() {
	return data;
}