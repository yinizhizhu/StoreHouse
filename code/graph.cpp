#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void initGraph(vector< vector<int> >& graph);
void showGraph(vector< vector<int> >& graph);
void floyd(vector< vector<int> >& graph);
void Dijkstra(vector< vector<int> >& graph, int i);
int main()
{
	vector< vector<int> > graph;
	initGraph(graph);

	for (int i = 0; i < 5; i++)
		Dijkstra(graph, i);

	floyd(graph);

	showGraph(graph);
	return 0;
}

void floyd(vector< vector<int> >& graph)
{
	int i, j, k;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((graph[i][k] && graph[k][j] && graph[i][k] < INT_MAX && graph[k][j] < INT_MAX) && (graph[i][k] + graph[k][j] < graph[i][j]))
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	return;
}

void Dijkstra(vector< vector<int> >& graph, int n)
{
	vector<int> s, dist, path;
	s.resize(5);
	dist.resize(5);
	path.resize(5);

	int i, j, tmp;
	for (i = 0; i < 5; i++)
	{
		s[i] = 0;
		dist[i] = graph[n][i];
	}
	s[n] = 1;

	for (j = 0; j < 4; j++)
	{
		tmp = -1;
		for (i = 0; i < 5; i++)
		{
			if (s[i] != 0)
				continue;
			if (tmp < 0)
				tmp = i;
			else if (dist[tmp] > dist[i])
				tmp = i;
		}
		s[tmp] = 1;
		//cout << dist[tmp] << endl;

		for (i = 0; i < 5; i++)
		{
			if (s[i] == 0)
			{
				if (graph[tmp][i] != INT_MAX && dist[tmp] + graph[tmp][i] < dist[i])
					dist[i] = dist[tmp] + graph[tmp][i];
			}
		}

	}
	for (i = 0; i < 5; i++)
		cout << dist[i] << "	";
	cout << endl;
	return;
}

void initGraph(vector< vector<int> >& graph)
{
	vector<int> tmp;
	tmp.resize(5);
	for (int i = 0; i < 5; i++)
		graph.push_back(tmp);
	showGraph(graph);

	graph[0][1] = 10;
	graph[0][2] = INT_MAX;
	graph[0][3] = INT_MAX;
	graph[0][4] = 5;

	graph[1][0] = INT_MAX;
	graph[1][2] = 1;
	graph[1][3] = INT_MAX;
	graph[1][4] = 2;

	graph[2][0] = INT_MAX;
	graph[2][1] = INT_MAX;
	graph[2][3] = 4;
	graph[2][4] = INT_MAX;

	graph[3][0] = 7;
	graph[3][1] = INT_MAX;
	graph[3][2] = 6;
	graph[3][4] = INT_MAX;

	graph[4][0] = INT_MAX;
	graph[4][1] = 3;
	graph[4][2] = 9;
	graph[4][3] = 2;
	showGraph(graph);
	return;
}

void showGraph(vector< vector<int> >& graph)
{
	cout << endl << "Current graph: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (graph[i][j] != INT_MAX)
				cout << graph[i][j] << "	";
			else
				cout << "-	";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
