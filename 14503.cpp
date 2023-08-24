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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int arr[51][51];
bool visited[51][51];

int n, m;



void re(int y, int x, int d, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int dd = (d + 3 - i) % 4;
		int ny = y + dy[dd];
		int nx = x + dx[dd];
		if (ny < 0 || ny > n || nx < 0 || nx > m || arr[ny][nx] == 1) //기준 벗어나 있으면 아웃
			continue;
		if (!arr[ny][nx] && !visited[ny][nx])
		{
			visited[ny][nx] = 1;
			re(ny, nx, dd, cnt + 1);
		}
	}
	int backd = d + 2 < 4 ? d + 2 : d - 2;
	int backy = y + dy[backd];
	int backx = x + dx[backd];
	if (0 <= backy && backy < n && 0 <= backx && backx < m)
	{
		if (arr[backy][backx] == 0)
			re(backy, backx, d, cnt);
		else
		{
			cout << cnt;
			exit(0);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, y, d;
	cin >> n >> m; //n: 세로 m:가로
	cin >> y >> x >> d; // 시작위치 y: 세로 x: 가로 d:방향
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = 0;
		}
	}
	visited[y][x] = 1;
	re(y, x, d, 1);
	return 0;
}