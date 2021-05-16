#include<iostream>
#include<vector>
#define MAX -1000000001
#define MIN 1000000001
using namespace std;
int num[12];
vector<int>	v;

int cal(int fn ,int sn, int oper)
{
	if (oper == 1)
		return fn + sn;
	else if(oper == 2)
		return fn - sn;
	else if(oper == 3)
		return fn * sn;
	else if(oper == 4)
		return fn / sn;
	return (0);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	int r_max = MAX;
	int r_min = MIN;
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> num[i];
	for(int i=1; i<=4; i++)
	{
		int oper;
		cin >> oper;
		for(int j=0; j<oper; j++)
			v.push_back(i);
	}
	do
	{
		int idx = 2;
		int fn = num[1];
		int res;
		for(int i=0; i<v.size(); i++)
		{
			int sn = num[idx];
			res = cal(fn, sn, v[i]);
			fn = res;
			idx++;
		}
		r_min = (res < r_min) ? res : r_min;
		r_max = (res > r_max) ? res : r_max;
	}while(next_permutation(v.begin(), v.end()));
	printf("%d\n%d\n", r_max, r_min);
}
