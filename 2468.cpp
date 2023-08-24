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

int n;
int max_heigh = 0;
int min_heigh = 9999;

int arr[101][101];
bool b[101][101];
bool visited[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<pair<int, int>> v;

void de(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= n || nx < 0)
			continue;
		if (!visited[ny][nx] && b[ny][nx])
		{
			visited[ny][nx] = 1;
			de(ny, nx);
		}
	}
}

int get_result(int num)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] <= num)
				b[i][j] = 0;
			else {
				b[i][j] = 1;
				v.push_back(make_pair(i, j));
			}
		}
	}
	while (!v.empty())
	{
		int y = v.back().first;
		int x = v.back().second;
		v.pop_back();
		if (!visited[y][x])
		{
			visited[y][x] = 1;
			de(y, x);
			cnt++;
		}
	}
	return cnt;
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
			min_heigh = min(min_heigh, arr[i][j]);
			max_heigh = max(max_heigh, arr[i][j]);
		}
	}
	int big = 1;
	int big_num = 0;
	for (int i = min_heigh; i <= max_heigh; i++)
	{
		big = max(big, get_result(i));
		memset(visited, 0, sizeof(visited));
	}
	cout << big;
	return 0;
}