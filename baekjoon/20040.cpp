#include <iostream>
#include <vector>
int N, M;
using namespace std;

int getRoot(vector<int> &parent, int idx)
{	
	if (parent[idx] == idx) return idx;
	else return parent[idx] = getRoot(parent, parent[idx]);
}

void merge(vector<int> &parent, int a, int b)
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);
	if (a == b) return;
	else if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	vector<int> parent(N + 1);
	for(int i=1; i<=N; i++)
		parent[i] = i;
	int i;
	for(i=0; i<M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		if (getRoot(parent, v1) != getRoot(parent, v2))
			merge(parent, v1, v2);
		else
		{
			printf("%d\n", i + 1);
			return (0);
		}
	}
	printf("0\n");
	return (0);
}
