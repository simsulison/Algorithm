#include <stdio.h>

char map[5][5];

int	cross_check(char ch)
{
	int cnt = 0;
	for(int i=0; i<4; i++)
	{
		if (map[i][i] == ch || map[i][i] == 'T')
			cnt++;	
	}
	if (cnt == 4)
		return (1);
	cnt = 0;
	for (int i=0; i<4; i++)
	{
		if (map[i][3-i] == ch || map[i][3-i] == 'T')
			cnt++;
	}
	if (cnt == 4)
		return (1);
	return (0);
}

int rc_check(char ch)
{
	int cnt = 0;
	for(int i=0; i<4; i++)
	{
		cnt = 0;
		for(int j=0; j<4; j++)
		{
			if (map[i][j] == ch || map[i][j] == 'T')
				cnt++;
		}
		if (cnt == 4)
			return (1);
	}
	for(int i=0; i<4; i++)
	{
		cnt = 0;
		for(int j=0; j<4; j++)
		{
			if (map[j][i] == ch || map[j][i] == 'T')
				cnt++;
		}
		if (cnt == 4)
			return (1);
	}
	return (0);
}

char *solve(int cnt)
{
	if (cross_check('O') || rc_check('O'))
		return ("O won\n");
	if (cross_check('X') || rc_check('X'))
		return ("X won\n");	
	if(cnt == 0)
		return ("Draw\n");
	else
		return ("Game has not complete\n");
}

int main(void)
{
	int test_case;
	int T;
	scanf("%d", &T);
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int cnt = 0;
		for(int i=0; i<4; i++)
		{
			scanf("%s", map[i]);
			for(int j=0; j<4; j++)
			{
				if (map[i][j] == '.')
					cnt++;
			}
		}
		for(int i=0; i<4; i++)
		{
			printf("%s\n", map[i]);
		}
		//printf("#%d %s", test_case, solve(cnt));
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
