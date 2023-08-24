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

int arr[501][501];
bool visited[501][501];

int row, col;

queue<pair<int, int>> q;

int big = 0;
int n;

int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0 ,1 ,-1 };

void DFS(int r, int c)
{
	n++;
	for (int i = 0; i < 4; i++)
	{
		int nx = c + dx[i];
		int ny = r + dy[i];
		if (ny < 0 || ny >= row || nx < 0 || nx >= col)
			continue;
		if (!visited[ny][nx] && arr[ny][nx])
		{
			visited[ny][nx] = 1;
			DFS(ny, nx);
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (!visited[r][c])
		{
			visited[r][c] = 1;
			DFS(r, c);
			cnt++;
			big = max(big, n);
			n = 0;
		}
	}
	cout << cnt << "\n" << big;
	return 0;
}