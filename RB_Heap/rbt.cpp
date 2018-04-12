#include "rbt.h"

rbTree::rbTree() {
	root = NULL;
	counter = 0;
}

rbTree::~rbTree() {
	int ext;
	for (int i = minh.top(ext); minh.getT(); i = minh.top(ext))
		if (i + 1)
			deleteRBNode(i);
}

void rbTree::processor() {
	string time, order, x, y;
	int a, b, t, i, ext;
	for (; cin >> time >> order;) {
		time.erase(time.end() - 1);
		t = strTInt(time);
		for (; counter < t; counter += ext) {
			i = minh.top(ext);
			if (i + 1)
				deleteRBNode(i);
			//cout << counter << ", " << t << endl;
		}
		x = "", y = "";
		if (order[0] == 'I') {
			for (i = 7; order[i] != ','; i++)
				x += order[i];
			for (++i; order[i] != ')'; i++)
				y += order[i];
			a = strTInt(x);
			b = strTInt(y);
			insert(a, b);
		}
		else if (order[0] == 'P') {
			if (order[2] == 'i') {
				for (i = 9; order[i] != ',' && order[i] != ')'; i++)
					x += order[i];
				a = strTInt(x);
				if (order[i] == ',') {
					for (++i; order[i] != ')'; i++)
						y += order[i];
					b = strTInt(y);
					printJob(a, b);
				}
				else
					printJob(a);
			}
			else {
				for (i = 12; order[i] != ',' && order[i] != ')'; i++)
					x += order[i];
				a = strTInt(x);
				preJob(a);
			}
		}
		else if (order[0] == 'N') {
			for (i = 8; order[i] != ',' && order[i] != ')'; i++)
				x += order[i];
			a = strTInt(x);
			nextJob(a);
		}
		else
			cout << "The order is wrong!" << endl;
	}
}

int rbTree::strTInt(string& str) {
	int ans = 0;
	int i = str.size() - 1, basis = 1;
	for (; i >= 0; i--, basis *= 10)
		ans += (str[i] - '0')*basis;
	return ans;
}

void rbTree::insert(int id, int t_t) {
	insertRBNode(id, t_t);
}

void rbTree::printJob(int id) {
	JOBP t = findRB(id);
	if (t)
		t->show();
	else
		null();
}

void rbTree::printJob(int id1, int id2) {
	if (id1 > id2) {
		cout << "ID1 > ID2 !!!!" << endl;
		return;
	}
	JOBP t = root, ans = NULL;
	int tmp = -1;
	for (; t;) {
		if (t->id > id1) {
			if (t->id > tmp) {
				ans = t;
				tmp = t->id;
			}
			t = t->lc;
		}
		else if (t->id < id1)
			t = t->rc;
		else {
			ans = t;
			break;
		}
	}
	if (ans)
		mOrder(ans, id1, id2);
	else
		null();
}

void rbTree::mOrder(JOBP t, int id1, int id2) {
	if (t && t->id >= id1 && t->id<=id2) {
		mOrder(t->lc, id1, id2);
		t->show();
		mOrder(t->rc, id1, id2);
	}
}

void rbTree::nextJob(int id) {
	JOBP t = root, ans = NULL;
	int tmp = INT_MAX;
	for (; t;) {
		if (t->id > id) {
			if (t->id < tmp) {
				ans = t;
				tmp = t->id;
			}
			t = t->lc;
		}
		else if (t->id <= id)
			t = t->rc;
	}
	if (ans)
		ans->show();
	else
		null();
}

void rbTree::preJob(int id) {
	JOBP t = root, ans = NULL;
	int tmp = -1;
	for (; t;) {
		if (t->id >= id)
			t = t->lc;
		else if (t->id < id) {
			if (t->id > tmp) {
				tmp = t->id;
				ans = t;
			}
			t = t->rc;
		}
	}
	if (ans)
		ans->show();
	else
		null();
}

void rbTree::null() {
	cout << "(0,0,0)" << endl;
}

void rbTree::insertRBNode(int id, int t_t) {
	JOBP pre = NULL, cur = root;
	while (cur != NULL) {
		pre = cur;
		if (cur->id > id)
			cur = cur->lc;
		else cur = cur->rc;
	}
	JOBP tmp = new JOB(id, t_t);
	minh.add(tmp);
	tmp->pa = pre;
	if (pre == NULL)
		root = tmp;
	else if (pre->id > tmp->id)
		pre->lc = tmp;
	else pre->rc = tmp;
	insertFixUp(tmp);//Keep the tree be Red Black Tree
}

JOBP rbTree::findRB(int id) {
	JOBP cur = root;
	while (cur != NULL) {
		if (cur->id == id)
			break;
		else if (cur->id > id)
			cur = cur->lc;
		else cur = cur->rc;
	}
	return cur;
}

JOBP rbTree::findPre(int id) {
	JOBP tmp = findRB(id);
	for (tmp = tmp->rc; tmp; tmp = tmp->rc);
	return tmp;
}

JOBP rbTree::findNext(int id) {
	JOBP tmp = findRB(id);
	for (tmp = tmp->lc; tmp; tmp = tmp->lc);
	return tmp;
}

