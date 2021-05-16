#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int R, C, M;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
typedef struct shark{
	int x;
	int y;
	int s;
	int dir;
	int size;
	int num;
}shark;
typedef struct info
{
	int x;
	int y;
	int flag;
}info;
deque<shark> dq[101][101];
vector<info> v;
int change_dir(int dir)
{
	if (dir == 1) return (2);
	else if (dir == 2) return (1);
	else if (dir == 3) return (4);
	else if (dir == 4) return (3);
	return (0);
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> M;
	for(int i=0; i<M; i++)
	{
		shark sh;
		cin >> sh.x >> sh.y >> sh.s >> sh.dir >> sh.size;
		sh.num = i;
		if (sh.dir <= 2)
			sh.s %= ((R - 1) * 2);
		else
			sh.s %= ((C - 1) * 2);
		dq[sh.x][sh.y].push_back(sh);
		info in = {sh.x, sh.y, 0};
		v.push_back(in); //상어의 현재 위치
	}
	int idx = 0;
	int res = 0;
	while (++idx <= C) //종료조건
	{
		for(int i=1; i<=R; i++)
		{
			if (dq[i][idx].size() == 1)
			{
				shark tmp = dq[i][idx].front();
				dq[i][idx].pop_front();
				res += tmp.size;
				v[tmp.num].flag = 1; //상어 위치에서 제거
				break;
			}
		}
		for(int i=0; i<v.size(); i++)
		{
			if (v[i].flag != 1)
			{
				int cur_x = v[i].x;
				int cur_y = v[i].y;
				shark sh;
				sh = dq[cur_x][cur_y].front(); //새로운 상어를 넣을때는 dq의 뒤에 넣어줘야한다!!
				dq[cur_x][cur_y].pop_front();
				int nx = cur_x, ny = cur_y;
				for(int j=1; j<=sh.s; j++)
				{
					nx = nx + dx[sh.dir];
					ny = ny + dy[sh.dir];
					if (nx <= 0 || ny <= 0 || nx > R || ny > C)
					{
						sh.dir = change_dir(sh.dir);
						j = j - 2;
					}
				}//상어의 위치 계산
				if (dq[nx][ny].size() == 1)
				{
					if (dq[nx][ny].front().size < sh.size)
					{
						shark t;
						t = dq[nx][ny].front();
						dq[nx][ny].pop_front();
						v[t.num].flag = 1;
						dq[nx][ny].push_back(sh);
						v[sh.num].x = nx;
						v[sh.num].y = ny;
					}
					else
						v[sh.num].flag = 1;
				}
				else
				{
					dq[nx][ny].push_back(sh);
					v[sh.num].x = nx;
					v[sh.num].y = ny;
				}
			}
		}
	}
	printf("%d\n", res);
	return (0);
}
