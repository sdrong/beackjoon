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
int arr[101][101];
bool visited[101][101];
int dir[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void BFS(int r, int c)
{
	visited[r][c] = true;
	dir[r][c] = 1;
	q.push(make_pair(r,c));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!visited[ny][nx] && ny >= 0 && ny < n && nx < n2 && nx >= 0 && arr[ny][nx] == 1)
			{
				visited[ny][nx] = true;
				dir[ny][nx] = dir[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> n2;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n2; j++)
		{
			arr[i][j] = s[j]-'0';
		}
	}
	BFS(0, 0);
	cout << dir[n-1][n2-1];
	return 0;
}