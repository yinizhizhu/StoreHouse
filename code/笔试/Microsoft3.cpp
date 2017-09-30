#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int tag[51];

int leaveNotFound(int sizeofApprovalLog, int numRequests, int *leaveRequests) {
	int i, ans = 0, tmp;
	queue<int> con;
	for (i = 1; i < 51; i++) tag[i] = 0;
	for (i = 0; i < numRequests; i++) {
		tmp = leaveRequests[i];
		if (tag[tmp] == 0) {
			ans++;
			tag[tmp] = 1;
			if (con.size() >= sizeofApprovalLog) {
				tag[con.front()] = 0;
				con.pop();
				con.push(tmp);
			}
			else
				con.push(tmp);
		}
	}
	return ans;
}

int main() {
	int* con = new int[6];
	con[0] = 1;
	con[1] = 2;
	con[2] = 1;
	con[3] = 3;
	con[4] = 1;
	con[5] = 2;
	for (int i = 0; i < 6; i++)
		cout << con[i] << " ";
	cout << endl;
	cout << leaveNotFound(2, 6, con) << endl;
	delete[]con;

	//int* con = new int[16];
	//con[0] = 7;
	//con[1] = 0;
	//con[2] = 1;
	//con[3] = 2;
	//con[4] = 0;
	//con[5] = 3;
	//con[6] = 0;
	//con[7] = 4;
	//con[8] = 2;
	//con[9] = 3;
	//con[10] = 0;
	//con[11] = 3;
	//con[12] = 2;
	//con[13] = 1;
	//con[14] = 2;
	//con[15] = 0;
	//for (int i = 0; i < 16; i++)
	//	cout << con[i] << " ";
	//cout << endl;
	//cout << leaveNotFound(3, 16, con) << endl;
	//delete[]con;

	//int* con = new int[9];
	//con[0] = 2;
	//con[1] = 3;
	//con[2] = 1;
	//con[3] = 3;
	//con[4] = 2;
	//con[5] = 1;
	//con[6] = 4;
	//con[7] = 3;
	//con[8] = 2;
	//for (int i = 0; i < 9; i++)
	//	cout << con[i] << " ";
	//cout << endl;
	//cout << leaveNotFound(2, 9, con) << endl;
	//delete[]con;
	return 0;
}

