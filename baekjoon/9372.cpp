#include<iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TestCase;
	cin >> TestCase;
	for(int i=0; i<TestCase; i++)
	{
		int N, M, tmp1, tmp2;
		cin >> N >> M;
		for(int j=0; j<M; j++)
			cin >> tmp1 >> tmp2;
		cout << N - 1 << "\n";
	}
}
