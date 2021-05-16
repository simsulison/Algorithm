#include<iostream>
using namespace std;
int R, C, K;
char map[6][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int res;
void dfs(int x, int y, int dist, bool visit[6][6])
{
	if (dist == K)
	{
		if (x == 0 && y == C - 1)
			res++;
		return;
	}	
	visit[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			continue;
		if (map[nx][ny] != 'T' && !visit[nx][ny])
		{
			bool tmp_visit[6][6];
			for(int j=0; j<R; j++)
			{
				for(int k=0; k<C; k++)
				{
					tmp_visit[j][k] = visit[j][k];
				}
			}
			dfs(nx, ny, dist + 1, tmp_visit);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> K;
	bool visit[6][6];
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			cin >> map[i][j];
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			visit[i][j] =false;
	dfs(R - 1, 0, 1, visit);
	printf("%d\n", res);
	return (0);
}
