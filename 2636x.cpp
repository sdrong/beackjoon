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

int x, y;

int arr[100][100];
bool visited[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int t = 0;
int r = 0;
bool BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	int cnt = 0;
	visited[0][0] = 1;
	t++;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (!visited[nr][nc] && nr >= 0 && nr < y && nc >= 0 && nc < x)
			{
				if (arr[nr][nc] == 0)
				{
					q.push(make_pair(nr, nc));
				}
				else
				{
					arr[nr][nc] = 0;
					cnt++;
				}
				visited[nr][nc] = 1;
			}
		}
	}
	if (cnt == 0)
	{
		cout << --t << "\n" << r;
		return true;
	}
	else {
		r = cnt;
		return false;
	}
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
	while (1)
	{
		if (BFS())
			break;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}