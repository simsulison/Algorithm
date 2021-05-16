#include<iostream>
#include<climits>
using namespace std;
int map[501][501];
int d[19][3][2]=
{
	{{0,1},{0,2},{0,3}},
	{{1,0},{2,0},{3,0}},

	{{0,1},{1,0},{1,1}},

	{{1,0},{2,0},{2,1}},
	{{1,0},{2,0},{2,-1}},
	{{0,1},{0,2},{1,0}},
	{{1,0},{1,1},{1,2}},
	{{0,1},{1,1},{2,1}},
	{{0,1},{1,0},{2,0}},
	{{0,1},{0,2},{-1,2}},
	{{0,1},{0,2},{1,2}},

	{{0,1},{0,2},{1,1}},
	{{0,1},{-1,1},{1,1}},
	{{0,1},{0,2},{-1,1}},
	{{1,0},{2,0},{1,1}},

	{{1,0},{1,1},{2,1}},
	{{0,1},{-1,1},{-1,2}},
	{{0,1},{1,1},{1,2}},
	{{1,0},{1,-1},{2,-1}}
};
int res = INT_MIN;
int main()
{
	int N, M;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> map[i][j];
	for(int i=0; i<19; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<M; k++)
			{
				int sum = map[j][k];
				int flag = 0;
				for(int l=0; l<3; l++)
				{
					int x1 = j + d[i][l][0]; int y1 = k + d[i][l][1];
					if (x1 < 0 || y1 < 0 || x1 >= N || y1 >= M)
					{
						flag = 1;
						break;
					}
					sum += map[x1][y1];
				}
				if(flag) continue;
				else res = max(res, sum);
			}
		}
	}
	printf("%d\n", res);
	return (0);
}
