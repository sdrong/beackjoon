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

int n, n2, s;
vector<int> graph[1000001];
int visited[1000001];
int result[1000001];
int cnt;

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	cnt++;
	result[v] = cnt;
	while (!q.empty())
	{
		int inti = q.front();
		q.pop();
		for (int i = 0; i < graph[inti].size(); i++)
		{
			int num = graph[inti][i];
			if (!visited[num])
			{
				visited[num] = true;
				cnt++;
				result[num] = cnt;
				q.push(num);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> n2 >> s;
	for (int i = 0; i < n2; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].rbegin(), graph[i].rend());
	}
	BFS(s);
	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
	return 0;
}