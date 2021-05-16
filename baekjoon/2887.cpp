#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
typedef long long ll;
typedef struct coor
{
	ll x,y,z;
	int idx;
}coor;

typedef struct graph
{
	int v1, v2;
	ll cost;
}graph;

vector<coor> v;
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

bool compX(coor a, coor b)
{
	return a.x < b.x;
}

bool compY(coor a, coor b)
{
	return a.y < b.y;
}

bool compZ(coor a, coor b)
{
	return a.z < b.z;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; i++)
	{
		coor c;
		cin >> c.x >> c.y >> c.z;
		c.idx = i + 1;
		v.push_back(c);
	}
	sort(v.begin(), v.end(), compX);
	for(int i=1; i<N; i++)
	{
		long long dist = min(min(abs(v[i-1].x - v[i].x), abs(v[i-1].y - v[i].y)), abs(v[i-1].z - v[i].z));
		graph tmp;
		tmp.v1 = v[i-1].idx;
		tmp.v2 = v[i].idx;
		tmp.cost = dist;
		g.push_back(tmp);
	}
	sort(v.begin(), v.end(), compY);
	for(int i=1; i<N; i++)
    {
        long long dist = min(min(abs(v[i-1].x - v[i].x), abs(v[i-1].y - v[i].y)), abs(v[i-1].z - v[i].z));
        graph tmp;
        tmp.v1 = v[i-1].idx;
        tmp.v2 = v[i].idx;
        tmp.cost = dist;
        g.push_back(tmp);
    }
	sort(v.begin(), v.end(), compZ);
	for(int i=1; i<N; i++)
    {
        long long dist = min(min(abs(v[i-1].x - v[i].x), abs(v[i-1].y - v[i].y)), abs(v[i-1].z - v[i].z));
        graph tmp;
        tmp.v1 = v[i-1].idx;
        tmp.v2 = v[i].idx;
        tmp.cost = dist;
        g.push_back(tmp);
    }
	sort(g.begin(), g.end(), comp);
	long long sum = 0;
	vector<int> parent(N + 1);
	for(int i=1; i<=N; i++)
		parent[i] = i;
	for(int i=0; i<g.size(); i++)
	{
		int v1 = g[i].v1; int v2 = g[i].v2;
		if (getRoot(parent, v1) != getRoot(parent, v2))
		{
			merge(parent, v1, v2);
			sum += g[i].cost;
		}
	}
	cout << sum << "\n";
	return (0);
}
