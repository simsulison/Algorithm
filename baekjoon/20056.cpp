#include<iostream>
#include<deque>
using namespace std;

typedef struct ball
{
	int m;
	int s;
	int d;
}ball;
int N, M, K;
deque<ball> dq[51][51];
deque<ball> tmp[51][51];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0 ,-1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int a[4] = {0, 2, 4, 6};
int b[4] = {1, 3, 5, 7};
//새로 추가되는 것은 무조건 뒤로 원래 있던거는 앞에서 빼기
void cal_xy(int *nx, int *ny)
{
	*nx = (*nx <= 0) ? N + *nx : *nx;
  	*nx = (*nx > N) ? *nx - N : *nx;
   	*ny = (*ny <= 0) ? N + *ny : *ny;
 	*ny = (*ny > N) ? *ny - N : *ny;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for(int i=0; i<M; i++)
	{
		int x, y, m, s, d;
		ball b;
		cin >> x >> y >> b.m >> b.s >> b.d;
		dq[x][y].push_back(b);
	}
	for(int i=0; i<K; i++)
	{
		for(int j=1; j<=N; j++)
		{
			for(int k=1; k<=N; k++)
			{
				while (!dq[j][k].empty())
				{
					ball cur = dq[j][k].front();
					dq[j][k].pop_front();
					int nx, ny, ns, dir;
					dir = cur.d;
					ns = cur.s % N;
					nx = j + dx[dir] * ns;
					ny = k + dy[dir] * ns;
					cal_xy(&nx, &ny);
					tmp[nx][ny].push_back(cur);
				}
			}	
		}
		for(int j=1; j<=N; j++)
		{
			for(int k=1; k<=N; k++)
			{
				if (tmp[j][k].size() >= 2)
				{
					ball new_ball;
					int tmp_s = 0, tmp_m = 0, tmp_d = 0;
					int flag = 0;
					for(int l=0; l<tmp[j][k].size(); l++)
					{
						tmp_s += tmp[j][k][l].s;
						tmp_m += tmp[j][k][l].m;
						if (tmp[j][k][l].d % 2 == 0)
							tmp_d++;
					}
					new_ball.m = tmp_m / 5;
					new_ball.s = tmp_s / tmp[j][k].size();
					flag = (tmp_d == tmp[j][k].size() || tmp_d == 0) ? 0 : 1;
					if (new_ball.m != 0)
					{
						if (flag == 0) //다 짝수나 홀수
						{
							for(int l = 0; l<4; l++)
							{
								new_ball.d = a[l];
								dq[j][k].push_back(new_ball);
							}
						}
						else 
						{
							for(int l = 0; l<4; l++)
                       		{
								new_ball.d = b[l];
                            	dq[j][k].push_back(new_ball);
                        	}
						}
					}
					while (!tmp[j][k].empty())
						tmp[j][k].pop_front();
				}
				else
				{
					if (tmp[j][k].size() == 1)
					{
						dq[j][k].push_back(tmp[j][k].back());
						tmp[j][k].pop_back();
					}
				}
			}
		}
		/*
		for(int j = 1; j <= N; j++)
		{
			for(int k =1; k<= N; k++)
			{
				printf("[");
				for(int l=0; l<dq[j][k].size(); l++)
				{
					printf("%d", dq[j][k][l].m);
				}
				printf("] ");
			}
			printf("\n");
		}*/
	}
	int res = 0;
	for(int i = 1; i<=N; i++)
		for(int j=1; j<=N; j++)
			for(int l=0; l<dq[i][j].size(); l++)
				res += dq[i][j][l].m;
	printf("%d\n", res);
	return (0);
}
