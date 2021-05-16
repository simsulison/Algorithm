#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[101][101];
queue<pair<int, char> > q;
queue<pair<int, int> > snake;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K, L;
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            map[i][j] = -1;
    cin >> K;
    for(int i=0; i<K; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 0;
    }
    cin>> L;
    for(int i=0; i<L; i++)
    {
        int t;
        char dir;
        cin >> t >> dir;
        q.push(make_pair(t, dir));
    }
    int time = 1;
    int pos = 0;
    int sx = 1, sy = 1;
    map[sx][sy] = 1;
    snake.push(make_pair(sx, sy));
    while (!q.empty())
    {
        pair<int, char> tmp = q.front();
        q.pop();
        while (time <= tmp.first)
        {
            int nx = sx + dx[pos];
            int ny = sy + dy[pos];
            if (nx <= 0 || nx > N || ny <= 0 || ny > N)
            {
                printf("%d\n", time);
                return (0);
            }
            if (map[nx][ny] == 0)
            {
                map[nx][ny] = 1;
                snake.push(make_pair(nx, ny));
            }
            else if (map[nx][ny] == -1)
            {
                pair<int, int> cur = snake.front();
                map[cur.first][cur.second] = -1;
                snake.pop();
                map[nx][ny] = 1;
                snake.push(make_pair(nx, ny));
            }
            else{
                printf("%d\n", time);
                return (0);
            }
            sx = nx;
            sy = ny;
            time++;
        }
        if (tmp.second == 'D')
            pos = (pos < 3) ? pos + 1 : 0;
        else
            pos = (pos > 0) ? pos - 1 : 3;
    }
    while (1)
    {
        int nx = sx + dx[pos];
        int ny = sy + dy[pos];
        if (nx <= 0 || nx > N || ny <= 0 || ny > N)
        {
            printf("%d\n", time);
            return (0);
        }
        if (map[nx][ny] == 0)
        {
            map[nx][ny] = 1;                
            snake.push(make_pair(nx, ny));
        }
        else if (map[nx][ny] == -1)
        {
            pair<int, int> cur = snake.front();
            map[cur.first][cur.second] = -1;
            snake.pop();
            map[nx][ny] = 1;
            snake.push(make_pair(nx, ny));
        }
        else{
            printf("%d\n", time);
            return (0);
        }
        sx = nx;
        sy = ny;
        time++;
    }
}