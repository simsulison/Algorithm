#include<iostream>
#include<algorithm>
using namespace std;

int N;
int t[16];
int p[16];
int dp[16];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> t[i];
		cin >> p[i];
		if (i + t[i] <= N)
			dp[i] = p[i];
	}
	int res = -1;
	for(int i=0; i<N; i++)
	{
		int next = i + t[i];
		for(int j=next; j<N; j++)
		{
			if (j + t[j] <= N)
				dp[j] = max(dp[j], dp[i] + p[j]);
		}
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
	return (0);
}
