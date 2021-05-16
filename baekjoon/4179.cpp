#include <iostream>
#include <queue>
using namespace std;
int R, C;
char map[1001][1001];
bool visit[1001][1001];
int check[1001][1001];
int jx, jy;
vector<pair<int, int> > fire;
typedef struct s{
	int x;
	int y;
	char ch;
}s;
queue<s> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void init()
{
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
		{
			visit[i][j] = false;
			check[i][j] = -1;
		}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	init();
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				jx = i; jy = j;
			}
			else if (map[i][j] == 'F')
			{
				s tmp = {i, j, 'F'};
				visit[i][j] = true;
				check[i][j] = -1;
				q.push(tmp);
			}
		}
	s tmp1 = {jx, jy, 'J'};
	q.push(tmp1);
	visit[jx][jy] = true;
	check[jx][jy] = 0;
	int flag; 
	while (!q.empty())
	{
		flag = 0;
		s cur = q.front();
		q.pop();
		int x = cur.x; int y = cur.y;
		for(int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			{
				if (cur.ch == 'J')
				{
					printf("%d\n", check[x][y] + 1);
					return (0);
				}
				else
					continue;
			}
			if (map[nx][ny] == '.' && !visit[nx][ny] && check[nx][ny] == -1)
			{
				if (cur.ch == 'J')
					check[nx][ny] = check[x][y] + 1;
				visit[nx][ny] = true;
				s tmp2 = {nx, ny, cur.ch};
				q.push(tmp2);
				flag = 1;
			}
		}
	}
	if (!flag)
		printf("IMPOSSIBLE\n");
	return (0);
}
