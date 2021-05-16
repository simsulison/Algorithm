#include<iostream>
using namespace std;
int check_r[101][101];
int check_c[101][101];
int map[101][101];
int N, L;
int row_cnt()
{
	int cnt = 0;
	for(int i=0; i<N; i++)
	{
		int start = map[i][0];
		int flag = 0;
		for(int j=0; j<N; j++)
		{
			if (map[i][j] == start)
				continue;
			else if (abs(map[i][j] - start) >= 2)
			{
				flag = 1;
				break ;
			}
			else if (map[i][j] == start - 1)
			{
				for(int k=0; k<L; k++)
				{
					if (check_r[i][j+k] != 0 || map[i][j + k] != start - 1)
					{
						flag = 1;
						break ;
					}
					else
						check_r[i][j + k] = 1;
				}
				start = start - 1;
			}
			else if (map[i][j] == start + 1)
			{
				for(int k=0; k<L; k++)
				{
					if (j - k - 1 >= 0)
					{
						if (check_r[i][j-k-1] != 0 || map[i][j-k-1] != start)
						{
							flag = 1;
							break;
						}
						else
							check_r[i][j - k - 1] = 1;
					}
					else
					{
						flag = 1;
						break ;
					}
				}
				if (!flag)
					start = start + 1;
			}
		}
		if (!flag)
			cnt++; 
	}
	return (cnt);
}

int col_cnt()
{

	int cnt = 0;
	for(int i=0; i<N; i++)
	{
		int start = map[0][i];
		int flag = 0;
		for(int j=0; j<N; j++)
		{
			if (map[j][i] == start)
				continue;
			else if (abs(map[j][i] - start) >= 2)
			{
				flag = 1;
				break ;
			}
			else if (map[j][i] == start - 1)
			{
				for(int k=0; k<L; k++)
				{
					if (check_c[j+k][i] != 0 || map[j + k][i] != start - 1)
					{
						flag = 1;
						break ;
					}
					else
						check_c[j+k][i] = 1;
				}
				if(!flag)
					start = start - 1;
			}
			else if (map[j][i] == start + 1)
			{
				for(int k=0; k<L; k++)
				{
					if (j - k - 1 >= 0)
					{
						if (check_c[j - k - 1][i] != 0 || map[j - k - 1][i] != start)
						{
							flag = 1;
							break;
						}
						else
							check_c[j - k - 1][i] = 1;
					}
					else
					{
						flag = 1;
						break ;
					}
				}
				if (!flag)
					start = start + 1;
			}
		}
		if (!flag)
			cnt++;
	}
	return (cnt);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> L;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	int cnt = row_cnt();
	cnt += col_cnt();
	printf("%d\n", cnt);
	return (0);
}
