#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

typedef struct str {
	int index, tail;
	string line;
	string target;
	str(string s) {
		index = 0;
		line = s;
		target = "";
		getTar();
	}
	int calc(string& a) {
		if (a.size() != target.size())
			return 2;
		int ans = a.size(), i = ans - 1;
		for (; i >= 0; i--)
			if (a[i] == target[i])
				ans--;
		return ans;
	}
	void doIt() {
		string tmp = getNext();
		while (tmp.size()) {
			int res = calc(tmp);
			if (res <= 1 && res >= 0)
				cout << index - tmp.size() << endl;
			tmp = getNext();
		}
	}
	string getNext() {
		string ans = "";
		while (index < tail && line[index] == ' ') index++;
		for (; index < tail; index++) {
			if (line[index] == ' ')
				break;
			ans += line[index];
		}
		return ans;
	}
	void getTar() {
		string tmp = "";
		tail = line.size() - 1;
		for (; tail >= 0; tail--) {
			if (line[tail] == ' ')
				break;
			tmp += line[tail];
		}
		for (int i = tmp.size() - 1; i >= 0; i--)
			target += tmp[i];
	}
}STR;

int main()
{
	int t;
	string line, tmp;
	cin >> t;
	getchar();
	for (; t; t--) {
		getline(cin, line);
		STR s(line);
		s.doIt();
	}
	return 0;
}
