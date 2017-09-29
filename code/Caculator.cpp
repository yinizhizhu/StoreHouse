100*(2+12)-(20/3)*2
100*(2-12)+(20/3)*(1-2)
10*(3+5*(5-5+1)*100+(5-9*(20-2)/2)*2*20/10)+1000
2/3-10
2+(2*4)
50/(50-20*2+1-9)*(10+12*12-12*10)
50*(50-20*2+1-9)*(10+12*12-12*10)/(1*2*3*4*5*6)
(1)+(1+2)+2*(1+3)
100*(2+12)-20/3*2
7*(8+2-(8/2+5*4))
3+((12+7*9)-15)
((5*(8+7)-5)+30*(7-6/3))*7
8/4*2
8/2*4

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
	if (c == ')') {
		for (; op.top() != '(';)
			step(num, op);
		op.pop();
		return;
	}
	if (op.empty() || op.top() == '(') {
		//cout << "New: " << c << endl;//
		op.push(c);
		return;
	}
	//cout << "Top: " << op.top() << " >> " << "New: " << c << endl;//
	for (; cmp(op.top(), c);) {		//For the order of calculating
		step(num, op);
		if (op.empty()) break;
	}
	op.push(c);
}

int getNum(char* line, int& i, int len) {
	int a;
	sscanf(line + i, "%d", &a);
	//cout << a << endl;//
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
		for (; line[i] == '('; i++)	//I's like to get many '(' continously
			op.push('(');
		num.push(getNum(line, i, len));
		for (; i < len;) {
			for (; line[i] == ')'; i++)	//It's the same with '('
				pushOp(num, op, line[i]);
			if (i >= len) break;
			pushOp(num, op, line[i++]);
			for (; line[i] == '('; i++)	//...
				op.push('(');
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
