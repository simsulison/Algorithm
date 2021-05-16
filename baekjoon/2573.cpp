#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int map[301][301];
int melt[301][301];
bool visit[301][301];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int> > v;

void dfs(int x, int y)
{
	visit[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && ny > 0 && nx <= N && ny <= M)
		{
			if (map[nx][ny] != 0 && !visit[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
				v.push_back(make_pair(i, j));
		}
	}
	int time = 0;
	while (++time)
	{
		for(int i=1; i<=N; i++)
			for(int j=1; j<=M; j++)
			{
				melt[i][j] = 0;
				visit[i][j] = false;
			}
		int len = v.size();
		for(int i=0; i<len; i++)
		{	
			int x = v[i].first;
			int y = v[i].second;
			if (x == -1 && y == -1)
				continue;
			int cnt = 0;
			for(int k=0; k<4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx > 0 && ny > 0 && nx <= N && ny <= M)
				{
					if (map[nx][ny] == 0)
						cnt++;
				}
			}
			melt[x][y] = cnt;
		}
		/*printf("melt\n");
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				printf("%d ", melt[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		for(int i=0; i<len; i++)
		{
			int x = v[i].first;
			int y = v[i].second;
			if (x == -1 && y == -1)
				continue;
			map[x][y] = (map[x][y] - melt[x][y] <= 0) ? 0 : map[x][y] - melt[x][y];
			if (map[x][y] == 0)
				v[i] = make_pair(-1, -1);
		}
		/*printf("%d\n", time);
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		int cnt = 0;
		int find = 0;
		for(int i=2; i<=N; i++)
		{
			for(int j=2; j<=M; j++)
			{
				if (map[i][j] != 0 && !visit[i][j])
				{
					dfs(i, j);
					cnt++;
					if (cnt == 2)
					{
						find = 1;
						break; 
					}
				}
			}
			if (find)
				break;
		}
		if (cnt == 0)
		{
			printf("0\n");
			return (0);
		}
		if (find)
		{
			printf("%d\n", time);
			return (0);
		}
	}
}
