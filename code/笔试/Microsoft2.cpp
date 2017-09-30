#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string rever(string& str) {
	string ans = "";
	int i = str.size() - 1;
	for (; i>=0; i--)
		ans += str[i];
	return ans;
}

vector<string> answerQeuries(int numWords, vector<string> words, int numQuestion, vector<int> question) {
	vector<string> ans;
	sort(words.begin(), words.end());
	int i;
	for (i = 0; i < numQuestion; i++) {
		switch (question[i])
		{
		case 1:
			ans.push_back(words[numWords - 1]);
			break;
		case 2:
			ans.push_back(words[0]);
			break;
		case 3:
			ans.push_back(words[1]);
			break;
		case 4:
			ans.push_back(words[numWords - 2]);
			break;
		case 5:
			words[0] = rever(words[0]);
			ans.push_back(words[0]);
			sort(words.begin(), words.end());
			break;
		default:
			break;
		}
	}
	return ans;
}

int main() {
	vector<string> words;
	words.push_back("abc");
	words.push_back("cde");
	words.push_back("fgh");
	vector<int> question;
	question.push_back(1);
	question.push_back(2);
	question.push_back(5);
	vector<string> ans = answerQeuries(3, words, 3, question);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	vector<string> words2;
	words2.push_back("ah");
	words2.push_back("cb");
	words2.push_back("ef");
	words2.push_back("gd");
	vector<int> q2;
	q2.push_back(1);
	q2.push_back(2);
	q2.push_back(3);
	q2.push_back(4);
	q2.push_back(5);
	q2.push_back(1);
	q2.push_back(2);
	q2.push_back(3);
	q2.push_back(4);
	vector<string> ans2 = answerQeuries(4, words2, 9, q2);
	for (int i = 0; i < ans2.size(); i++)
		cout << ans2[i] << " ";
	cout << endl;
	return 0;
}
