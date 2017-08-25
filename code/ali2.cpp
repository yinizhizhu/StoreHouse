:
编译器版本: gcc 4.8.4请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
时间限制: 1S (C/C++以外的语言为: 3 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
N路口的个数 N个路口，
第一列是路口id，
第二列是该路口通行周期
 M 路的条数
 M条路，
 第一列路一端的路口，
 第二列路另一端的路口，
 第三列通行所需要的时间
 S起点，T目标点
输出:
最短时间
输入范例:
9 
0,3 
1,5 
2,7 
3,3 
4,5 
5,7 
6,9 
7,3 
8,5 
14 
0,1,4 
0,7,8 
1,2,8 
1,7,11 
2,3,7 
2,5,4 
2,8,2 
3,4,9 
3,5,14 
4,5,10 
5,6,2 
6,8,6 
6,7,1 
7,8,7 
0,4
输出范例:
28
:
现在城市有N个路口，每个路口有自己的编号，从0到N-1，
每个路口还有自己的交通控制信号，
例如0,3表示0号路口的交通信号每3个时刻变化一次，
即0到3时刻0号路口允许通过，3到6时刻不允许通过，
而6到9时刻又允许通过；
以此类推，所有路口的允许通行都从时刻0开始。
同时城市中存在M条道路将这N个路口相连接起来，
确保从一个路口到另一个路口都可达，
每条路由两个端点加上通行所需要的时间表示。
现在给定起始路口和目的路口，
从0时刻出发,请问最快能在什么时刻到达？

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int result;
struct node {
	int id, t;
	node() : id(0), t(0) {}
	node(int i, int t_) : id(i), t(t_) {}
};
vector<bool> path;

bool cmp(const struct node& a, const struct node& b) {
	return a.id < b.id;
}

bool judge(vector<node>& containerN, int id, int time) {
	int ans = time / containerN[id].t;
	if (ans % 2 == 0)
		return true;
	return false;
}

void bfs(vector<node>& containerN, vector<vector<int> >& edge, int id, int time, int n, int destination) {
	if (!judge(containerN, id, time))
		time += containerN[id].t - (time % containerN[id].t);
	for (int i = 0; i < n; i++) {
		if (edge[id][i] != -1 && path[i] == false) {
			if (i == destination) {
				if (result > time+edge[id][i])
					result = time + edge[id][i];
			}
			else {
				path[i] = true;
				bfs(containerN, edge, i, time + edge[id][i], n, destination);
				path[i] = false;
			}
		}
	}
}

int main() {
	int a, b, s;
	int destination;
	int i, j, n, m, t, id;
	vector<node> containerN;
	vector<vector<int> > edge;
	//cin >> n;
	scanf("%d", &n);
	edge.resize(n);
	path.resize(n);
	for (i = 0; i < n; i++) {
		path[i] = false;
		edge[i].resize(n);
		for (j = 0; j < n; j++)
			edge[i][j] = -1;
		//cin >> id >> t;
		scanf("%d,%d", &id, &t);
		containerN.push_back(node(id, t));
	}
	sort(containerN.begin(), containerN.end(), cmp);
	//cin >> m;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		//cin >> a >> b >> t;
		scanf("%d,%d,%d", &a, &b, &t);
		edge[a][b] = t;
		edge[b][a] = t;
	}
	//cin >> s >> destination;
	scanf("%d,%d", &s, &destination);
	//result = 10000000;
	result = INT_MAX;
	path[0] = true;
	bfs(containerN, edge, s, 0, n, destination);
	cout << result << endl;
	return 0;
}