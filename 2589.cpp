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

char arr[51][51];
int choice_row, choice_col;

queue<pair<int, int>> q;
vector<pair<int, int>> v;
int big = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int visited[51][51];
int ccc[51][51];

void BFS(int r, int c)
{
	q.push(make_pair(r, c));
	visited[r][c] = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= choice_col || ny < 0 || ny >= choice_row)
				continue;
			if (arr[ny][nx] == 'L' && !visited[ny][nx])
			{
				ccc[ny][nx] = ccc[y][x] + 1;
				visited[ny][nx] = 1;
				big = max(big, ccc[ny][nx]);
				q.push(make_pair(ny, nx));
			}
		}
	}

}

void re()
{
	for (int j = 0; j < choice_row; j++)
	{
		for (int d = 0; d < choice_col; d++)
		{
			visited[j][d] = 0;
			ccc[j][d] = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> choice_row >> choice_col;

	string s;
	for (int i = 0; i < choice_row; i++)
	{
		cin >> s;
		for (int j = 0; j < choice_col; j++)
		{
			arr[i][j] = s[j];
			if (s[j] == 'L')
				v.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		BFS(v[i].first, v[i].second);
		re();
	}
	cout << big;
	return 0;
}