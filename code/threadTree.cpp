#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct node
{
	int value;
	int ltag, rtag;
	struct node *lChild, *rChild;
	node(int a) :value(a), ltag(0), rtag(0), lChild(NULL), rChild(NULL){}
} node;

void initT(node* root)	//get the full binary tree
{
	int i, len;
	int counter = 1, level = 2;
	node* newOne,* tmp = NULL;
	queue<node*> container;
	container.push(root);
	while (level > 0)
	{
		len = container.size();
		for (i = 0; i < len; i++)
		{
			tmp = container.front();
			container.pop();

			newOne = new node(++counter);
			tmp->lChild = newOne;
			container.push(newOne);
			newOne = new node(++counter);
			tmp->rChild = newOne;
			container.push(newOne);
		}
		level--;
	}
	return;
}

void inThread(node *&p, node *&pre)
{
	if (p)
	{
		inThread(p->lChild, pre);
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->ltag = 1;
		}
		if (pre && pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rtag = 1;
		}
		pre = p;
		inThread(p->rChild, pre);
	}
	return;
}

node *firstNode(node *T)//get the first node
{
	node *tmp = T;
	while (tmp->ltag == 0)
	{
		tmp = tmp->lChild;
	}
	return tmp;
}

node *nextNode(node *T)	//get the next node according to the current node.
{
	if (T->ltag == 0)
		return firstNode(T->rChild);
	else
		return T->rChild;
}

void inO(node *T)		//pass through the tree with inorder
{
	for (node *tmp = firstNode(T); tmp; tmp = nextNode(tmp))
		cout << tmp->value << " ";
	return;
}

void creatInThread(node *T)	//recreate the bT with threads.
{
	node *pre = NULL;
	if (T)
	{
		inThread(T, pre);
		pre->rChild = NULL;
		pre->rtag = 1;
	}
	return;
}

void show(node *T)		//it is easier to see the iner content of the tree.
{
	int i, len;
	node *tmp;
	queue<node*> container;
	container.push(T);
	while (!container.empty())
	{
		len = container.size();
		for (i = 0; i < len; i++)
		{
			tmp = container.front();
			container.pop();

			if (tmp->ltag == 0)
			{
				if (tmp->lChild)
					container.push(tmp->lChild);
				cout << "0";
			}
			else
			{
				if (tmp->lChild)
					cout << tmp->lChild->value;
				else
					cout << "0";
			}
			cout << " " << tmp->value << " ";
			if (tmp->rtag == 0)
			{
				if (tmp->rChild)
					container.push(tmp->rChild);
				cout << "0";
			}
			else
			{
				if (tmp->rChild)
					cout << tmp->rChild->value;
				else
					cout << "0";
			}
			cout << ", ";
		}
		cout << endl;
	}
}

int main()
{
	node* root = new node(1);
	initT(root);

	creatInThread(root);

	inO(root);
	cout << endl;

	show(root);
	return 0;
}