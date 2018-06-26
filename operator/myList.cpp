#include "myList.h"

cList::cList() {
	pHead = pCur = NULL;
	return;
}

cList::~cList() {
	PNODE tmp = NULL;
	while (pHead) {
		tmp = pHead->next;
		delete pHead;
		pHead = tmp;
	}
	return;
}

void cList::operator+=(const cPerson& p) {
	PNODE b = new NODE(p);
	PNODE pre = NULL, cur = pHead;
	if (cur) {
		while (cur) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = b;
	}
	else
		pHead = b;
}

bool operator++(cList&op, int){
	op.pCur = op.pCur->next;
	if (op.pCur)
		return true;
	return false;
}

PNODE cList::operator[] (string n) {
	PNODE cur = pHead;
	while (cur) {
		if (cur->data.name == n)
			break;
		cur = cur->next;
	}
	return cur;
}

void cList::SetCurToHead() {
	pCur = pHead;
}

void cList::ShowCurData() {
	if (pCur) {
		pCur->data.Show();
	}
	else
		cout << "The List is empty!" << endl;
}