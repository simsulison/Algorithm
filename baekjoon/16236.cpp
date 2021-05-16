#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int map[21][21];
int visit[21][21];
int c_map[21][21];
queue<pair<int, int> > q;
queue<pair<int, int> > v;
typedef struct shark{
	int x;
	int y;
	int size;
	int fishes;
}shark;

shark sh;
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
int check(int size)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			visit[i][j] = 0;
			if (map[i][j] != 0 && map[i][j] != -1 && map[i][j] < size)
				v.push(make_pair(i, j));
		}
	}
	if (v.size() == 0)
		return (1);
	return (0);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int x, y; //아기상어의 위치
	sh.size = 2;
	sh.fishes = 0; //현재 잡은 고기 
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				map[i][j] = -1;
				sh.x = i;
				sh.y = j;	
			}
		}
	}
	int time = 0;
	while (1)
	{
		if (check(sh.size)) //종료조건 + 현재 먹을 수 있는 물고기의 좌표들을 v에다가 저장한다. visit초기화
			break;
		q.push(make_pair(sh.x, sh.y));
		visit[sh.x][sh.y] = 1;
		for(int k=0; k<N; k++)
			for(int l=0; l<N; l++)
				c_map[k][l] = 0;
		int flag = 0;
		while(!q.empty())
		{
			pair<int, int> tmp = q.front();
			q.pop();
			for(int i=0; i<4; i++)
			{
				int nx = tmp.first + dx[i];
				int ny = tmp.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (map[nx][ny] != -1 && map[nx][ny] <= sh.size && visit[nx][ny] == 0)
				{
					if (map[nx][ny] != 0 && map[nx][ny] < sh.size)
						flag = 1;
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					if (c_map[nx][ny] == 0)
						c_map[nx][ny] = c_map[tmp.first][tmp.second] + 1;
					c_map[nx][ny] = min(c_map[nx][ny], c_map[tmp.first][tmp.second] + 1);
				}
			}
		}
		if (flag == 0)
			break;
		int minv = 987654321;
		int minx, miny;
		while (!v.empty())
		{
			pair<int, int> fish = v.front();
			v.pop();
			if (c_map[fish.first][fish.second] != 0)
			{
				if (minv > c_map[fish.first][fish.second])
				{
					minv = c_map[fish.first][fish.second];
					minx = fish.first;
					miny = fish.second;
				}
			}
		}
		time += minv;
		map[sh.x][sh.y] = 0;
		map[minx][miny] = -1;
		sh.x = minx;
		sh.y = miny;
		sh.fishes++;
		if (sh.fishes == sh.size)
		{
			sh.fishes = 0;
			sh.size++;
		}
	}
	printf("%d\n", time);
	return (0);
}
