#include<iostream>
using namespace std;
int N, M, H;
bool ladder[31][11];
int add;
bool finish;
void dfs(int cnt)
{
	if (finish)
		return;
	if (add == cnt) //몇개의 사다리를 추가했는지 
	{
		bool flag = true;
		for(int i=1; i<=N; i++)
		{
			int col = i;
			for(int j=1; j<=H; j++)
			{
				if (ladder[j][col])
					col++;
				else if (col > 1 && ladder[j][col - 1])
					col--;
			}
			if (i != col)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			finish = true;
		return;
		// i 번째 세로선에서 출발하여 i로 도착하는지 확인한다.
	}
	for(int i = 1; i <= H; i++)
	{
		for(int j=1; j<N; j++)
		{
			if (!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1])
			{
				ladder[i][j] = true; // 사다리 추가하고
				dfs(i, cnt + 1); // backtracking
				ladder[i][j] =false; // 사다리 빼기
			}
		}
	}
	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> H;

	for(int i=0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		ladder[x][y] = true;
	} //사다리 셋팅
	
	for(int i=0; i<=3; i++)
	{
		add = i; // 가로선 i개를 추가
		dfs(0); // 백트래킹
		if (finish)
		{
			cout << add << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}
