#include<iostream>

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
        long long N;
        long long cnt = 0;
        long long res = 1;
        cin >> N;
        for(long long x = N; x > 0; x >>= 1)
            if (x & 1)
                cnt++;
        res <<= cnt;
        printf("#%d %lld\n",test_case, N - res + 1);
	}
	return 0;
}