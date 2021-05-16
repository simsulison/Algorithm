#include<iostream>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long min, max;
	cin >> min >> max;
	long long cnt = 0;
	for(long long i = min; i<= max; i++)
	{
		double res1 = sqrt(i);
		long long res2= sqrt(i);
		if (res1 != res2)
			cnt++;
	}
	cout << cnt << "\n";
	return (0);
}
