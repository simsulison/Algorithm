#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N, L, R;
int map[51][51];
bool visit[51][51];
vector<pair<int, int> > uni;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void init()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			visit[i][j] = false;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> L >> R;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	int count = 0;
	while (1)
	{
		int flag = 0;
		init();
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if (!visit[i][j])
				{
					visit[i][j] = true;
					queue<pair<int, int> > q;
					uni.push_back(make_pair(i, j));
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						pair<int, int> tmp = q.front();
						q.pop();
						for(int k=0; k<4; k++)
						{
							int nx = tmp.first + dx[k];
							int ny = tmp.second + dy[k];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N)
								continue;
							if (!visit[nx][ny])
							{
								int diff = abs(map[nx][ny] - map[tmp.first][tmp.second]);
								if (diff >= L && diff <= R)
								{
									visit[nx][ny] = 1;
									uni.push_back(make_pair(nx, ny));
									q.push(make_pair(nx, ny));
									flag = 1;
								}
							}			
						}
					}
					int sum = 0;
					for(int k=0; k<uni.size(); k++)
					{
						int x = uni[k].first;
						int y = uni[k].second;
						sum += map[x][y];
					}
					int len = uni.size();
					while (!uni.empty())
					{
						int x = uni.back().first;
						int y = uni.back().second;
						map[x][y] = sum / len;
						uni.pop_back();
					}
				}
			}
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		if (!flag)
			break;
		count++;
	}
	printf("%d\n", count);
	return (0);
}
