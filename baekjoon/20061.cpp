#include<iostream>
using namespace std;
int N;
typedef struct block
{
	int t,x,y;
}block;
block b[10001];
int red[4][4];
int green[6][4];
int blue[4][6];

void move(int mode)
{
	if (mode == 0)
	{
		for(int i=4; i>=0; i--)
		{
			green[i + 1][0] = green[i][0];
			green[i + 1][1] = green[i][1];
			green[i + 1][2] = green[i][2];
			green[i + 1][3] = green[i][3];
		}
		for(int i=0; i<4; i++)
			green[0][i] = 0;
	}
	else if (mode == 1)
	{
		for(int i=4; i>=0; i--)
		{
			blue[0][i + 1] = blue[0][i];
			blue[1][i + 1] = blue[1][i];
			blue[2][i + 1] = blue[2][i];
			blue[3][i + 1] = blue[3][i];
		}
		for(int i=0; i<4; i++)
			blue[i][0] = 0;
	}
}

void special_check(int mode)
{
	if (mode == 0)
	{
		int row_cnt = 0;
		for(int j=0; j<4; j++)
		{
			if (green[0][j] != 0)
			{
				row_cnt++;
				break;
			}
		}
		for(int j=0; j<4; j++)
		{
			if (green[1][j] != 0)
			{
				row_cnt++;
				break;
			}
		}
		for(int j=0; j<row_cnt; j++)
			move(0);
	}
	else if (mode == 1)
	{
		int col_cnt = 0;
        for(int j=0; j<4; j++)
        {
            if (blue[j][0] != 0)
            {
                col_cnt++;
                break;
            }
        }
        for(int j=0; j<4; j++)
        {
            if (blue[j][1] != 0)
            {
                col_cnt++;
                break;
            }
        }
        for(int j=0; j<col_cnt; j++)
            move(1);
	}
}

int fill_check(int mode)
{
	int change = 0;
	if (mode == 0)
	{
		for(int i=5; i>=2; i--)
		{
			int cnt = 0;
			for(int j=0; j<4; j++)
			{
				if (green[i][j] != 0)
					cnt++;
			}
			if (cnt == 4)
			{
				for(int j = i - 1; j >= 0; j--)
				{
					green[j + 1][0] = green[j][0];
					green[j + 1][1] = green[j][1];
					green[j + 1][2] = green[j][2];
					green[j + 1][3] = green[j][3];
				}
				i++;
				change++;
			}
		}
	}
	else if (mode == 1)
	{
		for(int i=5; i>=2; i--)
        {
            int cnt = 0;
            for(int j=0; j<4; j++)
            {
                if (blue[j][i] != 0)
                    cnt++;
            }
            if (cnt == 4)
            {
                for(int j = i - 1; j >= 0; j--)
                {
                    blue[0][j + 1] = blue[0][j];
                    blue[1][j + 1] = blue[1][j];
                    blue[2][j + 1] = blue[2][j];
                    blue[3][j + 1] = blue[3][j];
                }
                i++;
                change++;
            }
        }
	}
	return change;
}

int tile_count(int mode)
{
	int cnt = 0;
	if (mode == 0) // 초록
	{
		for(int i=2; i<6; i++)
		{
			for(int j=0; j<4; j++)
			{
				if (green[i][j] != 0)
					cnt++;
			}
		}
	}
	else if (mode == 1) // 파란색
	{
		for(int i=0; i<4; i++)
		{
			for(int j=2; j<6; j++)
			{
				if (blue[i][j] != 0)
					cnt++;
			}
		}		
	}
	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> b[i].t >> b[i].x >> b[i].y;
	int score = 0;
	int total = 0;
	for(int i=0; i<N; i++)
	{
		int type = b[i].t;
		int x = b[i].x; int y = b[i].y;
		if (type == 1)
		{
			int nx = x; int ny = 0;
			while (ny < 5)
			{
				if (blue[nx][ny + 1] == 0)
					ny++;
				else break;
			}
			blue[nx][ny] = type;
			nx = 0; ny = y;
			while (nx < 5)
			{
				if (green[nx + 1][ny] == 0)
					nx++;
				else break;
			}
			green[nx][ny] = type;
		}
		else if (type == 2)
		{
			int nx = x, ny = 1;
			while (ny < 5)
			{
				if (blue[nx][ny + 1] == 0)
					ny++;
				else 
					break;
			}
			blue[nx][ny - 1] = type; blue[nx][ny] = type; 
			nx = 0; ny = y;
			while (nx < 5)
			{
				if (green[nx + 1][ny] == 0 && green[nx + 1][ny + 1] == 0)
					nx++;
				else break;
			}
			green[nx][ny] = type; green[nx][ny + 1] = type;
		}
		else if (type == 3)
		{
			int nx = x; int ny = 0;
			while (ny < 5)
			{
				if (blue[nx][ny + 1] == 0 && blue[nx + 1][ny + 1] == 0)
					ny++;
				else break;
			}
			blue[nx][ny] = type; blue[nx + 1][ny] = type;
			nx = 1; ny = y;
			while (nx < 5)
			{
				if (green[nx + 1][ny] == 0)
					nx++;
				else break;
			}
			green[nx - 1][ny] = type; green[nx][ny] = type;
		}
		int rows = 0, cols = 0;
		rows = fill_check(0); //green 점수내기
		score += rows;
		cols = fill_check(1); //blue 점수내기
		score += cols;
		special_check(0);
		special_check(1);
	}
	total = tile_count(0) + tile_count(1);
	cout << score << "\n" << total << "\n";
	return (0);
}

