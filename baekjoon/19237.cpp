#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int N, M, K;
int d[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
typedef struct shark
{
	int x, y, dir, num;
	vector<int> prio[5];
}shark;

typedef struct scent
{
	int k, num;
}scent;

int s_num;
scent s[21][21];
int map[21][21];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	vector<shark> v(M + 1);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
			{
				shark tmp;
				tmp.x = i; tmp.y = j; tmp.num = map[i][j];
				v[map[i][j]] = tmp;
			}
		}
	for(int i=1; i<=M; i++)
	{
		int dir;
		cin >> dir;
		v[i].dir = dir;
	}
	for(int i=1; i<=M; i++)
	{
		for(int k=1; k<=4; k++)
			for(int j=0; j<4; j++)
			{
				int pri;
				cin >> pri;
				v[i].prio[k].push_back(pri);
			}
	}
	for(int i=1; i<=M; i++)
	{
		int x = v[i].x;
		int y = v[i].y;
		scent tmp = {K, v[i].num};
		s[x][y] = tmp;
	}
	int time = 0;
	int shark_cnt = M;
	while(time <= 1000)
	{
		if (shark_cnt == 1)
		{
			printf("%d\n", time);
			return (0);
		}
		deque<shark> q;
		for(int i=1; i<=M; i++)
		{
			int x = v[i].x;
			int y = v[i].y;
			if (x == -1 && y == -1)
				continue;
			map[x][y] = 0;
			int dir = v[i].dir;
			int j;
			for(j=0; j<4; j++)
			{
				int n_dir = v[i].prio[dir][j];
				int nx = x + d[n_dir][0];
				int ny = y + d[n_dir][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (s[nx][ny].k == 0)
				{
					v[i].x = nx; v[i].y = ny;
					v[i].dir = n_dir;		
					q.push_back(v[i]);
					break;
				}
			}
			if (j == 4) //인접한 방향에 갈 곳이 없다면
			{
				for(int k=0; k<4; k++)
				{
					int nx = x + d[v[i].prio[dir][k]][0];
					int ny = y + d[v[i].prio[dir][k]][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;
					if (s[nx][ny].num == i)
					{
						v[i].x = nx; v[i].y = ny;
						v[i].dir = v[i].prio[dir][k];
						q.push_back(v[i]);
						break;
					}
				}
			}
		}
    	for(int i=0; i<N; i++)
    	{
        	for(int j=0; j<N; j++)
        	{
            	if (s[i][j].k != 0)
            	{
                	(s[i][j].k)--;
                	if (s[i][j].k == 0)
                    	s[i][j].num = 0;
            	}
        	}
    	}
		while (!q.empty())
		{
			shark f = q.front();
			q.pop_front();
			int x = f.x; int y = f.y;
			if (map[x][y] == 0 || map[x][y] == f.num)
			{
				map[x][y] = f.num;
				s[x][y].k = K; s[x][y].num = f.num;
			}
			else
			{
				if (map[x][y] > f.num)
				{
					v[map[x][y]].x = -1; v[map[x][y]].y = -1;
					map[x][y] = f.num;
					s[x][y].k = K; s[x][y].num = f.num;
				}
				else
				{
					v[f.num].x = -1; 
					v[f.num].y = -1;
				}
				shark_cnt--;
			}
		}
		time++;
	}
	printf("-1\n");
	return (0);
}
