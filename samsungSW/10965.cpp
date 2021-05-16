#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int ans = 1;
		cin >> N;
		for(int i=2; i * i <= N; i++)
		{
			int cnt = 0;
			while (N % i == 0){
				cnt++;
				N /= i;
			}
			if (cnt % 2 != 0)
				ans *= i;
		}
		if (N > 1)
			ans *= N;
		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}