#include<iostream>
#include<climits>
using namespace std;
int N, M;
int tree[1000001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0; i<N; i++)
		cin >> tree[i];
	long long  low = 0;
	long long  high = INT_MAX;
	long long  ans = -1;
	while (low <= high)
	{
		long long  mid = (low + high) / 2;
		long long  sum = 0;
		for(int i=0; i<N; i++)
		{
			if (tree[i] > mid)
				sum += (tree[i] - mid);
		}
		if (sum >= M)
		{
			low = mid + 1;
			ans = max(ans, mid);
		}
		else
			high = mid - 1;
	}
	cout << ans << "\n";
	return (0);
}
