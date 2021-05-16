#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 987654321
using namespace std;
int N, M;
vector<pair<int, int> > virus;
vector<int> pick;
int map[51][51];
int check[51][51];
bool visit[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;
int empty_cnt;
int ans = MAX;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
			else if (map[i][j] == 0)
				empty_cnt++;
		}
	}
	for(int i=0; i<virus.size() - M; i++)
		pick.push_back(0);
	for(int i=0; i<M; i++)
		pick.push_back(1);
	do{
		int time = 0;
		int infect = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				check[i][j] = -1;
				visit[i][j] = false;
			}
		for(int i=0; i<pick.size(); i++)
		{
			if (pick[i] == 1)
			{
				int x = virus[i].first;
				int y = virus[i].second;
				check[x][y] = 0;
				q.push(make_pair(x, y));
				visit[x][y] = true;
			}
		}
		while (!q.empty())
		{
			pair<int, int> tmp = q.front();
			q.pop();
			for(int i=0; i<4; i++)
			{
				int nx = tmp.first + dx[i];
				int ny = tmp.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (map[nx][ny] != 1 && !visit[nx][ny])
				{
					visit[nx][ny] = true;
					if (check[nx][ny] == -1)
					{
						check[nx][ny] = check[tmp.first][tmp.second] + 1;
						if (map[nx][ny] == 0)
						{
							infect++;
							time = check[nx][ny];					
						}
						q.push(make_pair(nx, ny));
					}	
				}
			}
		}
		if (infect == empty_cnt)
			ans = min(ans, time);
	}while (next_permutation(pick.begin(), pick.end()));
	if (ans != MAX)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return (0);
}

