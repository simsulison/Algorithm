#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int minv;
int maxv = -1;
int a[101];
int c[101];

void cal()
{
	minv = a[0] + 1;
	for(int i=0; i<N; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	for(int i=0; i<N; i++)
    {
        if (c[i] != 0)
        {
        	if (minv > a[i] / c[i])
            	minv = a[i] / c[i];
        }
    }
   	if (maxv < minv)
    	maxv = minv;
}

void division(int n, int sum, int index)
{
	for(int x=n; x>0; x--){
      if(index==0){ // 처음 시작 숫자
        c[index] = x;
        division(n-x, x, index+1);
      }
      else{ // 그 외
        c[index] = x;
        if(x<=c[index-1]) // 현재 숫자가 이전 숫자보다 작거나 같을 경우만
          division(n-x, sum+x, index+1); 
      }
    }  
    if(M == sum){
		cal();
    }
}

bool descending(int a, int b)
{
	return (a >= b);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(int i=0; i<N; i++)
			a[i] = 0;
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
			scanf("%d", &a[i]);
		sort(a, a+N, &descending);
		division(M, 0, 0);
		printf("%d\n", maxv);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
