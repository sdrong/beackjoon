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

int arr[17][17];

int n;

int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 1, 0 };

int cnt;

bool ok(int x, int y, int m)
{
	if (m == 0)
	{		
		int nx = x + dx[0];
		int ny = y + dy[0];
		if (!arr[nx][ny] || nx < 0 || nx > n - 1 || ny < 0 || nx > n - 1)
			return 1;
		else
			return 0;
	}
	if (m == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] || nx < 0 || nx > n-1 || ny < 0 || nx > n-1)
				return 0;
		}
		return 1;
	}
	if (m == 2)
	{
		int nx = x + dx[2];
		int ny = y + dy[2];
		if (!arr[nx][ny] || nx < 0 || nx > n - 1 || ny < 0 || nx > n - 1)
			return 1;
		else
			return 0;
	}
}

void DFS(int x, int y, int m)
{
	if (x >= n || y >= n)
	{
		return;
	}
	if (x == n - 1 && y == n - 1)
	{
		cnt++;
		return;
	}
	if (m == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ok(x, y, i))
			{
				DFS(nx, ny, i);
			}
		}
	}
	if (m == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ok(x, y, i))
			{
				DFS(nx, ny, i);
			}
		}
	}
	if (m == 2)
	{
		for (int i = 1; i < 3; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ok(x, y, i))
			{
				DFS(nx, ny, i);
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
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	DFS(0, 1, 0);
	cout << cnt;
	return 0;
}