void rbTree::leftRotate(JOBP tmp) {
	JOBP rightC = tmp->rc;
	if (rightC->lc != NULL)
		rightC->lc->pa = tmp;
	rightC->pa = tmp->pa;
	if (NULL == tmp->pa)
		root = rightC;
	else if (tmp == tmp->pa->lc)
		tmp->pa->lc = rightC;
	else tmp->pa->rc = rightC;
	tmp->pa = rightC;
	tmp->rc = rightC->lc;
	rightC->lc = tmp;
}

void rbTree::rightRotate(JOBP tmp) {
	JOBP leftC = tmp->lc;
	if (leftC->rc != NULL)
		leftC->rc->pa = tmp;
	leftC->pa = tmp->pa;
	if (NULL == tmp->pa)
		root = leftC;
	else if (tmp == tmp->pa->lc)
		tmp->pa->lc = leftC;
	else tmp->pa->rc = leftC;
	tmp->pa = leftC;
	tmp->lc = leftC->rc;
	leftC->rc = tmp;
}

void rbTree::insertFixUp(JOBP tmp) {
	JOBP paTmp = tmp->pa, ancleTempNode;
	while (paTmp != NULL&&RED == paTmp->color) {
		if (paTmp->pa != NULL) {
			if (paTmp->pa->lc == paTmp) {
				ancleTempNode = paTmp->pa->rc;
				if (ancleTempNode != NULL&&RED == ancleTempNode->color) {
					paTmp->color = BLACK;
					ancleTempNode->color = BLACK;
					paTmp->pa->color = RED;
					tmp = paTmp->pa;
					paTmp = tmp->pa;
				}
				else {
					if (tmp == paTmp->rc) {
						leftRotate(paTmp);
						tmp = tmp->lc;
						paTmp = tmp->pa;
					}
					paTmp->color = BLACK;
					paTmp->pa->color = RED;
					rightRotate(paTmp->pa);
					break;
				}
			}
			else {
				ancleTempNode = paTmp->pa->lc;
				if (ancleTempNode != NULL&&RED == ancleTempNode->color) {
					paTmp->color = BLACK;
					ancleTempNode->color = BLACK;
					paTmp->pa->color = RED;
					tmp = paTmp->pa;
					paTmp = tmp->pa;
				}
				else {
					if (tmp == paTmp->lc) {
						rightRotate(paTmp);
						tmp = tmp->rc;
						paTmp = tmp->pa;
					}
					paTmp->color = BLACK;
					paTmp->pa->color = RED;
					leftRotate(paTmp->pa);
					break;
				}
			}
		}
		else break;
	}
	root->color = BLACK;
}

void rbTree::deleteNoOrOneChildNode(JOBP pre, JOBP cur) {
	//pre - the pointer of parent of the node which will be deleted
	//cur - the node will be deleted
	if (NULL == cur->lc&&NULL == cur->rc) {//Both NULL
		if (NULL == pre)
			root = NULL;
		else if (pre->lc == cur)
			pre->lc = NULL;
		else pre->rc = NULL;
		delete cur;
	}
	else if (cur->rc != NULL) {//Right child is not NULL
		if (NULL == pre) {
			root = cur->rc;
			root->pa = NULL;
		}
		else if (pre->lc == cur) {
			pre->lc = cur->rc;
			cur->rc->pa = pre;
		}
		else {
			pre->rc = cur->rc;
			cur->rc->pa = pre;
		}
		delete cur;
	}
	else if (cur->lc != NULL) {//left child is not NULL
		if (NULL == pre) {
			root = cur->lc;
			root->pa = NULL;
		}
		else if (pre->lc == cur) {
			pre->lc = cur->lc;
			cur->lc->pa = pre;
		}
		else {
			pre->rc = cur->lc;
			cur->lc->pa = pre;
		}
		delete cur;
	}
}

void rbTree::deleteFixUp(JOBP tmp) {
	if (RED == tmp->color)
		insertFixUp(tmp);
}

void rbTree::deleteRBNode(int id) {
	JOBP pre = NULL, cur = root;
	while (cur != NULL) {
		if (cur->id == id)
			break;
		else {
			pre = cur;
			if (cur->id > id)
				cur = cur->lc;
			else cur = cur->rc;
		}
	}
	if (NULL == cur) {
		cout << "Cannot find the node with id = " << id << endl;
		return;
	}
	JOBP tmpC;
	int tmpColor;
	if (NULL == cur->lc || NULL == cur->rc) {
		if (NULL == cur->lc)//right child is NULL
			tmpC = cur->rc;
		else tmpC = cur->lc;
		tmpColor = cur->color;
		deleteNoOrOneChildNode(pre, cur);
		if (tmpC != NULL&&BLACK == tmpColor)
			deleteFixUp(tmpC);
	}
	else {//both are Not NULL
		JOBP rPre = cur, rCur = cur->rc;
		while (rCur->lc != NULL) {
			rPre = rCur;
			rCur = rCur->lc;
		}
		cur->id = rCur->id;
		tmpC = rCur->rc;
		tmpColor = rCur->color;
		deleteNoOrOneChildNode(rPre, rCur);
		if (tmpC != NULL&&BLACK == tmpColor)
			deleteFixUp(tmpC);
	}
}
