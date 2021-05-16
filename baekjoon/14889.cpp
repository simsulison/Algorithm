#include<iostream>
#include<stdio.h>
#include<vector>
#define MAX 987654321
using namespace std;
int N;
int map[21][21];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];
	vector<int> pick;
	for(int i=0; i<N/2; i++)
		pick.push_back(0);
	for(int i=0; i<N/2; i++)
		pick.push_back(1);
	int min = MAX;
	do{
		vector<int> a;
		vector<int> b;
		for(int i=0; i<pick.size(); i++)
		{
			if (pick[i] == 1)
				a.push_back(i + 1);
			else
				b.push_back(i + 1);
		}
		int res_a = 0;
		int res_b = 0;
		for(int i=0; i < a.size(); i++)
		{
			for(int j= i + 1; j < a.size(); j++)
			{
				res_a += map[a[i]][a[j]];
				res_a += map[a[j]][a[i]];
			}
		}
		for(int i=0; i < b.size(); i++)
		{
			for(int j= i+1; j < b.size(); j++)
			{
				res_b += map[b[i]][b[j]];
				res_b += map[b[j]][b[i]];
			}
		}
		if (min > abs(res_a - res_b))
			min = abs(res_a - res_b);
	}while(next_permutation(pick.begin(), pick.end()));
	printf("%d\n", min);
	return (0);
}
