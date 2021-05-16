#include<iostream>
#include<deque>
using namespace std;
int N;
deque<int> dir;
deque<int> storage;
deque<int> temp;
int map[21][21];
int copy_map[21][21];
int res = 0;
void fill_map_r(int row, int col, int mode)
{
	while (!temp.empty())
    {
    	int value = temp.front();
        temp.pop_front();
        copy_map[row][col] = value;
		row += mode; //mode는 1 또는 -1
   	}
}

void fill_map_c(int row, int col, int mode)
{
	while (!temp.empty())
	{
		int value = temp.front();
		temp.pop_front();
		copy_map[row][col] = value;
		col += mode;
	}	
}

int make_tmp(int size, int ans)
{

	for(int j=0; j<size; j++)
    {
    	int cur = storage.front();
       	storage.pop_front();
        if (storage.size() != 0 && storage.front() == cur)
       	{
        	storage.pop_front();
            temp.push_back(cur * 2);
            ans = max(ans, cur * 2);
            j++;
        }
        else
       	{
        	temp.push_back(cur);
            ans = max(ans, cur);
       	}
    }
	return (ans);
}

void solve()
{
	int ans = 0;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			copy_map[i][j] = map[i][j];
	while (!dir.empty())
	{
		int cur_d = dir.front();
		dir.pop_front();
		if (cur_d == 0)
		{
			for(int i=1; i<=N; i++)
			{
				for(int j=1; j<=N; j++)
				{
					if (copy_map[j][i] != 0)
						storage.push_back(copy_map[j][i]);
					copy_map[j][i] = 0;
				}
				ans = make_tmp(storage.size(), ans);
				fill_map_r(1, i, 1);
			}
		}
		else if (cur_d == 1)
		{
			for(int i=1; i<=N; i++)
            {
                for(int j=N; j>=1; j--)
                {
                    if (copy_map[j][i] != 0)
                        storage.push_back(copy_map[j][i]);
					copy_map[j][i] = 0;
                }
                ans = make_tmp(storage.size(), ans);
                fill_map_r(N, i, -1);
            }
		}
		else if (cur_d == 2)
		{
			for(int i=1; i<=N; i++)
            {
                for(int j=1; j<=N; j++)
                {
                    if (copy_map[i][j] != 0)
                        storage.push_back(copy_map[i][j]);
					copy_map[i][j] = 0;
                }
				ans = make_tmp(storage.size(), ans);
                fill_map_c(i, 1, 1);
            }
		}
		else if (cur_d == 3)
		{
			for(int i=1; i<=N; i++)
            {
                for(int j=N; j>=1; j--)
                {
					if (copy_map[i][j] != 0)
						storage.push_back(copy_map[i][j]);
					copy_map[i][j] = 0;
                }
				ans = make_tmp(storage.size(), ans);
				fill_map_c(i, N, -1);
            }
		}
	}
	res = max(ans, res);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int k=0; k<4; k++)
				for(int l=0; l<4; l++)
					for(int m=0; m<4; m++)
					{
						dir.push_back(i);
						dir.push_back(j);
						dir.push_back(k);
						dir.push_back(l);
						dir.push_back(m);					
						solve();
					}
	printf("%d\n", res);
	return (0);
}
