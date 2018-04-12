#include "heap.h"

heap::heap() {
	tail = 0;
	for (int i = N - 1; i >= 0; i--)
		container[i] = NULL;
}

heap::~heap() {}

int heap::getT() { return tail; }

void heap::add(JOBP x) {
	container[tail++] = x;
	int i = tail - 1, j;
	for (j = (i - 1) / 2; i > 0 && container[i]->e_t < container[j]->e_t; j = (i - 1) / 2) {
		swap(i, j);
		i = j;
	}
}

int heap::top(int &ext) {
	int ans = -1;
	if (tail) {
		container[0]->run();
		if (container[0]->e_t >= container[0]->t_t) {
			ans = container[0]->id;
			ext = 5 - container[0]->e_t + container[0]->t_t;
			container[0] = NULL;
			if (tail > 1)
				swap(0, tail - 1);
			tail--;
		}
		else {
			ext = 5;
			modify(0);
		}
	}
	return ans;
}

void heap::modify(int i) {
	int l = i * 2 + 1, r = l + 1, s = i;
	if (l < tail && container[s]->e_t > container[l]->e_t)
		s = l;
	if (r < tail && container[s]->e_t > container[r]->e_t)
		s = r;
	if (s - i) {
		swap(i, s);
		modify(s);
	}
}

void heap::swap(int i, int j) {
	JOBP tmp = container[i];
	container[i] = container[j];
	container[j] = tmp;
}
