#include<iostream>
#include<deque>
using namespace std;
int R, C, T;
deque<int> dq[51][51];
int map[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
deque<int> machine;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> T;
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
				machine.push_back(i);
			dq[i][j].push_front(map[i][j]);
		}
	int time = 0;
	while (++time <= T)
	{
		for(int i=1; i<=R; i++)
		{
			for(int j=1; j<=C; j++)
			{
				if (map[i][j] != -1)
				{
					int tmp = dq[i][j].front();
					dq[i][j].pop_front();
					int cnt = 0;
					for(int k=0; k<4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx <= 0 || ny <= 0 || nx > R || ny > C 
								|| map[nx][ny] == -1)
							continue;
						dq[nx][ny].push_back(tmp / 5);
						cnt++;
					}
					tmp = tmp - (tmp / 5) * cnt;
					dq[i][j].push_front(tmp);
				}
			}
		}
		for(int i=1; i<=R; i++)
		{
			for(int j=1; j<=C; j++)
			{
				int dust_sum = 0;
				while (!dq[i][j].empty())
				{
					int dust = dq[i][j].front();
					dq[i][j].pop_front();
					dust_sum += dust;
				}
				dq[i][j].push_front(dust_sum);
			}
		} //먼지 이동
		int mx = machine.front();
		int my = 1;
		//공기청정기 작동
		for(int i=1; i<mx - 1; i++)
		{
			int move = dq[i][1].front();
			dq[i][1].pop_front();
			dq[i + 1][1].push_back(move);	
		}
		dq[mx - 1][1].pop_front();
		for(int i = C; i > 1; i--)
		{
				int move = dq[1][i].front();
				dq[1][i].pop_front();
				dq[1][i - 1].push_back(move);
		}
		for(int i = mx; i > 1; i--)
		{
				int move = dq[i][C].front();
				dq[i][C].pop_front();
				dq[i - 1][C].push_back(move);
		}
		dq[mx][2].push_back(0);
		for(int i = 2; i < C; i++)
		{
				int move = dq[mx][i].front();
				dq[mx][i].pop_front();
				dq[mx][i + 1].push_back(move);
		}
		mx = machine.back();
		dq[mx][2].push_back(0);
		for(int i = 2; i < C; i++)
        {
				int move = dq[mx][i].front();
            	dq[mx][i].pop_front();
            	dq[mx][i + 1].push_back(move);
        }
		for(int i = mx; i < R; i++)
		{
				int move = dq[i][C].front();
				dq[i][C].pop_front();
				dq[i + 1][C].push_back(move);
		}
		for(int i = C; i > 1; i--)
		{
				int move = dq[R][i].front();
				dq[R][i].pop_front();
				dq[R][i -1].push_back(move);
		}
		for(int i = R; i > mx + 1; i--)
		{
				int move = dq[i][1].front();
				dq[i][1].pop_front();
				dq[i - 1][1].push_back(move);
		}
		dq[mx + 1][1].pop_front();
	}
	int sum = 0;
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			if (!dq[i][j].empty() && map[i][j] != -1)
				sum += dq[i][j].front();
		}
	}
	printf("%d\n", sum);
	return (0);
}
