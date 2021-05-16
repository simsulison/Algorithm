#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
typedef struct graph
{
	int v1, v2;
	double cost;
}graph;
vector<graph> g;

bool comp(graph a, graph b)
{
	return a.cost < b.cost;
}

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

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<pair<double, double> > v;
	vector<int> parent(N + 1);
	for(int i=0; i<N; i++)
	{
		double a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	for(int i=0; i<N; i++)
		parent[i] = i;
	for(int i=0; i<N-1; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			double x = v[i].first; double y = v[i].second;
			double nx = v[j].first; double ny = v[j].second;
			graph tmp;
			tmp.v1 = i;
			tmp.v2 = j;
			tmp.cost = sqrt((x - nx)*(x - nx) + (y - ny)*(y - ny));
			g.push_back(tmp);
		}
	}
	sort(g.begin(), g.end(), comp);
	double res = 0;
	int cnt = 0;
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
