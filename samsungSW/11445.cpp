#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string a;
    string b;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> a;
        cin >> b;
        int a_len = a.length();
        int b_len = b.length();
        if (a_len == b_len)
        {    
            printf("#%d Y\n", test_case);
        }
        else{
            int i;
            for(i = 0; i < a_len; i++)
            {
                if (a[i] != b[i])
                    break;
            }
            if (i == a_len)
            {
                if (b_len == a_len + 1 && b[b_len - 1] == 'a')
                {
                    printf("#%d N\n", test_case);
                    continue;
                }
            }
            printf("#%d Y\n", test_case);
        }
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}