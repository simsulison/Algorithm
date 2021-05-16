#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<char, int> m;
vector<char> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;
        int len = s.length();
		for(int i=0; i<len; i++)
			m[s[i]]++;
		map<char ,int>::iterator iter;
		for(iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second % 2 != 0)
				v.push_back(iter->first);
		}
        cout << "#" << test_case << ' ';
        if (v.size() == 0)
            cout << "Good";
        else
        {
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++)
                cout << v[i];
        }
        cout << "\n";
		m.clear();
        v.clear();
	}
	return 0;
}