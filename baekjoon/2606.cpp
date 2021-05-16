#include<iostream>
using namespace std;
int N, M;
bool d[101][101];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> M;
	for(int i=0; i<M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		d[v1][v2] = true;
		d[v2][v1] = true;
	}
	for(int k=1; k<=N; k++)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				if (d[i][k] && d[k][j])
					d[i][j] = true;
			}
		}
	}
	int cnt = 0;
	for(int i=2; i<=N; i++)
	{
		if (d[1][i])
			cnt++;
	}
	cout << cnt << "\n";
	return (0);
}
