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

int m, n, h;
int total = 0;
int cnt = 0;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[101][101][101];
int dir[101][101][101];
bool visited[101][101][101];
queue<int> qx;
queue<int> qy;
queue<int> qz;
int small = 0;
void BFS()
{
	while (!qz.empty()) {
		int z = qz.front();
		int y = qy.front();
		int x = qx.front();
		qz.pop();
		qy.pop();
		qx.pop();
		for (int i = 0; i < 6; i++)
		{
			int zz = z + dz[i];
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (!visited[zz][yy][xx] && yy >= 0 && yy < n && xx >= 0 && xx < m && zz >= 0 && zz < h && arr[zz][yy][xx] == 0)
			{
				visited[zz][yy][xx] = 1;
				dir[zz][yy][xx] = dir[z][y][x] + 1;
				qz.push(zz);
				qy.push(yy);
				qx.push(xx);
				cnt++;
				small = dir[zz][yy][xx];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				cin >> arr[i][j][l];
				if (arr[i][j][l] == 1)
				{
					visited[i][j][l] = 1;
					qx.push(l);
					qy.push(j);
					qz.push(i);
				}
				if (arr[i][j][l] == 0)
				{
					total++;
				}
			}
		}
	}
	BFS();
	if (total != cnt)
		cout << -1;
	else
		cout << small;
	return 0;
}