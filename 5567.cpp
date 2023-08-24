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

int man, n;

vector<int> v[1001];
int counts[1001];
int visited[1001];

int cnt = 0;

void BFS(int num)
{
	queue<int> q;
	q.push(num);
	visited[num] = 1;
	while (!q.empty())
	{
		int val = q.front();
		q.pop();
		for (int i = 0; i < v[val].size(); i++)
		{
			int child = v[val][i];
			if (!visited[child])
			{
				visited[child] = 1;
				counts[child] = counts[val] + 1;
				q.push(child);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> man >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	BFS(1);
	for (int i = 2; i <= man; i++)
	{
		if (counts[i] <= 2 && visited[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}