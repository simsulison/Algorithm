#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, answer;

typedef struct graph
{
	int v1;
	int v2;
	int cost;
} graph;

vector<graph> v;

bool comp(graph a, graph b)
{
	return a.cost < b.cost;
}

int getRoot(vector<int> &parent, int idx)
{
	if (parent[idx] == idx) return idx;
	else
	{
		parent[idx] = getRoot(parent, parent[idx]);
		return parent[idx];
	}
}

void merge(vector<int> &parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(vector<int> parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	if (a == b) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N; cin >> M;
	vector<int> parent(N + 1);
	for(int i=1; i<=N; i++)
		parent[i] = i;
	for(int i=0; i<M; i++)
	{
		graph g;
		cin >> g.v1 >> g.v2 >> g.cost;
		v.push_back(g);
	}
	sort(v.begin(), v.end(), comp);
	for(int i=0; i<v.size(); i++)
	{
		if (!find(parent, v[i].v1, v[i].v2))
		{
			merge(parent, v[i].v1, v[i].v2);
			answer += v[i].cost;
		}
	}
	cout << answer << "\n";
	return (0);
}
