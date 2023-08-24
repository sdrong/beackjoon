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

int n, m;

int result[100001];
int visited[100001];

vector<int> v[101];

void BFS(int val)
{
	queue<pair<int, int>> q;
	q.push(make_pair(val, 0));
	visited[val] = 1;
	int total = 0;
	while (!q.empty())
	{
		int num = q.front().first;
		int num_cnt = q.front().second;
		total += num_cnt;
		q.pop();
		for (int i = 0; i < v[num].size(); i++)
		{
			int link = v[num][i];
			if (!visited[link])
			{
				visited[link] = 1;
				q.push(make_pair(link, num_cnt + 1));
			}
		}
	}
	result[val] = total;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= n; i++)
	{
		BFS(i);
		memset(visited, 0, sizeof(visited));
	}
	int big = result[1];
	for (int i = 1; i <= n; i++)
	{
		if (big > result[i])
			big = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << "\n";
	}
	cout << big;
	return 0;
}