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
#include<utility>

using namespace std;

int r, c;

int arr[51][51];

int dx[8] = { 0, 1, 1, 1 ,0, -1, -1, -1 };

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

queue<pair<int, int>> q;

void BFS()
{
	while (!q.empty())
	{
		int col = q.front().second;
		int row = q.front().first;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = col + dx[i];
			int ny = row + dy[i];
			if (nx < 0 || ny < 0 || nx >= c || ny >= r)
				continue;
			if (arr[ny][nx] == 0)
			{
				arr[ny][nx] = arr[row][col] + 1;
				q.push(make_pair(ny, nx));
			}
			else if (arr[ny][nx] > arr[row][col]+1)
			{
				arr[ny][nx] = arr[row][col] + 1;
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

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	BFS();
	int result = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			result = max(result, arr[i][j]);
		}
	}
	cout << result-1;
	return 0;
}