#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[21][21];
bool visit[21][21];
bool visit2[21][21];
int check[21][21];
int check2[21][21];
typedef struct taxi
{
	int x;
	int y;
	int fuel;
}taxi;

typedef struct users
{
	int sx;
	int sy;
	int fx;
	int fy;
	int user_id;
}users;
taxi t;
vector<users> user;
queue<pair<int, int> > q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N,	M, fuel;

bool comp(users s1, users s2)
{
	if (s1.sx == s2.sx)
		return (s1.sy < s2.sy);
	else
		return (s1.sx < s2.sx);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> t.fuel;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];
	cin >> t.x >> t.y;
	for(int i=1; i<=M; i++)
	{
		users u;
		int sx, sy, fx, fy;
		cin >> u.sx >> u.sy >> u.fx >> u.fy;
		u.user_id = i;
		user.push_back(u);
	}
	sort(user.begin(), user.end(), comp);
	int iter = 0;
	while (iter < M)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				visit[i][j] = false;
				check[i][j] = -1;
				check2[i][j] = -1;
				visit2[i][j] = false;
			}
		}
		q.push(make_pair(t.x, t.y));
		visit[t.x][t.y] = true;
		check[t.x][t.y] = 0;
		while (!q.empty())
		{
			pair<int , int> tmp = q.front();
			q.pop();
			for(int i=0; i<4; i++)
			{
				int nx = tmp.first + dx[i];
				int ny = tmp.second + dy[i];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N)
					continue;
				if (!visit[nx][ny] && map[nx][ny] != 1)
				{
					visit[nx][ny] = true;
					if (check[nx][ny] == -1)
						check[nx][ny] = check[tmp.first][tmp.second] + 1;
					//else
					//	check[nx][ny] = min(check[nx][ny], check[tmp.first][tmp.second] + 1);
					q.push(make_pair(nx, ny));
				}
			}
		}
		int min_dist = 987654321;
		int min_idx = -1;
		for(int i=0; i<user.size(); i++) //가장 짧은 것
		{
			int x = user[i].sx;
			int y = user[i].sy;
			if (check[x][y] != -1 && min_dist > check[x][y])
			{
				min_dist = check[x][y];
				min_idx = i;
			}
		}
		if (min_idx == -1)
		{
			printf("-1\n");
			return (0);
		}
		int fin_x = user[min_idx].fx; //목적지 x
		int fin_y = user[min_idx].fy; //목적지 y
		q.push(make_pair(user[min_idx].sx, user[min_idx].sy));
		int f_flag = 0;
		check2[user[min_idx].sx][user[min_idx].sy] = 0;
		while (!q.empty())
		{
			pair<int ,int> tmp2 = q.front();
			q.pop();
			for(int i=0; i<4; i++)
			{
				int nx = tmp2.first + dx[i];
				int ny = tmp2.second + dy[i];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N)
					continue;
				if (map[nx][ny] != 1 && !visit2[nx][ny])
				{
					visit2[nx][ny] = true;
					if (check2[nx][ny] == -1)
						check2[nx][ny] = check2[tmp2.first][tmp2.second] + 1;
					else
						check2[nx][ny] = min(check2[nx][ny], check2[tmp2.first][tmp2.second] + 1);
					if (fin_x == nx && fin_y == ny)
					{
						f_flag = 1;
						break;
					}
					q.push(make_pair(nx, ny));			
				}
			}
			if (f_flag)
				break;
		}
		if (check2[fin_x][fin_y] == -1)
		{
			printf("-1\n");
			return (0);
		}
		int dist = check2[fin_x][fin_y];
		t.fuel -= (dist + min_dist); //손님 태우는 거리 + 목적지 가는 거리
		if (t.fuel < 0)
		{
			printf("-1\n");
			return (0);
		}
		else
		{
			t.fuel += 2 * dist;
			t.x = fin_x;
			t.y = fin_y;
			user.erase(user.begin() + min_idx, user.begin() + min_idx + 1); //그 유저 삭제
		}
		while(!q.empty())
			q.pop();
		iter++;
	}
	printf("%d\n", t.fuel);
	return (0);
}
