#include<iostream>
#include<vector>
using namespace std;
int R, C, N;
char map[101][101];
bool  visit[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int> > cluster;
bool floor_check;
void init()
{
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
			visit[i][j] = false;
}

void dfs(int x, int y)
{
	visit[x][y] = true;
	if (x == R)
	{
		floor_check = true;
		return ;
	}
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > R || ny > C)
			continue;
		if (map[nx][ny] == 'x' && !visit[nx][ny])
		{
			visit[nx][ny] = true;
			cluster.push_back(make_pair(nx, ny));
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	int clus = 0;
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
			cin >> map[i][j];
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int h;
		int b_point = -1;
		cin >> h;
		h = R - h + 1;
		if (i % 2 == 0)
		{
			for(int j=1; j<=C; j++)
			{
				if (map[h][j] == 'x')
				{
					b_point = j;
					break;
				}
			}
		}
		else
		{
			for(int j=C; j>=1; j--)
			{
				if (map[h][j] == 'x')
				{
					b_point = j;
					break;
				}
			}
		}
		if (b_point == -1)
			continue;
		map[h][b_point] = '.'; //벽이 부숴진 곳을 기준으로 하여 dfs탐색
		for(int j=0; j<4; j++)
		{
			int nx = h + dx[j];
			int ny = b_point + dy[j];
			if (nx <= 0 || ny <= 0 || nx > R || ny > C)
				continue;
			if (map[nx][ny] == '.')
				continue;
			init();
			cluster.clear();
			floor_check = false;

			cluster.push_back(make_pair(nx, ny));
			dfs(nx, ny);
			if (floor_check) //클러스터 중 하나라도 바닥에 닿아 있다면?
				continue;

			while (1)
			{
				bool down = true;
				for(int k = 0; k < cluster.size(); k++)
					map[cluster[k].first][cluster[k].second] = '.';
				for(int k = 0; k < cluster.size(); k++)
				{
					int x = cluster[k].first + 1;
					int y = cluster[k].second;
					
					if (x == R + 1 || map[x][y] == 'x') //하나라도 닿았다면?
					{
						down = false;
						break;
					}
				}
				for(int k=0; k < cluster.size(); k++)
				{
					if (down)
						cluster[k].first++;
					map[cluster[k].first][cluster[k].second] = 'x';
				}
				if (!down)
					break;
			}
		}
	}
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return (0);
}
