#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void heapSort(vector<int>& a);
void buildMaxHeap(vector<int>& a);
void adjustDown(vector<int>& a, int k, int len);

void quickSort(vector<int>& a, int head, int tail);
int partition(vector<int>& a, int head, int tail);
void show(vector<int>& a);

int main()
{
	vector<int> container;
	for (int i = 1; i <= 15; i++)
		container.push_back(i);
	show(container);
	buildMaxHeap(container);
	show(container);
	heapSort(container);
	show(container);
	return 0;
}

void heapSort(vector<int>& a)
{
	buildMaxHeap(a);
	int i, len = a.size() - 1;
	for (i = len; i > 1; i--)
	{
		swap(a[i], a[1]);
		adjustDown(a, 1, i - 1);
	}
	return;
}

void buildMaxHeap(vector<int>& a)
{
	int i, len = a.size() - 1;
	for (i = len / 2; i > 0; i--)
		adjustDown(a, i, len);
	return;
}

void adjustDown(vector<int>& a, int k, int len)
{
	int i;
	a[0] = a[k];
	for (i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && a[i] < a[i + 1])
			i++;
		if (a[0] >= a[i])
			break;
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];
	return;
}

void quickSort(vector<int>& a, int head, int tail)
{
	if (head < tail)
	{
		int pivot = partition(a, head, tail);
		quickSort(a, head, pivot - 1);
		quickSort(a, pivot + 1, tail);
	}
}

int partition(vector<int>& a, int head, int tail)
{
	int pivot = a[head];
	while (head < tail)
	{
		while (head < tail && a[tail] >= pivot)
			tail--;
		a[head] = a[tail];
		while (head < tail && a[head] <= pivot)
			head++;
		a[tail] = a[head];
	}
	a[head] = pivot;
	return head;
}

void show(vector<int>& a)
{
	int i = 0, len = a.size();
	cout << endl;
	for (i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
	return;
}