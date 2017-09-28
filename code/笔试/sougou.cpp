4
0.00000000
56.0000
179.000000
180.00000


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

#define N 1000000

int help(vector<double>& con, int i, int n) {
	int ans = 0, j;
	for (j = i + 1; j < n; j++) {
		if (con[j] - con[i] < 180)
			ans++;
		else
			break;
	}
	if (j == n) {
		for (j = 0; j < i; j++) {
			if (con[j] + 360 - con[i] < 180)
				ans++;
			else
				break;
		}
	}
	return (ans - 1)*ans / 2;
}

int main() {
	int i, n, ans = 0;
	double a;
	vector<double> con;
	scanf("%d", &n);
	for (i = 0;i< n; i++) {
		scanf("%lf", &a);
		con.push_back(a);
	}
	sort(con.begin(), con.end());
	for (i = 0; i < n; i++)
		ans += help(con, i, n);
	printf("%d\n", ans);
	return 0;
}