#include<iostream>
#include<queue>
using namespace std;
int N, K;
typedef struct robot
{
	int n; //내구도
	int r_flag; //로봇의 존재
}robot;

deque<robot> negudo;

void rotate()
{
	robot tmp;
	tmp = negudo.back();
	negudo.pop_back();
	negudo.push_front(tmp);
}

int check()
{
	int cnt = 0;
	for(int i=0; i<negudo.size(); i++)
	{
		if (negudo[i].n == 0)
			cnt++;
	}
	if (cnt >= K)
		return (1);
	return (0);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for(int i=0; i<2*N; i++)
	{
		int a;
		cin >> a;
		robot r;
		r.n = a;
		r.r_flag = 0;
		negudo.push_back(r);
	}
	int turn = 1;
	deque<int> v;
	while(1)
	{
		rotate();
		if (negudo[N - 1].r_flag == 1)
			negudo[N - 1].r_flag = 0;
		for(int i=0; i < N - 1; i++)
        {
			if (negudo[i].r_flag == 1)
				v.push_back(i);
		}
		while (!v.empty())
		{
			int idx = v.back();
			v.pop_back();
			if (negudo[idx + 1].n != 0 && negudo[idx + 1].r_flag == 0)
            {
            	negudo[idx].r_flag = 0;
                negudo[idx + 1].n = negudo[idx + 1].n - 1;
               	negudo[idx + 1].r_flag = 1;
            }
		}
		if (negudo[N - 1].r_flag == 1)
			negudo[N - 1].r_flag = 0;
		if (negudo[0].n != 0 && negudo[0].r_flag == 0)
		{
			negudo[0].r_flag = 1; //로봇 올리고
			negudo[0].n = negudo[0].n - 1; //내구도 하나 감소
		}
		if (check())
			break;
		turn++;
	}
	printf("%d\n", turn);
	return (0);
}
