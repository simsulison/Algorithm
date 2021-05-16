#include<iostream>
#include<climits>
using namespace std;
int N, K;
int lines[10001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	long long sum = 0;
	for(int i=0; i<N; i++)
	{
		cin >> lines[i];
		sum += lines[i];
	}
	long long low = 0;
	long long high = INT_MAX;
	long long ans = -1;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		int cnt = 0;
		for(int i=0; i<N; i++)
			cnt += lines[i] / mid;
		if (cnt >= K)
		{
			low = mid + 1;
			ans = max(ans, mid);
		}
		else if (cnt < K)
			high = mid - 1;	
	}
	cout << ans << "\n";
	return (0);
}
