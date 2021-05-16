#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int N;
string s;
int res = INT_MIN;
int cal(int a, int b, char ch)
{
	if (ch == '+')
		return a+b;
	else if (ch == '-')
		return a-b;
	else if (ch == '*')
		return a*b;
	return (-1);
}

void dfs(int idx, int val)
{
	if (idx >= N)
	{
		res = max(res, val);
		return ;
	}
	char op = (idx != 0) ? s[idx - 1] : '+';
	int tmp = cal(val, s[idx] - '0', op);
	
	dfs(idx + 2, tmp); //괄호 안묶음
	if (idx < N - 2)
	{
		tmp = cal(s[idx] - '0', s[idx + 2] -'0', s[idx + 1]);
		tmp = cal(val, tmp, op);
		dfs(idx + 4, tmp); //괄호 묶음
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> s;
	dfs(0, 0);
	cout << res;
	return (0);
}
