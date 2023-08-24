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

vector<int> vr;
vector<int> vc;

int g, s;

int arr[8][8];
int temp[8][8];
bool visited[8][8];

queue<int> qr;
queue<int> qc;

int big = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void copy(int temp[8][8], int arr[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
}

void BFS()
{
	int tem[8][8];
	copy(tem, temp);
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < g; j++)
		{
			if (tem[i][j] == 2)
			{
				qr.push(i);
				qc.push(j);
			}
		}
	}
	while (!qr.empty())
	{
		int x = qc.front();
		int y = qr.front();
		qc.pop();
		qr.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < g && ny >= 0 && ny < s && tem[ny][nx] == 0)
			{
				qc.push(nx);
				qr.push(ny);
				tem[ny][nx] = 2;
			}
		}
	}
	int val = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < g; j++)
		{
			if (!visited[i][j] && tem[i][j] == 0)
			{
				val++;
			}
		}
	}
	big = max(big, val);
}

void WALL(int inc)
{
	if (inc == 3)
	{
		BFS();
		return;
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < g; j++)
		{
			if (temp[i][j] == 0)
			{
				temp[i][j] = 1;
				WALL(inc + 1);
				temp[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> g;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < g; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < g; j++)
		{
			if (arr[i][j] == 0)
			{
				memset(visited, 0, sizeof(visited));
				copy(temp, arr);
				temp[i][j] = 1;
				WALL(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << big;
	return 0;
}