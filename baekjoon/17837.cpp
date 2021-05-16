#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int N, K;
int map[13][13];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

typedef struct horse
{
	int x;
	int y;
	int dir;
	int num;
}horse;
vector<pair<int, int> > locate; //n 번째 말의 현재 위치를 저장하고 있다.
deque<horse> dq[13][13];

int change_dir(int dir)
{
	if (dir == 1) return (2);
	else if (dir == 2) return (1);
	else if (dir == 3) return (4);
	else if (dir == 4) return (3);
	return (-1);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];
	locate.push_back(make_pair(0, 0));
	for(int i=1; i <= K; i++)
	{
		horse h;
		cin >> h.x >> h.y >> h.dir;
		h.num = i;
		dq[h.x][h.y].push_back(h);
		locate.push_back(make_pair(h.x, h.y));
	}
	int turn = 0;
	while (++turn <= 1000)
	{
		printf("%d\n", turn);
		for(int i = 1; i <= K; i++) //첫번째 말이 움직일 차례
		{
			int curx = locate[i].first;
			int cury = locate[i].second;
			int curd;
			int pos;
			int size = dq[curx][cury].size();
			for(pos = 0; pos < size; pos++)
			{
				if (i == dq[curx][cury][pos].num)
				{
					curd = dq[curx][cury][pos].dir;
					break;
				}
			}
			deque<horse> tmp;
			for(int j = 0; j <= pos; j++)
			{
				tmp.push_back(dq[curx][cury].front());
				dq[curx][cury].pop_front();
			}
			int nx = curx + dx[curd];
			int ny = cury + dy[curd];
			if (nx <= 0 || ny <= 0 || nx > N || ny > N || map[nx][ny] == 2)
			{
				int newd = change_dir(curd);
				tmp[pos].dir = newd;
				nx = curx + dx[newd];
				ny = cury + dy[newd];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N || map[nx][ny] == 2)
				{
					while (!tmp.empty())
					{
						dq[curx][cury].push_front(tmp.back()); //가만히 있는 경우 
						locate[tmp.back().num] = make_pair(curx, cury);
						tmp.pop_back();
					}
					if (dq[curx][cury].size() >= 4)
					{
						printf("%d\n", turn);
						return (0);
					}
				}
				else
				{
					if (map[nx][ny] == 0)
					{
						while (!tmp.empty())
						{
							dq[nx][ny].push_front(tmp.back());
							locate[tmp.back().num] = make_pair(nx, ny);
							tmp.pop_back();
						}
					}
					else
					{
						while (!tmp.empty())
						{
							dq[nx][ny].push_front(tmp.front());
							locate[tmp.front().num] = make_pair(nx, ny);
							tmp.pop_front();
						}
					}
					if (dq[nx][ny].size() >= 4)
					{
						printf("%d\n", turn);
						return (0);
					}
				}
			}
			else
			{
				if (map[nx][ny] == 0) //흰색
				{
					while (!tmp.empty())
					{
						dq[nx][ny].push_front(tmp.back());
						locate[tmp.back().num] = make_pair(nx, ny);
						tmp.pop_back();
					}
				}
				else if (map[nx][ny] == 1) //빨강
				{
					while (!tmp.empty())
					{
						dq[nx][ny].push_front(tmp.front());
						locate[tmp.front().num] = make_pair(nx, ny);
						tmp.pop_front();
					}
				}
				if (dq[nx][ny].size() >= 4)
				{
					printf("%d\n", turn);
					return (0);
				}
			}
		}
	}
	printf("-1\n");
	return (0);
}
