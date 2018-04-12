#ifndef JOB_H
#define JOB_H
#pragma once
#include <iostream>

using namespace std;

#define N 10000

#define RED 1
#define BLACK 0

typedef struct job {
	int id, e_t, t_t, color;
	job *lc, *rc, *pa;
	job(int i, int t) {
		id = i;
		t_t = t;
		e_t = 0;
		color = BLACK;
		lc = rc = pa = NULL;
	}
	void show() {
		cout << "(" << id << "," << e_t << "," << t_t << ")" << endl;
	}
	void run() {
		e_t += 5;
	}
}JOB, *JOBP;

#endif