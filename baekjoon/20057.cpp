#include<iostream>
using namespace std;
int N;
int res = 0;
int map[500][500];
//좌 하 우 상
int mx[4][10] = {
	{-1, 1, -2, 2, 0, -1, 1, -1, 1, 0},
	{-1, -1, 0, 0, 2, 0, 0, 1, 1, 1}, 
	{-1, 1, -2, 2, 0, -1, 1, -1, 1, 0}, 
	{1, 1, 0, 0, -2, 0, 0, -1, -1, -1}
};
int my[4][10] = {
	{1, 1, 0, 0, -2, 0, 0, -1, -1, -1},
	{-1, 1, -2, 2, 0, -1, 1, -1, 1, 0},
	{-1, -1, 0, 0, 2, 0 ,0, 1, 1, 1},
	{-1, 1, -2 ,2, 0, -1 ,1, -1, 1, 0}
};
int rate[9] = {1, 1, 2, 2, 5, 7, 7, 10, 10};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void change_dir(int *dir)
{
	if (*dir == 0) *dir = 1;
	else if(*dir == 1) *dir =2;
	else if(*dir == 2) *dir =3;
	else
		*dir = 0;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	int x = N / 2;
	int y = N / 2;
	int idx = 0;
	for(int i=1; i<N; i++)
	{
		for(int loop = 0; loop <2; loop++)
		{
			for(int j =0; j<i; j++)
			{
				x = x + dx[idx];
				y = y + dy[idx];
				int cur = map[x][y];
				if (cur == 0)
					continue;	
				for(int k = 0; k <9; k++)
				{
					int nx = x + mx[idx][k];
					int ny = y + my[idx][k];
					int sand = (rate[k] * map[x][y]) / 100;
					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						res += sand;
					else
						map[nx][ny] += sand;
					cur -= sand;
				}
				int new_x = x + mx[idx][9];
				int new_y = y + my[idx][9];
				if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
					res += cur;
				else
					map[new_x][new_y] += cur;
				map[x][y] = 0;
			}
			change_dir(&idx);
		}
	}
	idx = 0;
	for(int j= 0; j< N - 1; j++)
    {
		x = x + dx[idx];
		y = y + dy[idx];
    	int cur = map[x][y];
		if (cur == 0) continue;
        for(int k = 0; k <9; k++)
        {
            int nx = x + mx[idx][k];
            int ny = y + my[idx][k];
            int sand = (rate[k] * map[x][y]) / 100;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                res += sand;
            else
                map[nx][ny] += sand;
            cur -= sand;
        }
        int new_x = x + mx[idx][9];
        int new_y = y + my[idx][9];
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
            res += cur;
        else
            map[new_x][new_y] += cur;
		map[x][y] = 0;
    }
	printf("%d\n", res);
	return (0);
}
