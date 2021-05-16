#include<iostream>
#include<deque>
#include<vector>
using namespace std;
deque<char> t[5];
deque<pair<int, int> > v; //톱니바퀴 번호, 회전 방향

void rotate(int n, int dir)
{
	if (dir == 1) //시계
	{
		char back = t[n].back();
		t[n].pop_back();
		t[n].push_front(back);
	}
	else if (dir == -1)
	{
		char front = t[n].front();
		t[n].pop_front();
		t[n].push_back(front);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for(int i=1; i<=4; i++)
	{
		for(int j=0; j<8; j++)
		{	
			char ch;
			cin >> ch;
			t[i].push_back(ch);
		}
	}
	int K;
	int t_num, dir;
	cin >> K;
	for(int i=0; i<K; i++)
	{
		cin >> t_num >> dir;
		if (t_num == 1)
		{
			v.push_back(make_pair(1, dir));
			if (t[1][2] == t[2][6])
				v.push_back(make_pair(2, 0));
			else
				v.push_back(make_pair(2, -dir));
			if (t[2][2] != t[3][6])
				v.push_back(make_pair(3, -v.back().second));
			else
				v.push_back(make_pair(3, 0));
			if (t[3][2] != t[4][6])
				v.push_back(make_pair(4, -v.back().second));
			else
				v.push_back(make_pair(4, 0));
		}
		else if (t_num == 2)
		{
			if (t[1][2] == t[2][6])
				v.push_back(make_pair(1, 0));
			else
				v.push_back(make_pair(1, -dir));
			v.push_back(make_pair(2, dir));
			if (t[2][2] == t[3][6])
				v.push_back(make_pair(3, 0));
			else
				v.push_back(make_pair(3, -dir));
			if (t[3][2] != t[4][6])
				v.push_back(make_pair(4, -v.back().second));
			else
				v.push_back(make_pair(4, 0));
		}
		else if (t_num == 3)
		{
			v.push_back(make_pair(3, dir));
			if (t[3][2] == t[4][6])
				v.push_back(make_pair(4, 0));
			else
				v.push_back(make_pair(4, -dir));
			if (t[2][2] != t[3][6])
				v.push_front(make_pair(2, -dir));
			else
				v.push_front(make_pair(2, 0));
			if (t[1][2] != t[2][6])
				v.push_front(make_pair(1, -v.front().second));
			else
				v.push_front(make_pair(1, 0));
		}
		else if (t_num == 4)
		{
			v.push_back(make_pair(4, dir));
			if (t[3][2] == t[4][6])
				v.push_front(make_pair(3, 0));
			else
				v.push_front(make_pair(3, -dir));
			if (t[2][2] != t[3][6])
				v.push_front(make_pair(2, -v.front().second));
			else
				v.push_front(make_pair(2, 0));
			if (t[1][2] != t[2][6])
				v.push_front(make_pair(1, -v.front().second));
			else
				v.push_front(make_pair(1, 0));
		}
		while (!v.empty())
		{
			pair<int, int> tmp = v.front();
			v.pop_front();
			rotate(tmp.first, tmp.second);
		}
	}
	int res = 0;
	if (t[1][0] == '1')
		res += 1;
	if (t[2][0] == '1')
		res += 2;
	if (t[3][0] == '1')
		res += 4;
	if (t[4][0] == '1')
		res += 8;
	printf("%d\n", res);
}
