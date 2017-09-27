100*(2+12)-(20/3)*2
100*(2-12)+(20/3)*(1-2)
10*(3+5*(5-5+1)*100+(5-9*(20-2)/2)*2*20/10)+1000
2/3-10
2+(2*4)
50/(50-20*2+1-9)*(10+12*12-12*10)
50*(50-20*2+1-9)*(10+12*12-12*10)/(1*2*3*4*5*6)
26*4-25/(125/25)
13+7*2-8
24*5-6
(37-9)/7
26*4
63-7+8/4
16*2/4+3
91+9*100
41*7/2
88-12+12*2
78*50-1440/12
3856/16+85*16
4000/(16+832/13)
(326+95*25)/37
(7236/18-228)*28
(4275-24*75)/25
45+15*6
6*5/2*4
30*3+8
400/4+20
10+12/3
(80/20+80)/4
70+(100-10*5)
1+9*8*7*6*5/4/3/2+12*(10+10*2)/3
100/4/(25/5)/2

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

void step(stack<int>& num, stack<char>& op) {
	char top = op.top();
	op.pop();
	int a, b;
	b = num.top();
	num.pop();
	a = num.top();
	num.pop();
	//cout << a << top << b << "=";//
	if (top == '+')
		a += b;
	else if (top == '-')
		a -= b;
	else if (top == '*')
		a *= b;
	else a /= b;
	//cout << a << endl;//
	num.push(a);
}

bool cmp(char top, char c) {
	if (top == '(') return false;
	if (top == '+' || top == '-') {
		if (c == '+' || c == '-')
			return true;
		return false;
	}
	return true;
}

void pushOp(stack<int>& num, stack<char>& op, char c) {
	if (op.empty()) {
		//cout << "New: " << c << endl;//
		op.push(c);
		return;
	}
	//cout << "Top: " << op.top() << ", " << "New: " << c << endl;//
	if (c == ')') {
		for (; op.top() != '(';)
			step(num, op);
		op.pop();
		return;
	}
	if (op.top() == '(') {
		op.push(c);
		return;
	}
	//cout << "-.0" << endl;
	for (; cmp(op.top(), c);) {
		step(num, op);
		if (op.empty()) break;
	}
	op.push(c);
}

int getNum(char* line, int& i, int len) {
	int a;
	sscanf(line + i, "%d", &a);
	////cout << a << endl;//
	for (; i < len && line[i] >= '0' && line[i] <= '9'; i++);
	return a;
}

int main() {
	stack<int> num;
	stack<char> op;
	char line[101];
	int i, len;
	for (; scanf("%s", line) != EOF;) {
		i = 0;
		len = strlen(line);
		if (line[i] == '(') {
			i++;
			op.push('(');
		}
		num.push(getNum(line, i, len));
		for (; i < len;) {
			if (line[i] == ')')
				pushOp(num, op, line[i++]);
			if (i >= len) break;
			pushOp(num, op, line[i++]);
			if (line[i] == '(') {
				i++;
				op.push('(');
			}
			num.push(getNum(line, i, len));
		}
		for (; !op.empty();)
			step(num, op);
		i = num.top();
		num.pop();
		//cout << "Empty: " << num.size() << endl;
		printf("%d\n", i);
	}
	return 0;
}
