#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V, E;
typedef struct graph
{
	int v1;
	int v2;
	int cost;
}graph;
vector<graph> v;

int getRoot(vector<int> &parent, int idx)
{
	/*
	int i;
	for(i = idx; i != parent[i]; i = parent[i]);
	return i;*/
	if (parent[idx] == idx) return idx;
	else
	{
		int root = getRoot(parent, parent[idx]);
		parent[idx] = root;
		return parent[idx];
	}
}

bool find(vector<int> parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	if (a == b) return true;
	else return false;
}

void my_union(vector<int> &parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool comp(graph a, graph b)
{
	return a.cost < b.cost;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	vector<int> parent(V + 1);
	for(int i=1; i<=V; i++)
		parent[i] = i;
	for(int i=0; i<E; i++)
	{
		graph g;
		cin >> g.v1 >> g.v2 >> g.cost;
		v.push_back(g);
	}
	sort(v.begin(), v.end(), comp);
	int sum = 0;
	for(int i=0; i<v.size(); i++)
	{
		if (getRoot(parent, v[i].v1) != getRoot(parent, v[i].v2))
		{
			my_union(parent, v[i].v1, v[i].v2);
			sum += v[i].cost;
		}
	}
	printf("%d\n", sum);
	return (0);
}
