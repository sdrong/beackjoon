#include <iostream>
#include <string.h>
#include<algorithm>
#include<sstream>
#include<math.h>
#include<cctype>
#include<stdbool.h>
#include<vector>
#include<map>
#include<queue>
#include<stdbool.h>

using namespace std;

int n, n2;

int cx, cy;
int rx, ry;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1 , -2 };

int dir[301][301];
bool visited[301][301];
int cnt = 0;

queue<pair<int, int>> q;

void BFS(int y, int x)
{
	dir[y][x] = 0;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while(!q.empty()){
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int yy = qy + dy[i];
			int xx = qx + dx[i];
			if (!visited[yy][xx] && yy >= 0 && yy < n2 && xx >= 0 && xx < n2)
			{
				visited[yy][xx] = 1;
				dir[yy][xx] = dir[qy][qx] + 1;
				q.push(make_pair(yy, xx));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> n2;
		cin >> cy >> cx;
		cin >> ry >> rx;
		BFS(cy, cx);
		cout << dir[ry][rx] << "\n";
		memset(dir, 0, sizeof(dir));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}