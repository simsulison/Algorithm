#include<iostream>
#include<algorithm>
using namespace std;

int N;
int main(int argc, char** argv)
{
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int x, y;
		int sum = 0;
		double d_num;
		int i_num;
		for(int i = 0; i<N; i++)
		{
			cin >> x >> y;
			double tmp = sqrt(x*x + y*y);
			if (tmp > 200)
				continue;
			for(int j=1; j<=10; j++)
			{
				if (tmp <= 20 * j)
				{
					sum += 10 - j + 1;
					break;
				}
			}
		}
		cout << "#" << test_case << ' ' << sum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}