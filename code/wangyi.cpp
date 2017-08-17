#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node {
	int x, y;
	node() : x(0), y(0) {}
}NODE;
vector<NODE> nodes;

int abs(int a) {
	return (a > 0 ? a : -a);
}

int dist(NODE& a, NODE& b) {
	return (abs(a.x - b.x) + abs(a.y - b.y));
}

vector<vector<int> > con;

void init(int n) {
	nodes.resize(n);
	for (int i = 0; i < con.size(); i++)
		con[i].clear();
	con.resize(n);
}

void show(int n) {
	cout << "Container:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++)
			cout << con[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {
	while (true) {
		int i, j, k, l, n, ans, tmp;
		cin >> n;
		init(n);
		for (i = 0; i < n; i++)
			cin >> nodes[i].x;
		for (i = 0; i < n; i++)
			cin >> nodes[i].y;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				tmp = dist(nodes[i], nodes[j]);
				con[i].push_back(tmp);
				con[j].push_back(tmp);
			}
			sort(con[i].begin(), con[i].end());
		}
		show(n);
		cout << "0";
		for (i = 0, j = 0; i < n - 1; i++, j++) {
			ans = 0;
			for (k = 0; k <= j; k++)
				ans += con[0][k];
			for (l = 1; l < n - j; l++) {
				tmp = 0;
				for (k = 0; k <= j; k++)
					tmp += con[l][k];
				if (ans > tmp)
					ans = tmp;
			}
			cout << " " << ans;
		}
		cout << endl;
	}
	return 0;
}

//0
//1
//2 3
//2
//9 6
//6 9
//3
//1 4 5
//3 1 4
//4
//1 2 4 5
//5 8 4 6
