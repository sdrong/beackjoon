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

int s, e, t;

bool visited[100001];


int cnt = 0;

void BFS(int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	visited[n] = 1;
	while (!q.empty())
	{
		int now = q.front().first;
		int now_time = q.front().second;
		visited[now] = 1;
		q.pop();
		if (now == e && now_time == t && cnt)
		{
			cnt++;
		}
		if (now == e && !cnt)
		{
			t = now_time;
			cnt++;
		}
		if (now * 2 <= 100000 && !visited[now * 2])
		{
			q.push(make_pair(now * 2, now_time + 1));
		}
		if (now + 1 <= 100000 && !visited[now + 1])
		{
			q.push(make_pair(now + 1, now_time + 1));
		}
		if (now -1 >= 0 && !visited[now - 1])
		{
			q.push(make_pair(now - 1, now_time + 1));
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> e;
	BFS(s);
	cout << t << "\n" << cnt;
	return 0;
}