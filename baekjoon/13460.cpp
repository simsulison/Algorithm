#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
int ans = 987654321;

void m_move(pair<int, int> &K, int dir, char ch, char tmp_map[][11])
{
	int x = K.first;
	int y = K.second;
	while (1)
	{
		if (tmp_map[x][y] == 'O')
			break;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (tmp_map[nx][ny] == '#' || tmp_map[nx][ny] == ch)
			break;
		x = nx;
		y = ny;
	}
	tmp_map[K.first][K.second] = '.';
	if (tmp_map[x][y] != 'O')
	{
		if (ch == 'R')
			tmp_map[x][y] = 'B';
		else
			tmp_map[x][y] = 'R';
	}
	K = make_pair(x, y);
}

void solve(pair<int, int> R, pair<int, int> B, pair<int, int> O, bool visit[11][11][11][11], char map[11][11], int cnt)
{	
	if (B == O || cnt > 10)
		return ;
	else if (R == O)
	{
		ans = min(ans, cnt);
		return ;	
	}
	for(int i=0; i<4; i++)
	{
		pair<int, int> nR = R, nB = B;
		//상 하 좌 우
		int flag = 0;
		char tmp_map[11][11];
		for(int j=0; j<N; j++)
			for(int k=0; k<M; k++)
				tmp_map[j][k] = map[j][k];
		if (R.first == B.first) //현재 같은 행에 위치한 경우
		{
			if (i == 2)
			{
				if (R.second < B.second)
				{
					m_move(nR, i, 'B', tmp_map);
					m_move(nB, i, 'R', tmp_map);
				}
				else
				{
					m_move(nB, i, 'R', tmp_map);
					m_move(nR, i, 'B', tmp_map);
				}
				flag = 1;
			}
			else if (i == 3)
			{
				if (R.second < B.second)
				{
					m_move(nB, i, 'R', tmp_map);
                    m_move(nR, i, 'B', tmp_map);
				}
				else
				{
					m_move(nR, i, 'B', tmp_map);
                    m_move(nB, i, 'R', tmp_map);
				}
				flag = 1;
			}
		}
		else if (R.second == B.second) //같은 열에 위치한 경우
		{
			if (i == 0) 
			{
				if (R.first < B.first)
				{
					m_move(nR, i, 'B', tmp_map);
                    m_move(nB, i, 'R', tmp_map);
				}
				else
				{
					m_move(nB, i, 'R', tmp_map);
                    m_move(nR, i, 'B', tmp_map);
				}
				flag = 1;
			}
			else if (i == 1)
			{
				if (R.first < B.first)
				{
					m_move(nB, i, 'R', tmp_map);
                    m_move(nR, i, 'B', tmp_map);
				}
				else 
				{
					m_move(nR, i, 'B', tmp_map);
                    m_move(nB, i, 'R', tmp_map);
				}
				flag = 1;
			}
		}
		if (flag == 0)
		{
			m_move(nR, i, 'B', tmp_map);
          	m_move(nB, i, 'R', tmp_map);
		}
		if (!visit[nR.first][nR.second][nB.first][nB.second])
        {
        	visit[nR.first][nR.second][nB.first][nB.second] = true;
           	bool tmp_visit[11][11][11][11];
           	for(int k=0; k<N; k++)
            	for(int kk=0; kk<M; kk++)
                	for(int j=0; j<N; j++)
                    	for(int jj=0; jj<M; jj++)
                        	tmp_visit[k][kk][j][jj] = visit[k][kk][j][jj];
         	solve(nR, nB, O, tmp_visit, tmp_map, cnt + 1);
        }
	}	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	pair<int ,int> R;
	pair<int, int> B;
	pair<int, int> O;
	char map[11][11];
	for(int i=0; i<N; i++)
	{
		cin >> map[i];
		for(int j=0; j<M; j++)
		{
			if (map[i][j] == 'B')
				B = make_pair(i, j);
			else if (map[i][j] == 'R')
				R = make_pair(i, j);
			else if (map[i][j] == 'O')
				O = make_pair(i, j);
		}
	}
	bool visit[11][11][11][11];
	int cnt = 0;
	memset(visit, false, sizeof(visit));
	visit[R.first][R.second][B.first][B.second] = true;
	solve(R, B, O, visit, map, cnt);
	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return (0);
}
