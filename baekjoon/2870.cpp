#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> strarr;
bool comp(string s1, string s2)
{
	if (s1.size() < s2.size())
		return true;
	else if (s1.size() == s2.size())
		if (s1 < s2) return true;
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
    cin>>n;
    for(int l=0;l<n;l++){
        char line[101];
        scanf(" %s",line);
        string temp="";
        bool flag=false;
        for(int i=0;i<strlen(line);i++){
            if(line[i]>='0'&&line[i]<='9'){
                temp+=line[i];
                flag=true;
            }else{
                if(flag){
                    while(true){
                        if(temp.length()>1&&temp.at(0)=='0'){
                            temp=temp.substr(1,temp.length()-1);
                        }else{
                            break;
                        }
                    }
                    strarr.push_back(temp);
                }
                flag=false;
                temp="";
            }
        }
        if(flag){
            while(true){
                if(temp.length()>1&&temp.at(0)=='0'){
                    temp=temp.substr(1,temp.length()-1);
                }else{
                    break;
                }
            }
            strarr.push_back(temp);
        }
    }
	sort(strarr.begin(), strarr.end(), comp);
	for(int i=0; i<strarr.size(); i++)
		cout << strarr[i] << '\n';
}
