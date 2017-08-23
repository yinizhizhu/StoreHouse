#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct pm {
	int time_up, pri, time_ned;
	pm(int tu, int p, int tn)
		: time_up(tu), pri(p), time_ned(tn) {}
}PM;

vector<PM> store;
unordered_map<int, vector<PM> > con;
typedef unordered_map<int, vector<PM> > PART;
typedef unordered_map<int, vector<PM> >::iterator ITR;

bool cmp1(PM& a, PM& b) {
	return a.time_up < b.time_up;
}

bool cmp2(PM a, PM b) {
	if (a.pri > b.pri)
		return true;
	return a.time_ned < b.time_ned;
}

void output(int t) {
	if (store.size()) {
		cout << (t + store[0].time_ned) << endl;
		store.erase(store.begin());
	}
}

void getN(int t) {
	int tag = 0, counter = 0;
	for (ITR tmp = con.begin(); !tag && tmp != con.end(); tmp++) {
		for (int i = 0, counter = 0; !tag && i < tmp->second.size(); i++) {
			if (tmp->second[i].time_up <= t) {
				tag = 1;
				counter++;
				store.push_back(PM(tmp->second[i].time_up, tmp->second[i].pri, tmp->second[i].time_ned));
				tmp->second.erase(tmp->second.begin());
			}
		}
	}
	for (ITR tmp = con.begin(); tmp != con.end();) {
		if (tmp->second.size() == 0) {
			con.erase(tmp);
			tmp = con.begin();
		}
		else
			tmp++;
	}
	if (tag && store.size())
		sort(store.begin(), store.end(), cmp2);
	output(t);
}

int main() {
	int i, m, n, p;
	int id, tu, pri, tn;
	cin >> n >> m >> p;
	for (i = 0; i < p; i++) {
		cin >> id >> tu >> pri >> tn;
		ITR tmp = con.find(id);
		if (tmp != con.end())
			tmp->second.push_back(PM(tu, pri, tn));
		else {
			vector<PM> an;
			an.push_back(PM(tu, pri, tn));
			con[id] = an;
		}
	}
	for (ITR tmp = con.begin(); tmp != con.end(); tmp++)
		sort(tmp->second.begin(), tmp->second.end(), cmp1);
	for (i = 1; con.size(); i++)
		getN(i);
	return 0;
}
