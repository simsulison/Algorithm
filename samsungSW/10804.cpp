#include<iostream>
#include<map>
using namespace std;

map<char, char> m;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>T;
    m['b'] = 'd';
    m['d'] = 'b';
    m['p'] = 'q';
    m['q'] = 'p';
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        cin >> s;
        int len = s.length();
        cout << "#" << test_case << " ";
        for(int i = len - 1; i>=0; i--)
        {
            cout << m[s[i]];
        }
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}