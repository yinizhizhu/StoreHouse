#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int kmp(string& a, string& tmp, vector<int>& next);
void getNext(string& tmp, vector<int>& next);
void showNext(vector<int>& next);

int main()
{
	vector<int> next;
	string s = "abcabaaabaabcac";
	string a = "abaabcac";
	getNext(a, next);
	showNext(next);
	kmp(s, a, next);
	return 0;
}

int kmp(string& a, string& tmp, vector<int>& next)
{
	int i = 1, j = 1;
	int len1 = a.size(), len2 = tmp.size();
	while (i <= len1 && j <= len2)
	{
		if (j == 0 || a[i - 1] == tmp[j - 1])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > len2)
	{
		cout << "Match the string!" << endl;
		return true;
	}
	cout << "Match the nothing!" << endl;
	return false;
}

void getNext(string& tmp, vector<int>& next)
{
	int i = 1, j = 0;
	int len = tmp.size();
	cout << len << endl;
	next.resize(len + 1);
	next[i] = 0;
	while (i <= len)
	{
		if (i > 0 && (i - 1) < len && j > 0 && (j - 1) < len)
			cout << i << ", " << j << ": " << tmp[i - 1] << " " << tmp[j - 1] << endl;
		else
			cout << i << ", " << j << endl;
		if (j == 0 || tmp[i - 1] == tmp[j - 1])
		{
			++i;
			if (i > len)
				break;
			next[i] = ++j;
		}
		else
			j = next[j];
	}
	return;
}

void showNext(vector<int>& next)
{
	int i = 0, len = next.size();
	for (; i < len; i++)
		cout << next[i] << "	";
	cout << endl;
	return;
}