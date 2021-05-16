#include<iostream>
#include<vector>
using namespace std;
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int map[5][5];
typedef struct fish
{
	int x;
	int y;
	int dir;
}fish;
fish shark;
fish f[17];
int res;

void dfs(fish f[17], int map[5][5], fish shark, int score)
{
	res = max(res, score);
	for (int i=1; i<= 16; i++)
	{
		int x = f[i].x;
		int y = f[i].y;
		int dir = f[i].dir;

		if (dir == -1)
			continue;

		int flag = 0;
		int nx, ny;
		int j;
		for(j=0; j<8; j++)
		{
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (nx <=0 || ny <=0 || nx > 4 || ny > 4)
			{
				f[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = f[i].dir;
				continue;
			}

			if (nx == shark.x && ny == shark.y)
			{
				f[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = f[i].dir;
				continue;
			}
			break;
		}
		if (j == 8)
			continue;

		int nidx = map[nx][ny];

		if (nidx > 0)
		{
			f[nidx].x = x;
			f[nidx].y = y;
			map[x][y] = nidx;
		}
		else
			map[x][y] = 0;

		f[i].x = nx;
		f[i].y = ny;
		map[nx][ny] = i;
	} //물고기 이동
	int sx = shark.x;
	int sy = shark.y;
	int sd = shark.dir;

	for(int i=1; i<=3; i++)
	{
		fish tmp[17];
		
		for(int j=1; j<=16; j++)
			tmp[j] = f[j];

		int tmp_map[5][5];

		for(int j=1; j<=4; j++)
			for(int k=1; k<=4; k++)
				tmp_map[j][k] = map[j][k];

		int nx = sx + dx[sd] * i;
		int ny = sy + dy[sd] * i;
		//map[nx][ny] == 0 물고기가 없는 경우
		if (nx <= 0 || ny <= 0 || nx > 4 || ny > 4 || map[nx][ny] == 0)
			continue;
		
		shark.x = nx;
		shark.y = ny;
		int num = tmp_map[nx][ny];
		tmp_map[nx][ny] = 0;
		shark.dir = tmp[num].dir;
		tmp[num].dir = -1;
	
		dfs(tmp, tmp_map, shark, score + num);
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=4; j++)
		{
			int num;
			fish tmp;
			cin >> num >> tmp.dir;
			tmp.x = i; tmp.y = j;
			f[num] = tmp;
			map[i][j] = num;
		}
	}
	res = map[1][1];
	shark.dir = f[res].dir;
	f[res].dir = -1;
	shark.x = 1; shark.y = 1;
	map[1][1] = 0; //상어
	dfs (f, map, shark, res);
	cout << res << "\n";
	return (0);
}
