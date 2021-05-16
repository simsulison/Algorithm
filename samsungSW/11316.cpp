#include<iostream>
#include<vector>
using namespace std;

char map[21][21];
vector< pair<int, int> > v;
int N;

int check(int x, int y)
{
	int cnt = 0;
	for(int i = y; i < y + 5; i++)
	{
		if (i >= N)
			break ;
		if (map[x][i] == 'o')
			cnt++;
		else
			break;
	}
	if (cnt == 5)
		return (1);	
	cnt = 0;
	for(int i = x; i < x + 5; i++)
	{
		if (i >= N)
			break ;
		if (map[i][y] == 'o')
			cnt++;
		else
			break;
	}
	if (cnt == 5)
		return (1);
	cnt = 0;
	for(int i = 0; i<5; i++)
	{
		if (x + i >= N || y + i >= N)
			break;
		if (map[x+i][y+i] == 'o')
			cnt++;
		else
			break;
	}
	if (cnt == 5)
		return (1);
	cnt = 0;
	for(int i=0; i<5; i++)
	{
		if (x + i >= N || y - i < 0)
			break;
		if (map[x + i][y - i] == 'o')
			cnt++;
		else
			break;
	}
	if (cnt == 5)
		return (1);
	return (0);
}

void solve(int test_case)
{
	for(int i=0; i<v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		if (check(x, y))
		{
			printf("#%d YES\n", test_case);
			return ;
		}
	}
	printf("#%d NO\n", test_case);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for(int i=0; i< N; i++)
			cin >> map[i];
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if (map[i][j] == 'o')
					v.push_back(make_pair(i, j));
			}
		}
		solve(test_case);
		v.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}