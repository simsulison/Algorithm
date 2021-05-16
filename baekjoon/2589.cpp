#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N, M;
char map[51][51];
bool visit[51][51];
int check[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int> > v;
void init()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			visit[i][j] = false;
			check[i][j] = -1;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'L')
				v.push_back(make_pair(i, j));
		}
	int ans = -1;
	for(int i=0; i<v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		init();
		queue<pair<int, int> > q;
		q.push(make_pair(x, y));
		visit[x][y] = true;
		check[x][y] = 0;
		int res = -1;
		while (!q.empty())
		{
			pair<int, int> tmp = q.front();
			q.pop();
			for(int j=0; j<4; j++)
			{
				int nx = tmp.first + dx[j];
				int ny = tmp.second + dy[j];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				if (map[nx][ny] == 'L' && !visit[nx][ny] && check[nx][ny] == -1)
				{
					visit[nx][ny] = true;
					check[nx][ny] = check[tmp.first][tmp.second] + 1;
					q.push(make_pair(nx, ny));
					res = max(res, check[nx][ny]);
				}
			}
		}
		ans = max(res, ans);
	}
	if (ans == -1)
		printf("0\n");
	else
		printf("%d\n", ans);
	return (0);
}
