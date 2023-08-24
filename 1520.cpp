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

int y, x;

int arr[501][501];
int dir[501][501];
bool visited[501][501];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0 ,1, -1 };

int cnt = 0;

int DFS(int r, int c)
{
	if (r == y - 1 && c == x - 1)
	{
		return 1;
	}
	if (visited[r][c])
		return dir[r][c];
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = c + dx[i];
		int ny = r + dy[i];
		if ( nx >= 0 && nx < x && ny >= 0 && ny < y && arr[r][c] > arr[ny][nx])
		{
			dir[r][c] += DFS(ny, nx);
		}
	}
	return dir[r][c];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> y >> x;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> arr[i][j];
		}
	}
	DFS(0, 0);
	cout << dir[0][0];
	return 0;
}