#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
int map[11][11];
bool visit[11][11];
bool visit2[11][11];
int costs[11][11];
vector<pair<int, int> > v[7];
queue<pair<int, int> > q;
typedef struct graph{
	int v1, v2, cost;
}graph;
vector<graph> g;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init()
{
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
		{
			visit[i][j] = false;
			visit2[i][j] = false;
			costs[i][j] = 0;
		}
	}	
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

bool comp(graph a, graph b)
{
	return a.cost < b.cost;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> map[i][j];
	init();
	int idx = 1;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				map[i][j] = idx;
				visit[i][j] = true;
				v[idx].push_back(make_pair(i, j));
				while (!q.empty())
				{
					pair<int, int> coor = q.front();
					q.pop();
					for(int k=0; k<4; k++)
					{
						int nx = coor.first + dx[k];
						int ny = coor.second + dy[k];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M)
							continue;
						if (!visit[nx][ny] && map[nx][ny] == 1)
						{
							q.push(make_pair(nx, ny));
							visit[nx][ny] = true;
							map[nx][ny] = idx;
							v[idx].push_back(make_pair(nx, ny));
						}
					}
				}
				idx++;
			}
		}
	}
	//우랑 하만 체크
	for(int i = 1; i < idx; i++)
	{
		for(int j=0; j<v[i].size(); j++)
		{
			int x = v[i][j].first; int y = v[i][j].second; int cnt = 0;
			int tmp_x = x; int tmp_y = y;
			while (++tmp_x < N)
			{
				if (map[tmp_x][y] == map[x][y])
					break;
				if (map[tmp_x][y] == 0)
				{
					cnt++;
					continue;
				}	
				else if (map[tmp_x][y] != map[x][y])
				{
					if (cnt >= 2)
					{
						int v1 = map[x][y];
						int v2 = map[tmp_x][y];
						if (costs[v1][v2] == 0 && costs[v2][v1] == 0)
						{
							costs[v2][v1] = cnt;
							costs[v1][v2] = cnt;
						}
						else
						{
							costs[v1][v2] = min(costs[v1][v2], cnt);
							costs[v2][v1] = min(costs[v2][v1], cnt);
						}
					}
					break;
				}
			}
			cnt = 0;
			while (++tmp_y < M)
			{
				if (map[x][tmp_y] == map[x][y])
					break;
				if (map[x][tmp_y] == 0)
				{
					cnt++;
					continue;
				}
				else if (map[x][tmp_y] != map[x][y])
				{
					if (cnt >= 2)
					{
						int v1 = map[x][tmp_y];
                     	int v2 = map[x][y];
                     	if (costs[v1][v2] == 0 && costs[v2][v1] == 0)
                     	{
                        	 costs[v2][v1] = cnt;
                         	costs[v1][v2] = cnt;
                     	}
                     	else
                     	{
                         	costs[v1][v2] = min(costs[v1][v2], cnt);
                         	costs[v2][v1] = min(costs[v2][v1], cnt);
                     	}
					}
                    break;
				}
			}
		}
	}
	for(int i=1; i<idx-1; i++)
	{
		for(int j=i+1; j<idx; j++)
		{
			if (costs[i][j] != 0)
			{
				graph t;
				t.v1 = i;
				t.v2 = j;
				t.cost = costs[i][j];
				g.push_back(t);
			}
		}
	}
	sort(g.begin(), g.end(), comp);
	int sum = 0;
	vector<int> parent(idx);
	for(int i=1; i<idx; i++)
		parent[i] = i;
	int mst_cnt = 0;
	for(int i=0; i<g.size(); i++)
	{
		int v1 = g[i].v1; int v2 = g[i].v2;
		if (getRoot(parent, v1) != getRoot(parent, v2))
		{
			merge(parent, v1, v2);
			sum += g[i].cost;
			mst_cnt++;
		}
	}
	if (sum == 0 || mst_cnt != idx - 2)
		sum = -1;
	printf("%d\n", sum);
	return (0);
}
