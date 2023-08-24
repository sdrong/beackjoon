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

char girl[5][5];
bool visited[5][5];
vector<int> r;
vector<int> c;


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int result;

void Input()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> girl[i][j];
		}
	}
}

bool Fours() {
	int s = 0;
	for (int i = 0; i < 7; i++)
	{
		if (girl[r[i]][c[i]] == 'S')
			s++;
	}
	if (s >= 4)
		return 1;
	else
		return 0;
}

bool Snuggle()
{
	queue<pair<int, int>> q;
	
	q.push(make_pair(r[0], c[0]));

	int svisited[5][5];

	int re = 0;

	memset(svisited, 0, sizeof(svisited));
	
	int cnt = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (cnt == 7)
		{
			re = 1;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
			{
				if (visited[ny][nx] && !svisited[ny][nx])
				{
					svisited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					cnt++;
				}
			}
		}
	}
	return re;
}

void Dfs(int start , int cnt) {
	if (cnt == 7)
	{
		if (Fours())
		{
			if (Snuggle())
			{
				result++;
			}
		}
	}
	int i = start / 5;
	int j = start % 5;
	for (i; i < 5; i++)
	{
		for (j; j < 5; j++)
		{
			if (!visited[i][j])
			{
				r.push_back(i);
				c.push_back(j);
				visited[i][j] = 1;
				Dfs(i * 5 + j * 5, cnt + 1);
				visited[i][j] = 0;
				r.pop_back();
				c.pop_back();
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Dfs(0, 0);
	cout << result;
	return 0;
}