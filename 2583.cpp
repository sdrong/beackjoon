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

int m, n, k;

int arr[100][100];
bool visited[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int cnts[10000];

int cnt = 0;

bool DFS(int r, int c)
{
	if (visited[r][c] == 1)
		return false;
	int ct = 0;
	queue<int> qr;
	queue<int> qc;
	qr.push(r);
	qc.push(c);
	visited[r][c] = 1;
	while (!qr.empty())
	{
		ct++;
		int x = qc.front();
		qc.pop();
		int y = qr.front();
		qr.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = y + dy[i];
			int nc = x + dx[i];
			if (!visited[nr][nc] && nr >= 0 && nr < m && nc >= 0 && nc < n)
			{
				qr.push(nr);
				qc.push(nc);
				visited[nr][nc] = 1;
			}
		}
	}
	cnts[cnt] = ct;
	return true;
}

void print()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int sc, sr, ec, er;
		cin >> sc >> sr >> ec >> er;
		for (int j = sr; j < er; j++)
		{
			for (int l = sc; l < ec; l++)
			{
				visited[j][l] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (DFS(i, j))
			{
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	sort(cnts, cnts + cnt);
	for (int i = 0; i < cnt; i++)
	{
		cout << cnts[i] << " ";
	}
	return 0;
}