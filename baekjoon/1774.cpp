#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N, M;
typedef struct graph
{
	long v1, v2;
	double cost;
}graph;
vector<pair<int, int> > v;
vector<graph> g;

int getRoot(vector<int> &parent, int idx)
{
	if (parent[idx] == idx) return idx;
	else return parent[idx] = getRoot(parent, parent[idx]);
}

void merge(vector<int> &parent, int a, int b)
{
	a = getRoot(parent, a); b = getRoot(parent, b);
	if (a == b) return;
	else if (a < b) parent[b] = a;
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
	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for(int i=1; i<=N-1; i++)
	{
		for(int j=i+1; j<=N; j++)
		{
			long long x = v[i-1].first; long long y = v[i-1].second;
			long long nx = v[j-1].first; long long ny = v[j-1].second;
			graph tmp;
			tmp.cost = sqrt((x - nx)*(x - nx) + (y - ny)*(y - ny));
			tmp.v1 = i;
			tmp.v2 = j;
			g.push_back(tmp);
		}
	}
	vector<int> parent(N + 1);
	for(int i=1; i<=N; i++)
		parent[i] = i;
	for(int i=0; i<M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		merge(parent, v1, v2);
	}
	sort(g.begin(), g.end(), comp);
	double res = 0;
	for(int i=0; i<g.size(); i++)
	{
		int v1 = g[i].v1; int v2 = g[i].v2;
		if (getRoot(parent, v1) != getRoot(parent, v2))
		{
			merge(parent, v1, v2);
			res += g[i].cost;
		}
	}
	printf("%.2f\n", res);
	return (0);
}
