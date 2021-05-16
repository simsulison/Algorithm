#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N, Q, L;
int map[65][65];
bool visit[65][65];
bool map2[65][65];
queue<int> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt;
void rotate()
{
	if (L == 0)
		return ;
	for(int i=1; i<= (1 << N); i++)
		for(int j=1; j<= (1 << N); j++)
			q.push(map[i][j]);
	for(int k=1; k<= (1 << N); k += (1 << L)) //묶음 개수
	{
		for(int x=0; x<(1<<L); x++)
		{
			for(int i= (1 << L) - x; i<= (1 << N); i += (1 << L))
			{
				for(int l= 0; l < (1 << L); l++)
				{
					int tmp = q.front();
					q.pop();
					map[k + l][i] = tmp;
				}
			}
		}
	}
}

void dfs(int x, int y)
{
	visit[x][y] = 1;
	cnt++;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > (1 << N) || ny > (1 << N))
			continue;
		if (map[nx][ny] != 0 && !visit[nx][ny])
			dfs(nx, ny);
	}	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	int total = 0;
	int res = 0;
	for(int i=1; i<= (1 << N); i++)
		for(int j=1; j<= (1 << N); j++)
		{
			cin >> map[i][j];
			total += map[i][j];
			visit[i][j] = false;
		}
	for(int i=0; i<Q; i++)
	{
		cin >> L;
		rotate();
		for(int j=1; j<= (1<<N); j++)
			for(int k=1; k<= (1<<N); k++)
				map2[j][k] = false;
		for(int j=1; j<= (1<<N); j++)
		{
			for(int k=1; k<= (1<<N); k++)
			{
				if (map[j][k] > 0)
				{
					int flag = 0;
					for(int l=0; l<4; l++)
					{
						int nx = j + dx[l];
						int ny = k + dy[l];
						if (nx <= 0 || ny <= 0 || nx > 1<<N || ny > 1<<N)
							continue;
						if (map[nx][ny] > 0)
							flag++;
					}
					if (flag <= 2)
						map2[j][k] = true;
				}
			}
		}
		for(int j=1; j<= (1 <<N); j++)
			for(int k=1; k<= (1 <<N); k++)
				if(map2[j][k] == true)
				{
					map[j][k]--;
					total--;
				}
	}
	printf("%d\n", total);
	for(int i=1; i<=1 <<N; i++)
	{
		for(int j=1; j<=1 <<N; j++)
		{	
			if (!visit[i][j] && map[i][j] != 0)
			{
				cnt = 0;
				dfs(i, j);
			}
			res = max(res, cnt);
		}
	}
	printf("%d\n", res);
	return (0);
}
