#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> party[51];
int getRoot(vector<int> parent, int idx)
{
	if (parent[idx] == idx) return idx;
	else return getRoot(parent, parent[idx]);
}

bool find(vector<int> parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	if (a == b) return true;
	else return false;
}

void my_union(vector<int> &parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	parent[b] = a;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	vector<int> parent(N + 1);
	vector<int> knows;
	int know, people, num;
	for(int i=1; i<=N; i++)
		parent[i] = i;
	cin >> know;
	for(int i=0; i<know; i++)
	{
		cin >> num;
		knows.push_back(num);
	}
	for(int i=0; i<M; i++)
	{
		cin >> people;
		for(int j=0; j<people; j++)
		{
			cin >> num;
			party[i].push_back(num);
		}
	}
	for(int i=0; i<M; i++)
	{
		int v1 = party[i][0];
		for(int j=1; j<party[i].size(); j++)
		{
			int v2 = party[i][j];
			my_union(parent, v1, v2);
		}
	}
	int cnt = 0;
	for(int i=0; i<M; i++)
	{
		int flag = 0;
		for(int j=0; j<party[i].size(); j++)
		{
			if(flag) 
				break;
			int person = party[i][j];
			for(int k=0; k<knows.size(); k++)
			{
				if (find(parent, person, knows[k]) == true)
				{
					flag = 1;
					break;
				}
			}
		}
		if (!flag)
			cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}
