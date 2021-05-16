#include<iostream>
#include<queue>
using namespace std;

int N, M;
char map[1001][1001];
int check[1001][1001];
bool visit[1001][1001];
queue<pair<int, int> >q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve()
{
    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            check[nx][ny] = min(check[x][y] + 1, check[nx][ny]);
            if (!visit[nx][ny])
            {
                visit[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;
        for(int i= 0; i<N; i++)
            for(int j=0; j<M; j++)
                check[i][j] = INT_MAX;
        for(int i = 0; i < N; i++)
        {
            cin >> map[i];
            for(int j=0; j<M; j++)
            {
                if(map[i][j] == 'W')
                {
                    q.push(make_pair(i,j));
                    visit[i][j] = 1;
                    check[i][j] = 0;
                }
            }
        }
        solve();
        int sum = 0;
        for(int i =0; i<N; i++)
            for(int j = 0; j<M; j++)
                sum += check[i][j];
        printf("#%d %d\n",test_case, sum);
	}
	return 0;
}